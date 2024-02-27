#include "../inc/Library.h"
#include <filesystem>

Library::Library()
{
    addPlaylist(defaultPlaylist());
}

Playlist *Library::createPlaylist(const std::string name)
{
    return new Playlist(name);
}

void Library::addPlaylist(Playlist *newPlaylist)
{
    listOfPlaylist.push_back(newPlaylist);
}

void Library::deletePlaylist(std::string name)
{
    for (auto iterator = listOfPlaylist.begin(); iterator != listOfPlaylist.end(); ++iterator)
    {
        if ((*iterator)->getPlaylistName() == name)
        {
            std::cout << "Deleting " << (*iterator)->getPlaylistName() << "\n";
            delete *iterator;
            listOfPlaylist.erase(iterator);
            break;
        }
    }
}

void Library::display()
{
    int index = 1;
    std::cout << "\n===============================\n";
    for (auto iterator = listOfPlaylist.begin(); iterator != listOfPlaylist.end(); ++iterator)
    {
        std::cout << "\n"
                  << index++ 
                  << ". " 
                  << (*iterator)->getPlaylistName();
    }
    std::cout << "\n===============================\n";
}

bool Library::validPlaylist(std::string name)
{
    for (auto iterator = listOfPlaylist.begin(); iterator != listOfPlaylist.end(); ++iterator)
    {
        if ((*iterator)->getPlaylistName() == name)
        {
            return true;
        }
    }
    return false;
}

Playlist *Library::getPlaylist(std::string name)
{
    for (auto iterator = listOfPlaylist.begin(); iterator != listOfPlaylist.end(); ++iterator)
    {
        if ((*iterator)->getPlaylistName() == name)
        {
            return *iterator;
        }
    }
    return nullptr;
}

Playlist *Library::defaultPlaylist()
{
    Playlist *likedPlaylist = nullptr;
    likedPlaylist = createPlaylist("Liked");
    std::string folderPath = "../lib/sampleMusic/";

    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.path().extension() == ".mp3")
        {
            likedPlaylist->addSong(likedPlaylist->loadMusicData(entry.path().string()));
        }
    }
    return likedPlaylist;
}

Library::~Library()
{
    for (auto playlist : listOfPlaylist)
    {
        delete playlist;
    }
    listOfPlaylist.clear();
}