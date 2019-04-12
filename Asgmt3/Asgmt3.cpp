#include <iostream> 
#include <cmath> 
#include <fstream> 
using namespace std; 

int main()  
{
    int id = 0, right_ans = 0, wrong_ans = 0, omitted = 0, answered = 0, grade = 0, total_students = 0, 
        highest_grade = 0, student_grade = 0, student_percentage = 0; 
    double correct_ans_percentage = 0, best_percentage = 0; 

    /*
        Declare the ifstream cin(input) of below for redirecting the cin to a file instead of inputting from 
        the keyboard but i'll need to change the infile to cin. All the user input must be cin and at the end 
        need to add cin.close(); or uncomment it if its there. The ifstream infile ("/dev/stdin") should remain 
        the way it is coz ifstream cin ("/dev/stdin") doesn't compile and there is example of it in the class
        notes. 
    */
    ifstream cin("Asgmt3_Input.txt"); 

    //uncomment below for outputting the program on screen for debugging purposes.
    //ifstream infile("/dev/stdin"); 

    //declaring the outfile(output file) and then opening it. 
    ofstream outfile("Asgmt3_Output.txt"); 

    //uncomment below for outputting the program on the screen for debegging purposes. 
    //ofstream outfile("/dev/stdout"); 

    outfile << "Kenneth Dorji" << endl << "CISC 1110 - Jan1(20759)\n" << "Prof. C. Ziegler\n" << 
            "Chapter 3: Assignment" << endl << endl; 
    outfile << "_____________________________________________________________________________________________"
            "____________________" << endl; 
    outfile << "\t\t\t\t\t\t\tStudent Exam Statistics" << endl; 
    outfile << "_____________________________________________________________________________________________"
            "____________________" << endl;
    outfile << "ID  RIGHT  WRONG  Answered  Omitted  Percentage  Grade   \tMessage \t\tRemarks" << endl << endl; 
    cout << "Enter your ID number: "; 
    cin >> id; 

    /* These 2 line below for decimal precision has to be converted to outfile from cout and it has to be
       written after declaring the outfile. Then only the code will work. 
    */
    outfile.setf(ios::fixed,ios::floatfield); 
    outfile.precision(3); 

    while ( id != -1) 
    { 
        cout << "Enter the number of right answers: "; 
        cin >> right_ans; 
        cout << "Enter the number of wrong answers: ";
        cin >> wrong_ans; 

        total_students++; 

        if ( right_ans + wrong_ans > 50 )
            outfile <<"\nError: The student answered more than 50 questions." << endl; 
    
        else 
        {
            answered = right_ans + wrong_ans; 
            omitted = 50 - answered; 

            if(answered ==0) 
            { 
                outfile <<"\nError: The total no of question answered was 0. So correct answer percentage " 
                        << "cannot be divided by zero. Since anything divided by 0 is undefined." << endl; 
            }
            else if(answered != 0)  
            {
                correct_ans_percentage = double(right_ans)/answered; 
                if(correct_ans_percentage > best_percentage)    
                {
                    best_percentage = correct_ans_percentage; 
                    student_percentage = id; 
                }
                grade = right_ans * 2; 
                if (grade > highest_grade)  
                {
                    highest_grade = grade; 
                    student_grade = id; 
                }
                /* This width precision has to be also converted into outfile from cout and in order for this 
                   code to work the width no of the first outfile code here its 8 must be made bigger if it 
                   doesn't work since the 3 inplace of 8 doesn't make the code work where it doesn't align 
                   even a bit                 
                */
               outfile.width(2); 
               outfile << id; 
               outfile.width(5); 
               outfile << right_ans; 
               outfile.width(7); 
               outfile << wrong_ans; 
               outfile.width(8); 
               outfile << answered; 
               outfile.width(10); 
               outfile << omitted; 
               outfile.width(12); 
               outfile << correct_ans_percentage; 
               outfile.width(8); 
               outfile << grade; 

               if (right_ans > wrong_ans) 
               {
                   outfile.width(25);
                   outfile << "More right answers"; 
               }
               else if (right_ans == wrong_ans) 
               {
                   outfile.width(14); 
                   outfile << "Same No"; 
               }
               else 
               {
                   outfile.width(25); 
                   outfile << "More wrong answers"; 
               }
               
               if (omitted >= 14)   
               {
                   if (right_ans > wrong_ans || wrong_ans > right_ans)  
                   {
                       outfile.width(34); 
                       outfile << "Omitted 10/more questions."; 
                   }
                   else
                   {
                       outfile.width(45); 
                       outfile << "Omitted 10/more questions."; 
                   }
               }
            }
            outfile << endl << endl; 
                   
        }
        cout << "\nEnter your ID number; "; 
        cin >> id; 
    }


    outfile << endl << "The total no of students in the class is " << total_students << endl << endl; 
    outfile << "Id no " << student_percentage << " has the best correct answer percentage." << endl << endl; 
    outfile << "Id no " << highest_grade << " has the highest grade.\n\n\n" << endl; 
    outfile << "EXIT..." << endl << endl; 

    //Close the output file after opening it for security reasons, especially in networking environment. 
    outfile.close(); 
    //Uncomment below for debugging cin. 
    //infile.close();
    cin.close();  //Uncomment when inputting the values from a file. 

    return 0; 
}