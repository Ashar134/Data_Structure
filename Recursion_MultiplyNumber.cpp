#include <iostream>
using namespace std;
int multiply(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        return 0;
    }

    if (num2 > 0)
    {
        return num1 + multiply(num1, num2 - 1);
    }
    else
    {
        return -multiply(num1, -num2);
    }
}

int main()
{
    int num1;
    int num2;

    cout << "Enter number 1 :";
    cin >> num1;

    cout << "Enter number 2 :";
    cin >> num2;

    cout << "Number 1 : " << num1 << endl;
    cout << "Number 2 : " << num2 << endl;
    cout << "Result : " << multiply(num1, num2);
    return 0;
}