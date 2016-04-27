#ifndef MEDIA_H
#define MEDIA_H

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
        Media(){};
        virtual void print() const { };
        virtual void createMedia() { };
        virtual void loadMedia(std::string const fileName, std::string readFromFile) {};
        virtual void saveMedia(std::string const fileName) const {};
};



class Mediacenter {
    public:
        Mediacenter() {};
        void readFileType();
        void readCommand(std::string);
        void loadMedias();
        void saveMedias();

        std::vector<Media*> data;
        Command command;
};


#endif // BOOK_H
