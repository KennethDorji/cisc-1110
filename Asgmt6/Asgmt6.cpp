/**
 * Kenneth Dorji
 * CISC 1110 - JAN1(20759)
 * Prof. C. Ziegler
 * Chapter 6 - Calculator
 */

#include <iostream> 
#include <fstream> 
using namespace std;

// Prototype Functions
void readData (int &n, int vals[], ofstream &outfile); 
int countZeros (int &n, int vals[]); 
void append (int &n, int vals[], ofstream &outfile); 

/** 
 * Function readData()
 * Input:
 *      n - Reads in a value of amount of numbers that will be in the array.
 *      vals - Reads in the numbers that will be in the array of vals 
 *      outfile - Reference to the output file.  
 * Process: 
 *      Reads in the value for n and the amount of numbers that have been read in for vals. 
 * Output: 
 *      Reads the arrays from the input file and prints them out. 
 */

void readData (int &n, int vals[], ofstream &outfile)
{
    // Creating an input file
    ifstream infile; 
    infile.open("Asgmt6_Input.txt");  // Calling the infile. 

    // Reading the  value of n 
    infile >> n; 

    // Reading the numbers 
    for (int i = 0; i < n; i++)
        infile >> vals[i]; 
    outfile << "Input Values: " << endl; 
    
    for (int i = 0; i < n; i++)
        outfile << vals[i] << " ";  // Prints the infile values
    outfile << endl; 

    infile.close(); 
    return; 
} 

/** 
 * Function countZero()
 * Input:
 *      n - Reads in a value of amount of numbers that will be in the array.
 *      vals - Reads in the numbers that will be in the array of vals 
 * Process: 
 *      Counts the amount of zero that are in the array of vals
 * Output: 
 *      Returns amount of zero meaning the amount of zero that were counted.  
 */

int countZeros (int &n, int vals[]) 
{
    int amtOf_Zero = 0;   // Setting the variable to 0

    for(int index = 0; index < n; index++)  
    {
        // Checks whether index is zero to count zero 
        if (vals[index] == 0)
            amtOf_Zero++; 
    }

    return amtOf_Zero; 
    
}

/** 
 * Function apphend()
 * Input:
 *      n - Reads in a value of amount of numbers that will be in the array.
 *      vals - Reads in the numbers that will be in the array of vals 
 *      outfile - Reference to the outfile file
 * Process: 
 *      Reads in new numbers that adds onto the array vals 
 *      
 * Output: 
 *      Prints out the new values added. 
 */

void append (int &n, int vals[], ofstream &outfile) 
{
    int add; 
    cout << "How many numbers would you like to add" << endl; 
    cin >> add; 
    // outfile << add << endl; 

    cout << endl << "What are the numbers" << endl; 

    // Adding new numbers 
    for (int i = n; i < n + add; i++)
    {
        cin >> vals[i]; 
        outfile << vals[i] << " "; 
    }
    outfile << endl << endl; 
    n = n + add; 

    return; 
}

int main()
{
    // Creating an output file 
    ofstream outfile; 
    outfile.open("Asgmt6_Output.txt"); 

    // Output to print my name, class, prof and howework no. 
    outfile << " Kenneth Dorji\n CISC 1110 - JAN1(20759)\n Prof. C. Ziegler\n Chapter 6 - "
                "Count Zero(Assignment 6)\n\n" << endl << endl; 
    int n = 0; 
    int vals[100]; 
    int zero; 

    readData(n, vals, outfile); 
    zero = countZeros(n, vals); 

    outfile << "\nThere are " << zero << " zeros" << endl << endl; 
    outfile << "New numbers are: " << endl; 
    append(n, vals, outfile); 
    outfile << "Updated Value is: " << endl; 

    for(int i = 0; i < n; i++)
        outfile << vals[i] << " "; 

    outfile << endl; 

    //  Recounts the zeros a second time 
    zero = countZeros(n, vals); 

    outfile << "\nNow there are " << zero << " zeros" << endl; 
    outfile << "\n\n\n\nProgram exit..."; 

    outfile.close(); 
    return 0;  

}




    
    





