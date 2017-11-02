#include <iostream>
#include <string>

using namespace std;

struct mp3{
string song_title;
string file_name;
string genre;
bool favorite;
};

mp3 songs[100];
int main()
{
    int menu_option = 0;
    int menu_option2 = 0;
    int track_number = -1;
    char fav;
    int total_songs = 0;
    do
    {
        cout << "Menu options" << endl;
        cout << "1.) Enter a New Song\n";
        cout << "2.) Delete a Song\n";
        cout << "3.) Display all songs\n";
        cout << "4.) Edit a song\n";
        cout << "5.) Display all Favorites\n";
        cout << "6.) Exit Program\n";
        cin >> menu_option;
        switch (menu_option)
        {
            case 1: cout << "What track number would you like the song to be?\n";
                cin >> track_number;
                track_number -= 1;
                total_songs++;
                cout << "What is the title of the song?\n";
                cin >> songs[track_number].song_title;
                cout << "What is the file name of the song?\n";
                cin >> songs[track_number].file_name;
                cout << "What is the genre of the song?\n";
                cin >> songs[track_number].genre;
                do
                {
                    cout << "Would you like to favorite this song? Y or N. \n";
                    cin >> fav;
                    if (fav == 'Y' || fav == 'y')
                        songs[track_number].favorite = 1;
                    if ( fav != 'Y' && fav != 'y' && fav != 'n' && fav != 'N')
                    {
                        cout << "That option is invalid. Try again.\n";
                    }
                } while (fav != 'Y' && fav != 'y' && fav != 'n' && fav != 'N');
                break;
            case 2: cout << "What is the track number of the song you wish to delete?";
                cin >> track_number;
                track_number -= 1;
                songs[track_number].song_title = "";
                songs[track_number].file_name = "";
                songs[track_number].genre = "";
                songs[track_number].favorite = 0;
                break;
            case 3: for (int i = 0; i < total_songs; i++ )
                    {
                        track_number = i + 1;
                        cout << "track number: " << track_number << "\n\t" << songs[i].song_title << "\n\t" << songs[i].file_name
                        << "\n\t" << songs[i].genre << endl;
                    }
                    break;
            case 4: "What is the track number of the song you wish to edit?";
                    cin >> track_number;
                    track_number-= 1;
                    do
                    {
                        cout << "Which part would you like to edit?\n";
                        cout << "1.) title\n2.) filename\n3.) genre\n4.) favorite\n5.)Exit Meta-Menu";
                        cin >> menu_option2;
                        switch (menu_option2)
                        {
                            case 1: cout <<"Enter a new title\n";
                                    cin >> songs[track_number].song_title;
                                    break;
                            case 2: cout <<"Enter a new filename\n";
                                    cin >> songs[track_number].file_name;
                                    break;
                            case 3: cout << "Enter a new Genre\n";
                                    break;
                            case 4: do
                                    {
                                        cout << "Would you like to favorite this song? Y or N. \n";
                                        cin >> fav;
                                        if (fav == 'Y' || fav == 'y')
                                            songs[track_number].favorite = 1;
                                        if ( fav != 'Y' && fav != 'y' && fav != 'n' && fav != 'N')
                                            {
                                                cout << "That option is invalid. Try again.\n";
                                            }
                                    } while (fav != 'Y' && fav != 'y' && fav != 'n' && fav != 'N');
                        }
                    } while (menu_option != 5);
                    break;
                case 5: for (int i = 0; i < total_songs; i++ )
                        {
                            track_number = i + 1;
                            if (songs[track_number].favorite == 1)
                            {
                                cout << "track number: " << track_number << "\n\t" << songs[i].song_title << "\n\t" << songs[i].file_name
                                << "\n\t" << songs[i].genre << endl;
                            }
                        }
        }

    } while (menu_option != 6);

    return 0;
}
