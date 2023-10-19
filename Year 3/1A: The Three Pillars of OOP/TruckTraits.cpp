#include "Vehicle.h"
#include"TruckTraits.h"
#include <iostream>     //Needed to use cout.
using namespace std;    //Used to avoid the use of std:: in statements.

TruckTraits::TruckTraits(string typ, string clr, int whls, string brnd, string mdl, int yr)
   : Vehicle(typ, clr, whls)  //Calls the base class constructor.
{
    
    setBrand(brnd);  //Sets variable brand to brnd.
    setModel(mdl);  //Sets variable model to mdl.
    setYear(yr);   //Sets variable year to yr.
    
    cout << "Ouputting additional parameters for TruckTraits child class..." << endl;
    cout << "Truck brand: " << getBrand() << endl;   //Outputs car brand provided in parameters.
    cout << "Truck model: " << getModel() << endl;   //Outputs car model provided in parameters.
    cout << "Year truck was built: " << getYear() << endl << endl;   //Outputs year car was built provided in paramaters.
}


void TruckTraits::setBrand(string brnd)   //Definition of setBrand function.
{
   brand = brnd;
}

void TruckTraits::setModel(string mdl)   //Defiition of setModel function.
{
   model = mdl;
}

void TruckTraits::setYear(int yr)   //Definition of setYear function.
{
   year = yr;
}

string TruckTraits::getBrand()   //Definition of getBrand function.
{
   return brand;
}

string TruckTraits::getModel()   //Definition of getModel function.
{
   return model;
}
  
int TruckTraits::getYear()   //Definotion of getYear function.
{
   return year;
}

TruckTraits& TruckTraits::operator=(const TruckTraits& other)  //Definition for operation overloading function.
{
   
    if (this == &other)  //Checks for self assignment.
        return *this;

   
    this->brand = other.brand;  //Copies data member brand.
    this->model = other.model; //Copies data member model.
    this->year = other.year;   //Copies data member year.

    Vehicle::operator=(other);     //Calls the base class's assignment operator

    return *this;
}
