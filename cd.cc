#include <iostream>

#include "cd.h"
#include "tools.h"

CD::CD() {

}

CD::~CD() {

}


bool CD::findInfo(std::string str) {
    /* compare str to object attributes, searching for
       what the user asks 
    */
    bool var = false;
    auto strc = str.c_str();

    var =           compareStrLow(title, str);
    var = var ||    compareStrLow(genre, str);
    var = var ||    compareStrLow(author, str);
    var = var ||    compareStrLow(label, str);

    var = var || nbTrack == std::atoi(strc) || length == std::atoi(strc);

    return var;
}


void CD::createMedia() {
    std::cout << "Ajout d'un cd..." << std::endl;

    std::cout << "Nom du titre : ";
    get_input(title);

    std::cout << "Nom de l'auteur : ";
    get_input(author);

    std::cout << "Maison de disque : ";
    get_input(label);

    std::cout << "Genre : ";
    get_input(genre);

    std::cout << "Nombre de piste : ";
    std::cin >> nbTrack;

    std::cout << "Duree du cd : ";
    std::cin >> length;

    id = std::rand();
}


void CD::print() const {
    std::string extension = ".cd";
    std::string titleSimple = title;

    // delete the extension ".cd" in the title
    if(title.find(".cd") != std::string::npos)
        titleSimple = titleSimple.replace( title.find( extension.c_str() ), 
                                           extension.length(), "" );

    std::cout << "artiste :"            << author       << std::endl;
    std::cout << "titre :"              << titleSimple  << std::endl;
    std::cout << "genre :"              << genre        << std::endl;
    std::cout << "durée :"              << length       << std::endl;
    std::cout << "nombre de piste: "    << nbTrack      << std::endl;
    std::cout << "maison de disque : "  << label        << std::endl;
    std::cout << "ID :"                 << id           << std::endl << std::endl;
}


void CD::loadMedia(std::string const& fileName, std::string readFromFile) {
    /* splits a string read from the database and fills 
       the object fields 
    */

    std::vector<std::string> splitted = split(readFromFile, '|');

    title   = splitted[0];
    author  = splitted[1];
    genre   = splitted[2];
    length  = std::stoi( splitted[3] );
    nbTrack = std::stoi( splitted[4] );
    label   = splitted[5];
    id      = std::stoi( splitted[6] );
}


void CD::saveMedia(std::string const& fileName, int& FLAG) const {
    /* writing at the end of file, ios::app specifies 
       to write at the end of file 
       ios::trunc rewrites everything
    */

    std::ofstream streamFile(fileName.c_str(), (FLAG == 0) ? std::ios::app : std::ios::trunc);

    if(streamFile.is_open()) {
        if(title.find(".cd") != std::string::npos)
            streamFile << title << '|';

        else streamFile << title << ".cd" << '|';

        streamFile << author    << '|'
                   << genre     << '|'
                   << length    << '|'
                   << nbTrack   << '|'
                   << label     << '|'
                   << id        << std::endl;

        std::cout << "media cd \"" << title <<  "\" " 
                  << "saved into : " 
                  << fileName         << std::endl;
    }

    else
        std::cout << "error could not open the file : " << fileName
                  << std::endl;

}


