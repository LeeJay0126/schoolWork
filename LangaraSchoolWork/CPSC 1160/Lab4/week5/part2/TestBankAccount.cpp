#include "BankAccount.h"
#include <iostream>
using   namespace std;

// g++ BankAccount.cpp TestBankAccount.cpp -o a.out

int main( )
{
    BankAccount account1(1345.52, 2.3), account2;
    cout << "account1 initialized as follows:\n";
    account1.output( );
    cout << "account2 initialized as follows:\n";
    account2.output( );

    account1 = BankAccount(999, 99, 5.5);
    cout << "account1 reset to the following:\n";
    account1.output( );

    cout << "Enter new data for account 2:\n";
    account2.input( );
    cout << "account2 reset to the following:\n";
    account2.output( );

    account2.update( );
    cout << "In one year account2 will grow to:\n";
    account2.output( );

    return 0;
}

