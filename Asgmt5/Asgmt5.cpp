/**
 * Kenneth Dorji
 * CISC 1110 - JAN1(20759)
 * Prof. C. Ziegler
 * Chapter 6 - Calculator
 */
#include <iostream> 
#include <fstream> 
#include <cmath> 
using namespace std; 

//Declaring all the function prototype. 
void menu();
void add(ofstream &, ifstream &); 
void subtract(ofstream &, ifstream &); 
void multiply(ofstream &, ifstream &); 
void division(ofstream &, ifstream &); 
void remainder(ofstream &, ifstream &); 
void avg(ofstream &, ifstream &); 
void max(ofstream &, ifstream &); 
void min(ofstream &, ifstream &); 
void sq(ofstream &, ifstream &); 

/** 
 * Function menu()
 * Input:
 *      None. 
 * Process: 
 *      None
 * Output: 
 *      Prints the functions menu on the screen. 
 */

void menu()
{
    cout << "\nEnter + for addition of two numbers." << endl; 
    cout << "Enter - for addition of two numbers." << endl; 
    cout << "Enter * for addition of two numbers." << endl; 
    cout << "Enter / for addition of two numbers." << endl; 
    cout << "Enter % for addition of two numbers." << endl; 

    cout << "A represents the average of two numbers." << endl; 
    cout << "X represents the maximum of two numbers." << endl; 
    cout << "M represents the minimum of two numbers." << endl; 
    cout << "S represents the square of two numbers." << endl; 
    cout << "Q indicated the user wants to quit the program." << endl << endl; 

    return; 
}

/**
 * Function add()
 * Input: 
 *      outfile - A reference to outfile file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Addition
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void add(ofstream &out1, ifstream &cin)
{
    int add1 = 0, add2 = 0, add_value = 0; 

    cout << "Please enter two interfers for addition: "; 
    cin >> add1 >> add2; 
    
    add_value = add1 + add2; 

    out1 << "Operation: Addition\n" << "Integer 1: " << add1 << "\nInteger 2: " << add2 << "\nSum: " << add_value << endl << endl; 
    
    return; 
}

/** 
 * Function subtract()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Subtraction. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void subtract (ofstream &out2, ifstream &cin)
{
    int minuend = 0, subtrahend = 0, difference = 0; 

    cout << "Please enter an integer for minuend: "; 
    cin >> minuend; 
    cout << "Please enter an integer for subtrahend: "; 
    cin >> subtrahend; 

    difference = minuend - subtrahend; 

    out2 << "Operation: Subtraction\n" << "Integer 1: "<< minuend << "\nInteger 2: " << subtrahend << "\nDifference: " << 
         difference << endl << endl;

    return; 
}

/** 
 * Function multiply()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Multiplication. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void multiply(ofstream &out3, ifstream &cin)
{
    int num7 = 0, num8 = 0, product = 0; 

    cout << "Please enter two integer for multiplication: "; 
    cin >> num7 >> num8; 

    product = num7 * num8; 

    out3 << "Operation: Multiplication\n" << "Integer 1: "<< num7 << "\nInteger 2: " << num8 << "\nProduct: " << product << 
            endl << endl;

    return; 
}

/** 
 * Function division()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Division. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void division (ofstream &out4, ifstream &cin)
{
    int divisor = 0, dividend = 0, quotient = 0; 

    cout << "Please enter an integer for division: "; 
    cin >> dividend; 
    cout << "Please enter an integer for divisor: "; 
    cin >> divisor; 

    quotient = dividend - divisor; 

    out4 << "Operation: Division\n" << "Integer 1: "<< divisor << "\nInteger 2: " << dividend << "\nQuotient: " 
         << quotient << endl << endl;

    return; 
}

/** 
 * Function remainder()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Remainder. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void remainder (ofstream &out5, ifstream &cin)
{
    int divisor = 0, dividend = 0, remainder = 0; 

    cout << "Please enter an integer for division: "; 
    cin >> dividend; 
    cout << "Please enter an integer for divisor: "; 
    cin >> divisor; 

    remainder = abs(dividend % divisor); 

    out5 << "Operation: Modulus\n" << "Integer 1: "<< divisor << "\nInteger 2: " << dividend << "\nRemainder: " 
         << remainder << endl << endl;

    return; 
}

/** 
 * Function avg()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Average. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void avg(ofstream & out6, ifstream &cin)
{
    int num1 = 0, num2 = 0, average = 0; 

    cout << "Please enter two integer for average calculation: "; 
    cin >> num1 >> num2; 

    average = (num1 + num2)/2; 

    out6 << "Operation: Average\n" << "Integer 1: "<< num1 << "\nInteger 2: " << num2 << "\nAverage: " << average << 
            endl << endl;

    return; 
}

/** 
 * Function max()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Maximum value. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void max(ofstream & out7, ifstream &cin)
{
    int num3 = 0, num4 = 0, maximum = 0; 

    cout << "Please enter two integer for maximum calculation: "; 
    cin >> num3 >> num4; 

    if (num3 == num4)
        out7 << "Operation: Maximum\n" << "Integer 1: "<< num3 << "\nInteger 2: " << num4 << "\nMaximum: None. Since both " 
             "integers have the same value." << endl << endl;
    else if (num3 > num4)
    {
        maximum = num3; 
        out7 << "Operation: Maximum\n" << "Integer 1: "<< num3 << "\nInteger 2: " << num4 << "\nMaximum: " << maximum 
             << endl << endl;
    }
    else 
    {
        maximum = num4; 
        out7 << "Operation: Maximum\n" << "Integer 1: "<< num3 << "\nInteger 2: " << num4 << "\nMaximum: " << maximum 
             << endl << endl;
    }

    return; 
}

/** 
 * Function min()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Minimum value. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void min(ofstream & out7, ifstream &cin)
{
    int num3 = 0, num4 = 0, minimum = 0; 

    cout << "Please enter two integer for minimum calculation: "; 
    cin >> num3 >> num4; 

    if (num3 == num4)
        out7 << "Operation: Minimum\n" << "Integer 1: "<< num3 << "\nInteger 2: " << num4 << "\nMinimum: None. Since both " 
             "integers have the same value." << endl << endl;
    else if (num3 > num4)
    {
        minimum = num4; 
        out7 << "Operation: Minimum\n" << "Integer 1: "<< num3 << "\nInteger 2: " << num4 << "\nMinimum: " << minimum 
             << endl << endl;
    }
    else 
    {
        minimum = num3; 
        out7 << "Operation: Minimum\n" << "Integer 1: "<< num3 << "\nInteger 2: " << num4 << "\nMinimum: " << minimum 
             << endl << endl;
    }

    return; 
}

/** 
 * Function sq()
 * Input: 
 *      outfile - A reference to a output file. 
 *      cin - A reference to a input file. 
 * Process: 
 *      Computes Square. 
 * Output: 
 *      Prints the Operation, Two user input integer and the computed adition value. 
 */

void sq(ofstream & outfile, ifstream &cin)
{
    int sq_Num = 0, square = 0; 

    cout << "Please enter an integer for squaring: "; 
    cin >> sq_Num; 

    square = sq_Num * sq_Num; 

    outfile << "Operation: Average\n" << "Integer: "<< sq_Num << "\nSquare: " << square << endl << endl;

    return; 
}

int main ()
{
    // Directing cin to a file
    ifstream cin("Asgmt5_Input.txt"); 

    // Declaring and then direting outfile to a file
    ofstream outfile("Asgmt5_Output.txt"); 

    // Output to print information. 
    outfile << " Kenneth Dorji\n CISC 1110 - JAN1(20759)\n Prof. C. Ziegler\n Chapter 6 - "
                "Calculator(Assignment 5)" << endl << endl; 

    char choice; 
    bool not_done = true; 

    do 
    { 
        menu(); // Calling the menu function. 

        cout << "Make a selection: "; 
        cin >> choice; 

        switch(choice)
        {
            case 'Q':
            case 'q': 
                not_done = false; 
                break; 
            // Need to put outfile within the parameter of the function for redirecting the output to the outfile. 
            case '+': 
                add(outfile, cin); 
                break; 

            case '-': 
                subtract(outfile, cin); 
                break;

            case '*': 
                multiply(outfile, cin); 
                break;

            case '/': 
                division(outfile, cin);
                break; 

            case '%': 
                remainder(outfile, cin); 
                break;
            
            case 'A':
            case 'a': 
                avg(outfile, cin); 
                break; 

            case 'X':
            case 'x': 
                max(outfile, cin); 
                break; 

            case 'M':
            case 'm': 
                min(outfile, cin);
                break;
                
            case 'S':
            case 's': 
                sq(outfile, cin);
                break; 

            /** Default clause helps to catch the error values that a user may have inputted by error etc. For instance if 
             *  we ask user to input no 2 to 5. There is possibility of user inputting no that's not within the range 2 -5 
             *  for instance like 6. So that no is caught by default. 
             */
            default: 
                cout << "\n\nThe entered value " << choice << "wasn't within the displayed menu." << endl << endl; 
        }
    }

    while(not_done); 
        outfile << endl << "User entered '" << choice << "' to quit the program. \nExit..." << endl; 

    cin.close(); 
    outfile.close(); 
    return 0; 

}


