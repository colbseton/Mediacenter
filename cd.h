#ifndef CD_H
#define CD_H

#include <string>

class CD {
    public:
        CD();


    private:
        int length;
        int nbTrack;
        
        std::string title;
        std::string genre;
        std::string author;
        std::string label;
};

#endif // CD_H
