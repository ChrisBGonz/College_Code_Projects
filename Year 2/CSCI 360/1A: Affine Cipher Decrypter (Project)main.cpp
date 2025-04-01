#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b;
    string AE_Encr, AE_Decr;
    
    cout << "Please enter an integer (this will be your key a): ";
    cin >> a; //It should be 21
    
    cout << "Please enter another integer (this will be your key b): ";
    cin >> b; //It should be 7
    
    cout << "Enter your cipher text: ";
    cin >> AE_Encr;
    /* Please copy and paste the following: KAPONXQDLQNUCNADVQYNENDNUSPIVENNKRYPEEPBCRBHVYTUDQPUTAGTUDQYTVNCPPJTVIPAQYNLVNPIHURPUNHURBYNANHQUPXPVQHUSBTQYHEZPVQUPANVQATXQTPUVBYHQVPNGNARPLZHRXPKRTQDTGNTQHBHRPAANLVNTQLUSNAQYNQNAZVPIQYNKAPONXQDLQNUCNADETXNUVNTUXELSNSBTQYQYTVNCPPJPAPUETUNHQBBBDLQNUCNADPADQTQENQYNENDNUSPIVENNKRYPEEPBHLQYPABHVYTUDQPUTAGTUDKPVQTUDSHQNOLUNNCPPJANENHVNSHQNPXQPCNAEHUDLHDNNUDETVYXYHAHXQNAVNQNUXPSTUDHVXTTVQHAQPIQYTVKAPONXQDLQNUCNADNCPPJQYNENDNUSPIVENNKRYPEEPBKAPSLXNSCRTEHUHZJTUDVENRUNBCRHUSDANDUNBCRQYNENDNUSPIVENNKRYPEEPBC
     */
    
    for (int i = 0; i < AE_Encr.size(); i++)
    {
        AE_Decr += ((AE_Encr[i] - 'A' - b + 26) * 5) % 26 + 'A';
    }
    
     cout << "\nDecrypted Message is " << AE_Decr << endl;
    
    return 0;
}
