#ifndef RES_H
#define RES_H

#include <string>
#include "media.h"


class ResNum : public Media {
    public:
        ResNum();
        void createMedia();
        void print() const;
        void loadMedia(std::string const& fileName, std::string readFromFile);
        void saveMedia(std::string const& fileName, int& FLAG) const;

        bool findInfo(std::string);

        ~ResNum();

    private:
        std::string author;
        std::string type;
        std::string name;
        std::string webUrl;
};

#endif // BOOK_H
