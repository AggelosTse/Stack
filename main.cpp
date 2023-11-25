#include <iostream>
#include <unistd.h>
#include "stack.hpp"

using std::endl, std::string, std::cout,std::cin;

void clearscreen()      //function that clears old data from the screen.
{
  #ifdef _WIN32     //checks if the program is running from a Windows operating system.
    system("cls");  //if it does, it runs this command, which clears old data from the screen (runs only on windows).
  #else
    system("clear");  //if it is running from unix or macOS, it runs this command that does the same thing.
  #endif
}  
 
int main()
{
    int cap;
    cout << "give stack's capacity." << endl;
    cin >> cap;         //gets stacks capacity from user.
    while(cap < 0)      //checks for valid data.
    {
        cout << "invalid input, try again" << endl;
        cin >> cap;
    }
    clearscreen();
    stack s(cap);       //calls the stack constructor.
    
    for(;;)             //endless loop that breaks when user decides to stop program.
    {
    cout << "Press 1 to push a number in stack." << endl; 
    cout << "Press 2 to pop a number in stack." << endl;
    cout << "Press 3 to print all numbers in stack." << endl;
    cout << "Press 4 to Stop using the stack." << endl;

    string choise, a;
    cin >> choise;
    clearscreen();
    a = s.checkifnumber(choise);        //calls function that checks for valid input.
    if(a == "1")                        //if a = 1, it means that user wants to push data in stack.
    {
         if(s.overflowing())    //calls overflowing function, if its not full, calls the push function.
         {
             int element;
             cout << "What number you want to push?" << endl;
             cin >> element;
             s.push(element);
             cout << element << " pushed successfully" << endl;
         }
         else{
            cout << "Stack is full. You cant add another element." << endl;
         }
         sleep(2);
       clearscreen();
    }
    else if(a == "2")               //if a = 2, it means that user wants to pop data from the stack.
    {
        if(s.underflowing())        //calls function that checks if the stack is empty.
        {
            s.pop();                //if its not, it pops data from the top of it.
        }
        else 
        {
            cout << "stack is empty. You cant remove elements." << endl;
        }
        sleep(2);
        clearscreen();
        
    }
    else if(a == "3")           //if a = 3 it means that user wants to print stack, so it calls the printstack function.
    {
        s.printstack();
        clearscreen();
        
    }
    else                        //if a is not 1,2 or 3, it means its 4, because of the function that asks for valid input, so it prints stack and closes program.
    {
        clearscreen();
        s.endprogram();
        return 0;
    }
        
}
}
