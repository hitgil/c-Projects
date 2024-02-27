#include "../inc/Playlist.h"
#include <stack>
Playlist::Playlist(const std::string name) : playlistName(name) {}

std::string &Playlist::getPlaylistName()
{
    return playlistName;
}

void Playlist::displaySongList()
{
    int i = 0;
    std::cout << "\nSONGS"
              << "\n_____\n";
    for (const auto &song : songList)
    {
        std::cout << ++i << ". " << song.getTitle() << std::endl;
    }
}

Song Playlist::loadMusicData(const std::string &filePath)
{
    std::string title;
    std::string artist;
    int duration = 0;

    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag())
    {
        TagLib::Tag *tag = file.tag();
        title = tag->title().toCString();
        artist = tag->artist().toCString();
        duration = file.audioProperties()->lengthInSeconds();
    }

    return Song(title, artist, duration);
}
void Playlist::addSong(const Song &song)
{
    songList.push_back(song);
}

void Playlist::moveSongUp(const std::string &songTitle)
{
    for (auto ittrator = songList.begin(); ittrator != songList.end(); ++ittrator)
    {
        if (ittrator->getTitle() == songTitle && ittrator != songList.begin())
        {
            std::iter_swap(ittrator, std::prev(ittrator));
            return;
        }
    }
}

void Playlist::moveSongDown(const std::string &songTitle)
{
    for (auto ittrator = songList.begin(); ittrator != songList.end(); ++ittrator)
    {
        if (ittrator->getTitle() == songTitle && std::next(ittrator) != songList.end())
        {
            std::iter_swap(ittrator, std::next(ittrator));
            return;
        }
    }
}


int musicPlayer(const std::string &fileName)
{
    int playbackAction = 0;

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        throw std::runtime_error("SDL could not initialize");
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        throw std::runtime_error("SDL_mixer could not initialize");
    }

    Mix_Music *music = Mix_LoadMUS(fileName.c_str());
    if (!music)
    {
        throw std::runtime_error("Failed to load music!");
    }

    Mix_PlayMusic(music, 0);
    char command = ' ';
    std::cout << "\nMusic Control"
              << "\nUse 'p' to pause, 'r' to resume, 'n' for next, 'b' for previous, 'u' to move up, 'd' to move down, 'q' to quit.\n";
    do
    {
        std::cin >> command;
        switch (command)
        {
        case 'p':
            if (Mix_PlayingMusic())
            {
                Mix_PauseMusic();
                std::cout << "Music paused.\n";
            }
            break;
        case 'r':
            if (Mix_PausedMusic())
            {
                Mix_ResumeMusic();
                std::cout << "Music resumed.\n";
            }
            break;
        case 'n':
            if (Mix_PlayingMusic())
            {
                Mix_HaltMusic();
                std::cout << "Next song\n";
                playbackAction = 1;
            }
            break;
        case 'b':
            if (Mix_PlayingMusic())
            {
                std::cout << "Previous song\n";
                playbackAction = 2;
            }
            break;

        case 'q':
            std::cout << "Exiting music playback.\n";
            playbackAction = 3;
            break;
        default:
            std::cout << "Invalid command. Use 'p' to pause, 'r' to resume, 'n' for next, 'b' for previous, 'u' to move up, 'd' to move down, 'q' to quit.\n";
            break;
        }
    } while (playbackAction == 0 && Mix_PlayingMusic());

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return playbackAction;
}

void Playlist::playSongs()
{
    std::string prefix = "../lib/sampleMusic/";
    std::stack<std::string> stack;

    for (auto &song : songList)
    {
        std::cout << "\n==================================\n";
        song.display();

        std::string songName = prefix + song.getTitle() + ".mp3";
        stack.push(songName);
        int presentSong = musicPlayer(stack.top());

        switch (presentSong)
        {
        case 2:
            std::cout << "\n==================================\n";
            stack.pop();
            if (!stack.empty())
            {
                musicPlayer(stack.top());
            }
            break;
        case 3:
            return;
        default:
            break;
        }

        std::cout << "\n==================================\n";
    }
}
