#include "Vehicle.h"
#include <iostream>     //Needed to use cout.
using namespace std;    //Used to avoid the use of std:: in statements.

 Vehicle::Vehicle()     //Definition of the default constructor.
{
    cout << "Default constructor called:" << endl;  //Message to indicate that the default constructor was called.
    
     type = "Vehicle type not specified\n";   //This message will appear since if no brand was specified.
     color = "Vehicle color not specified\n";   //This message will appear since if no model was specified.
     numWheels = 0;   //Provides a default number for year built.
    
    cout << type;
    cout << color;
    cout << "Default number of wheels = " << numWheels << endl; //This message will appear since if no year was specified.
    
}


 Vehicle::Vehicle(string typ,string clr, int whls)    //Definition of the override constructor.
{
     cout << "Override constructor called:" << endl; //Message to indicate that the override constructor was called.

    
    setType(typ);   //Sets variable type to typ entered in parameters.
    setColor(clr);  //Sets variable color to clr entered in parameters.
    setNumWheels(whls);  //Sets variable numWheels to whls entered in parameters.
    
    cout << "Vehicle type: " << getType() << endl;    //Outputs the vehicle type provided in parameters.
    cout << "Vehicle color: " << getColor() << endl;    //Outputs the vehicle color provided in parameters.
    cout << "Number of wheels: " << getNumWheels() << endl;    //Outputs the year vehicle was built in parameters.
}


 Vehicle::Vehicle(const Vehicle& pass)  //Definition of the copy constructor.
{
     cout << "Copy constructor called:" << endl;    //Message to indicate that the copy constructor was called.
    
     type = pass.type;    //Passes brand information of the class object that is being copied.
     color = pass.color;    //Passes model information of the class object that is being copied.
     numWheels = pass.numWheels;  //Passes year built the class object that is being copied.
     
     cout << "Vehicle type: " << getType() << endl;    //Outputs copied brand.
     cout << "Vehicle color: " << getColor() << endl;    //Outputs copied model.
     cout << "Number of Wheels: " << getNumWheels() << endl << endl;    //Outputs copied year built.
}


Vehicle::~Vehicle() //Deifnition of destructor.
{
    cout << "Destructor called: " << endl;      //Message to indicate the destructor was called.
}


void Vehicle::setType(string typ)    //Definition of setType function.
{
    type = typ;
}


void Vehicle::setColor(string clr) //Definition of setColor function.
{
    color = clr;
}


void Vehicle::setNumWheels(int whls) //Definition of setNumWheels function.
{
    numWheels = whls;
}


string Vehicle::getType() //Definition of getType function.
{
    return type;
}


string Vehicle::getColor() //Definition of getColor function.
{
    return color;
}


int Vehicle::getNumWheels() //Definition of getNumWheels function.
{
    return numWheels;
}

