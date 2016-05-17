#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "book.h"
#include "cd.h"
#include "media.h"
#include "vhs.h"
#include "tools.h"

using namespace std;
                         
int main(int argc, char *argv[]) {
    srand(time(NULL));

    string input("");
    Mediacenter mediacenter;

    /* interactive session */
    while(1) {
        get_input(input);
        mediacenter.readCommand(input);
        input = "";
    }

    return 0;
}
