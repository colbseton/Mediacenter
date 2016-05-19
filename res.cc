#include <iostream>

#include "res.h"
#include "tools.h"


ResNum::ResNum() {

}

ResNum::~ResNum() {

}


bool ResNum::findInfo(std::string str) {
    /* compare str to object attributes, searching for
       what the user asks 
    */
    bool var = false;
    auto strc = str.c_str();

    var =           compareStrLow(name, str);
    var = var ||    compareStrLow(type, str);
    var = var ||    compareStrLow(author, str);
    var = var ||    compareStrLow(webUrl, str);

    return var;
}


void ResNum::createMedia(){
    std::cout << "Ajout d'une ressource numérique  ..." << std::endl;

    std::cout << "Nom du fichier : ";
    get_input(name);

    std::cout << "Format du fichier : ";
    get_input(type);

    std::cout << "Auteur du fichier : ";
    get_input(author);

    std::cout << "Adresse sur le serveur ";
    get_input(webUrl);
}



void ResNum::print() const{
    std::string extension = ".res";
    std::string nameSimple = name;

    // delete the extension ".ResNum" in the title
    if(name.find(".res") != std::string::npos)
        nameSimple = nameSimple.replace( name.find( extension.c_str() ), 
                                         extension.length(), "" );

    std::cout << "nom : "     << nameSimple   << std::endl;
    std::cout << "type : "    << type         << std::endl;
    std::cout << "auteur : "  << author       << std::endl;
    std::cout << "URL : "     << webUrl       << std::endl;
    std::cout << "ID : "      << id           << std::endl << std::endl;
}


void ResNum::loadMedia(std::string const& fileName, std::string readFromFile){
    /* splits a string read from the database and fills 
       the object fields 
    */
    std::vector<std::string> splitted = split(readFromFile, '|');

    name    = splitted[0];
    type    = splitted[1];
    author  = splitted[2];
    webUrl  = splitted[3];
    id      = std::stoi( splitted[4] );

}


void ResNum::saveMedia(std::string const& fileName, int& FLAG) const {
    /* writing at the end of file, 
       ios::app specifies 
       to write at the end of file 
       ios::trunc rewrites everything
    */

    std::ofstream streamFile(fileName.c_str(), (FLAG == 0) ? std::ios::app : std::ios::trunc);

    if(streamFile.is_open()) {
        if(name.find(".res") != std::string::npos)
            streamFile << name << '|';

        else streamFile << name << ".res" << '|';

        streamFile << type    << '|'
                   << author  << '|'
                   << webUrl  << '|'
                   << id      << std::endl;

        std::cout << "media res_num \"" << name <<  "\" " 
                  << "saved into : " 
                  << fileName         << std::endl;
    }
    else
        std::cout << "error could not open the file : " << fileName
                  << std::endl;

}

