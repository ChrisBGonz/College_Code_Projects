#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int choice;
    
    cout << "Select the cipher you want to decrypt from the choices below:\n";
    cout << "1. Affine\n";
    cout << "2. Caesar\n";
    cout << "3. Vigenere\n\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch (choice) 
    {
        case 1: 
        {
            /*
            Use the following information to test the affine decrypter:
            Cipher text = QYTVZNVVHDNYHVCNNUVLXXNVVILEERSNXARKQNS
            Key a = 21
            Key b = 7
            */
            
            int a, b;
            string AE_Encr, AE_Decr;
            
            cout << "Enter your cipher text: ";
            cin >> AE_Encr;
            
            cout << "Please enter the value of key a: ";
            cin >> a;
    
            cout << "Please enter the value of key b: ";
            cin >> b;
    
            for (int i = 0; i < AE_Encr.size(); i++)
            {
                AE_Decr += ((AE_Encr[i] - 'A' - b + 26) * 5) % 26 + 'A';
            }
    
            cout << "\nDecrypted Message is " << AE_Decr << endl;
            break;
        }
        
        case 2: 
        {
            /*
            Use the following information to test the caesar decrypter:
            Cipher text = HVWGASGGOUSVOGPSSBGIQQSGGTIZZMRSQFMDHSR
            Key = 14
            */
            
            int i, key;
            string CC_Encr, CC_Decr;
            
            cout << "Enter the message to decrypt: ";
            cin >> CC_Encr;
            
            cout << "Enter the value of the key: ";
            cin >> key; 

            for(i = 0; i < CC_Encr.size(); i++)
            {
                CC_Decr += (CC_Encr[i] - 'A' - key + 26) % 26 +'A';
            }
            
            cout << "\nDecrypted message is "<< CC_Decr <<'\n';
            break;
        }
        
        case 3: 
        {
            /*
            Use the following information to test the vigenere decrypter:
            Cipher text = LGAGNWRKOHWGSGCWDFGVUBWGTXTDZZVDUFZHSWR
            Key = SZSOB
            */
            
            int i;
            string key, VE_Encr, VE_Decr;
            
            cout << "Enter the message to decrypt: ";
            cin >> VE_Encr;
            
            cout << "Please enter the key: ";
            cin >> key;

            for (i = 0; i < VE_Encr.size(); i++)
            {
                VE_Decr += ((VE_Encr[i] - 'A') - (key[(i % key.length())] - 'A') + 26) % 26 + 'A';
            }
    
            cout << "\nDecrypted message is " << VE_Decr << endl;
            break;
        }
    }
    
    return 0;
}