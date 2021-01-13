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
#ifndef PDE
#define PDE
/*! \class PDE_Solverclass PDE.h PDE.h
 *
 *  This object takes the responsibility to solve the Nonhomogeneous PDE - Heat equation problem
 */

 /************************************************
 *  here is the list of all libraries has been used in PDE
 ***********************************************/
#include <vector>
#include <iostream>
#include <cmath>
//==============================================================================
/*! \def
 *
 *  PDE_PI is an alternative for PI value (M_PI)
 */
#ifndef PDE_PI
#define PDE_PI 3.1415926535897932384626433832795 // PI value
#endif
//==============================================================================
/*! \def
 *
 *  PDE_EXPO is an alternative for Exponential value
 */
#ifndef PDE_EXPO
#define PDE_EXPO 2.71828
#endif
//==============================================================================
/*! \namespace _PDE
 *
 *  This is the general namespace of current project which holds all the macros,classes,structs,... etc.
 */
namespace _PDE
{
  /*! \struct PDE_boundry
   *
   *  this structure
   */
   
  struct PDE_boundry
  {
    double left;
    double right;
  };

class PDE_Solver
{
  public:
PDE_Solver()
{
}
    /*
    @brief constructure of the class to initialize the class properties_destroyed
    @param one : the initial value for x
    @param two: the initial value for T
    @param three: definition of the boundries of the given x values
    @param four: definition of the boundries of the given T values
    */
PDE_Solver(std::vector<double> pde_x,double pde_t,
        PDE_boundry pde_x_boundry, PDE_boundry pde_t_boundry)
{
  this->x=pde_x;
  this->t=pde_t;
  this->x_boundries=pde_x_boundry;
  this->t_boundries=pde_t_boundry;
}
const PDE_boundry& get_X_boundries() const
{
  return this->x_boundries;
}
const PDE_boundry& get_T_boundries() const
{
  return this->t_boundries;
}
void set_X_boundries( PDE_boundry boundry)
{
  this->x_boundries=boundry;
}
void set_T_boundries( PDE_boundry boundry)
{
  this->t_boundries=boundry;
}
void set_X_values(std::vector<double> x_vector)
{
  this->x=x_vector;
}
const double& get_T_value()
{
  return this->t;
}

std::vector<double> get_X_value()
{
  return this->x;
}
void set_T_values(double t_value)
{
  this->t=t_value;
};
/*Calculate the integral X= a + (i + 0.5) * step*/
double integral(double(*f)(double x_val), double(*g)(double x_val), double a, double b, int n)
{
    double step = (b - a)/n;   // width of rectangle
    double area = 0.0;
    double y = 0;  // height of rectangle
    for(int i = 0; i < n; ++i)
    {

        y = f(a + (i + 0.5) * step) * g((a + (i + 0.5) * step)*PDE_PI*n);

        area += y * step;  // find the area of the rectangle and add it to the previous area. Effectively summing up the area under the curve.

    }


    return area;
}
double integralt(double(*f)(double t,int n,double x_val), double a, double b, int n,double x_val)
{
    double step = (b - a)/n;   // width of rectangle
    double area = 0.0;
    double y = 0;  // height of rectangle

    for(int i = 0; i < n; ++i)
    {

        y = f(q_n_t(a + (i + 0.5)* step,n,x_val),n,x_val);

        area += y * step;  // find the area of the rectangle and add it to the previous area. Effectively summing up the area under the curve.

    }


    return area;
}
/*f(x,t)*/
static double f_x_t(double x_val)
{

  return 1/(1+x_val);
}
/*p_o_x*/
static double p_o_x(double x_val)
{

  return std::pow(PDE_EXPO,-x_val);
}
/*eigenfunction*/
static double eigenfunction(double x_val,double n)
{
  return std::sin(x_val*n*PDE_PI);
}
/*q_n(t) function*/
double q_n_t(double t,int n,double x_val)
{
  return 2*(integral(f_x_t,std::sin,0,1,n));
}

double u_n_0(double t,int n,double x_val)
{
  return 2*(integral(p_o_x,std::sin,0,1,n));
}
 static double q_n_t_prime(double t,int n,double x_val)
{
  return t*std::pow(PDE_EXPO,std::pow(n,2)*std::pow(PDE_EXPO,2)*t);
}
 double u_n_t(double t,int n,double x_val)
{
  return u_n_0(t,n,x_val)* std::pow(PDE_EXPO,std::pow(-n,2)*std::pow(PDE_EXPO,2)*t)+
  std::pow(PDE_EXPO,std::pow(-n,2)*std::pow(PDE_EXPO,2)*t)*integralt(q_n_t_prime,0,t,n,x_val);
}

  private:
         PDE_boundry x_boundries;
         PDE_boundry t_boundries;
      std::vector<double> x;
      double t;
  };

//==============================================================================













}

#endif
