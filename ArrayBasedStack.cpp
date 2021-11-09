//including libraries

#include<iostream>
#include<string>
using namespace std;

// Stack class
class Stack
{

private:
const int size = 50; // size of stack initally defined 50.
string *arr = new string[size]; // array of type string to use as stack.
int ptr = -1; // pointer points to location where data is to be added.
public:

    // function to check that stack is empty or not.
    bool isEmpty()
    {
        return ptr == -1;
    }

    // function to check that stack is full or not.
    bool isFull()
    {
        return ptr == size -1;
    }

    // function to push element into stack.
    void push(string value)
    {
        if (!isFull())
        {
            ptr = ptr + 1;
            arr[ptr] = value;
        }
        else
        {
            cout<<"Stack Overflow."<<endl;
        }
    }

    // function to pop a element from stack.
    void pop()
    {
        if(!isEmpty())
        {
            string element;
            element = arr[ptr];
            ptr--;
        }
        else
        {
            cout<<"Stack Underflow."<<endl;
        }
    }

    // function to return top of the stackt, if stack is empty then return null.

    string* top()
    {
        string* element;
        element = NULL;
        if(!isEmpty())
        {
            element = &(arr[ptr]);
            return element;
        }

        else
        {
            return element ;
        }
    }


}; // end of class.

// main function.

int main()
{
Stack a; // creating instant of stack class.

// adding data to stack.
a.push("5");
a.push("6");
a.push("7");
a.push("8");
a.push("9");
a.push("10");

// poping data from stack.
a.pop();
a.pop();

string* t; // string variable to store returned element from stack.
t = a.top();

// condition to output the top of the stack based on the returned element from top function.
if (t == NULL)
{
    cout<<"\nStack underflow."<<endl;
}

else
{
    cout<<"\nTop of Stack: " <<*t <<endl;
}

return 0;
} 
