/*
        Chemical Kinetics and Dynamics Library
        Copyright (C) 2008-2013, Yuri Georgievski <ygeorgi@anl.gov>

        This library is free software; you can redistribute it and/or
        modify it under the terms of the GNU Library General Public
        License as published by the Free Software Foundation; either
        version 2 of the License, or (at your option) any later version.

        This library is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
        Library General Public License for more details.
*/

#ifndef POLYNOM_HH
#define POLYNOM_HH

#include <vector>
#include <set>
#include <iostream>
#include <cstdlib>

/************************************************************************************************
 *********************** POTENTIAL POLYNOMIAL EXPANSION INFRASTRUCTURE **************************
 ************************************************************************************************/

namespace Polynom {

/************************************************************************************************
 ***************************************** SYMMETRIC POLYNOMIAL *********************************
 ************************************************************************************************/

  class SymPol {

    bool _init;
    void _isinit () const ;

    int _dim;
    int _term_order_max;
    int _poly_order_max;

    int _term_val_map_size;
    std::vector<int>  _term_new_map;
    std::vector<int>  _term_pow_map;
    std::vector<int>  _term_max_map;

    std::vector<int>                _one_poly_map; // one-dimensional linear index to polynomial index map
    std::vector<std::vector<int> > _poly_term_map; // indices of single terms contributing to polinomial
    std::vector<int>               _poly_factor;   // polynomial symmetry factor

  public:
    SymPol () : _init(false) {}

    int      dimension () const { _isinit(); return            _dim; }
    int term_order_max () const { _isinit(); return _term_order_max; }
    int poly_order_max () const { _isinit(); return _poly_order_max; }

    void init(int dim, int term_order_max, int pol_order_max) ;

    void update_map (const std::vector<double>&, std::vector<double>&) const ;

    double operator() (const std::multiset<int>&, const std::vector<double>& ) const ;      

  }; // SymPol (symmetric polynomial)

}

#endif
