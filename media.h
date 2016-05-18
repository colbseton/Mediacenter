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
    /* Media is an abstract classe */
    public:
        Media() { };
        virtual bool findInfo(std::string) = 0;
        virtual void print() const = 0;
        virtual void createMedia() = 0;
        virtual void loadMedia(std::string const& fileName, std::string readFromFile) = 0;
        virtual void saveMedia(std::string const& fileName, int& FLAG) const = 0 ;
        virtual ~Media() {};

    protected:
        friend class Mediacenter;
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
        void logToRoot(void);
        ~Mediacenter();

        std::string getPasswd(void) { // accessor
            return password;
        }

        std::vector<Media*> data;
        enum user userType;

    private:
        bool isSearching;
        std::vector<Media*> searchResults;
        std::string mediaFile;
        Command command;
        const std::string password = "labuche";

};


#endif // BOOK_H
