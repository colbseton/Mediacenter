#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "media.h"

class Book : public Media {
    public:
        Book();
        virtual void createMedia();
        virtual void affiche() const;

    private:
        std::string title;
        std::string author;
        std::string recap;
        std::string edition;
        int year;
        int nbPages;
};

#endif // BOOK_H
