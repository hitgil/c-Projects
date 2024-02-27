#include "../inc/Library.h"

int main()
{

    Library AMUSE;

    int choice;
    do
    {
        std::cout << "\n================="
                  << "\nWELCOME TO AMUSE\n"
                  << "=================\n"
                  << "\nPLAYLIST";
        AMUSE.display();
        std::cout << "Choose\n"
                  << "1. Create Playlist\n"
                  << "2. Delete Playlist\n"
                  << "3. View playlist\n"
                  << "4. Exit\n";

        std::cin >> choice;

        std::string playlistName, songName;

        switch (choice)
        {
        case 1:
        {
            std::cout << "\nEnter the name of the playlist to create: \n";
            std::cin.ignore(254, '\n');
            std::getline(std::cin, playlistName);
            Playlist *newPlaylist = AMUSE.createPlaylist(playlistName);

            Playlist *defaultPlaylist = AMUSE.getPlaylist("Liked");
            defaultPlaylist->displaySongList();

            char choice;
            do
            {
                std::string prefix = "../lib/sampleMusic/";
                std::string songName;

                std::cout << "\nEnter the Selected song name to add to the " << playlistName << ":\n";
                std::getline(std::cin, songName);
                newPlaylist->addSong(newPlaylist->loadMusicData(prefix + songName + ".mp3"));
                newPlaylist->playSongs();

                std::cout << "\nEnter 'Y' to add One more song:\n";
                std::cin >> choice;
                std::cin.ignore(254, '\n');
            } while (choice == 'Y' || choice == 'y');

            AMUSE.addPlaylist(newPlaylist);
            AMUSE.display();
        }

        break;

        case 2:
            std::cout << "Enter the name of the playlist you want to delete: ";
            std::cin.ignore(254, '\n');
            std::getline(std::cin, playlistName);
            AMUSE.deletePlaylist(playlistName);
            AMUSE.display();
            break;

        case 3:
            std::cout << "Enter the name of the playlist: ";
            std::cin.ignore(254, '\n');
            std::getline(std::cin, playlistName);

            if (AMUSE.validPlaylist(playlistName))
            {
                Playlist *selectedPlaylist = AMUSE.getPlaylist(playlistName);
                if (selectedPlaylist != nullptr)
                {
                    while (true)
                    {
                        std::cout << "\nAvailable Songs:\n";
                        selectedPlaylist->displaySongList();
                        std::cout << "\nSelect an option:\n"
                                  << "1. Play songs\n"
                                  << "2. Move a song up\n"
                                  << "3. Move a song down\n"
                                  << "4. Exit\n";

                        int option;
                        std::cin >> option;
                        std::cin.ignore(254, '\n');

                        std::string songSelection;

                        switch (option)
                        {
                        case 1:
                            selectedPlaylist->playSongs();
                            break;
                        case 2:
                            std::cout << "Enter the name of the song to move up: ";
                            std::getline(std::cin, songSelection);
                            selectedPlaylist->moveSongUp(songSelection);
                            break;
                        case 3:
                            std::cout << "Enter the name of the song to move down: ";
                            std::getline(std::cin, songSelection);
                            selectedPlaylist->moveSongDown(songSelection);
                            break;
                        case 4:
                            std::cout << "Exiting to main menu.\n";
                            break;
                        default:
                            std::cout << "Invalid option. Please enter a number between 1 and 4.\n";
                            break;
                        }

                        if (option == 4)
                            break; // Exit the loop to return to the main menu
                    }
                }
                else
                {
                    std::cout << "Playlist not found.\n";
                }
            }
            else
            {
                std::cout << "Playlist does not exist. Please enter a valid playlist name.\n";
            }
            break;

        case 4:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 4);

    return 0;
}
