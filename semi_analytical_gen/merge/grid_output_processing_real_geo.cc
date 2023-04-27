// reads grid output and creates slimmed file for semi-analytic parameterisation generation 
void grid_output_processing_real_geo(TString type){
	//string type = "laterals_full_refl_xenon_varying_z"; 
  	TString lista_files = "./List_of_Grid_files_"+type; //List_of_Grid_files
	TString positions = "dunevd_optical_mapping.txt";  
	
	//getting the pmt positions (y and z)
	ifstream Traks_file1(positions);
	if(!Traks_file1) cerr << "WARNING:  Failed to open file with optical detector positions"<< endl;
	Traks_file1.seekg(0);
	vector<double> devx;
	vector<double> devy;
	vector<double> devz;
	double id, x, y, z;
	while(!(Traks_file1.eof())) { 
		Traks_file1 >> id >> x >> y >> z;
		devx.push_back(x);
		devy.push_back(y);
		devz.push_back(z);
	}

	int numberDevices = devy.size();
	cout<<"----> numberDevices: "<<numberDevices<<endl;
	
	//getting the file names
	ifstream Traks_file2(lista_files);
	if(!Traks_file2) cerr << "WARNING:  Failed to open file with Input file names"<< endl;
	Traks_file2.seekg(0);
	vector<string> names;
	string nombre;
	while(!(Traks_file2.eof())) { 
		Traks_file2 >> nombre;
		names.push_back(nombre);
	}
	const int n_files = names.size();
	cout<<"----> number of files: "<<n_files<<endl;

	const Int_t kMaxDevices = 600;
	if(kMaxDevices < numberDevices) {
		cout<<"Warning: numberDevices larger than kMaxDevices, so change the last to continue!!!"<<endl;
		exit(0);
	}

	// create a new tree file with all the information needed
	const TString root_file_name = "/dune/data/users/jiaoyang/new_traning_sample_0427/semi_analytic_hits_vd_"+type+".root";
	TFile *hfile = new TFile(root_file_name,"RECREATE");
	TTree *myTree = new TTree("myTree","A ROOT tree");
	int VUV_hits[kMaxDevices];
	int Vis_hits[kMaxDevices];
	double posX, posY, posZ;
	int genPhotons;
	double wavelength_new;
	myTree->Branch("numberDevices",&numberDevices,"numberDevices/I");
	myTree->Branch("X", &posX, "X/D");
	myTree->Branch("Y", &posY, "Y/D");
	myTree->Branch("Z", &posZ, "Z/D");
	myTree->Branch("VUV_hits",VUV_hits,"VUV_hits[numberDevices]/I");
	myTree->Branch("Vis_hits",Vis_hits,"Vis_hits[numberDevices]/I");
	myTree->Branch("genPhotons", &genPhotons, "genPhotons/I");
	myTree->Branch("Wavelength", &wavelength_new, "Wavelength/D");

	//loop over files
	for(int n=0; n<n_files; n++) { //n_files
	//for (int n = 0; n < 3; n++) {
		// set initial hits to 0 for each pmt
		for(int i=0; i<numberDevices; i++) {
			VUV_hits[i] = 0;
			Vis_hits[i] = 0;
		}

		// read data file
		string input_file = names.at(n);
		cout<<"-------------------------------------------------------"<<endl;
    	cout<<"File " << n << ": " << input_file << endl;
    	cout<<"-------------------------------------------------------"<<endl;
		TFile *infile = TFile::Open(input_file.c_str());//new TFile(input_file.c_str());
		
		if (infile && !infile->IsZombie()) { // checking if the file is zombine or not.
		   //std::cerr << "Error opening file" << endl;
		
			// set branch addresses
			TTree *AllPhotons = nullptr;	 
		    infile->GetObject("pmtresponse/AllPhotons", AllPhotons);
			
			int EventID, OpChannel; float Wavelength, Time;
			if (AllPhotons) {
				AllPhotons->SetBranchAddress("EventID", &EventID);
				AllPhotons->SetBranchAddress("OpChannel", &OpChannel);
				AllPhotons->SetBranchAddress("Wavelength", &Wavelength);
				AllPhotons->SetBranchAddress("Time", &Time);
			}else{
				std::cout<<"corrupted file!"<<std::endl<<std::endl<<std::endl;
				continue;
			}

			TTree *PhotonsGenerated = nullptr;
			infile->GetObject("generator/PhotonsGenerated", PhotonsGenerated);

			Double_t X, Y, Z;
			if (PhotonsGenerated) {
				PhotonsGenerated->SetBranchAddress("X", &X);
				PhotonsGenerated->SetBranchAddress("Y", &Y);
				PhotonsGenerated->SetBranchAddress("Z", &Z);
			}else{
				std::cout<<"corrupted file!"<<std::endl<<std::endl<<std::endl;
				continue;
			}
			
			// position and number of photons
			PhotonsGenerated->GetEntry(0);
		    posX = X;
		    posY = Y;
		    posZ = Z;
		    genPhotons = PhotonsGenerated->GetEntries();
		    wavelength_new = Wavelength;

		 	// loop through photons   
			int num_entries = AllPhotons->GetEntries();
			for (int i = 0; i < num_entries; i++){
				
				AllPhotons->GetEntry(i);
				
				// apply wavelength cut to separate vuv and visible	
				if (Wavelength < 300) {
		  			VUV_hits[OpChannel]++;
				}
				else {
		  			Vis_hits[OpChannel]++;
				}
			
			} // end photon loop

			// fill tree
			myTree->Fill();

			// delete file
			delete infile;
		}else{
			std::cerr << "Error opening file, the file is corrupted." << endl;
		}

	} // end file loop

	// write output file
	hfile->Write();
   	hfile->Close();
}
