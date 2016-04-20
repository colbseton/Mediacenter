#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "cd.h"
#include "media.h"
#include "vhs.h"
#include "command.h"
#include "tools.h"

using namespace std;
                         
int main(int argc, char *argv[]) {
    string input;
    //Command command;
    Mediacenter mediacenter;

    while(1) {
        get_input(input);
        cout << input;
        mediacenter.readCommand(input);

        cout << "voici le premier attribut de l'objet crée : ";
        mediacenter.data[0]->affiche(); break;

    }

    return 0;
}
