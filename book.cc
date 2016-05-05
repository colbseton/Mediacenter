#include <iostream>

#include "book.h"
#include "tools.h" // <ctime>

Book::Book() {

}


bool Book::findInfo(std::string str) {
    /* compare str to object attributes, searching for
       what the user asks */

    bool var = false;
    auto strc = str.c_str();

    var = title.find(strc) != std::string::npos;
    var = var || author.find(strc) != std::string::npos;
    var = var || recap.find(strc) != std::string::npos;
    var = var || edition.find(strc) != std::string::npos;

    var = var || year == std::atoi(strc) || nbPages == std::atoi(strc);
    return var;
}


void Book::createMedia() {
    std::cout << "Ajout d'un livre..." << std::endl;

    std::cout << "Nom du titre : ";
    get_input(title);

    std::cout << "Nom de l'auteur : ";
    get_input(author);

    std::cout << "Petit résumé : ";
    get_input(recap);

    std::cout << "Éditon : ";
    get_input(edition);

    std::cout << "Année de parution : ";
    std::cin >> year;

    std::cout << "Nombre de pages : ";
    std::cin >> nbPages;

    id = std::rand();
}


void Book::print() const {
    std::string extension = ".book";
    std::string titleSimple = title;

    // delete the extension ".book" in the title
    if(title.find(".book") != std::string::npos)
        titleSimple = titleSimple.replace(title.find(extension.c_str()), extension.length(), "");

    std::cout << "titre : " << titleSimple  << std::endl;
    std::cout << "auteur : " << author      << std::endl;
    std::cout << "petit résumé : " << recap << std::endl;
    std::cout << "édition : " << edition    << std::endl;
    std::cout << "année : " << year         << std::endl;
    std::cout << "pages : " << nbPages      << std::endl ;
    std::cout << "ID :" << id               << std::endl << std::endl;
}


void Book::loadMedia(std::string const fileName, std::string readFromFile) {
    /* splits a string read from the database and fills 
       the object fields */

    std::vector<std::string> splitted = split(readFromFile, '|');

    title = splitted[0];
    author = splitted[1];
    recap = splitted[2];
    edition = splitted[3];
    year = std::atoi(splitted[4].c_str());
    nbPages = std::atoi(splitted[5].c_str());
    id = std::atoi(splitted[6].c_str());
}


void Book::saveMedia(std::string const fileName) const {
    /* writing at the end of file */
    std::ofstream streamFile(fileName.c_str(), std::ios::app);

    if(streamFile.is_open()) {
        streamFile << title    << ".book|" 
                   << author   << '|' 
                   << recap    << '|'   
                   << edition  << '|'    
                   << year     << '|'   
                   << nbPages  << '|'
                   << id       << std::endl;

        std::cout << "medias \"" << title << ".book \" " << "saved into : " 
                  << fileName << std::endl;

        /* penser à fermer le fichier */
    }

    else 
        std::cout << "error could not open the file : " << fileName 
                  << std::endl;

}


