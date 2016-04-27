#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "cd.h"
#include "media.h"
#include "vhs.h"
#include "tools.h"

using namespace std;
                         
int main(int argc, char *argv[]) {
    string input("");
    //Command command;
    Mediacenter mediacenter;

    while(1) {
        get_input(input);
        mediacenter.readCommand(input);
        input = "";
    }
    return 0;
}
