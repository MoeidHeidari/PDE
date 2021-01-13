/*
The MIT License (MIT)

Copyright (c) 2021 Moeidheidari(Skheydari@stud.etu.ru) and Omar Mohammed(Omokhammed@stud.etu.ru)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*! \file main main.cpp
 *
 *  this class the entry pint of the project containing main function
 */
#include "../include/PDE.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

int main(int argc, char *argv[])
{
  /*instantiation of X and T boundry structs
  */
   _PDE::PDE_boundry x_boundry;
   _PDE::PDE_boundry t_boundry;
  /* \brief here the initialization of the X and T boudries happen
  through the command line input
  \param x_right
  \param x_left
  \param t_right
  \param t_left
  */
  x_boundry.right=1;
  x_boundry.left=0;
  t_boundry.right=1;
  t_boundry.left=0;
  std::vector<double> x_values;
  unsigned t_value=1;
  /* \brief main for loop of the calculation (supports vector of x values)
  */
  for(double i=0.001;;i+=0.001)
  {
    if(i<=x_boundry.left || i>=x_boundry.right)
    break;

    x_values.push_back(i);
  }
//===============================================================================
  _PDE::PDE_Solver pde(x_values,t_value,x_boundry,t_boundry);
  for (auto &x : pde.get_X_value()) // Access by reference to avoid copying
  {
    double tmp=pde.u_n_t(t_value,2,x) * std::sin(PDE_PI*2*x)+pde.u_n_t(t_value,3,x) * std::sin(PDE_PI*2*x);
    std::cout<<x<<":->>>>"<<tmp<<std::endl;
  }



  return 0;
}
