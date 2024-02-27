#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <filesystem>
#include "./Playlist.h"
#include "./Song.h"


class Library
{
private:
    std::list<Playlist *> listOfPlaylist;

    Playlist *defaultPlaylist();

public:
    Library();
    Playlist *createPlaylist(const std::string name);
    void addPlaylist(Playlist *newPlaylist);
    void deletePlaylist(std::string name);
    void display();
    bool validPlaylist(std::string name);
    Playlist *getPlaylist(std::string name);
    ~Library();
};
#endif
