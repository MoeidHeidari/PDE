#include "../include/PDE.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

int main(int argc, char *argv[])
{
  /*@brief instantiation of X and T boundry structs
  */
   _PDE::PDE_boundry x_boundry;
   _PDE::PDE_boundry t_boundry;
  /* @brief here the initialization of the X and T boudries happen
  through the command line input
  first argument: x_right
  second argument: x_left
  third argument: t_right
  forth argument: t_right
  */
  x_boundry.right=1;
  x_boundry.left=0;
  t_boundry.right=1;
  t_boundry.left=0;
  std::vector<double> x_values;
  unsigned t_value=1;
  for(double i=0.01;;i+=0.01)
  {
    if(i<=x_boundry.left || i>=x_boundry.right)
    break;

    x_values.push_back(i);
  }
  //===============================================================
  _PDE::PDE_Solver pde(x_values,t_value,x_boundry,t_boundry);
  for (auto &x : pde.get_X_value()) // Access by reference to avoid copying
{

  double tmp=pde.u_n_t(t_value,2,x) * std::sin(PDE_PI*2*x)+pde.u_n_t(t_value,2,x) * std::sin(PDE_PI*2*x);
  std::cout<<tmp<<std::endl;

  //Final result for current x is:
}



  return 0;
}
