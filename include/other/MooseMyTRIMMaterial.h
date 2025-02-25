/**********************************************************************/
/*                     DO NOT MODIFY THIS HEADER                      */
/* MAGPIE - Mesoscale Atomistic Glue Program for Integrated Execution */
/*                                                                    */
/*            Copyright 2017 Battelle Energy Alliance, LLC            */
/*                        ALL RIGHTS RESERVED                         */
/**********************************************************************/

#pragma once

#include "mytrim/material.h"
#include "mytrim/element.h"

/**
 * MyTRIM material class that stores element indices as tags
 */
class MooseMyTRIMMaterial : public MyTRIM_NS::MaterialBase
{
public:
  MooseMyTRIMMaterial(MyTRIM_NS::SimconfType * simconf);

  virtual const MyTRIM_NS::Element & getElement(unsigned int nn);

  /**
   * Calculate the density rho by multiplying the fractions t with the atomic weight
   * and dividing by the site volume.
   * This needs to be called before prepare, as prepare renormalizes the fractions
   * to sum up to one. However we are assuming the fraction difference to one to be
   * the fraction of unoccupied sites.
   */
  virtual void calculateDensity(Real site_volume);
};
