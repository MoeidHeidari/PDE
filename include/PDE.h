#ifndef PDE
#define PDE

#ifndef PDE_PI
#define PDE_PI 3.1415926535897932384626433832795
#endif

#ifndef PDE_EXPO
#define PDE_EXPO 2.71828
#endif
template<typename T>
struct boundry
{
  T left;
  T right;
};
namespace _PDE
{
/*Constant values used in PDE*/

  class PDE_Solver
  {
  public:
    explicit PDE_Solver(n,k,l,
      struct<T>,struct<T>);
  private:
    struct<T> x_boundries;
    struct<T> T_boundries;


  };

//==============================================================================

}
#endif
