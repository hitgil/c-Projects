#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
#include <taglib/fileref.h>
#include <taglib/tag.h>

class Song
{
private:
    std::string title;
    std::string artist;
    int duration;

public:
    Song(std::string title = "", std::string artist = "", int duration = 0);
    void display();
    std::string getTitle() const;
};

#endif
