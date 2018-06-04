#ifndef PLUIE_GAMMATONS_HPP
#define PLUIE_GAMMATONS_HPP_

#include "Obj/CRay.hpp"
#include <vector>

class pluie_gammatons{
private:
  vector<CRay> list_gam;
public:  
  pluie_gammatons(int nb_rayons);
  int getSizeListGam();
  CRay getListInd(int i);
};

#endif
