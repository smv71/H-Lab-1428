#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	//NUMBER OF ROWS AND COLUMNS
	const int ROWS = 10;
	const int COLS = 10;
	char life[ROWS][COLS];
	char life_copy[ROWS][COLS];
	int counter = 0, gen_num = 0;

	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;

	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}
    // Create a copy of the array
	for(int r=0; r < ROWS; r++)
    {
        for(int c=0; c < COLS; c++)
        {
            life_copy[r][c]=life[r][c];
        }
    }
    // Determine the number of runs
    cout << "How many generations do you want to run?";
    cin >> gen_num;
    // Display the first array
        cout << "\nGeneration One\n";
        for(int r=0; r<ROWS; r++)
        {
            for(int c =0; c<COLS;c++)
            {
                cout << life[r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    for(int i = 2; i <= gen_num; i++)
    {
        // Determine who lives and who dies
        for (int r = 0; r < ROWS; r ++)
        {
            for (int c = 0; c < COLS; c ++)
            {
                counter = 0;
                if ((r-1) >= 0 && (c-1) >= 0 && life_copy[r-1][c-1]== '*')
                    counter++;
                if ((r-1) >= 0 && life_copy[r-1][c] == '*')
                    counter++;
                if ((r-1) >= 0 && (c+1) < 10 && life_copy[r-1][c+1] == '*')
                    counter++;
                if ((c-1) >= 0 && life_copy[r][c-1] == '*')
                    counter++;
                if ((c+1) < 10 && life_copy[r][c+1] == '*')
                    counter++;
                if ((r+1) < 10 && (c-1) >= 0 && life_copy[r+1][c-1] == '*')
                    counter++;
                if ((r+1) < 10 && life_copy[r+1][c] == '*')
                    counter++;
                if  ((r+1) < 10 && (c+1) < 10 && life_copy[r+1][c+1] == '*')
                    counter++;
                // Change the values in the copy array
                if (counter < 2 && (life_copy[r][c] == '*'))
                    life_copy[r][c] = ' ';
                if (counter == 3 && (life_copy[r][c] == ' '))
                    life_copy[r][c] = '*';
                if (counter > 3 && (life_copy[r][c] == '*'))
                    life_copy[r][c] = ' ';
            }
        }
        // Change the values in the life
        for ( int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                life[r][c] = life_copy[r][c];
            }
        }
        // Display the next generation
        cout << "Generation " << i <<endl;
        for(int r=0; r<ROWS; r++)
        {
            for(int c =0; c<COLS;c++)
            {
                cout << life[r][c] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

