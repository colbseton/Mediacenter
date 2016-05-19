#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "tools.h"
#include "media.h"

using namespace std;
                         
int main(int argc, char *argv[]) {
    srand(time(NULL));

    string input("");
    Mediacenter mediacenter;

    /* interactive session */
    while(1) {
        cout << "mediacenter $: ";
        get_input(input);
        mediacenter.readCommand(input);
        input = "";
    }

    return 0;
}
