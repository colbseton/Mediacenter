#ifndef MEDIA_H
#define MEDIA_H

#include <algorithm> // copy_if
#include <vector>
#include <iostream> 
#include <cstdlib>
#include <fstream>

enum user {
    USER, ROOT
};

class Command {
    public:
        Command() {};
        std::string commandName;
        std::string arg;
};


class Media {
    public:
        Media() { };
        virtual bool findInfo(std::string) { };
        virtual void print() const { };
        virtual void createMedia() { };
        virtual void loadMedia(std::string const fileName, std::string readFromFile) {};
        virtual void saveMedia(std::string const fileName, int FLAG) const {};

        int id;
};



class Mediacenter {
    public:
        Mediacenter();
        void readFileType();
        void readCommand(std::string);
        void loadMedias();
        void saveMedias(int FLAG);
        void searchMedias();
        void printMedias();
        void showMediaID();
        void deleteMediaID();
        void resetMedias();

        std::vector<Media*> data;
        Command command;

        bool isSearching;
        std::vector<Media*> searchResults;

        std::string mediaFile;
};


#endif // BOOK_H
