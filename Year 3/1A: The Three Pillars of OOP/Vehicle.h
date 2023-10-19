#ifndef Vehicle_h
#define Vehicle_h
#include <string>   //Library is needed to use string variable.
using namespace std;    //Used to avoid the use of std:: in statements.

class Vehicle   //Declaration of parent class Vehicle.
{
  public:
    
    Vehicle();  //Default constructor
    Vehicle(string, string, int);   //Override constructor
    Vehicle(const Vehicle& pass);   //Copy constructor
    ~Vehicle(); //Destructor
    
    void setType(string); //Set function for vehicle brand.
    void setColor(string);  //Set function for vehicle model.
    void setNumWheels(int);  //Set function for the year vehicle was built.
    
    string getType(); //Get function for vehicle brand.
    string getColor(); //Get function for vehicle model.
    int getNumWheels(); //Get function for the year vehicle was built.
    
    
  private:  //Privtate data members cannot be accessed without class functions.
    
    string type;
    string color;
    int numWheels;
    
};

#endif
