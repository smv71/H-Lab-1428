#include <iostream>

using namespace std;

int main()
{
    float meal_cost = 0, tip_percent = 0, tip = 0;
    cout << "Enter the cost of your meal \n";
    cin >> meal_cost;
    while ( meal_cost < 0)
    {
        cout << "Your meal must be a positive value. Please enter a new value:\n";
        cin >> meal_cost;
    }
    cout << "Enter the percent you would like to tip: ";
    cin >> tip_percent;
    while (tip_percent < 0)
    {
        cout << " Your tip percent must be a positive value. please enter a positive value.";
        cin >> tip_percent;
    }
    while (tip_percent > 100)
    {
        cout << "A percent can not be greater than 100. Enter a value less than or equal to 100.";
        cin >> tip_percent;
    }
    tip_percent = tip_percent / 100;
    tip = meal_cost * tip_percent;
    cout << "\nYou should tip $" << tip;
    return 0;
}
