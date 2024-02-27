#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <map>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "./Song.h"

class Playlist
{
private:
    std::string playlistName;
    std::list<Song> songList;

public:
    Playlist(const std::string name);
    std::string &getPlaylistName();
    Song loadMusicData(const std::string &filePath);
    void addSong(const Song &song);
    void displaySongList();
    void moveSongUp(const std::string &songTitle);
    void moveSongDown(const std::string &songTitle);
    void playSongs();
};

#endif
