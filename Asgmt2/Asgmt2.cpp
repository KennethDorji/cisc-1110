#include <iostream> 
#include <cmath> 
#include <fstream> 
using namespace std; 

int main () 
{
    double x = 0, y = 0, y_closest = 0, y_closest_x = 0; 
    int negNum = 0, posNum = 0, nulNum = 0; 

    //Declearing the outfile. 
    ofstream outfile; 
    // Now naming an output file and opening it after having declared it above. 
    outfile.open("Asgmt2_Output.txt"); 

    //Uncomment below for outputting the program on screen for bebugging purposes. 
    //outfile.open("/dev/stdout"); 

    /* 
       These 2 lines below are for decimal precision has to be converted to outfile 
       from cout and it has to be written after declaring the outfile. Then only 
       the code will work. 
    */
    outfile.setf(ios::fixed,ios::floatfield); 
    outfile.precision(2); 

    outfile << "\n\nProgram has just begun and below we have Assignment 2 output"
            << endl << endl; 
    outfile << "\n\t\t\tTable of Contents" << endl << endl; 
    outfile << "\t X" << "\t\t Y" << "\t\t\t  Statement" << endl << endl; 

    for( x = -3; x <= 4; x = x + 0.5) 
    {
        y = (9*x*x*x - 27*x*x - 4*x + 12)/(sqrt(3*x*x + 1) + abs(5 - x*x*x*x)); 
        /*
            This width precision has to be also converted into outfile from 
            cout and inorder for this code to work the width no of the first 
            outfile code here its 8 must be made bigger if it doesnt work since
            the 3 inplace of 8 doesnt make the code work where it doesnt align
            even a bit
        */
       outfile.width(12); 
       outfile << x; 
       outfile.width(16); 
       outfile << y; 

       if ( y < 0 )
       {
           outfile << "\t\t\tY is NEGATIVE" << endl; 
           negNum++; 
       }
       else if ( y == 0 )
       {
           outfile << "\t\t\tY is ZERO" << endl; 
           nulNum++; 
       }
        else //( y > 0 )
        {
            outfile << "\t\t\tY is POSITIVE" << endl; 
            posNum++; 
        }
        if ( y > y_closest )
        {
            y_closest = y; 
            y_closest_x = x; 
        }
    }
        outfile << "\n\n1) The Y value closest to 10 is " << y_closest << 
                " and the X value closest to Y value is " << y_closest_x << 
                endl; 
        outfile << endl << "2) The formula yields " << negNum << " negative " 
                << nulNum << " zero and " << posNum << " positive values for y."
                << endl; 
        outfile << "\n\nThe table has completed. \n\nProgram exit." << 
                endl << endl; 
        
        /* Closing the output file after opening it for security reasons, especially 
           in networking environment. 
        */ 
       outfile.close(); 

       return 0; 
}
