#include <iostream>

#include "book.h"
#include "tools.h"


Book::Book() {

}

Book::~Book() {

}


bool Book::findInfo(std::string str) {
    /* compare str to object attributes, searching for
       what the user asks 
    */
    bool var = false;
    auto strc = str.c_str();

    var =           compareStrLow(title, str);
    var = var ||    compareStrLow(author, str);
    var = var ||    compareStrLow(recap, str);
    var = var ||    compareStrLow(edition, str);

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

    std::string buffer("");
    std::cout << "Année de parution : ";
    get_input(buffer);
    year = std::atoi( buffer.c_str() );

    std::cout << "Nombre de pages : ";
    buffer = "";
    get_input(buffer);
    nbPages = std::atoi( buffer.c_str() );

    id = std::rand();
}


void Book::print() const {
    std::string extension = ".book";
    std::string titleSimple = title;

    // delete the extension ".book" in the title
    if(title.find(".book") != std::string::npos)
        titleSimple = titleSimple.replace( title.find( extension.c_str() ), 
                                          extension.length(), "" );

    std::cout << "titre : "         << titleSimple  << std::endl;
    std::cout << "auteur : "        << author       << std::endl;
    std::cout << "petit résumé : "  << recap        << std::endl;
    std::cout << "édition : "       << edition      << std::endl;
    std::cout << "année : "         << year         << std::endl;
    std::cout << "pages : "         << nbPages      << std::endl ;
    std::cout << "ID :"             << id           << std::endl << std::endl;
}


void Book::loadMedia(std::string const& fileName, std::string readFromFile) {
    /* splits a string read from the database and fills 
       the object fields 
    */
    std::vector<std::string> splitted = split(readFromFile, '|');

    title   = splitted[0];
    author  = splitted[1];
    recap   = splitted[2];
    edition = splitted[3];
    year    = std::stoi( splitted[4] );
    nbPages = std::stoi( splitted[5] );
    id      = std::stoi( splitted[6] );

}


void Book::saveMedia(std::string const& fileName, int& FLAG) const {
    /* writing at the end of file, ios::app specifies 
       to write at the end of file 
       ios::trunc rewrites everything
    */
    std::ofstream streamFile(fileName.c_str(), (FLAG == 0) ? std::ios::app : std::ios::trunc);

    if(streamFile.is_open()) {
        if(title.find(".book") != std::string::npos)
            streamFile << title << '|';

        else streamFile << title << ".book" << '|';


        streamFile << author   << '|' 
                   << recap    << '|'   
                   << edition  << '|'    
                   << year     << '|'   
                   << nbPages  << '|'
                   << id       << std::endl;

        std::cout << "media book \"" << title <<  "\" " 
                  << "saved into : " 
                  << fileName         << std::endl;
    }

    else 
        std::cout << "error could not open the file : " << fileName 
                  << std::endl;

}





