#ifndef CarTraits_h
#define CarTraits_h
#include"Vehicle.h"
#include <string>   //Library is needed to use string variable.
using namespace std;    //Used to avoid the use of std:: in statements.

class CarTraits: public Vehicle     //Declaration of child class CarTraits
{
  public:
    
    CarTraits(string, string, int, string, string, int);
    
    void setBrand(string);   //Set function for car brand.
    void setModel(string);   //Set function for car model.
    void setYear(int);    //Set function for year car was built.
     
    string getBrand();   //Get function for car brand.
    string getModel();   //Get function for car model.
    int getYear();    //Get function for year car was built.

  private:
    
    string brand;
    string model;
    int year;
};

#endif 
