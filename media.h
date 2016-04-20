#ifndef MEDIA_H
#define MEDIA_H

#include <vector>
#include <iostream> 
#include <cstdlib>


enum user {
    USER, ROOT
};

class Command {
    public:
        Command();
        std::string commandName;
        std::string arg;
};


class Media {
    public:
        Media();
        virtual void affiche() const { };
        virtual void createMedia() { };
};



class Mediacenter {
    public:
        Mediacenter();
        void readFileType();
        void readCommand(std::string);

        std::vector<Media*> data;
        Command command;
};


#endif // BOOK_H
