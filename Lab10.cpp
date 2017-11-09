#include <iostream>
bool IsPrime();
bool IsHappy();
bool AddToCycle();
bool cyclecontains();
void SelectionSort();

int a[20] = {};
int num = 0;
int counter = 0;
int sum = 0;

using namespace std;

int main()
{
    cout << "Enter the value you wish to test the happiness of\n";
    cin >> num;

    if(IsHappy()){
        cout<<"working"<<endl;
    }
    else{
        cout<<"Ok"<<endl;
    }
    if ( IsPrime( ) == true && IsHappy( ) == true)
    {
        cout << num << " is happy :)\n";
    }

    return 0;
}

bool IsPrime()
{
    for( int i = 2; i <= (num / 2); ++i)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool IsHappy()
{
    int digit = 0;
    int num2 = 0;
    num2 = num;
    do
    {
        while ( num2 > 0 )
           {
               digit = (num2 % 10);
               num2 /= 10;
               sum += (num2 * num2);
           }
    digit = sum;
    AddToCycle();
    if ( sum == 1)
    {
        return true;
    }
    }while(sum != 4);
    return false;
}

bool AddToCycle()
{
    if ( cyclecontains( ) == false)
    {
        a[counter] = num;
        counter++;
        SelectionSort( );
        return true;
    }
}

bool cyclecontains( )
{
    for(int i = 0; i < 20; i++)
    {
        if( a[i] == num)
        {
            return true;
        }
    }
    return false;
}

void SelectionSort()
{
    for( int i = 0; i < (20-1); i++)
    {
        int mi = i;
        for (int j = i+1; j < 20; j++)
        {
            if(a[j] < a[mi])
            {
                mi = j;
            }
        }
        if ( mi != i)
        {
            int temp = a[mi];
            a[mi] = a[i];
            a[i] = temp;
        }
    }
}

