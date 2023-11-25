#include "stack.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

using std::string,std::cin,std::cout,std::endl;

   stack::stack(int c)         //constructor that initialises the stack, when the object is created.
    {
        capacity = c;           //stack's capacity is given from the user.
        top = -1;
        data = new int[capacity];      //allocating memory for the stack.
    }


   stack::~stack()              //destructor, frees memory and destroys the object when the job is finished.
    {
        delete[] data;          //frees memory.
    }


   void stack::endprogram()     //this function is called when the user decides to close the program.
    {
        int i;
        for(i=0;i<=top;i++)
        {

        cout<< data[i] << " ";      //prints stack's data before closing.
        }
        cout << "\n";
        return;
    }

    
   string stack::checkifnumber(string ch)   //gets user's number and checks for valid input.
    {
        while(ch != "1" && ch != "2" && ch != "3" && ch != "4")
        {
            cout << "invalid input, try again" << endl;
            cin >> ch;
        }
        return ch;
    }


   bool stack::overflowing()    //checks if the stack is overflowing (is full) before it adds data to it.
    {
        if(top == capacity -1)
        {
            return false;
        }
        return true;
    }


   bool stack::underflowing()   //checks if the stack is underflowing (is empty), before it removes data from it.
    {
        if(top < 0)
        {
            return false;
        }
        return true;
    }


   void stack::push(int elem)   //puts data on top of the stack.
    {
        top++;
        data[top] = elem;       
    }
  

   void stack::pop()            //removes data from the top of the stack.
    {
        cout << data[top] << " element popped." << endl;
        top--;
    } 

 
   void stack::printstack()     //prints data from the stack when user decides.
    {
        int i;
        if(top < 0)             //checks if the stack is empty.
        {
            cout << "no elements inside stack." << endl;
            sleep(2);
        }
        else
        {
        for(i=0;i<=top;i++)     //if it is not empty, it prints data from it.
        {

        cout<< data[i] << " ";
        }
        cout << "\n";
        sleep(3);
        }
    }