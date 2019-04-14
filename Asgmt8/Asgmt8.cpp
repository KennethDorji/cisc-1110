/** 
 * Kenneth Dorji 
 * CISC 1110 - Jan1(20759)
 * Prof. C. Ziegler 
 * Donation Assignment 
 */

#include <iostream>
#include <fstream>
using namespace std;

// Prototype Functions
int readInput(int idNumbers[], int donations[], ofstream &outfile);
void print(int idNumbers[], int donations[], int num, ofstream &outfile);
void idSort(int idNumbers[], int donations[], int num, ofstream &outfile);
void donationSort(int idNumbers[], int donations[], int num, ofstream &outfile);

/** 
 * Function readInput()
 * Input:
 *      idNumbers - Specifies the id numbers. 
 *      donations - Specifies the amount of donations
 *      outfile - Reference to the output file.  
 * Process: 
 *      Reads in the input file for idNumbers and donations.  
 * Output: 
 *      Prints out the data contained in the input file and prints out the original input. 
 */

int readInput(int idNumbers[], int donations[], ofstream &outfile)
{
    // Declaring the opening the input file to read in Id and Donations amount
    ifstream infile("Asgmt8_Input.txt");

    int num = 0;

    // Reads in the input file
    infile >> idNumbers[num];
    infile >> donations[num];

    while (!infile.eof())
    {
        num++;
        infile >> idNumbers[num];
        infile >> donations[num];
    }
    outfile << "\n***********************\nThe Original Data is:\n";
    outfile << "***********************\n";

    print(idNumbers, donations, num, outfile);
    outfile << endl;

    return num;
}

/** 
 * Function readInput()
 * Input:
 *      idNumbers - Specifies the id numbers. 
 *      donations - Specifies the amount of donations
 *      num - Iterator number for array index of idNumbers and donations. 
 *      outfile - Reference to the output file.  
 * Process: 
 *      Prints out the table with the list of Id and donations. 
 * Output: 
 *      Prints out the result of the function 
 */

void print(int idNumbers[], int donations[], int num, ofstream &outfile)
{
    outfile << "\nID\t\tDonation " << endl;

    for (int i = 0; i < num; i++)
    {
        outfile << "\n"
                << idNumbers[i] << "\t\t"
                << "$" << donations[i];
    }

    return;
}

/** 
 * Function idSort()
 * Input:
 *      idNumbers - Specifies the id numbers. 
 *      donations - Specifies the amount of donations
 *      num - Iterator number for array index of idNumbers and donations. 
 *      outfile - Reference to the output file.  
 * Process: 
 *      Sorts the id numbers in numerical order while the donation corresponds to it. Calls the print() function. 
 * Output: 
 *      Prints out the header. 
 */

void idSort(int idNumbers[], int donations[], int num, ofstream &outfile)
{
    int id = 0, donation = 0;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (idNumbers[j] > idNumbers[i])
            {
                id = idNumbers[j];
                idNumbers[j] = idNumbers[i];

                donation = donations[j];
                donations[j] = donations[i];

                int k = 0;

                for (int k = i; k > j; k--)
                {
                    idNumbers[k] = idNumbers[k - 1];
                    donations[k] = donations[k - 1];
                }
                idNumbers[k + 1] = id;
                donations[k + 1] = donation;
            }
        }
    }
    outfile << "\n***********************\nThe Sorted Id Data is: \n";
    outfile << "************************\n";
    print(idNumbers, donations, num, outfile);
    outfile << endl;

    return;
}

/** 
 * Function donationSort()
 * Input:
 *      idNumbers - Specifies the id numbers. 
 *      donations - Specifies the amount of donations
 *      num - Iterator number for array index of idNumbers and donations. 
 *      outfile - Reference to the output file.  
 * Process: 
 *      Sorts the donation in numerical order while the id's correspond to it. Finally it calls the print function();  
 * Output: 
 *      Prints out the header. 
 */

void donationSort(int idNumbers[], int donations[], int num, ofstream &outfile)
{
    int id = 0, donation = 0;

    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (donations[j] > donations[i])
            {
                id = idNumbers[j];
                idNumbers[j] = idNumbers[i];

                donation = donations[j];
                donations[j] = donations[i];

                int k = 0;

                for (int k = i; k > j; k--)
                {
                    idNumbers[k] = idNumbers[k - 1];
                    donations[k] = donations[k - 1];
                }
                idNumbers[k + 1] = id;
                donations[k + 1] = donation;
            }
        }
    }
    outfile << "\n***********************\nThe Sorted Donation Data is: \n";
    outfile << "************************" << endl;
    print(idNumbers, donations, num, outfile);

    return;
}

int main()
{
    ofstream outfile("Asgmt8_Output.txt");

    // Output to print my information above on the ouput.
    outfile << " Kenneth Dorji\n CISC 1110 - JAN1(20759)\n Prof. C. Ziegler\n Chapter 9 - "
               "Donations(Assignment 8)\n"
            << endl;

    // Creating all the data variables for the program.
    const int ARRAY_INDEX = 50;
    int idNumbers[ARRAY_INDEX];
    int donations[ARRAY_INDEX];
    int num = 0;

    num = readInput(idNumbers, donations, outfile);

    idSort(idNumbers, donations, num, outfile);
    donationSort(idNumbers, donations, num, outfile);

    outfile << "\n\n\nProgram Exit Normally...";

    return 0;
}
