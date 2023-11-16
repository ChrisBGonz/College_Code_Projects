#include <iostream>
#include "cpp.cpp"
#include "header.h"
using namespace std;

int main()
{
    ArrayStack<float> GoogleStock(10); //The stack will hold information of Google's closing stock price.
    
    //This information was retrieved from yahoo finance.
    
    GoogleStock.push(131.45); //The closing value of a Google stock for 11/06/23.
    GoogleStock.push(130.37); //The closing value of a Google stock for 11/03/23.
    GoogleStock.push(128.58); //The closing value of a Google stock for 11/02/23.
    GoogleStock.push(127.57); //The closing value of a Google stock for 11/01/23.
    GoogleStock.push(125.30); //The closing value of a Google stock for 10/31/23.
    GoogleStock.push(125.75); //The closing value of a Google stock for 10/30/23.
    GoogleStock.push(123.40); //The closing value of a Google stock for 10/27/23.
    GoogleStock.push(123.44); //The closing value of a Google stock for 10/26/23.
    GoogleStock.push(126.67); //The closing value of a Google stock for 10/25/23.
    GoogleStock.push(140.12); //The closing value of a Google stock for 10/24/23.
        
    int n = GoogleStock.size(); // Gets the number of elements in GoogleStock.
    float price[n]; //Stores the stock values into an array which will be used in later function.

     for (int i = n - 1; i >= 0; i--) //Will store all the stock values into array.
     {
         price[i] = GoogleStock.top(); //Uses the top element value to store in array.
         GoogleStock.pop(); //Once the top element value is stored, it will be popped from stack.
     }

     int span[n]; //Creates an array that will return the span for each element.
    
     GoogleStock.calculateSpan(price, n, span); //Function will calculate the span.

     for (int i = 0; i < n; i++) //Loop will print out the span for each stock value.
         cout << "Span for day " << i + 1 << ": " << span[i] << endl;
        
    cout << endl;
    
    return 0;
}
