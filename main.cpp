#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void betFunc(int &myMoney, int &bet);
void getRolls(int &compDie1, int &userDie1);
void results(int &compDie1, int &userDie1, int &myMoney, int &betAmount);

int main()
{
    int myMoney = 1000;
    int bet = 0;
    char choice;
    int userDie1 = 0;
    int compDie1 = 0;

    cout << "Gambling is an addiction..." << endl;
    do
    {
        betFunc(myMoney, bet);
        getRolls(compDie1, userDie1);
        results(compDie1, userDie1, myMoney, bet);
        if(myMoney == 0)
        {
            cout << "You can not play any more, I have taken all of your money :)";
            return 0;
        }
        cout << endl << "Would you like to bet again :) ? ";
        cin >> choice;
    }while(choice == 'Y' || choice == 'y');

    return 0;
}

void betFunc(int &myMoney, int &bet)
{
    cout << "You currently have $" << myMoney << endl;
    do
    {
        cout << "How much would you like to bet?" << endl;
        cin >> bet;
        if( bet > myMoney)
        {
            cout << "You can not bet money you do not have." << endl;
        }
        else if(bet < 0)
        {
            cout << "You can not bet a negative number" << endl;
        }
    } while( bet > myMoney || bet < 0);
}

void getRolls(int &compDie1, int &userDie1)
{
    srand(time(NULL));
    compDie1 = rand() % 6 + 1;
    cout << "I rolled a " << compDie1 << endl;
    userDie1 = rand() % 6 + 1;
    cout << "You rolled a " << userDie1 << endl;
}

void results(int &compDie1, int &userDie1, int &myMoney, int &bet)
{
    if(compDie1 > userDie1)
    {
        cout << "You lose $" << bet << endl;
        myMoney -= bet;
    }
    else if( userDie1 > compDie1)
    {
        cout << "You gain $" << bet << endl;
        myMoney += bet;
    }
    else
    {
        cout << "Looks like a tie";
    }
}
