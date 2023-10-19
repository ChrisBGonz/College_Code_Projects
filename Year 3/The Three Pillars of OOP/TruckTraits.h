#ifndef TruckTraits_h
#define TruckTraits_h
#include"Vehicle.h"
#include <string>   //Library is needed to use string variable.
using namespace std;    //Used to avoid the use of std:: in statements.

class TruckTraits: public Vehicle     //Declaration of child class CarTraits
{
  public:
    
    TruckTraits(string, string, int, string, string, int);
    
    void setBrand(string);   //Set function for truck brand.
    void setModel(string);   //Set function for truck model.
    void setYear(int);    //Set function for year truck was built.
     
    string getBrand();   //Get function for truck brand.
    string getModel();   //Get function for truck model.
    int getYear();    //Get function for year truck was built.

    TruckTraits& operator=(const TruckTraits& other); //Function for operation overloading.
    
  private:
    
    string brand;
    string model;
    int year;
};

#endif 
