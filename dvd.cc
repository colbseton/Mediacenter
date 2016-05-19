#include <iostream>

#include "dvd.h"
#include "vhs.h"
#include "tools.h"


DVD::DVD() {

}

DVD::~DVD() {

}


bool DVD::findInfo(std::string str) {
    /* compare str to object attributes, searching for
       what the user asks 
    */
    bool var = false;
    auto strc = str.c_str();

    var =           compareStrLow(title, str);
    var = var ||    compareStrLow(author, str);
    var = var ||    compareStrLow(label, str);

    var = var || length == std::atoi(strc);
    var = var || nbChapters == std::atoi(strc);

    return var;
}


void DVD::createMedia(){
     std::cout << "Ajout d'un DVD ..." << std::endl;

    std::cout << "Nom du titre : ";
    get_input(title);

    std::cout << "Nom de l'auteur : ";
    get_input(author);

    std::cout << "Maison de production : ";
    get_input(label);

    std::cout << "Durée du DVD: ";
    std::string buffer("");
    get_input(buffer);
    length = std::atoi( buffer.c_str() );

    std::cout << "Nombre de chapitres : ";
    buffer = "";
    get_input(buffer);
    nbChapters = std::atoi( buffer.c_str() );
}



void DVD::print() const{
    std::string extension = ".dvd";
    std::string titleSimple = title;

    // delete the extension ".DVD" in the title
    if(title.find(".dvd") != std::string::npos)
        titleSimple = titleSimple.replace( title.find( extension.c_str() ), 
                                           extension.length(), "" );

    std::cout << "titre : "                  << titleSimple  << std::endl;
    std::cout << "auteur : "                 << author       << std::endl;
    std::cout << "durée : "                  << length       << std::endl;
    std::cout << "nombre de chapitres : "    << nbChapters   << std::endl;
    std::cout << "maison de production : "   << label        << std::endl;
    std::cout << "ID : "                     << id           << std::endl << std::endl;

}


void DVD::loadMedia(std::string const& fileName, std::string readFromFile){
    /* splits a string read from the database and fills 
       the object fields 
    */
    std::vector<std::string> splitted = split(readFromFile, '|');

    title      = splitted[0];
    author     = splitted[1];
    length     = std::stoi( splitted[2] );
    label      = splitted[3];
    nbChapters = std::stoi( splitted[4] );
    id         = std::stoi( splitted[5] );

}


void DVD::saveMedia(std::string const& fileName, int& FLAG) const {
    /* writing at the end of file, 
       ios::app specifies 
       to write at the end of file 
       ios::trunc rewrites everything
    */

    std::ofstream streamFile(fileName.c_str(), (FLAG == 0) ? std::ios::app : std::ios::trunc);

    if(streamFile.is_open()) {
        if(title.find(".dvd") != std::string::npos)
            streamFile << title << '|';

        else streamFile << title << ".dvd" << '|';

        streamFile << author     << '|'
                   << length     << '|'
                   << label      << '|'
                   << nbChapters << '|'
                   << id         << std::endl;

        std::cout << "media dvd \"" << title <<  "\" " 
                  << "saved into : " 
                  << fileName         << std::endl;
    }
    else
        std::cout << "error could not open the file : " << fileName
                  << std::endl;

}

