#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a1[100], a2[100];

    cout << "Enter Your First Name: ";
    cin.getline(a1, 100) ;

    cout << "Enter Your Last Name: " ;
    cin.getline(a2, 100) ;

    strcat(a1, a2);

    cout << "Full Name =  "  << a1 << endl;


    return 0;
}
