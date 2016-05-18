#include <iostream>

#include "vhs.h"
#include "tools.h"

VHS::VHS() {

}

VHS::~VHS() {

}


bool VHS::findInfo(std::string str) {
    /* compare str to object attributes, searching for
       what the user asks 
    */
    bool var = false;
    auto strc = str.c_str();

    var =           compareStrLow(title, str);
    var = var ||    compareStrLow(author, str);
    var = var ||    compareStrLow(label, str);

    var = var || length == std::atoi(strc);

    return var;
}


void VHS::createMedia(){
     std::cout << "Ajout d'une video VHS ..." << std::endl;

    std::cout << "Nom du titre : ";
    get_input(title);

    std::cout << "Nom de l'auteur : ";
    get_input(author);

    std::cout << "Maison de production : ";
    get_input(label);

    std::cout << "Durée de la video: ";
    std::cin >> length;
}



void VHS::print() const{
    std::string extension = ".vhs";
    std::string titleSimple = title;

    // delete the extension ".vhs" in the title
    if(title.find(".vhs") != std::string::npos)
        titleSimple = titleSimple.replace( title.find( extension.c_str() ), 
                                           extension.length(), "" );

    std::cout << "Titre :"              << titleSimple  << std::endl;
    std::cout << "Auteur :"             << author       << std::endl;
    std::cout << "durée :"              << length       << std::endl;
    std::cout << "maison de disque : "  << label        << std::endl << std::endl;

}


void VHS::loadMedia(std::string const& fileName, std::string readFromFile){
    /* splits a string read from the database and fills 
       the object fields 
    */

    std::vector<std::string> splitted = split(readFromFile, '|');

    title   = splitted[0];
    author  = splitted[1];
    length  = std::stoi( splitted[2] );
    label   = splitted[3];
    id      = std::stoi( splitted[4] );

}


void VHS::saveMedia(std::string const& fileName, int& FLAG) const {
    /* writing at the end of file, ios::app specifies 
       to write at the end of file 
       ios::trunc rewrites everything
    */

    std::ofstream streamFile(fileName.c_str(), (FLAG == 0) ? std::ios::app : std::ios::trunc);

    if(streamFile.is_open()) {
        if(title.find(".vhs") != std::string::npos)
            streamFile << title << '|';

        else streamFile << title << ".vhs" << '|';

        streamFile << author  << '|'
                   << length  << '|'
                   << label   << '|'
                   << id      << std::endl;

        std::cout << "media vhs \"" << title <<  "\" " 
                  << "saved into : " 
                  << fileName         << std::endl;
    }

    else
        std::cout << "error could not open the file : " << fileName
                  << std::endl;

}

