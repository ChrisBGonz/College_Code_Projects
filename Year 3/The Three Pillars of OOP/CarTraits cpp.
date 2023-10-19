#include "Vehicle.h"
#include"CarTraits.h"
#include <iostream>     //Needed to use cout.
using namespace std;    //Used to avoid the use of std:: in statements.


CarTraits::CarTraits(string typ, string clr, int whls, string brnd, string mdl, int yr)
   : Vehicle(typ, clr, whls) //Calls the base class constructor.
{
    
    setBrand(brnd);  //Sets variable brand to brnd.
    setModel(mdl);  //Sets variable model to mdl.
    setYear(yr);   //Sets variable year to yr.
    
    cout << "Ouputting additional parameters for CarTraits child class..." << endl;
    cout << "Car brand: " << getBrand() << endl;   //Outputs car brand provided in parameters.
    cout << "Car model: " << getModel() << endl;   //Outputs car model provided in parameters.
    cout << "Year car was built: " << getYear() << endl << endl;   //Outputs year car was built provided in paramaters.
}


void CarTraits::setBrand(string brnd)   //Definition of setBrand function.
{
   brand = brnd;
}

void CarTraits::setModel(string mdl)   //Defiition of setModel function.
{
   model = mdl;
}

void CarTraits::setYear(int yr)   //Definition of setYear function.
{
   year = yr;
}

string CarTraits::getBrand()   //Definition of getBrand function.
{
   return brand;
}

string CarTraits::getModel()   //Definition of getModel function.
{
   return model;
}
  
int CarTraits::getYear()   //Definotion of getYear function.
{
   return year;
}
