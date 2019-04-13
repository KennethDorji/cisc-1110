#include <iostream>
#include <fstream>
using namespace std;

/* 
    Function prototype. Unlike its functions the functions protoptupe must end with a semi colon and come before its actual
    function and int main() function to avoid compilation error. 

*/
int validGroup(int, int, int, ofstream &);
void oneGameScore(int, ofstream &);
int threeGameAvgScore(int, int, int);

/**  Function validGroup()
 *   Input:
 *      a - Receives score1 of the Bowling. 
 *      b - Receives score2 of the Bowling. 
 *      c - Receives score3 of the Bowling. 
 *   Process: 
 *      Evalutes the group(score1, score2 abd score3) validity. 
 *   Output: 
 *      Prints either "The group is valid." or "The score and mentions that the group is invalid."
 */

int validGroup(int a, int b, int c, ofstream &outfile)
{
    int valid_group = 0; 

    if (a < 0 || a > 300)
    {
        valid_group = 1;
        outfile << endl << a << " is an invalid score. Therefore the group is invalid."; 
    }
    if (b < 0 || b > 300)
    {
        valid_group = 1;
        outfile << endl << b << " is an invalid score. Therefore the group is invalid."; 
    }
    if (c < 0 || c > 300)
    {
        valid_group = 1;
        outfile << endl << c << " is an invalid score. Therefore the group is invalid."; 
    }
    outfile << endl; 
    
    return (valid_group); 
}

/**
 *  Function oneGameScore()
 *  Input: 
 *      d - Receives score1 of the bowling. Followed by score 2 and 3. 
 *  Process: 
 *      Evaluates the scores of its performance level. 
 *  Output: 
 *      Prints the score and along its performance remarks. 
 */

void oneGameScore(int d, ofstream &outfile)  
{
    if (d >= 250)
        outfile << "Score " << d << ": Professional Game." << endl; 
    else if (d >= 200)
        outfile << "Score " << d << ": Excellent Game." << endl; 
    else if ( d >= 140)
        outfile << "Score " << d << ": Very Good Game." << endl; 
    else if ( d >= 100)
        outfile << "Score " << d << ": Good Game." << endl; 
    else if ( d >= 50)
        outfile << "Score " << d << ": Poor Game." << endl; 
    else 
        outfile << "Score " << d << ": Horrible Game." << endl; 

    return; 
}

/**
 * Function threeGameAvgScore()
 * Input: 
 *      d - Receives score1 of the bowling. 
 *      e - Receives score2 of the bowling. 
 *      f - Receives score3 of the bowling. 
 * Process: 
 *      Computes the average score for score1, score2 and score3. 
 * Output: 
 *      Returns the average score to the main. 
 */

int threeGameAvgScore(int e, int f, int g)
{
    int average_score = (e + f + g) / 3; 
    return (average_score); 
}

int main()
{
    // Directing the cin to a file. 
    ifstream cin("Asgmt4_Input.txt"); 

    // Declaring and opening a output file. 
    ofstream outfile ("Asgmt4_Output.txt"); 

    // Uncomment below line to debug the program onto a screen as output. 
    // ofstream outfile ("/dev/stdout"); 

    // Output to print my name, class, prof and assignment #. 
    outfile << " Kenneth Dorji\n CISC 1110 - JAN1(20759)\n Prof. C. Ziegler\n Chapter 5 - "
                "Bowling Scores(Assignment 4)" << endl << endl; 
    
    // All the variables need for the main functions are declared here. 
    int score1 = 0, score2 = 0, score3 = 0, group_validity = 0, average = 0, group_processed = 0, no_validGroup = 0, 
        no_invalidGroup = 0; 
    
    cout << "Enter the first Bowling Score: "; 
    cin >> score1; 

    while (score1 != -1)
    {
        cout << "Enter the second Bowling Score: "; 
        cin >> score2; 
        cout << "Enter the third Bowling Score: "; 
        cin >> score3; 

        group_processed++; // The no of Total Group processed count increment. 

        // Calling the function named validGroup. 
        group_validity = validGroup(score1, score2, score3, outfile); 

        if( group_validity == 0)
        {
            // Calling the function oneGameScore and sending the scores one at a time.  
            oneGameScore(score1, outfile); 
            oneGameScore(score2, outfile); 
            oneGameScore(score3, outfile); 
        
            // Calling the function named threeGameAvgScore. 
            average = threeGameAvgScore(score1, score2, score3); 
            outfile << "The average score is " << average << ". "; 

            /** Calling the function named oneGameScore and sending the return of threeGameAvgScore function to oneGameScore
             *  function ot oneGameScore function to compte the average performance. 
            */
            oneGameScore(average, outfile); 

            cout << endl << endl << endl; 

            no_invalidGroup++; // The no of Valid Group count increment. 

            cout << "Enter the first Bowling Score: "; 
            cin >> score1; 
        }

        else
        {
            no_invalidGroup++;  // The no of Invalid Group count increment. 

            cout << "Enter the first Bowling Score: ";
            cin >> score1; 
        }
    }
    outfile << endl << "The total no of Groups processed is " << group_processed << endl; 
    outfile << "The no of valid groups processed is " << no_validGroup << endl; 
    outfile << "The no of invalid groups processed is " << no_invalidGroup << endl; 
    outfile << "\n\nProgram Ended..." << endl; 

    cin.close(); 
    outfile.close(); 
    return 0;
}