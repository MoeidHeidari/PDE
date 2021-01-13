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
/*! \file PDE_Solverclass_file PDE.h PDE.h
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
   *  this structure holds the left-right boundries of x_value and t_value
   */
  struct PDE_boundry
  {
    double left;
    double right;
  };
  //==============================================================================
  /*! \class PDE_solver
   *
   *  this class contains all computation functions and member variables needed by
   *  functions
   */
class PDE_Solver
{
  public:
    //! PDE_Solver Overloaded constructor constructor.
    /*!
      Actually it is the right contructor which should be used to do instantiation
      of this class with necessary parameters.\n
      \param one : the initial value for x\n
      \param two: the initial value for T\n
      \param three: definition of the boundries of the given x values\n
      \param four: definition of the boundries of the given T values\n
    */
    PDE_Solver(std::vector<double> pde_x,double pde_t,
            PDE_boundry pde_x_boundry, PDE_boundry pde_t_boundry)
    {
      this->x=pde_x;
      this->t=pde_t;
      this->x_boundries=pde_x_boundry;
      this->t_boundries=pde_t_boundry;
    }
//==============================================================================
    //! get_X_boundries.
    /*!
      this function is the getter of provided x_boundries.\n
      \return const PDE_boundry&
    */
    const PDE_boundry& get_X_boundries() const
    {
      return this->x_boundries;
    }
//==============================================================================
    //! get_T_boundries.
    /*!
      this function is the getter of provided t_boundries.\n
      \return const PDE_boundry&
    */
    const PDE_boundry& get_T_boundries() const
    {
      return this->t_boundries;
    }
//==============================================================================
    //! set_X_boundries.
    /*!
      this function is the setter of x_boundries.\n
      \return void
      \param  PDE_boundry
    */
    void set_X_boundries( PDE_boundry boundry)
    {
      this->x_boundries=boundry;
    }
//==============================================================================
    //! set_T_boundries.
    /*!
      this function is the setter of t_boundries.\n
      \return void
      \param  PDE_boundry
    */
    void set_T_boundries( PDE_boundry boundry)
    {
      this->t_boundries=boundry;
    }
//==============================================================================
    //! set_X_values.
    /*!
      this function is the setter of X_values.\n
      \return void
      \param  std::vector<double> takes a vector of doubles as x inputes
    */
    void set_X_values(std::vector<double> x_vector)
    {
      this->x=x_vector;
    }
//==============================================================================
    //! get_T_value.
    /*!
      this function is the getter of T_value.\n
      \return const double&
    */
    const double& get_T_value()
    {
      return this->t;
    }
//==============================================================================
    //! get_X_value.
    /*!
      this function is the getter of X_value.\n
      \return std::vector<double>
    */
    std::vector<double> get_X_value()
    {
      return this->x;
    }
//==============================================================================
    //! set_T_values.
    /*!
      this function is the setter of X_values.\n
      \return void
      \param  double the provided t_value
    */
    void set_T_values(double t_value)
    {
      this->t=t_value;
    };
//==============================================================================
    //! integral.
    /*!
      this function Calculate the integral X= a + (i + 0.5) * step.\n
      \return double
      \param  double(*f)(double x_val) function pointer to the first integral function f(x)
      \param  double(*g)(double x_val) function pointer to the secong integral function g(x)
      \param  double left border of the integral curve
      \param  double right border of the integral curve
      \param  int number of iterations
    */
    double integral(double(*f)(double x_val), double(*g)(double x_val), double a, double b, int n)
    {
        double step = (b - a)/n;
        double area = 0.0;
        double y = 0;
        for(int i = 0; i < n; ++i)
        {
            y = f(a + (i + 0.5) * step) * g((a + (i + 0.5) * step)*PDE_PI*n);
            area += y * step;
        }
        return area;
    }
//==============================================================================
    //! integralt.
    /*!
      this function Calculate the integral X= a + (i + 0.5) * step.\n
      \return double
      \param  double(*f)(double x_val) function pointer to the first integral function f(x)
      \param  double left border of the integral curve
      \param  double right border of the integral curve
      \param  int number of iterations
      \param  double provided x value based on t parameter (dt)
    */
    double integralt(double(*f)(double t,int n,double x_val), double a, double b, int n,double x_val)
    {
        double step = (b - a)/n;
        double area = 0.0;
        double y = 0;
        for(int i = 0; i < n; ++i)
        {
            y = f(q_n_t(a + (i + 0.5)* step,n,x_val),n,x_val);
            area += y * step;
        }
        return area;
    }
//==============================================================================
    //! f_x_t static.
    /*!
      this function Calculates f(x,t) used inside the integral.\n
      \return double
      \param  provided x value.
    */
    static double f_x_t(double x_val)
    {

      return 1/(1+x_val);
    }
//==============================================================================
    //! p_o_x static.
    /*!
      this function Calculates POX used inside the integral.\n
      \return double
      \param  provided x value.
    */
    static double p_o_x(double x_val)
    {

      return std::pow(PDE_EXPO,-x_val);
    }
//==============================================================================
    //! eigenfunction static.
    /*!
      this function is the main eigenfunction.\n
      \return double
      \param  provided x value.
      \param  provided n value.
    */
    static double eigenfunction(double x_val,double n)
    {
      return std::sin(x_val*n*PDE_PI);
    }
//==============================================================================

    //! q_n_t .
    /*!
      this function to calculate q_n(t).\n
      \return
      \param double provided t value
      \param  provided n value.
      \param  provided x value.
    */
    double q_n_t(double t,int n,double x_val)
    {
      return 2*(integral(f_x_t,std::sin,0,1,n));
    }
//==============================================================================
    //! u_n_0 .
    /*!
      this function to calculate u_n_0(t).\n
      \return
      \param double provided t value
      \param  provided n value.
      \param  provided x value.
    */
    double u_n_0(double t,int n,double x_val)
    {
      return 2*(integral(p_o_x,std::sin,0,1,n));
    }
//==============================================================================
    //! q_n_t_prime static.
    /*!
      this function to calculate q_n_t_prime(t) function used as f(x) in integralt.\n
      \return double provided t value
      \param  provided n value.
      \param  provided x value.
    */
     static double q_n_t_prime(double t,int n,double x_val)
    {
      return t*std::pow(PDE_EXPO,std::pow(n,2)*std::pow(PDE_EXPO,2)*t);
    }
//==============================================================================
    //! u_n_t .
    /*!
      this function to calculate u_n_t(t) function.\n
      \return double
      \param provided t value
      \param  provided n value.
      \param  provided x value.
    */
     double u_n_t(double t,int n,double x_val)
    {
      return u_n_0(t,n,x_val)* std::pow(PDE_EXPO,std::pow(-n,2)*std::pow(PDE_EXPO,2)*t)+
      std::pow(PDE_EXPO,std::pow(-n,2)*std::pow(PDE_EXPO,2)*t)*integralt(q_n_t_prime,0,t,n,x_val);
    }
//==============================================================================
  private:
    //! PDE_Solver Default constructor.
    /*!
      this is the default contructor of PDE_Solver class which
      is not allowed at all.(initial values should be passed during the instantiation)
    */
    PDE_Solver(){}
//==============================================================================
    //! \var provided boundries for x values
    PDE_boundry x_boundries;
    //! \var provided boundries for t values
    PDE_boundry t_boundries;
    //! \var vector of provided x values
    std::vector<double> x;
    //! \var provided t values
    double t;
  };

//==============================================================================













}

#endif
