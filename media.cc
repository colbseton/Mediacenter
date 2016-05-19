#include "media.h"

#include "book.h" 

#include "cd.h"

#include "vhs.h"
#include "dvd.h"

#include "res.h"

Mediacenter::Mediacenter() {
    isSearching = false;
    userType = USER;
}

Mediacenter::~Mediacenter() {
    myClearFree<Media>(data);
}


void Mediacenter::resetMedias() {
    myClearFree<Media>(data);
    searchResults.clear();

    isSearching = false;

    std::ofstream streamFile(mediaFile.c_str(), std::ios::trunc);

    if(streamFile.is_open())
        streamFile << "";
}


void Mediacenter::deleteMediaID() {
    int idToFind = std::atoi(command.arg.c_str());

    /* deleting the ID from the data vector */
    auto it = std::remove_if(data.begin(),
                             data.end(),
                             [idToFind](Media* obj) { return obj->id == idToFind; });

    data.erase(it);

    // rewriting
    saveMedias(1);

    delete (*it); // the object was created with "new" 
}


void Mediacenter::showMediaID() {
    int idToFind = std::atoi(command.arg.c_str());
    bool findId = false;

    auto it = std::find_if(data.begin(), 
                           data.end(), 
                           [idToFind](Media* obj) { return obj->id == idToFind; });

    if (it != data.end()) 
        (*it)->print(); 
    else 
        std::cout << "ressource non trouvée" << std::endl;      
}


void Mediacenter::searchMedias() {
    std::string strToFind = command.arg;

    std::vector<Media*> copy;

    /* filtering data vector with the search results.
       the predicat is our function findInfo.
       the results of the filter operation is inserted in the vector named
       "copy".
    */

    std::copy_if(searchResults.begin(), searchResults.end(),
                 std::back_inserter(copy), 
                 [strToFind](Media* obj){ return (obj->findInfo(strToFind)); });

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

    mediaFile = fileName; // for the record

    if(streamFile.is_open()) {
        while(getline(streamFile, buffer)) {

            if(buffer.find(".book") != std::string::npos) { // is there ".book" in buffer ?
                Book *newBook = new Book;
                newBook->loadMedia(fileName, buffer);
                data.push_back(newBook); // new media from a file, added to our media vector
            }

            else if(buffer.find(".cd") != std::string::npos) { 
                CD *newCD = new CD;
                newCD->loadMedia(fileName, buffer);
                data.push_back(newCD); 
            }

            else if(buffer.find(".vhs") != std::string::npos) { 
                VHS *newVHS = new VHS;
                newVHS->loadMedia(fileName, buffer);
                data.push_back(newVHS); 
            }

            else if(buffer.find(".dvd") != std::string::npos) { 
                DVD *newDVD = new DVD;
                newDVD->loadMedia(fileName, buffer);
                data.push_back(newDVD); 
            }

            else if(buffer.find(".res") != std::string::npos) { 
                ResNum *newResNum = new ResNum;
                newResNum->loadMedia(fileName, buffer);
                data.push_back(newResNum); 
            }
        }
        std::cout << "medias loaded from file : " << fileName << std::endl;
    }
    else 
        std::cout << "error could not open the file : " << fileName 
                  << std::endl;
}


void Mediacenter::saveMedias(int FLAG) {
    std::string fileName = (FLAG == 0) ? command.arg + ".media" : mediaFile;
    // ^ is it necessary to add ".media" extension or not ?

    for(auto it : data)
        it->saveMedia(fileName, FLAG);

    myClearFree<Media>(data);
    searchResults.clear();
}


void Mediacenter::readFileType() {
    if(command.commandName.compare("add") == 0) {

        if(command.arg.compare("book") == 0) {
            Book* newbook = new Book;
            newbook->createMedia();

            data.push_back(newbook); // new media added to our media vector
        }

        else if(command.arg.compare("cd") == 0) {
            CD* newCD = new CD;
            newCD->createMedia();

            data.push_back(newCD);
        }

        else if(command.arg.compare("vhs") == 0) {
            VHS *newVHS = new VHS;
            newVHS->createMedia();
            
            data.push_back(newVHS);
        }

        else if(command.arg.compare("dvd") == 0) {
            DVD *newDVD = new DVD;
            newDVD->createMedia();
            
            data.push_back(newDVD);
        }

        else if(command.arg.compare("resnum") == 0) {
            ResNum *newResNum = new ResNum;
            newResNum->createMedia();
            
            data.push_back(newResNum);
        }
            /* … */
    }
}

void Mediacenter::logToRoot(void) {
    std::string input("");

    std::cout << "password for root : ";
    get_input(input);

    if( userType == USER) {
        if( input.compare( getPasswd() ) == 0) {
            userType = ROOT;
        }

        else 
            std::cout << "wrong password, failed to log as root" << std::endl;
    }

    else 
        std::cout << "you are already logged as root" << std::endl;
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
            saveMedias(0);


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

        else if(command.commandName.compare("sudo") == 0) {
            logToRoot();
        }
        else if(command.commandName.compare("delete") == 0) {
            if(userType == ROOT)
                deleteMediaID();

            else std::cout << "you need to be logged as root" <<  std::endl;
        }

        else if(command.commandName.compare("reset") == 0) {
            if(userType == ROOT)
                resetMedias();

            else 
                std::cout << "you need to be logged as root" <<  std::endl;
        }

        else if (command.commandName.compare("bye") == 0) {
            std::cout << "Session terminated" << std::endl;
            std::exit(0);
            /* program stops */
        }
    }
}
