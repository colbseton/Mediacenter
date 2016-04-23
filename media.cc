#include "media.h"
#include "tools.h"

#include "book.h"


void Mediacenter::saveMedias() {
    std::string fileName = command.arg;

    for(auto it : data)
        it->saveMedia(fileName);

    data.clear();
}

void Mediacenter::readFileType() {
    if(command.commandName.compare("add") == 0) {

        if(command.arg.compare("book") == 0) {

            Book* newbook = new Book;
            newbook->createMedia();

            data.push_back(newbook);
        }

        else if(command.arg.compare("cd"));
            /* fonction créer cd */

        else if(command.arg.compare("vhs"));
            /* fonction créer vhs */
    }
}

void Mediacenter::readCommand(std::string input) {
    std::vector<std::string> input_split = split(input, ' ');

    if(input_split.size() > 0) {
        command.commandName = input_split[0];

        if(input_split.size() > 1) {
            command.arg = input_split[1];
        }

        if(command.commandName.compare("add") == 0) {
            readFileType();
        }

        else if(command.commandName.compare("load") == 0) {

        }

        else if(command.commandName.compare("save") == 0) {
            saveMedias();
        }

        else if(command.commandName.compare("search") == 0) {

        }

        else if(command.commandName.compare("clear") == 0) {

        }

        else if(command.commandName.compare("list") == 0) {

        }

        else if(command.commandName.compare("show") == 0) {

        }

        else if(command.commandName.compare("delete") == 0) {

        }

        else if(command.commandName.compare("reset") == 0) {

        }

        else if (command.commandName.compare("bye") == 0) {
            std::cout << "Session terminated" << std::endl;
            std::exit(0);
        }
    }
}
