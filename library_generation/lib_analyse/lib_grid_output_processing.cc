#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"
#include <iostream>
#include <fstream>

TChain * CreateChainFromList_opt(std::string ListFileName, std::string ChainName, bool DoCheck, TString zombine_files);

void lib_grid_output_processing(TString type = "argon", TString zombine_files = "./List_zombies_argon")
{ 
  bool debug = false;
  std::cout<<"Begining AssembleSingleFile.C\n";
  
  std::string FileList = "./List_of_Grid_files_"+std::string(type); //List_of_Grid_files
  
  TChain * ch = CreateChainFromList_opt(FileList.c_str(), "pmtresponse/PhotonLibraryData", true, zombine_files);

  Int_t Voxel, OpChannel;
  Float_t Visibility;
  ch->SetBranchAddress("Voxel",      &Voxel);
  ch->SetBranchAddress("OpChannel",  &OpChannel);
  ch->SetBranchAddress("Visibility", &Visibility);
  
  std::cout<<"Create Output File\n";

  TString save_dir = "/dune/data/users/jiaoyang/newLib0503/";
  gSystem->Exec("mkdir -p " + save_dir);
  //gSystem->Exec("rm "+save_dir+"*");
  const TString root_file_name = save_dir+"dunevd10kt_3view_30deg_v5_refactored_1x8x14ref_"+type+"_new.root";
  TFile *f = new TFile(root_file_name,"RECREATE");
  TTree *tt = new TTree("PhotonLibraryData","PhotonLibraryData");
  tt->Branch("Voxel",      &Voxel,      "Voxel/I");
  tt->Branch("OpChannel",  &OpChannel,  "OpChannel/I");
  tt->Branch("Visibility", &Visibility, "Visibility/F");
  

  /*TChain * ch2 = CreateChainFromList_opt(FileList.c_str(),"generator/PhotonsGenerated",false);  
  Double_t X, Y, Z;
  if(debug){
    ch2->SetBranchAddress("X", &X);
    ch2->SetBranchAddress("Y", &Y);
    ch2->SetBranchAddress("Z", &Z);

    tt->Branch("X", &X, "X/D");
    tt->Branch("Y", &Y, "Y/D");
    tt->Branch("Z", &Z, "Z/D");
  }
  */

  std::cout<<"Start Fill of output file branches\n";
  long int nEnt = ch->GetEntries();
  std::cout<<"Need to loop over "<<nEnt<<" entries.";
  for(long int i=0; i<nEnt; ++i)
    { 
      if( i%1000==0) {
        std::cout<<"Now on entry "<<i<<" of "<<nEnt<<"\n";
      }else if( i>nEnt || i<0 ){
        std::cout<<"ERROR: i="<<i<<" does not fall in the range 0 to "<<nEnt<<". Aborting.\n";
        //throw std::logic_error();
        throw 20;
      }
      
      ch->GetEntry(i);
      //ch2->GetEntry(i);
      //std::cout << "Voxel: " << Voxel << ", X: " << X << ", Y:" << Y << ", Z: " << Z <<std::endl;

      tt->Fill();
    }
  
  std::cout<<"write output file\n";
  f->Write();
  f->Close();
}

TChain * CreateChainFromList_opt(std::string ListFileName, std::string ChainName, bool DoCheck, TString zombine_files)
{
  ifstream InputFile(ListFileName.c_str());
  std::string FileName;

  TChain * TheChain = new TChain(ChainName.c_str());
  if(!DoCheck){
    while(getline(InputFile, FileName)){
      //FileName=BaseDirectory+FileName;
      std::cout<<"Adding file "<< FileName.c_str()<<" to the TChain"<<std::endl;
      TheChain->Add(FileName.c_str());
    }
  }
  else{
    std::ofstream outputFile(zombine_files);
    while(getline(InputFile, FileName)){
      //FileName=BaseDirectory+FileName;
      TFile *infile = TFile::Open(FileName.c_str());
      if (infile && !infile->IsZombie()){
        //if(infile->Get(ChainName.c_str())){
        //std::cout<<"Adding file "<< FileName.c_str()<<" to the TChain"<<std::endl;
        //if (TheChain->GetFile() && !TheChain->GetFile()->IsZombie()){
          TheChain->Add(FileName.c_str());
        }else{
          //std::cout << "Zombie file detected: " << filename << std::endl;
          outputFile << FileName.c_str() << std::endl;
        }
      /*}else {
        outputFile << FileName.c_str() << std::endl;
      }*/
    }
    outputFile.close();
  }
  return TheChain;
}