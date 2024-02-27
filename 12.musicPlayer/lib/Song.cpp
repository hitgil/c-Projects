#include "../inc/Song.h"

Song::Song(std::string title, std::string artist, int duration) : title(title), artist(artist), duration(duration) {}

void Song::display()
{
    std::cout << "\nTitle: " << title << "\nArtist: " << artist << "\nDuration: " << duration << " seconds\n";
}

std::string Song::getTitle() const
{
    return title;
}

