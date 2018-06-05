#include "pluie_gammatons.hpp"

pluie_gammatons::pluie_gammatons(int nb_rayons){
  float ks = 0.0;
  float kp = 0.0;
  float kf = 0.0;
  /*
  cout << "Choisir les motion probabilities des gammatons (straight, parabolic, flow) " << endl;
  cout << "La somme doit etre inferieure a 1  et differents" << endl;
  do{
    cout << "Saisir de nouveau" << endl;
    cout << " probabilité straight = " << endl;
    cin >> ks;
    cout << " probabilité parabolic = " << endl;
    cin >> kp;
    cout << " probabilité flow = " << endl;
    cin >> kf;
  }
  while((((ks + kp + kf) > 1) || (ks == kp) || (ks == kf) || (kp == kf)));
  */
  float sh = 0.0;
  float sd = 0.0;
  float sf = 0.0;

  Cvector v(-0.50, -0.5, 0.0);
  
  for(int i = 0; i < nb_rayons; i++){
    Cpoint p((13*(float) rand() / RAND_MAX)-2, 6, 15*((float) rand() / RAND_MAX)-9);
    
    CRay r(ks, kp, kf, sh, sd, sf, p, v, i);
    list_gam.push_back(r);
  }
}

int pluie_gammatons::getSizeListGam(){
  return list_gam.size();
}

CRay pluie_gammatons::getListInd(int i){
  return list_gam[i];
}
