#ifndef DVD_H
#define DVD_H

#include <string>

#include "vhs.h"


class DVD : public VHS {
    public:
        DVD();
        void createMedia();
        void print() const;
        void loadMedia(std::string const& fileName, std::string readFromFile);
        void saveMedia(std::string const& fileName, int& FLAG) const;

        bool findInfo(std::string);

        virtual ~DVD();

    private:
        int nbChapters;
};

#endif // DVD_H
