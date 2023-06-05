// cathode foils information - DUNE VD
// tpc drift length
const double plane_depth = 651.51; // cm 
// size of cathode covered by foils
const double y_dimension_foils = 1468.44; //cm
const double z_dimension_foils = 2000.00; //cm
// centre coordinates of foils
const double x_foils = 324.97; const double y_foils = 0; const double z_foils = 1000; // cm


double min_number_entries = 1000;
  // width and height in cm of arapuca active window  
double arapuca_w = 60;
double arapuca_h = 60;

// Y-Z coordinates of the active volume center
const double centerYZ[2] = {0., 1000.};
const double centerXZ[2] = {0., 1000.};  // laterals

// LAr absorption length in cm
// This needs to match with the value used in the full-geant4 simulation
const double L_abs = 8000.;
const double pi = 3.1415;

// base GH corrections, Xenon case
// cathode 
const double fGHVUVPars[4][9] = {{1.1049, 1.07479, 1.02076, 0.93363, 0.82446, 0.698284, 0.543591, 0.393275, 0.245505},
                {337.657, 341.668, 337.686, 306.357, 399.302, 385.279, 526.609, 468.479, 579.694}, 
                {48.0672, 48.4208, 52.8376, 72.644, 57.6821, 83.6268, 73.8169, 190.04, 120.46}, 
                {-5000, -5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000} };  
const std::vector<double> angulo = {5, 15, 25, 35, 45, 55, 65, 75, 85};
const std::vector<double> slopes1 = {-0.000102714, -0.000113153, -0.000114518, -9.82358e-05, -8.03786e-05, -8.05226e-05, -6.21285e-05, -4.80135e-05, -4.58966e-05};  
const std::vector<double> slopes2 = {-0.173699, -0.143313, -0.0883797, 0.000720782, -0.150663, -0.029365, -0.166611, 0.102775, 0.200032}; 
const std::vector<double> slopes3 = {0.0200722, 0.0246623, 0.0151071, -0.0115584, 0.0398629, 0.0150788, 0.0763549, 0.0102863, 0.0898464};


// laterals
//old -- backup. 
double fGHVUVPars_lateral[4][9] = { {0.768429, 0.746231, 0.688473, 0.614132, 0.519218, 0.423708, 0.32315, 0.219395, 0.130225}, 
                            {75.5799, 81.3074, 134.1, 228.048, 384.154, 463.658, 507.277, 503.066, 618.262}, 
                            {199.322, 203.701, 190.664, 152.499, 119.471, 116.854, 114.914, 200.094, 161.337}, 
                            {-5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000, -3000} }; 
std::vector<double> slopes1_lateral = {8.48603e-06, 8.98247e-06, -3.63653e-06, -9.95952e-06, -1.75055e-05, -1.37906e-05, -2.25792e-05, -1.47632e-05, -2.48246e-06};  
std::vector<double> slopes2_lateral = {-0.0959428, -0.107448, -0.131037, -0.146021, -0.0775682, -0.110341, 0.0835893, 0.202368, 0.165891};  
std::vector<double> slopes3_lateral = {-0.0403316, -0.0448196, 0.00571835, 0.041887, 0.0274199, 0.0441016, 0.0233044, -0.000372937, 0.0428478};  

/*
std::vector<double> fGH_d_anode = {17., 39., 104., 180., 252.}; // larger distances use 260cm case
std::vector<std::vector<std::vector<double>>> fGHVUVPars_lateral = { 
  { {0.702395, 0.674004, 0.629027, 0.56269, 0.487242, 0.405077, 0.31262, 0.239467, 0.165155},
    {0.71793, 0.693233, 0.65714, 0.594806, 0.525876, 0.436993, 0.337352, 0.27575, 0.202563},
    {0.727217, 0.707722, 0.665706, 0.603831, 0.533153, 0.449494, 0.354854, 0.282249, 0.21031},
    {0.744886, 0.717514, 0.67731, 0.616522, 0.544997, 0.459856, 0.362849, 0.293873, 0.219273},
    {0.773897, 0.738748, 0.684699, 0.613509, 0.546194, 0.461667, 0.365074, 0.286016, 0.206577}
  },
  { {-210.168, -107.002, -51.5141, 2.42869, 271.894, 351.304, 436.882, 633.402, 707.127},
    {-53.9173, 42.8726, 69.1177, 95.1767, 297.642, 389.209, 369.464, 532.888, 513.222},
    {74.1934, 51.8974, 73.3663, 246.006, 356.251, 403.12, 362.036, 556.74, 564.064},
    {143.524, 68.7196, 102.834, 262.17, 393.44, 439.581, 471.373, 594.018, 557.582},
    {203.181, 112.45, 161.049, 257.266, 290.641, 434.449, 573.296, 667.369, 753.476}
  },
  { {199.486, 199.992, 199.983, 199.992, 135.057, 145.059, 167.517, 199.998, 199.988},
    {176.026, 197.56, 199.884, 199.443, 128.933, 136.905, 199.993, 199.997, 199.852},
    {151.261, 199.997, 199.935, 145.369, 121.838, 132.574, 199.569, 199.98, 199.944},
    {158.101, 183.76, 199.961, 147.555, 115.464, 134.99, 167.456, 199.997, 199.795},
    {163.588, 199.845, 199.973, 200, 171.887, 139.149, 137.857, 199.984, 200}
  },
  { {5000, -5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000}, 
    {5000, -5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000}, 
    {5000, -5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000}, 
    {5000, -5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000}, 
    {5000, -5000, -5000, -5000, -5000, -5000, -5000, -3000, -3000}
  } 
};
*/


Double_t pol1(double *x,double *par){ 
  return (*x*par[1] + par[0]);
}

double interpolate( const std::vector<double> &xData, const std::vector<double> &yData, double x, bool extrapolate ) {
  int size = xData.size();
  int i = 0;                                          // find left end of interval for interpolation
  if ( x >= xData[size - 2] )                         // special case: beyond right end
    {
      i = size - 2;
    }
  else
    {
      while ( x > xData[i+1] ) i++;
    }
  double xL = xData[i], yL = yData[i], xR = xData[i+1], yR = yData[i+1]; // points on either side (unless beyond ends)
  if ( !extrapolate )                                                    // if beyond ends of array and not extrapolating
    {
      if ( x < xL ) yR = yL;
      if ( x > xR ) yL = yR;
    }
  double dydx = ( yR - yL ) / ( xR - xL );            // gradient
  return yL + dydx * ( x - xL );                      // linear interpolation
}

TGraphErrors *Profile_to_Graph(TProfile *px, TProfile *py, int j) {

  TAxis *xaxis = py->GetXaxis(); 
  Int_t nbins = xaxis->GetNbins(); 
  vector<double> vx, vy, vex, vey;
  for (Int_t bin=0; bin <= nbins; bin++) {    
    double x_value = px->GetBinContent(bin);
    double y_value = py->GetBinContent(bin);
    double x_error = px->GetBinError(bin);
    double y_error = py->GetBinError(bin);

    if(y_value == 0) continue;
    vx.push_back(x_value);
    vy.push_back(y_value);
    vex.push_back(x_error);
    vey.push_back(y_error);
  }

  TGraphErrors *gr = new TGraphErrors(vx.size(), &vx[0], &vy[0], 0, &vey[0]);
  return gr;
  
}

///////////////////////////////////////////////////
Double_t GaisserHillas(double *x,double *par)
{
  //This is the Gaisser-Hillas function
  Double_t X_mu_0=par[3];
  Double_t Normalization=par[0];
  Double_t Diff=par[1]-X_mu_0;
  Double_t Term=pow((*x-X_mu_0)/Diff,Diff/par[2]);
  Double_t Exponential=TMath::Exp((par[1]-*x)/par[2]);
  
  return ( Normalization*Term*Exponential);
}

//Distance to the center in the Y-Z Plane
double GetDistanceCenter(const double center[2], double z, double y){
  //z = abs(z - center[1]) - center[1];
  //y = abs(y) - center[0];
  z -= center[1];
  y -= center[0];
  
  return  sqrt(y*y + z*z);
}  

// solid angle of rectanglular aperture
// structure definition for solid angle of rectangle function
struct acc{
  // ax,ay,az = centre of rectangle; w = width; h = height
  double ax, ay, az, w, h;
};

double Rectangle_SolidAngle(double a, double b, double d){
  
  double aa = a/(2.0*d);
  double bb = b/(2.0*d);
  double aux = (1+aa*aa+bb*bb)/((1.+aa*aa)*(1.+bb*bb));
  return 4*std::acos(std::sqrt(aux));
  
}

double Rectangle_SolidAngle(acc& out, TVector3 v){
  
  //v is the position of the track segment with respect to
  //the center position of the arapuca window
  
  // arapuca plane fixed in x direction
  
  if( v.Y()==0.0 && v.Z()==0.0){
    return Rectangle_SolidAngle(out.w,out.h,v.X());
  }
  
  if( (std::abs(v.Y()) > out.w/2.0) && (std::abs(v.Z()) > out.h/2.0)){
    double A, B, a, b, d;
    A = std::abs(v.Y())-out.w/2.0;
    B = std::abs(v.Z())-out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.X());
    double to_return = (Rectangle_SolidAngle(2*(A+a),2*(B+b),d)-Rectangle_SolidAngle(2*A,2*(B+b),d)-Rectangle_SolidAngle(2*(A+a),2*B,d)+Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  
  if( (std::abs(v.Y()) <= out.w/2.0) && (std::abs(v.Z()) <= out.h/2.0)){
    double A, B, a, b, d;
    A = -std::abs(v.Y())+out.w/2.0;
    B = -std::abs(v.Z())+out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.X());
    double to_return = (Rectangle_SolidAngle(2*(a-A),2*(b-B),d)+Rectangle_SolidAngle(2*A,2*(b-B),d)+Rectangle_SolidAngle(2*(a-A),2*B,d)+Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  
  if( (std::abs(v.Y()) > out.w/2.0) && (std::abs(v.Z()) <= out.h/2.0)){
    double A, B, a, b, d;
    A = std::abs(v.Y())-out.w/2.0;
    B = -std::abs(v.Z())+out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.X());
    double to_return = (Rectangle_SolidAngle(2*(A+a),2*(b-B),d)-Rectangle_SolidAngle(2*A,2*(b-B),d)+Rectangle_SolidAngle(2*(A+a),2*B,d)-Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  
  if( (std::abs(v.Y()) <= out.w/2.0) && (std::abs(v.Z()) > out.h/2.0)){
    double A, B, a, b, d;
    A = -std::abs(v.Y())+out.w/2.0;
    B = std::abs(v.Z())-out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.X());
    double to_return = (Rectangle_SolidAngle(2*(a-A),2*(B+b),d)-Rectangle_SolidAngle(2*(a-A),2*B,d)+Rectangle_SolidAngle(2*A,2*(B+b),d)-Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  // error message if none of these cases, i.e. something has gone wrong!
  std::cout << "Warning: invalid solid angle call." << std::endl;
  return 0.0;
}

double Rectangle_SolidAngle_lateral(acc& out, TVector3 v){
  
  //v is the position of the track segment with respect to
  //the center position of the arapuca window
  
  // arapuca plane fixed in y direction
  
  if( v.X()==0.0 && v.Z()==0.0){
    return Rectangle_SolidAngle(out.w,out.h,v.Y());
  }
  
  if( (std::abs(v.X()) > out.w/2.0) && (std::abs(v.Z()) > out.h/2.0)){
    double A, B, a, b, d;
    A = std::abs(v.X())-out.w/2.0;
    B = std::abs(v.Z())-out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.Y());
    double to_return = (Rectangle_SolidAngle(2*(A+a),2*(B+b),d)-Rectangle_SolidAngle(2*A,2*(B+b),d)-Rectangle_SolidAngle(2*(A+a),2*B,d)+Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  
  if( (std::abs(v.X()) <= out.w/2.0) && (std::abs(v.Z()) <= out.h/2.0)){
    double A, B, a, b, d;
    A = -std::abs(v.X())+out.w/2.0;
    B = -std::abs(v.Z())+out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.Y());
    double to_return = (Rectangle_SolidAngle(2*(a-A),2*(b-B),d)+Rectangle_SolidAngle(2*A,2*(b-B),d)+Rectangle_SolidAngle(2*(a-A),2*B,d)+Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  
  if( (std::abs(v.X()) > out.w/2.0) && (std::abs(v.Z()) <= out.h/2.0)){
    double A, B, a, b, d;
    A = std::abs(v.X())-out.w/2.0;
    B = -std::abs(v.Z())+out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.Y());
    double to_return = (Rectangle_SolidAngle(2*(A+a),2*(b-B),d)-Rectangle_SolidAngle(2*A,2*(b-B),d)+Rectangle_SolidAngle(2*(A+a),2*B,d)-Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  
  if( (std::abs(v.X()) <= out.w/2.0) && (std::abs(v.Z()) > out.h/2.0)){
    double A, B, a, b, d;
    A = -std::abs(v.X())+out.w/2.0;
    B = std::abs(v.Z())-out.h/2.0;
    a = out.w;
    b = out.h;
    d = std::abs(v.Y());
    double to_return = (Rectangle_SolidAngle(2*(a-A),2*(B+b),d)-Rectangle_SolidAngle(2*(a-A),2*B,d)+Rectangle_SolidAngle(2*A,2*(B+b),d)-Rectangle_SolidAngle(2*A,2*B,d))/4.0;
    return to_return;
  }
  // error message if none of these cases, i.e. something has gone wrong!
  std::cout << "Warning: invalid solid angle call." << std::endl;
  return 0.0;
}


// visible number of hits calculation function
// does not apply any correction
// Visible hits calculation
double VisHits(const int &Nphotons_created, const TVector3 &ScintPoint, const TVector3 &OpDetPoint, const bool isLat) {
 
  // 1). calculate total number of hits of VUV photons on reflective foils via solid angle + Gaisser-Hillas corrections:

  // set cathode plane struct for solid angle function
  acc cathode_plane; 
  cathode_plane.ax = x_foils; cathode_plane.ay = y_foils; cathode_plane.az = z_foils;       // centre coordinates of cathode plane
  cathode_plane.w = y_dimension_foils; cathode_plane.h = z_dimension_foils;                     // width and height in cm

  // get scintpoint coords relative to centre of cathode plane
  TVector3 cathodeCentrePoint(x_foils,y_foils,z_foils);
  TVector3 ScintPoint_relative = ScintPoint - cathodeCentrePoint; 

  // calculate solid angle of cathode from the scintillation point
  double solid_angle_cathode = Rectangle_SolidAngle(cathode_plane, ScintPoint_relative);

  // calculate distance and angle between ScintPoint and hotspot
  // vast majority of hits in hotspot region directly infront of scintpoint,therefore consider attenuation for this distance and on axis GH instead of for the centre coordinate
  double distance_cathode = std::abs(x_foils - ScintPoint[0]); 

  double cosine_cathode = 1;
  double theta_cathode = 0.0;

  // calculate hits on cathode plane via geometric acceptance
  double cathode_hits_geo = exp(-1.*distance_cathode/L_abs) * (solid_angle_cathode / (4.*pi)) * Nphotons_created;

  // apply Gaisser-Hillas correction for Rayleigh scattering distance and angular dependence
  // offset angle bin
  int j = (theta_cathode/10);  
  // correction
  double pars_ini[4] = {fGHVUVPars[0][j], fGHVUVPars[1][j], fGHVUVPars[2][j], fGHVUVPars[3][j]};
  
  // gh border
  double r_distance = sqrt( pow(ScintPoint[1] - y_foils, 2) + pow(ScintPoint[2] - z_foils, 2)); 
  
  double s1 = interpolate( angulo, slopes1, theta_cathode, true);
  double s2 = interpolate( angulo, slopes2, theta_cathode, true);
  double s3 = interpolate( angulo, slopes3, theta_cathode, true);

  pars_ini[0] = pars_ini[0] + s1 * r_distance;
  pars_ini[1] = pars_ini[1] + s2 * r_distance;
  pars_ini[2] = pars_ini[2] + s3 * r_distance;
  pars_ini[3] = pars_ini[3];

  double GH_correction = GaisserHillas(&distance_cathode, pars_ini);

  double cathode_hits_rec = GH_correction*cathode_hits_geo/cosine_cathode;


  // 2). calculate number of these hits which reach the optical channel from the hotspot via solid angle 
  
  // calculate hotspot location  
  TVector3 v_to_wall(x_foils - ScintPoint[0],0,0);        
  TVector3 hotspot = ScintPoint + v_to_wall;

  // solid angle :
  double solid_angle_detector = 0;
  // rectangular aperture

  // set Arapuca geometry struct for solid angle function
  acc detPoint; 
  detPoint.ax = OpDetPoint[0]; detPoint.ay = OpDetPoint[1]; detPoint.az = OpDetPoint[2];  // centre coordinates of optical detector
  detPoint.w = arapuca_w; detPoint.h = arapuca_h; // width and height in cm of arapuca active window

  // get hotspot coordinates relative to detpoint
  TVector3 emission_relative = hotspot - OpDetPoint;

  // calculate solid angle of optical channel
  if (isLat){
    solid_angle_detector = Rectangle_SolidAngle_lateral(detPoint, emission_relative);

  }
  else {
    solid_angle_detector = Rectangle_SolidAngle(detPoint, emission_relative);

  }

  // calculate number of hits via geometeric acceptance  
  double hits_geo = (solid_angle_detector / (2*pi)) * cathode_hits_rec;

  // distance to hotspot
  double distance_vuv = sqrt(pow(ScintPoint[0] - hotspot[0],2) + pow(ScintPoint[1] - hotspot[1],2) + pow(ScintPoint[2] - hotspot[2],2));
  // distance from hotspot to arapuca
  double distance_vis = sqrt(pow(hotspot[0] - OpDetPoint[0],2) + pow(hotspot[1] - OpDetPoint[1],2) + pow(hotspot[2] - OpDetPoint[2],2));
  // angle between hotspot and arapuca
  double cosine_vis = sqrt(pow(hotspot[0] - OpDetPoint[0],2)) / distance_vis;
  double theta_vis = acos(cosine_vis)*180./pi;

  // apply correction curves, interpolation
  //int k = (theta_vis/delta_angulo);
  //double x_position_corr = ScintPoint[0];
  //double corr = interpolate(fVIS_XPos, fVIS_Pars[k], x_position_corr, false);

  //double hits_rec = corr*hits_geo/cosine_vis;
  double hits_rec = hits_geo;

  /*
  // apply border correction
  // calculate radial distance from centre
  double r_distance = sqrt( pow(ScintPoint[1] - y_foils, 2) + pow(ScintPoint[2] - z_foils, 2)); 
  // interpolate in x for each r bin
  std::vector<double> interp_vals = {0,0,0,0};
  for (int i = 0; i < 4; i++){
    interp_vals[i] = interpolate(vDistances_x, VIS_RS60_SP_Borders[k][i], std::abs(ScintPoint[0]), false);
  }
  // interpolate in r
  double border_correction = interpolate(vDistances_r, interp_vals, r_distance, false);
  // apply correction
  double hits_rec_borders = border_correction * hits_rec / cosine_vis;
  */

  // round final result
  double hits_vis = hits_rec;

  return hits_vis;
}

void calcula(string positions, string input_file, vector<double> &v1, vector<double> &v2,
	     vector<double> &v3, vector<double> &v4, vector<double> &v5, bool IsRectangular,
	     bool IsSphere) {
  cout<<"calcula function ..."<<endl;

  double min_number_entries = 2500;
  // width and height in cm of arapuca active window	
  double arapuca_w = 60;
  double arapuca_h = 60;
 
  // Y-Z coordinates of the active volume center
  const double centerYZ[2] = {0., 1000.};
  const double centerXZ[2] = {0., 1000.};  // laterals

  
  gRandom->SetSeed(0);

  //getting the pmt positions (y and z)
  ifstream Traks_file1(positions.c_str());
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


  cout<<"-------------------------------------------------------"<<endl;
  cout<<"-------------------------------------------------------"<<endl;
  cout<<"-------------------------------------------------------"<<endl;
  cout<<"Input File: "<<input_file<<endl;
  cout<<"-------------------------------------------------------"<<endl;
  cout<<"-------------------------------------------------------"<<endl;
  cout<<"-------------------------------------------------------"<<endl;
    
  
  vector<double> v_hits, v_distance, v_rec_hits, v_offset_angle, v_d_center;
  //loop over files
  TFile* f = new TFile(input_file.c_str());
  TTree *tree = (TTree *)f->Get("myTree");
  const Int_t kMaxDevices = 600;
  int VUV_hits[kMaxDevices];
  int Vis_hits[kMaxDevices];
  double X, Y, Z;
  int genPhotons, numberDevices;
  tree->SetBranchAddress("numberDevices",&numberDevices);
  tree->SetBranchAddress("X", &X);
  tree->SetBranchAddress("Y", &Y);
  tree->SetBranchAddress("Z", &Z);
  tree->SetBranchAddress("VUV_hits",VUV_hits);
  tree->SetBranchAddress("Vis_hits",Vis_hits);
  tree->SetBranchAddress("genPhotons", &genPhotons);
  
  for(int n=0; n!=tree->GetEntries(); ++n){
    tree->GetEntry(n);

    //cout << X << ", " << Y << ", " << Z << endl;
    
    double posSource[3]={X, Y, Z};
    double num_phot_generated = genPhotons;
    double distance_to_center = GetDistanceCenter(centerYZ, posSource[2], posSource[1]);
    double distance_to_center_lateral = GetDistanceCenter(centerXZ, posSource[2], posSource[0]); 

    
    if(distance_to_center<=0) {
    	cout << "Warning: distance to center < 0" << endl;
    	continue;
    }
    
    //loop over the channels
    for(int i=0; i<numberDevices; i++) {
      // Required User to modify: 
      if (devy.at(i) < 730) continue;    // remove cathode and far laterals
      if ( abs(posSource[1] - devy.at(i)) < 57)  continue;// remove the scintillation points outside the field cage. 
      //if (abs(devy.at(i)) > 730) continue; // remove laterals 
      
      int op_channel_orientation = -1;
      if (abs(devy.at(i)) > 730) op_channel_orientation = 1; // lateral.
      else op_channel_orientation = 0; // cathode

    	int entries = VUV_hits[i];
    	if(entries < min_number_entries) continue;
    	
    	double distance_to_pmt = sqrt(pow(posSource[0] - devx.at(i),2) +
                      				      pow(posSource[1] - devy.at(i),2) +
                      				      pow(posSource[2] - devz.at(i),2));

    	// calculate theta
    	double theta = -1;
      double coseno;
    	if (op_channel_orientation == 1) {
  	  	// laterals
  	  	coseno = sqrt(pow(posSource[1] - devy.at(i),2))/distance_to_pmt;
  		  theta = acos(coseno)*180/3.1416;
    	}else if(op_channel_orientation == 0){
    		// cathode
    		coseno = sqrt(pow(posSource[0] - devx.at(i),2))/distance_to_pmt;
    		theta = acos(coseno)*180/3.1416;
    	}
    	if(theta >= 90 || theta == -1) {
    		cout << "Warning -- Theta: " << theta << endl;
    		continue;
    	}
    	
    	double geo_factor = -1;
    	if(IsRectangular) {
    	  //------Rectangle---------
    	  acc detPoint;
    	  TVector3 ScintPoint_rel;

    	  // centre coordinates of optical detector
    	  detPoint.ax = devx.at(i); detPoint.ay = devy.at(i); detPoint.az = devz.at(i);
    	  // width and height in cm of arapuca active window	
    	  detPoint.w = arapuca_w; detPoint.h = arapuca_h; 
    	  // get scintillation point coordinates relative to arapuca window centre
    	  TVector3 ScintPoint(posSource[0], posSource[1], posSource[2]);
    	  TVector3 OpDetPoint(devx.at(i), devy.at(i), devz.at(i));
    	  ScintPoint_rel = ScintPoint - OpDetPoint;
    	  	
    	  if (op_channel_orientation == 1) {
    	  	// laterals
    	  	// calculate solid angle
    	  	geo_factor  = Rectangle_SolidAngle_lateral(detPoint, ScintPoint_rel);
    	  }else if (op_channel_orientation == 0) {
    	  	// cathode
    		  // calculate solid angle
    	  	geo_factor  = Rectangle_SolidAngle(detPoint, ScintPoint_rel);  
    	  }  	
       }
       else {
          cout << "Only available for rectangular apperture" << endl;
          exit(1);
       }

    	//pure geometric estimation of the number of arriving VUV photons
    	double rec_N =  exp(-1.*distance_to_pmt/L_abs)*gRandom->Poisson(num_phot_generated*geo_factor/(4*3.1416));

      // determine Gaisser-Hillas correction for Rayleigh scattering distance and angular dependence, accounting for border effects
      // offset angle bin
      int j = (theta/10);
      // distance from center for border corrections
      double r_distance = 0;
      if (op_channel_orientation == 1) {
        r_distance = distance_to_center_lateral;
      }
      else r_distance = distance_to_center;  
      
      // GH parameters
      double pars_ini[4] = {0,0,0,0};
      double s1 = 0; double s2 = 0; double s3 = 0;
      if (op_channel_orientation == 0) { // cathode. 
        // determine initial parameters and border corrections by optical detector type   
          pars_ini[0] = fGHVUVPars[0][j];
          pars_ini[1] = fGHVUVPars[1][j];
          pars_ini[2] = fGHVUVPars[2][j];
          pars_ini[3] = fGHVUVPars[3][j];
          s1 = interpolate( angulo, slopes1, theta, true);
          s2 = interpolate( angulo, slopes2, theta, true);
          s3 = interpolate( angulo, slopes3, theta, true);
      }else if (op_channel_orientation == 1){ //lateral
        // determine initial parameters and border corrections by optical detector type
        // get find appropriate GH parameters with interpolation
        // build arrays for interpolation
        /*vector<double> p1_set;
        vector<double> p2_set;
        vector<double> p3_set;
        vector<double> p4_set;
        for (int i = 0; i < fGH_d_anode.size(); i++) {
          p1_set.push_back(fGHVUVPars_lateral[0][i][j]);
          p2_set.push_back(fGHVUVPars_lateral[1][i][j]);
          p3_set.push_back(fGHVUVPars_lateral[2][i][j]);
          p4_set.push_back(fGHVUVPars_lateral[3][i][j]);
        }
        // interpolate in distance to anode
        pars_ini[0] = interpolate(fGH_d_anode, p1_set, r_distance, false);
        pars_ini[1] = interpolate(fGH_d_anode, p2_set, r_distance, false);
        pars_ini[2] = interpolate(fGH_d_anode, p3_set, r_distance, false);
        pars_ini[3] = interpolate(fGH_d_anode, p4_set, r_distance, false);*/

        pars_ini[0] = fGHVUVPars_lateral[0][j];
        pars_ini[1] = fGHVUVPars_lateral[1][j];
        pars_ini[2] = fGHVUVPars_lateral[2][j];
        pars_ini[3] = fGHVUVPars_lateral[3][j];
        s1 = interpolate( angulo, slopes1_lateral, theta, true);
        s2 = interpolate( angulo, slopes2_lateral, theta, true);
        s3 = interpolate( angulo, slopes3_lateral, theta, true);

      }else  {
        std::cout << "Error: Invalid optical detector orientation." << endl;
        exit(1);
      }
      
      // add border correction
      pars_ini[0] = pars_ini[0] + s1 * r_distance;
      pars_ini[1] = pars_ini[1] + s2 * r_distance;
      pars_ini[2] = pars_ini[2] + s3 * r_distance;
      pars_ini[3] = pars_ini[3];
      
      // calculate correction factor
      double GH_correction = GaisserHillas(&distance_to_pmt, pars_ini);
      
      // apply correction
      double hits_rec =  std::round(GH_correction*rec_N/coseno);


    	//if (entries > 1000)	cout << "OpDet: " << i << ", distance: " << distance_to_pmt << ", theta: " << theta << ", G4: " << entries << ", S-A: " << rec_N << ", geo = " << geo_factor << endl;
      bool isLat; 
      // calculate theta_c
      // calculate hotspot location, anode  
      TVector3 hotspot(x_foils, posSource[1], posSource[2]);
      double distance_c = sqrt(pow(hotspot[0] - devx.at(i),2) + pow(hotspot[1] - devy.at(i),2) + pow(hotspot[2] - devz.at(i),2));
      double pi = 3.1415;
      double theta_c = -1;
      double coseno_c;
      if (abs(devy.at(i)) > 730) {
        // laterals
        coseno_c = sqrt(pow(hotspot[1] - devy.at(i),2)) / distance_c;
        theta_c = acos(coseno_c)*180./pi;
        isLat = true;
      }else {
        // cathode
        coseno_c = sqrt(pow(hotspot[0] - devx.at(i),2)) / distance_c;
        theta_c = acos(coseno_c)*180./pi;
        isLat = false;
      }
      
      if(theta >= 90 || theta == -1) {
        cout << "Warning -- Theta: " << theta << endl;
        continue;
      }


      // implement "visible" light model to account for reflected part
      // solid angle prediction, with reflectivity factor
      TVector3 OpDetPoint(devx.at(i), devy.at(i), devz.at(i));
      double nPhotons_solid_refl = 0.12 * VisHits(num_phot_generated,posSource,OpDetPoint, isLat);

      // total prediction
      double hits_total = hits_rec + nPhotons_solid_refl;
      //double hits_total = nPhotons_solid_refl;
      if ( entries  < 2500) continue;
    	v_hits.push_back(entries);
    	//v_distance.push_back(distance_to_pmt);
      //v_distance.push_back(distance_c);
      v_distance.push_back(std::abs(x_foils - posSource[0])); // swapped to distance to anode
      //v_distance.push_back(x_foils - devx.at(i)); // swapped to distance to anode
    	v_rec_hits.push_back(hits_total);
    	v_offset_angle.push_back(theta_c);

      //v_d_center.push_back(distance_to_center);
       if (abs(devy.at(i)) > 730) {
        // laterals
        v_d_center.push_back(distance_to_center_lateral);
      }else{
        v_d_center.push_back(distance_to_center);
      }
    }// channels
  }//files
  v1 = v_distance;
  v2 = v_hits;
  v3 = v_rec_hits;
  v4 = v_offset_angle;
  v5 = v_d_center;
}

void Semi_Mode_Gen_v2_reflections_full_model() {
 
  // path to the directory where the files are 
  string path_files = "/Users/s2138786/Downloads/Edinburgh/Second_Year/Vertical-Drift-DUNE/dune_light/";
  // path + file containing the LDS id and positions (x, y, z)
  string positions = path_files + "optical_channel_mapping/dune_optical_mapping.txt";
  // path + file containing the Sim-Info
  string file_name = "semi_analytic_hits_vd_cathode_full_refl_xenon";
  // semi_analytic_hits_vd_laterals_full_refl_xenon.root semi_analytic_hits_vd_full_refl_xenon
  string input_file = path_files + "data/" + file_name + ".root";
  string save_dir = "./reflected_plots/";
 
  // If PMTs (IsSphere), if (X-)ARAPUCAS (IsRectangular),
  // acrylic disk in front of the PMTs (both false)
  bool IsRectangular = true;
  bool IsSphere = false;
  //offset- angle theta binning
  const int N = 9;
  double delta_angulo = 90./N;
  vector<double> angulo;

  double theta[N];
  for(int i=0; i<N; i++)
    theta[i] =  delta_angulo/2 + i*delta_angulo;
  
  //Distance range and step for the profile to fit with GH
  double d_min = 0;
  double d_max = 700; //700
  double step_d = 50;
  
  //Center distance bins --- anode distance
  double range_d = 1100;//1100;
  //double delta_d = range_d/M;

  // Modification requried from Users:
  const int M = 7;
  //double range_d_array[M+1] = {0.,200.,400.,600.,800.,900.,1000.,range_d}; // cathode.
  double range_d_array[M+1] = {0.,300.,400.,500.,600.,850.,950.,range_d}; // lateral.

  TH1D* h=new TH1D("","",range_d, 0, range_d*1.05);
  
  TH1D* hd_centers[M];
  TLine* line[M+1];
  for(int k=0; k < M; k++) {
    hd_centers[k] = new TH1D("","",M,range_d_array);
    line[k] = new TLine(range_d_array[k], 0.,range_d_array[k],2000);
  }

  TProfile* pdiff_d[N][M];
  TProfile* pdiff_dx[N][M];
  for(int j=0; j < N; j++) {
    double theta_min = j*delta_angulo;
    double theta_max = theta_min + delta_angulo;
    angulo.push_back(theta_min + delta_angulo/2);
    for(int k=0; k < M; k++) {
      pdiff_d[j][k] = new TProfile("","", int((d_max-d_min)/step_d), d_min, d_max, "s");
      pdiff_dx[j][k] = new TProfile("","", int((d_max-d_min)/step_d), d_min, d_max, "s");
    }
  }

  vector<double> v_distance, v_hits, v_rec_hits, v_offset_angle, v_d_center;
  calcula(positions, input_file, v_distance, v_hits, v_rec_hits, v_offset_angle, v_d_center, IsRectangular, IsSphere);
 
  vector<int> vdummy(9,0);
  vector<vector<int>> nEntries(M, vdummy);
  for(int i=0; i<v_distance.size(); i++) {
    double costheta = cos(3.1416*v_offset_angle.at(i)/180.);
    //which angulat bin
    int j = int(v_offset_angle.at(i)/delta_angulo);
    //which "center/crown" bin
    double temp = v_d_center.at(i);
    int k = std::lower_bound(range_d_array, range_d_array+M+1, temp) - range_d_array - 1;
    if(k>=M) continue;
    
    //if (v_hits.at(i) <= 1000 || v_rec_hits.at(i) <= 1000) continue; // remove statistical fluctuations implying negative photons from the foils, cause chaos; and low stats regions
    //std::cout<< v_distance.at(i) <<endl;
    pdiff_d[j][k]->Fill(v_distance.at(i), v_hits.at(i)/v_rec_hits.at(i)*costheta);
    hd_centers[k]->Fill(v_d_center.at(i));
    h->Fill(v_d_center.at(i));
    pdiff_dx[j][k]->Fill(v_distance.at(i), v_distance.at(i));

    nEntries[k][j]++;
  }  
 
  TCanvas *canvas0 = new TCanvas("canvas0", "graph draw options",200,200,500,400);
  h->SetTitle("Help to choose the \"border-study\" distance bins");
  h->GetXaxis()->SetTitle("distance to centre in Y-Z plane [cm]");
  h->SetStats(0);
  h->Draw("hist");
  line[M] = new TLine(range_d, 0.,range_d,2000);
  for(int k=0; k < M+1; k++) {
    line[k]->SetLineColor(2);
    line[k]->SetLineWidth(3);
    line[k]->SetLineStyle(kDashed);
    line[k]->Draw("same");
  }
  canvas0->Update();
  canvas0->Modified();

  TString fig_name = save_dir + file_name+"_crown_plot.pdf";
  canvas0->SaveAs(fig_name);
  //canvas0->WaitPrimitive();

  //Estimate range to fit in distance
  double max_x[N][M], min_x[N][M], n_entries[N][M];
  for(int j=0; j < N; j++) {
    for(int k=0; k < M; k++) {
      n_entries[j][k] = 0;
      TAxis *xaxis  =  pdiff_d[j][k]->GetXaxis(); 
      Int_t nbins  = xaxis->GetNbins(); 
      double min = d_max;
      double max = 0;
      for (Int_t bin=0;bin<=nbins;bin++) {
        n_entries[j][k] += pdiff_d[j][k]->GetBinContent(bin);
  
        if(pdiff_d[j][k]->GetBinContent(bin) == 0) continue; 
        if(min > xaxis->GetBinCenter(bin))
          min = xaxis->GetBinCenter(bin);
        if(max < xaxis->GetBinCenter(bin))
          max = xaxis->GetBinCenter(bin); 
      }
      max_x[j][k] = max;
      min_x[j][k] = min;
    }
  }
    
  vector<int> N_canvas;
  vector<double> d_center;
  string title[M];
  for(int k=0; k < M; k++) {
    for(int j=0; j < N; j++) 
      if(n_entries[j][k]>0) {
	N_canvas.push_back(k);
	break;
      }
    if(hd_centers[k]->GetEntries()>0) {
      d_center.push_back(hd_centers[k]->GetMean());
      title[k] =  "Distance to centre " +  to_string(int(hd_centers[k]->GetMean())) + "cm";
    }
  }

  // Making plots and fits ...
  const int dim = N_canvas.size();
  TGraphErrors *gr[N][M];
  TGraphErrors *grx[N][M];
  for(int k=0; k < M; k++) {
    for(int j=0; j < N; j++) {    
      if(n_entries[j][k] > 0) {
      	gr[j][k] = Profile_to_Graph(pdiff_dx[j][k], pdiff_d[j][k], j);
      	gr[j][k]->SetLineColor(1 + j%9);
      	gr[j][k]->SetMarkerColor(1 + j%9);
      	if(j==4) {gr[j][k]->SetLineColor(kOrange+7);gr[j][k]->SetMarkerColor(kOrange+7);}
      	gr[j][k]->SetMarkerStyle(20 + j);
      	//gr[j][k]->SetMarkerSize(0.6);
      }
    }
  }
  const int dimension = ceil(double(N_canvas.size())/2.);
  TCanvas *canvas1 = new TCanvas("canvas1", "graph draw options",200,200,dimension*420,800);
  if(N_canvas.size() > 1) {
    double nn = double(N_canvas.size())/2.;
    canvas1->Divide(ceil(nn),2);
  }
  double x_0[2] = {0, d_max};
  double y_0[2] = {0, 2.};
  TGraph* gg0[dim];
  vector<double> p1[dim], p2[dim], p3[dim], p4[dim], ep1[dim], ep2[dim], ep3[dim];
  TLegend *leg1=new TLegend(0.6, 0.7, 0.89, 0.89, NULL,"brNDC");
  leg1->SetHeader("");
  leg1->SetBorderSize(0);
  char label[N][25];
  for(int l=0; l < dim; l++) {
    int k = N_canvas.at(l);
    canvas1->cd(1 + l);
    gPad->SetGrid();
    gg0[l] = new TGraph(2,x_0,y_0);
    gg0[l]->SetTitle(title[k].c_str());
    gg0[l]->GetYaxis()->SetTitleSize(0.05);
    gg0[l]->GetYaxis()->SetTitleOffset(1.);
    gg0[l]->GetXaxis()->SetTitleSize(0.05);
    gg0[l]->GetXaxis()->SetTitleOffset(1.);
    gg0[l]->GetXaxis()->SetRangeUser(0,d_max);
    gg0[l]->GetYaxis()->SetRangeUser(0, 2.0);
    gg0[l]->GetXaxis()->SetTitle("d_{A} [cm]");
    gg0[l]->GetYaxis()->SetTitle("N_{hit} / N_{#Omega} / cos(#theta_{A})");
    gg0[l]->Draw("ap");   
  
    
    for(int j=0; j < N; j++) {
      if(n_entries[j][k]>0) {
	      gr[j][k]->Draw("p");
        if(l==0) {
      	int a_min = j*delta_angulo;
      	int a_max = (j+1)*delta_angulo;
      	sprintf(label[j],"#theta_{A} #in [%i, %i] deg",a_min, a_max);
      	leg1->AddEntry(gr[j][k],label[j],"p");
        }      
      }
      if(l==0)  leg1->Draw();
    }
    canvas1->Update();
    canvas1->Modified();

    TString fig_name2 = save_dir + file_name+"_GH.pdf";
    canvas1->SaveAs(fig_name2);
    //canvas1->WaitPrimitive();
  }

  // extract parameters from profiles and output
  vector<vector<double>> pars;
  vector<vector<double>> pars_errs;
  vector<double> x_positions;
  for (int r = 0; r < M; r++) {

    pars.clear();
    pars_errs.clear();
    x_positions.clear();

    for(int loop = 0; loop < N; loop++) { 
      if (nEntries[r][loop] == 0){
        // skip empty angle bins, not all large angles exist due to geometry
        // parameters set to parameter for previous bin
        pars.push_back(pars[loop-1]);
        continue;
      }

      vector<double> pars_loop;
      vector<double> pars_errs_loop;
      int n_bins = (d_max-d_min)/step_d;

      for (int i = 0; i < n_bins; i++){
        // skip empty bins
        if(!(pdiff_d[loop][r]->GetBinEntries(i) > 0)) continue;
        // save parameters
        pars_loop.push_back(pdiff_d[loop][r]->GetBinContent(i));
        pars_errs_loop.push_back(pdiff_d[loop][r]->GetBinError(i));
        // save x positions on first loop
        if (loop == 2) {
          x_positions.push_back((i-1) * step_d + step_d/2);
        }       
      }
      pars.push_back(pars_loop);
      pars_errs.push_back(pars_errs_loop);
    }  

    cout << "X values = ";
    for (int i = 0; i < x_positions.size(); i++) {
      if (i == x_positions.size() - 1){
        cout << x_positions[i] << endl;
      }
      else cout << x_positions[i] << ", ";
    }


    cout << "Correction Parameters: " << endl;
    for (int angle_bin = 0; angle_bin < pars.size(); angle_bin++){
      for (int x_bin = 0; x_bin < pars[2].size(); x_bin++){
        if (x_bin == pars[2].size() - 1){
          cout << pars[angle_bin][x_bin] << endl;
        }
        else {
          cout << pars[angle_bin][x_bin] << ", ";
        }
      }
    }
    /*
    cout << "Correction Parameters Uncertainties: " << endl;
    for (int angle_bin = 0; angle_bin < pars_errs.size(); angle_bin++){
      for (int x_bin = 0; x_bin < pars_errs[0].size(); x_bin++){
        if (x_bin == pars_errs[0].size() - 1){
          cout << pars_errs[angle_bin][x_bin] << endl;
        }
        else cout << pars_errs[angle_bin][x_bin] << ", ";
      }
    }
    */  
  }  
}
