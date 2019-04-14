/**
 * Kenneth Dorji
 * CISC 1110 - JAN1(20759)
 * Prof. C. Ziegler
 * Chapter 7 - Banking 
 */

#include <iostream>
#include <fstream>
using namespace std;

// Prototype Functions
void menu(ofstream &outfile);
int readAccts(int acctnum_array[], double balance_array[], int max_accts);
void printAccts(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile);
int findAcct(int acctnum_array[], int num_accts, int account);
void withdrawal(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile);
void deposit(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile);
void bankBalance(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile);
int newAcct(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile);
int deleteAcct(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile);

/** 
 * Function menu()
 * Input:
 *      outfile - Reference to the output file.  
 * Process: 
 *      Prints out a menu table for the transactions this function prints an option letting the user decide what
 *      kind of operation they want to use. 
 * Output: 
 *      Prints the operation to use. 
 */

void menu(ofstream &outfile)
{
    outfile << endl;
    outfile << "W - Withdrawal " << endl;
    outfile << "D - Deposit " << endl;
    outfile << "N - New Account " << endl;
    outfile << "B - Balance " << endl;
    outfile << "Q - Quit " << endl;
    outfile << "X - Delete Account \n " << endl;

    return;
}

/** 
 * Function readAccts()
 * Input:
 *      outfile - Reference to the output file.  
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      max_accts - The max number of accounts. 
 * Process: 
 *      Reads in the account and balance from the input file for each array of account and balance 
 * Output: 
 *      Returns count meaning the number of accounts and balances. 
 */

int readAccts(int acctnum_array[], double balance_array[], int max_accts)
{
    // Declaring and opening the input file to read customers information
    ifstream infile;
    infile.open("Asgmt7_Input.txt");

    int count = 0;

    infile >> acctnum_array[count];
    infile >> balance_array[count];

    while (!infile.eof() && count < max_accts)
    {
        count++;
        infile >> acctnum_array[count];
        infile >> balance_array[count];
    }

    infile.close();
    return count;
}

/** 
 * Function printAccts()
 * Input:
 *      outfile - Reference to the output file.  
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      max_accts - The max number of accounts. 
 * Process: 
 *      Reads in the account and balance from the input file for each array of account and balance 
 * Output: 
 *      Returns count meaning the number of accounts and balances. 
 */

void printAccts(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile)
{
    outfile << "\nDetails of Bank Account" << endl
            << endl;
    outfile << "Account\tBalance" << endl
            << endl;

    for (int index = 0; index < num_accts; index++)
    {
        outfile << acctnum_array[index];
        outfile << "\t$" << balance_array[index];
        outfile << endl;
    }
    return;
}

/** 
 * Function findAcct()
 * Input:
 *      acctnum_array[] - Reads in the account number from the input file
 *      num_accts - The number of accounts. 
 *      account - The account number. 
 * Process:
 *      Finds the account number through the array of the acctnum_array
 * Output: 
 *      Return index if account number is found else it returns -s if not found 
 */

int findAcct(int acctnum_array[], int num_accts, int account)
{
    for (int index = 0; index <= num_accts; index++)
    {
        if (acctnum_array[index] == account)
            return index;
    }
    return -1;
}

/** 
 * Function withdrawal()
 * Input:
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      num_accts - The number of accounts. 
 *      outfile - A reference to the output file  
 * Process:
 *      Goes throught the array of accounts and balances, finds the index of the account you want to withdraw from. 
 *      Checks if its valid to withdraw or invalid for error. 
 * Output: 
 *      Prints out the result. 
 */

void withdrawal(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile)
{
    int account = 0, index = 0;
    double amt_to_withdraw = 0;

    cout << "Type in the account number: ";
    cin >> account;

    // Finds the account number chosen
    index = findAcct(acctnum_array, num_accts, account);

    if (index == -1)
    {
        outfile << endl
                << "Transaction Requested: Withdrawal" << endl;
        outfile << "Error! Account number " << account << " does not exist" << endl;
    }
    else
    {
        cout << "Enter the amount for withdrawal: ";
        cin >> amt_to_withdraw;
    }

    if (amt_to_withdraw <= 0.00 || balance_array[index] < amt_to_withdraw)
    {
        outfile << endl
                << "Transaction Requested: Withdrawal" << endl;
        outfile << "Account number: " << account << endl;
        outfile << "Error " << amt_to_withdraw << " is an invalid amount" << endl;
    }
    else
    {
        outfile << endl
                << "Transaction Requested: Withdrawal" << endl;
        outfile << "Account number: " << account << endl;
        outfile << "Old Balance " << balance_array[index] << endl;
        balance_array[index] -= amt_to_withdraw;
        outfile << "New Balance: $" << balance_array[index] << endl;
    }
    return;
}

/** 
 * Function deposit()
 * Input:
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      num_accts - The number of accounts. 
 *      outfile - A reference to the output file  
 * Process:
 *      Goes throught the array of accounts and balances, finds the index of the account you want to deposit from. 
 *      Checks if its valid to deposit or invalid for error. 
 * Output: 
 *      Prints out the result. 
 */

void deposit(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile)
{
    int account = 0, index = 0;
    double amt_to_deposit = 0;

    cout << "Enter your account number: ";
    cin >> account;

    // Finds the user provided account number
    index = findAcct(acctnum_array, num_accts, account);

    if (index == -1)
    {
        outfile << endl
                << "Transaction Requested: Deposit" << endl;
        outfile << "Error! Account number " << account << " does not exist" << endl;
    }
    else
    {
        cout << "Enter the amount for deposit: ";
        cin >> amt_to_deposit;

        if (amt_to_deposit <= 0.00)
        {
            outfile << endl
                    << "Transaction Requested: Deposit" << endl;
            outfile << "Account number: " << account << endl;
            outfile << "Error " << amt_to_deposit << " is an invalid amount" << endl;
        }
        else
        {
            outfile << endl
                    << "Transaction Requested: Deposit" << endl;
            outfile << "Account number: " << account << endl;
            outfile << "Old Balance " << balance_array[index] << endl;
            outfile << "Amount to Deposit: " << amt_to_deposit << endl;

            balance_array[index] += amt_to_deposit;
            outfile << "New Balance: $" << balance_array[index] << endl;
        }
    }
    return;
}

/** 
 * Function bankBalance()
 * Input:
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      num_accts - The number of accounts. 
 *      outfile - A reference to the output file  
 * Process:
 *      Goes throught the array of accounts and balances, finds the index of the account you want to find the balance for. 
 *      Checks if account is valid for balance inquiry or invalid for error. 
 * Output: 
 *      Prints out the result. 
 */

void bankBalance(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile)
{
    int account = 0, index = 0;

    cout << "Enter Account number: ";
    cin >> account;

    // Finds the user provided account number
    index = findAcct(acctnum_array, num_accts, account);

    if (index == -1)
    {
        outfile << endl
                << "Transaction Requested: Balance Inquiry" << endl;
        outfile << "Error! Account number " << account << " does not exist" << endl;
    }

    else
    {
        outfile << endl
                << "Transaction Requested: Balance Inquiry" << endl;
        outfile << "Account Number: " << account << endl;
        outfile << "Current Balance " << balance_array[index] << endl;
    }
    return;
}

/** 
 * Function newAcct()
 * Input:
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      num_accts - The number of accounts. 
 *      outfile - A reference to the output file  
 * Process:
 *      Goes throught the array of accounts to check for exiting account, and if there is an existing account already then 
 *      it throws an error. Else it creates a new account.  
 * Output: 
 *      Prints a new account with balance of 0$. 
 */

int newAcct(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile)
{
    int new_accts = 0, index = 0;

    cout << "Enter new account number: " << endl;
    cin >> new_accts;

    // Finds the user provided account number
    index = findAcct(acctnum_array, num_accts, new_accts);

    if (index != -1)
        outfile << "This account already exists " << endl
                << endl;

    else
    {
        acctnum_array[num_accts] = new_accts;
        balance_array[num_accts] = 0;
        outfile << "Balance " << balance_array[index] << endl
                << endl;
        num_accts++;
    }
    return num_accts;
}

/** 
 * Function deleteAcct()
 * Input:
 *      acctnum_array[] - Reads in the account number from the input file
 *      balance_array[] - Reads in the balance number of the account from the input file
 *      num_accts - The number of accounts. 
 *      outfile - A reference to the output file  
 * Process:
 *      Goes throught the array of accounts to find the index of the account you want to delete and deletes it. 
 * Output: 
 *      Deletes the account you desire and prints it. 
 */

int deleteAcct(int acctnum_array[], double balance_array[], int num_accts, ofstream &outfile)
{
    int i = 0, index = 0, account = 0;

    cout << "Please enter the account you wish to delete: " << endl;
    cin >> account;

    // Finds the user provided account number
    index = findAcct(acctnum_array, num_accts, account);

    if (index != -1)
    {
        outfile << "Please enter the Account you wish to delete: ";
        outfile << account << endl;
        outfile << "Your account exists" << endl;
        outfile << "Account Information. " << endl;
        outfile << "Balance in account " << account << " is $" << balance_array[index] << endl;
        // for (i = index; i < num_accts - 1; i++)
        // {
        //     acctnum_array[i] = acctnum_array[i+1];
        //     balance_array[i] = balance_array[i+1];
        // }
        num_accts--;
        outfile << "Your account has been deleted" << endl
                << endl;
        printAccts(acctnum_array, balance_array, num_accts, outfile);
        outfile << endl;
    }

    else if (index == -1)
    {
        outfile << "This account does not exist.\n"
                << endl;
    }
    return num_accts;
}

/** 
 * Function main()
 * Input:
 *      Calls all the functions in the outfile.  
 * Process:
 *      Reads in the functions.
 * Output: 
 *      Prints out the information of the bank accounts along with what option you want ot choose
 */

int main()
{
    // Creating an outfile file
    ofstream outfile;
    outfile.open("Asgmt7_Output.txt");

    // Setting up decimal precision
    outfile.setf(ios::fixed, ios::floatfield);
    outfile.precision(2);
    outfile << " Kenneth Dorji\n CISC 1110 - JAN1(20759)\n Prof. C. Ziegler\n Chapter 7 - "
               "Bank Accounts(Assignment 7)\n"
            << endl;
    const int MAX_NUM = 50;

    int acctnum_array[MAX_NUM];
    double balance_array[MAX_NUM];
    int num_accts;

    num_accts = readAccts(acctnum_array, balance_array, MAX_NUM);

    char choice;
    bool not_done = true;

    menu(outfile);

    do
    {
        cout << "\nSelect one of the following" << endl;
        cin >> choice;

        switch (choice)
        {
        case 'W':
        case 'w':
            withdrawal(acctnum_array, balance_array, num_accts, outfile);
            break;

        case 'D':
        case 'd':
            deposit(acctnum_array, balance_array, num_accts, outfile);
            break;

        case 'B':
        case 'b':
            bankBalance(acctnum_array, balance_array, num_accts, outfile);
            break;

        case 'N':
        case 'n':
            num_accts = newAcct(acctnum_array, balance_array, num_accts, outfile);
            break;

        case 'X':
        case 'x':
            num_accts = deleteAcct(acctnum_array, balance_array, num_accts, outfile);
            break;

        case 'Q':
        case 'q':
            not_done = false;
            printAccts(acctnum_array, balance_array, num_accts, outfile);
            break;

        default:
            outfile << choice << " is invalid" << endl
                    << endl;
            break;
        }
    }

    while (not_done);
    outfile.close();
    return 0;
}
