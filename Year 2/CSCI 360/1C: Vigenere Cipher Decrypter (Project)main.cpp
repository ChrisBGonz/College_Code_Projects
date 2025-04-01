#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i;
    string key, VE_Encr, VE_Decr;
    
    cout << "Please enter the key (this will be used to decrypt the message): ";
    cin >> key; //It should be SZSOB
    
    cout << "Enter the message to decrypt: ";
    cin >> VE_Encr;
    /* Please copy and paste the following:
     LGWDSGIWQUYTLSOTDJUFTNGYPXOAPZKBGHUZDEDIAKDHIARWPPGJAGGGQLVFMRWCGSMQCOWZFMXZDJSBLMGQPKSSBEOHLVBDLGGUFNJSTLQAQUANFGXZZLGPWUWFZGTEOZUNHMJLFAJFASSKBQNJFFMRWWUMMVSSLGWHFJLKCGLGWDSGIWQUYTLSOTDJUMABWBTWHFQMMCWRXASZHIARWPPGJGFPFKABFSSOKXYTLSOTDJUPJFLWUDDHWUGODODWRSIUZNJGDGSLVFEOZWMDQWZFSRWRBLDBIOWDTCPCKSBHMZYSFFFDWTZBZOSSBLSSKDLSOUNVWOYZKQJARLOSLNXHIARHFPBDUHHMSWBCWQYSCGNCDJLGWGFVHYWUKBSAFXQGATUNLHIWLHVJDKKS
     
     */
    
    for (i = 0; i < VE_Encr.size(); i++)
    {
        VE_Decr += ((VE_Encr[i] - 'A') - (key[(i % 5)] - 'A') + 26) % 26 + 'A';
    }
    
    cout << "\nDecrypted message is " << VE_Decr << endl;
    
    return 0;
}
