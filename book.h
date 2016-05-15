#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "media.h" /* <fstream>, <iostream>, <vector>… */

class Book : public Media {
    public:
        Book();
        virtual void createMedia();
        virtual void print() const;
        virtual void loadMedia(std::string const fileName, std::string readFromFile);
        virtual void saveMedia(std::string const fileName, int FLAG) const;

        virtual bool findInfo(std::string);

    private:
        std::string title;
        std::string author;
        std::string recap;
        std::string edition;

        int year;
        int nbPages;
};

#endif // BOOK_H
