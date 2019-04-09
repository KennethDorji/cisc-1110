/*              Homework – Chapter 1 – Print 1 to 100  

    Write  a  program  that  prints  the numbers  from  1  to  100  with  
    five values per line, two blank spaces betweenvalues.  The last few 
    lineswill look like this:        
      
        ...     
    91  92  93  94  95     
    96  97  98  99  100
 */

#include <iostream>
using namespace std; 

int main() 
{
    int x; 

    /*This for loop has extra space between the numbers for single digit 
      numbers. So the single digit spacing align properly with the double 
      digits numbers. 
    */
    for(x = 1; x < 100; x = x+5)
    {
        cout << x << "  " << x + 1 << "  " << x + 2 << "  " << x + 3 
             << "  " << x + 4 << endl; 
    }

    cout << endl; 
    return 0; 
}
