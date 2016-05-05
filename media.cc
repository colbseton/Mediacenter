#include "media.h"
#include "tools.h"

#include "book.h" // <string.h>

/*
auto it = std::find_if(data.begin(), data.end(), [&](const Data& d) { return d.id == idToFind; });
if (it != date.end()) it->print(); else std::cout << "ID non trouve" << std::endl;                */

Mediacenter::Mediacenter() {
    isSearching = false;
}

void Mediacenter::showMediaID() {
    int idToFind = std::atoi(command.arg.c_str());
    bool findId = false;

    for(auto it : data) {
        if( (it->id) == idToFind) {
            it->print();
            findId = true;
        }
    }

    if(findId == false)
        std::cout << "ressource non trouvée" << std::endl;
}


void Mediacenter::searchMedias() {
    std::string strToFind = command.arg;

    std::vector<Media*> copy;

    /* filtering data vector with the search results */

    std::copy_if(searchResults.begin(), searchResults.end(),
                 std::back_inserter(copy), 
                 [strToFind](Media* obj){ return (obj->findInfo(strToFind)); } );

    searchResults = copy;
}


void Mediacenter::printMedias() {
    if(isSearching == true) {
        std::cout << "Résultats de la recherche incrémentale :\n";
        for(auto it : searchResults)
            it->print();
    }

    else 
        for(auto it : data)
            it->print();
}


void Mediacenter::loadMedias() {
    std::string fileName = command.arg + ".media";
    std::string buffer = "";
    std::ifstream streamFile(fileName.c_str());

    if(streamFile.is_open()) {
        while(getline(streamFile, buffer)) {

            if(buffer.find(".book") != std::string::npos) { // is there ".book" in buffer ?
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
            isSearching = true;
            searchResults = data;
            searchMedias();
        }

        else if(command.commandName.compare("clear") == 0) {
            isSearching = false;
        }

        else if(command.commandName.compare("list") == 0) 
            printMedias();


        else if(command.commandName.compare("show") == 0) {
            showMediaID();
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
