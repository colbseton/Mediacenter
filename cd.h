#ifndef CD_H
#define CD_H

#include <string>
#include "media.h"

class CD : public Media {
    public:
        CD();
        virtual void createMedia();
        virtual void print() const;
        virtual void loadMedia(std::string const& fileName, std::string readFromFile);
        virtual void saveMedia(std::string const& fileName, int& FLAG) const;

        virtual bool findInfo(std::string);

        virtual ~CD();

    private:
        int length;
        int nbTrack;

        std::string title;
        std::string genre;
        std::string author;
        std::string label;
};

#endif // CD_H
