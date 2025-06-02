#include <iostream>
#include <string>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

//Functions for Affine cipher.
int modInverse(int a, int m);
string affineEncrypt(string text, int a, int b);
string affineDecrypt(string text, int a, int b);

//Function for Atbash cipher.
string atbashCipher(string text);

//Functions for Rail Fence cipher.
string railfenceEncrypt(string text, int key);
string railfenceDecrypt(string cipherText, int key);

//Functions for Vigenère cipher.
string generateVigenereKey(string text, string key);
string vigenereEncrypt(string text, string key);
string vigenereDecrypt(string cipherText, string key);

//Functions for XOR cipher.
void encryptDecrypt(string& Input, char key);
void printASCII(const string& Output);

//Global Variables and initiation.
int ED_Choice = 0; //Allows program to know if the user wants to encrypt/decrypt.
int Key = 0; //Numerical key used for encryption/decryption.
string key = ""; //String key used for encryption/decryption.
string Input = ""; //Where the user will enter plaintext/ciphertext.
string Output = ""; //Will be returned to the user after encrypting/decrypting.

int main() 
{
    int Menu_Choice; //Variable that stores user's selection from menu.

    while (true) //Loop that will always return user to menu after use.
    {
        cout << "Hello, and welcome to the program.\n";
        cout << "Please select the cipher you wish to use from the choices below:\n";

        cout << "1. Atbash Cipher\n";
        cout << "2. Caesar Cipher\n"; 
        cout << "3. Rail Fence Cipher\n";
        cout << "4. Columnar Transposition Cipher\n"; 
        cout << "5. Vigenère Cipher\n"; 
        cout << "6. Affine Cipher\n"; 
        cout << "7. ROT13 Cipher\n"; 
        cout << "8. XOR Cipher\n"; 
        cout << "9. Choose for me\n"; 
        cout << "10. End Session \n"; 

        cout << "Enter your choice (1-10): "; 
        cin >> Menu_Choice; //The user makes their choice by entering a number from 1-10.
        cin.ignore(); 

        if (Menu_Choice == 9) //If the user wants the program to pick a cipher.
        {
            Menu_Choice = (rand() % 8) + 1; //Formula used for random cipher selection.
            cout << "\nRandom selection chose Option " << Menu_Choice << "!\n";
        }

        if (Menu_Choice == 10) //If the user chooses to end the session.
        {
            cout << "\nExiting program. Goodbye!\n";
            break;
        }

        switch (Menu_Choice)
        {
            case 1: //Atbash Cipher code by Isaia Jimenez.
            {
                /*
                Example:
                Plaintext = ATBASH CIPHER 
                Ciphertext = ZGYZHS XRKSVI
                */
                
                cout << "\nChoice 1 selected (Atbash Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }
                
                if (ED_Choice == 1)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);
                    Output = atbashCipher(Input); //The atbashCipher() function is called to encrypt.

                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";
                }
                
                else if (ED_Choice == 2)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);
                    Output = atbashCipher(Input); //The atbashCipher() function is called to decrypt.

                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n"; 
                }
                
                break;
            }



            case 2: //Caesar Cipher code by Christopher Gonzalez.
            {
                /*
                Example:
                Plaintext = Caesar Cipher 
                Ciphertext = Fdhvdu Flskhu
                */
                
                int Key = 3; //Key used for traditional encryption/decryption.
                
                cout << "\nChoice 2 selected (Caesar Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }

                cout << "Enter the message: ";
                getline(cin, Input); 
                
                /*
                If the user wishes to enter any key value.
                //cout << "Enter the key: ";
                //cin >> Key;
                */
                
                for (char ch : Input) //Loop encrypts/decrypts input per character.
                {
                    if (isupper(ch)) //Formula for uppercase letters.
                        Output += (ch - 'A' + (ED_Choice == 1 ? Key : -Key) + 26) % 26 + 'A';

                    else if (islower(ch)) //Formula for lowercase letters.
                        Output += (ch - 'a' + (ED_Choice == 1 ? Key : -Key) + 26) % 26 + 'a';

                    else //If the character is not a letter.
                        Output += ch; //No action is performed on non-letters.
                }

                cout << "The result is: " << Output << '\n';
                Output = "";
                cout << "\nReturning to main menu...\n\n";

                break;
            }



            case 3: //Rail Fence Cipher code by Daniel Minton.
            {
                /*
                Example:
                Plaintext = Rail Fence Cipher 
                Rails = 3
                Ciphertext = R ciralFneCpeie h
                */

                cout << "\nChoice 3 selected (Rail Fence Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }

                if (ED_Choice == 1)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);

                    cout << "Enter the key (number of rails): ";
                    cin >> Key;

                    Output = railfenceEncrypt(Input, Key); //railfenceEncrypt() function is called to encrypt.
                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";

                }

                else if (ED_Choice == 2)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);

                    cout << "Enter the key (number of rails): ";
                    cin >> Key;

                    Output = railfenceDecrypt(Input, Key); //railfenceEncrypt() function is called to dencrypt.
                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";

                }

                break;
            }



            case 4: //Columnar Transposition Cipher code by Christopher Gonzalez.
            {
                /*
                Example:
                Plaintext = CTC_Cipher 
                Ciphertext = TCh_C_prCie_
                key = Key
                */

                cout << "\nChoice 4 selected (Columnar Transposition Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }
                

                if (ED_Choice == 1) //If the user chooses to encrypt.
                {
                    cout << "Enter the message (Please use underscores '_' instead of spaces): ";
                    getline(cin, Input);
                
                    cout << "Enter a keyword: ";
                    getline(cin, key);
                
                    transform(key.begin(), key.end(), key.begin(), ::toupper);
                
                    int len_key = key.length();
                    int len_msg = Input.length();
                
                    int no_rows = len_msg / len_key;
                    if (len_msg % len_key != 0)
                        no_rows++;
                
                    //Pad with underscores to fill the matrix completely.
                    while (Input.length() < no_rows * len_key)
                        Input += '_';
                
                    //Sort the key to get column order.
                    int val = 1, count = 0, ind;
                    int col_val[len_key];
                    memset(col_val, 0, sizeof(col_val));
                
                    while (count < len_key)
                    {
                        int min = 999;
                        for (int i = 0; i < len_key; i++)
                        {
                            if ((min > int(key[i])) && (col_val[i] == 0))
                            {
                                min = int(key[i]);
                                ind = i;
                            }
                        }
                        col_val[ind] = val;
                        count++;
                        val++;
                    }
                
                    //Fill the matrix row by row.
                    char enc_mat[no_rows][len_key];
                    int x = 0;
                    for (int i = 0; i < no_rows; i++)
                    {
                        for (int j = 0; j < len_key; j++)
                        {
                            enc_mat[i][j] = Input[x++];
                        }
                    }
                
                    //Read columns in order of sorted key.
                    Output = "";
                    for (int t = 1; t <= len_key; t++)
                    {
                        for (int i = 0; i < len_key; i++)
                        {
                            if (col_val[i] == t)
                            {
                                for (int j = 0; j < no_rows; j++)
                                    Output += enc_mat[j][i];
                            }
                        }
                    }
                
                    cout << "The result is: " << Output << '\n';
                    Output = "";
                    cout << "\nReturning to main menu...\n";
                }


                else if (ED_Choice == 2) //If the user chooses to decrypt.
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);
                
                    cout << "Enter the key: ";
                    getline(cin, key);
                
                    transform(key.begin(), key.end(), key.begin(), ::toupper);
                
                    int len_key = key.length();
                    int len_msg = Input.length();
                
                    int no_rows = len_msg / len_key;
                    if (len_msg % len_key != 0)
                        no_rows++;
                
                    //Sort the key to get column order.
                    int val = 1, count = 0, ind;
                    int col_val[len_key];
                    memset(col_val, 0, sizeof(col_val));
                
                    while (count < len_key)
                    {
                        int min = 999;
                        for (int i = 0; i < len_key; i++)
                        {
                            if ((min > int(key[i])) && (col_val[i] == 0))
                            {
                                min = int(key[i]);
                                ind = i;
                            }
                        }
                        col_val[ind] = val;
                        count++;
                        val++;
                    }
                
                    //Determine column lengths.
                    int base_col_height = len_msg / len_key;
                    int extra_chars = len_msg % len_key;
                    int col_lengths[len_key];
                
                    for (int i = 0; i < len_key; i++)
                        col_lengths[i] = base_col_height;
                
                    for (int t = 1, given = 0; t <= len_key && given < extra_chars; t++)
                    {
                        for (int i = 0; i < len_key; i++)
                        {
                            if (col_val[i] == t)
                            {
                                col_lengths[i]++;
                                given++;
                                break;
                            }
                        }
                    }
                
                    //Fill the matrix column by column.
                    char dec_mat[no_rows][len_key];
                    memset(dec_mat, '_', sizeof(dec_mat));
                    int x = 0;
                
                    for (int t = 1; t <= len_key; t++)
                    {
                        for (int i = 0; i < len_key; i++)
                        {
                            if (col_val[i] == t)
                            {
                                for (int j = 0; j < col_lengths[i]; j++)
                                {
                                    if (x < len_msg)
                                        dec_mat[j][i] = Input[x++];
                                }
                            }
                        }
                    }
                
                    //Read the matrix row by row.
                    Output = "";
                    for (int i = 0; i < no_rows; i++)
                    {
                        for (int j = 0; j < len_key; j++)
                        {
                            Output += dec_mat[i][j];
                        }
                    }
                
                    cout << "The result is: " << Output << '\n';
                    Output = "";
                    cout << "\nReturning to main menu...\n";
                }

                break;   
            }



            case 5: //Vigenère Cipher code by Daniel Minton.
            {
                /*
                Example:
                Plaintext = Vigenere Cipher
                Key = France
                Ciphertext = Azgrpiwv Cvrlji
                */

                cout << "\nChoice 5 selected (Vigenère Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }
                
                if (ED_Choice == 1)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);

                    cout << "Enter the key (letters only): ";
                    getline(cin, key);

                    //Function that transforms key to capital letters for shifting.
                    for (int i = 0; i < key.length(); i++)
                    {
                        if (key[i] >= 'a' && key[i] <= 'z')
                            key[i] = key[i] - 32;
                    }

                    key = generateVigenereKey(Input, key); //Function to validate key.

                    Output = vigenereEncrypt(Input, key); //Function to encrypt input.
                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";
                }

                else if (ED_Choice == 2)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);

                    cout << "Enter the key (letters only): ";
                    getline(cin, key);

                    //Function that transforms key to capital letters for shifting.
                    for (int i = 0; i < key.length(); i++)
                    {
                        if (key[i] >= 'a' && key[i] <= 'z')
                            key[i] = key[i] - 32;
                    }

                    key = generateVigenereKey(Input, key); //Function to validate key.

                    Output = vigenereDecrypt(Input, key); //Function to decrypt input.
                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";
                }

                break;
            }



            case 6: //Affine Cipher code by Isaia Jimenez.
            {
                /*
                Example:
                Plaintext = Affine Cipher 
                Ciphertext = Ihhwvc Swfrcp
                Keys: a = 5, b = 8
                */
                
               int a = 5, b = 8; //The keys used in the Affine Cipher will always be 5 and 8.

                cout << "\nChoice 6 selected (Affine Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }
                
                if (ED_Choice == 1)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);

                    Output = affineEncrypt(Input, a, b); //Function that will encrypt the input.

                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";
                }
                
                if (ED_Choice == 2)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);

                    cout << "The result is: " << affineDecrypt(Input, a, b) << endl; //Function that will decrypt the input.
                    Output = "";
                    cout << "\nReturning to main menu...\n\n";
                }

                break;
            }



            case 7: //ROT13 Cipher code by Joseph Ipanaque.
            {
                /*
                Example:
                Plaintext = ROTThrtn Cipher 
                Ciphertext = EBGGuega Pvcure
                */

                cout << "\nChoice 7 selected (ROT13 Cipher). ";
                cout << "Would you like to perform encryption or decryption?\n";
    
                //Loop until valid input is received.
                while (true) 
                {
                    cout << "Enter 1 for encryption, 2 for decryption: ";
                    cin >> ED_Choice;

                    if (cin.fail()) 
                    {
                        cin.clear(); //Clears the error flag.
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards bad input.
                        cout << "\nInvalid input! Please enter a number (1 or 2).\n";
                    } 
                    
                    else if (ED_Choice != 1 && ED_Choice != 2) 
                    {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard any leftover input.
                        cout << "\nInvalid choice! Please enter 1 or 2.\n";
                    } 
                    
                    else 
                    {
                        cin.ignore(); //Discards newline.
                        break; //The input is valid and the program continues.
                    }
                }
                
                if (ED_Choice == 1 || 2)
                {
                    cout << "Enter the message: ";
                    getline(cin, Input);
                    
                    //Loop that transforms input appropriately whether upper or lowercase.
                    for (char c : Input) 
                    {
                        if (isalpha(c)) 
                        {
                            char base = isupper(c) ? 'A' : 'a';
                            Output += (base + ((c - base + 13) % 26)); //Input is shifted by 13 spaces.
                        } 
                    
                        else //If the character is not a letter.
                        Output += c; //No action is performed on non-letters. 
                    }

                    cout << "The result is: " << Output << endl;
                    Output = "";
                    cout << "Note: ROT13 is its own inverse - applying it again will reverse the operation.\n";
                    cout << "\nReturning to main menu...\n\n";
                }
                
                break;
            }



            case 8:
            {
                /*
                Example:
                Plaintext = XOR Cipher 
                Key = K
                Ciphertext = ";#.9
                Ciphertext (ASCII Code) = 19 4 25 107 8 34 59 35 46 57
                */
                
                cout << "\nChoice 8 selected (XOR Cipher)." << endl;
                
                string keyInput;
                char key;

                //Prompt user for input message.
                cout << "Enter the message: ";
                getline(cin, Input);

                //Prompt user for XOR key and validate input.
                while (true) 
                {
                    cout << "Enter a single character key for XOR encryption: ";
                    getline(cin, keyInput);

                    if (keyInput.length() == 1) 
                    {
                        key = keyInput[0];
                        break;
                    } 
                    
                    else
                    {
                        cerr << "\nInvalid input. Please enter exactly one character.\n";
                        
                    }
                }

                //Encrypt the input.
                encryptDecrypt(Input, key);
                string Output = Input;
                cout << "The result is: " << Output << endl;
                cout << "The ASCII code of the result is: ";
                printASCII(Output);

                //Decrypt the output.
                encryptDecrypt(Output, key);
                cout << "The decryption is: " << Output << endl;
                Output = "";
                cout << "\nReturning to main menu...\n\n";


                break;
            }



            default: //If Menu_Choice is not a number from 1-10.
                if (cin.fail()) //If the user enters a non-integer.
                {
                    cin.clear(); //Clears the error flag.
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards invalid input.
                    cout << "\nInvalid option. Please enter a number between 1 and 10.\n\n";
                }
                
                else //If the user enters a number outside the range.
                   cout << "\nInvalid option. Please enter a number between 1 and 10.\n\n";
        }
    }

    return 0;
}

//Function for modular inverse.
int modInverse(int a, int m) 
{
    for (int x = 1; x < m; x++) 
    {
        if ((a * x) % m == 1) 
            return x;
    }
    return -1;
}

//Function for Affine cipher (encryption).
string affineEncrypt(string text, int a, int b) 
{
    string result = "";

    for (char c : text) 
    {
        if (isalpha(c)) 
        {
            char base = isupper(c) ? 'A' : 'a';
            int P = c - base;
            int C = (a * P + b) % 26;
            result += C + base;
        } 

        else 
            result += c;

    }

    return result;
}

//Function for Affine cipher (decryption)
string affineDecrypt(string text, int a, int b) 
{
    string result = "";
    int a_inv = modInverse(a, 26);

    if (a_inv == -1) 
        return "Error: No modular inverse found. Choose a different 'a'.";

    for (char c : text) 
    {
        if (isalpha(c)) 
        {
            char base = isupper(c) ? 'A' : 'a';
            int C = c - base;
            int P = (a_inv * (C - b + 26)) % 26;
            result += P + base;
        } 

        else 
            result += c;

    }

    return result;
}

//Function for Atbash cipher (encryption/decryption)
string atbashCipher(string text) 
{
    string result = "";
    for (char c : text) 
    {
        if (isalpha(c)) 
        {
            char base = isupper(c) ? 'A' : 'a';
            result += base + ('Z' - c);
        } 

        else 
            result += c;

    }

    return result;
}

//Function for Rail Fence cipher (encryption)
string railfenceEncrypt(string text, int key)
{
    string cipherText;
    char rail[key][text.length()];
    int row = 0, direction = 1;

    if (key <= 1)
        return text;

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
    }

    for (int i = 0; i < text.length(); i++)
    {
        rail[row][i] = text[i];
        row += direction;

        if (row == 0 || row == key - 1)
            direction = -direction;
    }

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            if (rail[i][j] != '\n')
                cipherText += rail[i][j];
        }
    }

    return cipherText;
}

//Function for Rail Fence cipher (decryption)
string railfenceDecrypt(string cipherText, int key)
{
    string plainText;
    char rail[key][cipherText.length()];
    int row = 0, direction = 1, index = 0;

    if (key <= 1)
        return cipherText;

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < cipherText.length(); j++)
            rail[i][j] = '\n';
    }

    for (int i = 0; i < cipherText.length(); i++)
    {
        rail[row][i] = '#';
        row += direction;

        if (row == 0 || row == key - 1)
            direction = -direction;
    }

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < cipherText.length(); j++)
        {
            if (rail[i][j] == '#' && index < cipherText.length())
                rail[i][j] = cipherText[index++];
        }
    }

    row = 0;
    direction = 1;

    for (int i = 0; i < cipherText.length(); i++)
    {
        plainText += rail[row][i];
        row += direction;

        if (row == 0 || row == key - 1)
            direction = -direction;
    }

    return plainText;
}

//Function for Vigenère cipher (key validation)
string generateVigenereKey(string text, string key)
{
    string extendedKey;
    int index = 0, klen = key.length();

    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            extendedKey += key[index % klen];
            index++;
        }

        else
            extendedKey += text[i];
    }

    return extendedKey;
}

//Function for Vigenère cipher (encryption)
string vigenereEncrypt(string text, string key)
{
    string cipherText;
    int shift;

    for (int i = 0; i < text.length(); i++)
    {
        char tchar = text[i];
        char kchar = key[i];

        if (tchar >= 'A' && tchar <= 'Z')
        {
            shift = kchar - 'A';
            char encryptedChar = (((tchar - 'A') + shift) % 26) + 'A';
            cipherText += encryptedChar;
        }

        else if (tchar >= 'a' && tchar <= 'z')
        {
            shift = kchar - 'A';
            char encryptedChar = (((tchar - 'a') + shift) % 26) + 'a';
            cipherText += encryptedChar;
        }

        else
            cipherText += tchar;
    }

    return cipherText; 
}

//Function for Vigenère cipher (decryption)
string vigenereDecrypt(string cipherText, string key)
{
    string text;
    int shift;

    for (int i = 0; i < cipherText.length(); i++)
    {
        char tchar = cipherText[i];
        char kchar = key[i];

        if (tchar >= 'A' && tchar <= 'Z')
        {
            shift = kchar - 'A';
            char decryptedChar = (((tchar - 'A') - shift + 26) % 26) + 'A';
            text += decryptedChar;
        }

        else if (tchar >= 'a' && tchar <= 'z')
        {
            shift = kchar - 'A';
            char decryptedChar = (((tchar - 'a') - shift + 26) % 26) + 'a';
            text += decryptedChar;
        }

        else
            text += tchar;
    }

    return text;
}

//Function for XOR cipher (encryption/decryption)
void encryptDecrypt(string& Input, char key) 
{
    for (size_t i = 0; i < Input.length(); i++) 
        Input[i] = Input[i] ^ key;
}

//Function for XOR ciopher (print ASCII values)
void printASCII(const string& Output) 
{
    for (char c : Output) 
        cout << static_cast<int>(c) << " ";
        
    cout << endl;
}
