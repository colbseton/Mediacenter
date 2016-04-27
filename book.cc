#include <iostream>

#include "book.h"
#include "tools.h" 

Book::Book() {

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
}


void Book::print() const {
    std::string extension = ".book";
    std::string titleSimple = title;
    titleSimple = titleSimple.replace(title.find(extension.c_str()), extension.length(), "");

    std::cout << "titre : " << titleSimple << std::endl;
    std::cout << "autheur : " << author << std::endl;
    std::cout << "petit résumé : " << recap << std::endl;
    std::cout << "édition : " << edition << std::endl;
    std::cout << "année : " << year << std::endl;
    std::cout << "pages : " << nbPages << std::endl;
}


void Book::loadMedia(std::string const fileName, std::string readFromFile) {
    std::vector<std::string> splitted = split(readFromFile, '|');

    title = splitted[0];
    author = splitted[1];
    recap = splitted[2];
    edition = splitted[3];
    year = std::atoi(splitted[4].c_str());
    nbPages = std::atoi(splitted[5].c_str());
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
                   << nbPages  << std::endl;

        std::cout << "medias \"" << title << ".book \" " << "saved into : " 
                  << fileName << std::endl;

        /* penser à fermer le fichier */
    }

    else 
        std::cout << "error could not open the file : " << fileName 
                  << std::endl;

}


