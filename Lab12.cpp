#include <iostream>

using namespace std;
int factorial(int num);
int fib(int num2);

int main()
{
    //problem 1
    int num = 0;
    int value = 0;
    cout << "enter the the number" << endl;
    cin >> num;
    value = factorial(num);
    cout << "The value is " << value << endl;

    // problem 2
    int num2 = 0;
    int value2 = 0;
    cout << "Enter the number of Fibonacci numbers you want" << endl;
    cin >> num2;
    value2 = fib(num2);
    cout << "The Fibonacci number is " << value2;

    return 0;
}
int factorial( int num)
{
    if( num == 0)
    {
        return 1;
    }
    return (num * factorial( num - 1));
}

int fib(int num2)
{
    if ( num2 <= 1)
    {
        return num2;
    }
    return (fib(num2 - 1) + fib( num2 - 2));
}
