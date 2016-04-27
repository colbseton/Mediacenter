#include "media.h"
#include "tools.h"

#include "book.h"


void Mediacenter::loadMedias() {
    std::string fileName = command.arg + ".media";
    std::string buffer = "";
    std::ifstream streamFile(fileName.c_str());

    if(streamFile.is_open()) {
        while(getline(streamFile, buffer)) {
            auto visBook = buffer.find(".book");
            /* … */ 

            if(visBook >= 0 && visBook <= buffer.length()) {
                Book *newBook = new Book;
                newBook->loadMedia(fileName, buffer);
                data.push_back(newBook);
            }
            /* … */
        }
        std::cout << "medias loaded from file : " << fileName << std::endl;
    }

    else 
        std::cout << "error could not open the file : " << fileName 
                  << std::endl;
}


void Mediacenter::saveMedias() {
    std::string fileName = command.arg + ".media";

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
            /* … */

        else if(command.arg.compare("vhs"));
            /* … */
    }
}

void Mediacenter::readCommand(std::string input) {
    std::vector<std::string> inputSplit = split(input, ' ');

    if(inputSplit.size() > 0) {
        command.commandName = inputSplit[0];

        if(inputSplit.size() > 1) 
            command.arg = inputSplit[1];

        if(command.commandName.compare("add") == 0)
            readFileType();

        else if(command.commandName.compare("load") == 0)
            loadMedias();

        else if(command.commandName.compare("save") == 0)
            saveMedias();

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
            /* program stops */
        }
    }
}
