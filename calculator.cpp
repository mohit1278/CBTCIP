#include <bits/stdc++.h>
using namespace std;
int main()
{
    // defining vaariables
    double num1, num2;
    char op;

    // using while loop to run the programm repeatadely
    while (1)
    {
        // inputting opeartor and operands

        cout << "\nenter first number :";
        cin >> num1;
        cout << "enter the opeartor (+ - * / %) : ";
        cin >> op;
        cout << "enter second number :";
        cin >> num2;

        // using switch case for switching the opearions between multiple opeartors
        switch (op)
        {

        // for addition
        case '+':
            cout << num1 << op << num2 << " = " << num1 + num2 << endl;
            break;

        // for substraction
        case '-':
            cout << num1 << op << num2 << " = " << num1 - num2 << endl;
            break;

        // for multiplication
        case '*':
            cout << num1 << op << num2 << " = " << num1 * num2 << endl;
            break;

        // for division
        case '/':

            // check weather is divisor is 0 or not
            if (num2 == 0)
            {
                cout << "Can not divide by  ZERO 0 " << endl;
            }
            else
            {
                cout << num1 << op << num2 << " = " << num1 / num2 << endl;
            }
            break;

        // default condition
        default:
            cout << "Invalid operator" << endl;
            break;
        }
    }

    return 0;
}