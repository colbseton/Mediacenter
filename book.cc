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
    std::cout << "titre : " << title << std::endl;
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

        std::cout << "medias \"" << title << ".book \" " << "saved into :" 
                  << fileName << std::endl;
    }

    else 
        std::cout << "error could not open the file : " << fileName 
                  << std::endl;
}


