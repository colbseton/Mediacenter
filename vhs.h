#ifndef VHS_H
#define VHS_H

#include <string>

class VHS {
    public:
        VHS();

    private:
        int length;
        
        std::string title;
        std::string author;
        std::string label;
};

#endif // VHS_H
