#include <iostream>
#include "Vehicle.h"
#include "CarTraits.h"
#include"TruckTraits.h"
using namespace std;

int main()
{
   Vehicle v1;    //Object will trigger and output the default constructor.
   cout << endl;
    
   Vehicle v2("Car", "Yellow", 4); //Object will trigger and output the override constructor with the given parameters.
   cout << endl;
    
   Vehicle v3("Truck", "White", 6);  //Object will trigger and output the override constructor with the given parameters.
   cout << endl;

   Vehicle v4(v2);   //Object will trigger and output the copy constructor by assigning it to the values of v2.
   cout << endl;
    
    CarTraits c1("Car","Red", 4, "GMC", "Acadia", 2014);   //Object will call the parent class constructor and additional paramaters.
    cout << endl;
    
    TruckTraits t1("Truck", "Blue", 6, "Mack", "Pinancle", 2023);  //Object will call the parent class constructor and additional paramaters.
    cout << endl;
    
    TruckTraits t2("Truck", "Red", 8, "Kenworth", "W900L", 2020);  //Object will call the parent class constructor and additional paramaters.
    cout << endl;
    
    cout << "Now applying operation overloading to change t2 values to t1...";
    t2 = t1;  //This statement will use operation overloading to change the values of t2 to t1.
    
    cout << "\nUpdated TruckTraits t2:" << endl << endl;
    cout << "Vehicle type: " << t2.getType() << endl;
    cout << "Vehicle color: " << t2.getColor() << endl;
    cout << "Number of wheels: " << t2.getNumWheels() << endl;
    cout << "Truck brand: " << t2.getBrand() << endl;
    cout << "Truck model: " << t2.getModel() << endl;
    cout << "Year truck was built: " << t2.getYear() << endl << endl;
    
    return 0;
}
