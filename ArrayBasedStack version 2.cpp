// including libraries

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Stack of string type.
class Stack
{

private:
    const int size = 50;            // size of stack initally defined 50.
    char *arr = new char[size]; // array of type string to use as stack.
    int ptr = -1;                   // pointer points to location where data is to be added.
public:
    // function to check that stack is empty or not.
    bool isEmpty()
    {
        return ptr == -1;
    }

    // function to check that stack is full or not.
    bool isFull()
    {
        return ptr == size - 1;
    }

    // function to push element into stack.
    void push(char value)
    {
        if (!isFull())
        {
            ptr = ptr + 1;
            arr[ptr] = value;
        }
        else
        {
            cout << "Stack Overflow." << endl;
        }
    }

    // function to pop a element from stack.
    void pop()
    {
        if (!isEmpty())
        {
            char element;
            element = arr[ptr];
            ptr--;
        }
        else
        {
            cout << "Stack Underflow." << endl;
        }
    }

    // function to return top of the stackt, if stack is empty then return null.

    char top()
    {
        char element;
        // element = NULL;
        if (!isEmpty())
        {
            element = arr[ptr];
            return element;
        }
    }

}; // end of class.


// stack of integer type.
class Stack2
{

private:
    const int size = 50;            // size of stack initally defined 50.
    int *arr = new int[size]; // array of type string to use as stack.
    int ptr = -1;                   // pointer points to location where data is to be added.
public:
    // function to check that stack is empty or not.
    bool isEmpty()
    {
        return ptr == -1;
    }

    // function to check that stack is full or not.
    bool isFull()
    {
        return ptr == size - 1;
    }

    // function to push element into stack.
    void push(int value)
    {
        if (!isFull())
        {
            ptr = ptr + 1;
            arr[ptr] = value;
        }
        else
        {
            cout << "Stack Overflow." << endl;
        }
    }

    // function to pop a element from stack.
    void pop()
    {
        if (!isEmpty())
        {
            int element;
            element = arr[ptr];
            ptr--;
        }
        else
        {
            cout << "Stack Underflow." << endl;
        }
    }

    // function to return top of the stack, if stack is empty then return null.

    int top()
    {
        int element;
        if (!isEmpty())
        {
            element = arr[ptr];
            return element;
        }

    }

}; // end of class.


// program to convert from infix to postfix.
class InfixToPostfix
{
public:
    string postfix;
    Stack a;
    Stack2 b;

    // function to check for operators in expression.
    bool isoperator(char symbol)
    {
        if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //function to check for precedence of operators.
    int precedence(char symbol)
    {
        if (symbol == '^')
        {
            return 3;
        }
        else if (symbol == '*' || symbol == '/')
        {
            return 2;
        }
        else if (symbol == '+' || symbol == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // functon to convert from infix to postfix.
    string Itf(string infix)
    {
        Stack s;

        for (int i = 0; i < infix.length(); i++)
        {
            
            if (infix[i] == ' ' || infix[i] == '^' || infix[i] == '(' || infix[i] == ')' || infix[i] == '{' || infix[i] == '}')
            {
                postfix += ' ';
            }

            if (isalpha(infix[i]) || isdigit(infix[i]))
            {

                postfix += infix[i];
            }
            else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
            {
                s.push(infix[i]);
            }
            else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
            {
                while ((s.top() != '(' && s.top() != '{' && s.top() != '[') && (!s.isEmpty()))
                {
                    char temp = s.top();
                    postfix += temp;
                    s.pop();
                }

                if (s.top() == '(' || s.top() == '{' || s.top() == '[')
                {
                    s.pop();
                }
            }
            else if (isoperator(infix[i]))
            {
                if (s.isEmpty())
                {
                    s.push(infix[i]);
                }
                else

                {
                    if (precedence(infix[i]) > precedence(s.top()))
                    {
                        s.push(infix[i]);
                    }
                    else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                    {
                        s.push(infix[i]);
                    }
                    else
                    {
                        while ((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.top())))
                        {
                            char temp = s.top();
                            postfix += temp;
                            s.pop();
                        }
                        s.push(infix[i]);
                    }

                }
            }
        }

        // empty stack in the end.
        while (!s.isEmpty())
        {
            postfix += ' ';
            postfix += s.top();
            s.pop();
        }
        return postfix;
    }

    // function to perform operation based on operator encountered.
    int PerformOperation(char operation, int operand1, int operand2)
    {
        if (operation == '+')
            return operand1 + operand2;
        else if (operation == '-')
            return operand1 - operand2;
        else if (operation == '*')
            return operand1 * operand2;
        else if (operation == '/')
            return operand1 / operand2;
        else if (operation == '^')
            return ((int)pow(operand1, operand2));

    }

    // function to solve the postfix expression.
    void solving()
    {
        int num1, num2, num3;
        Stack2 iny;
        string temp;

        for (int i = 0; i < postfix.length(); i++)
        {
            if (isdigit(postfix[i]))
            {
                string j(1, postfix[i]);
                temp += j;
                j.clear();
            }

            // converting number to integer for solving.
            if (isdigit(postfix[i - 1]) && postfix[i] == ' ')
            {
                temp += "\0";
                iny.push(stoi(temp));
                temp.clear();
            }

            if (!iny.isEmpty())
            {
                if (postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
                {
                    int result = 0;
                    num2 = (iny.top());
                    iny.pop();
                    num3 = (iny.top());
                    iny.pop();
                    result = PerformOperation(postfix[i], num3, num2);
                    iny.push(result);
                }
            }
        }
        cout << "\n\nResult of the expession is : " << iny.top() << endl;
    }
}; // end fo class.

//main method.
int main()
{

    string infix, postfix;
    InfixToPostfix a;
    // taking input from user to convert from infix to postfix.

    cin.clear();
    cout << "Enter a infix expression: " << endl;
    getline(cin, infix);

    // displaying infix , postfix and solution of expression.

    cout << "Infix Expression: " << infix << endl;
    postfix = a.Itf(infix);
    cout << endl
         << "Postfix Expression: " << postfix;
    a.solving();

    return 0;
}