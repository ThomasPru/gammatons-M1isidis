#ifndef PLUIE_GAMMATONS_HPP
#define PLUIE_GAMMATONS_HPP_

#include "Obj/CRay.hpp"
#include <vector>

using namespace std;

class pluie_gammatons{
public:  
  pluie_gammatons(int nb_rayons);
  int getSizeListGam();
  CRay getListInd(int i);
  vector<CRay> list_gam;
};

#endif
