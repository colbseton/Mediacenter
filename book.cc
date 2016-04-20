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

void Book::affiche() const {
    std::cout << "titre : " << title << std::endl;
}