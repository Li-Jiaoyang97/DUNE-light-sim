//defining some global variables 
const double gLowerCorner[3] = {-261.69, -275.0382, -59.9294};
const double gUpperCorner[3] = {261.69, 275.0382, 649.2353};
const int gxSteps = 104;
const int gySteps = 54;
const int gzSteps = 71;
const double deltaX = (gUpperCorner[0] - gLowerCorner[0])/gxSteps;
const double deltaY = (gUpperCorner[1] - gLowerCorner[1])/gySteps;
const double deltaZ = (gUpperCorner[2] - gLowerCorner[2])/gzSteps;
const double gLowerActive[3] = {-201.3, -203.732, 0};
const double gUpperActive[3] = {201.3, 203.732, 509.4};
//------------------------------------------------------
//------------------------------------------------------
double* GetVoxelCoords(int ID)
{  

  double *ReturnVector = new double[3];
  ReturnVector[0] = ID % gxSteps;
  ReturnVector[1] = int((ID - ReturnVector[0]) / gxSteps) % gySteps;
  ReturnVector[2] =
    int((ID - ReturnVector[0] - (ReturnVector[1] * gxSteps)) / (gySteps * gxSteps)) % gzSteps;

  ReturnVector[0] = gLowerCorner[0] + (ReturnVector[0] + 0.5)*deltaX;
  ReturnVector[1] = gLowerCorner[1] + (ReturnVector[1] + 0.5)*deltaY;
  ReturnVector[2] = gLowerCorner[2] + (ReturnVector[2] + 0.5)*deltaZ;
  
  return ReturnVector;
}
//------------------------------------------------------
//------------------------------------------------------

void Filter_ActiveVol(std::string input_file, std::string OutputName){

  TFile *f = TFile::Open(OutputName.c_str(),"RECREATE");
  Int_t Voxel, OpChannel;
  Float_t Visibility, ReflVisibility;
  TTree * tt = new TTree("PhotonLibraryData","PhotonLibraryData");
  tt->Branch("Voxel",      &Voxel,      "Voxel/I");
  tt->Branch("OpChannel",  &OpChannel,  "OpChannel/I");
  tt->Branch("Visibility", &Visibility, "Visibility/F");
  tt->Branch("ReflVisibility", &ReflVisibility, "ReflVisibility/F");

  TFile* f_input = new TFile(input_file.c_str());
  Int_t Voxel0, OpChannel0;
  Float_t Visibility0, ReflVisibility0;
  TTree *tree = (TTree *)f_input->Get("PhotonLibraryData");
  tree->SetBranchAddress("Voxel", &Voxel0);
  tree->SetBranchAddress("OpChannel", &OpChannel0);
  tree->SetBranchAddress("Visibility", &Visibility0);
  tree->SetBranchAddress("ReflVisibility", &ReflVisibility0);
  int contador_in = 0;
  int contador_out = 0;
  for(int i=0; i!=tree->GetEntries(); ++i)
    {
      tree->GetEntry(i);
      
      double *Position = new double[3];
      Position = GetVoxelCoords(Voxel0);

       if(!(Position[0] > gLowerActive[0] && Position[0] < gUpperActive[0] &&
      	   Position[1] > gLowerActive[1] && Position[1] < gUpperActive[1] &&
      	   Position[2] > gLowerActive[2] && Position[2] < gUpperActive[2]))

	{
	  Voxel = Voxel0;
	  OpChannel = OpChannel0;
	  Visibility = Visibility0;
	  ReflVisibility = ReflVisibility0;
	  
	  tt->Fill();
	  contador_out++;
	}
      else {
	contador_in++;
	//cout<<"No guardo esta voxel -> (x,y,z): ("<<Position[0]<<", "<<Position[1]<<", "<<Position[2]<<")   ID: "<<Voxel0<<endl;
      }
    }
  
  //f->cd();
  f->Write();
  f->Close();
  delete f;
  cout<<"Finaly: Voxels IN: "<<contador_in<<"  Voxels OUT: "<<contador_out<<endl;
}

void remove_Active(){

  string input_file = "SBND_OpLibFULL_v2.00New.root";
  string OutputNameFiltered = "SBND_OpLibOUT_v2.00New.root";
  Filter_ActiveVol(input_file.c_str(), OutputNameFiltered.c_str());

}
