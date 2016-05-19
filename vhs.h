#ifndef VHS_H
#define VHS_H

#include <string>
#include "media.h"


class VHS: public Media {
    public:
        VHS();
        virtual void createMedia();
        virtual void print() const;
        virtual void loadMedia(std::string const& fileName, std::string readFromFile);
        virtual void saveMedia(std::string const& fileName, int& FLAG) const;

        virtual bool findInfo(std::string);

        virtual ~VHS();

    protected:
        std::string title;
        std::string author;
        std::string label;
        int length;
};

#endif // VHS_H
