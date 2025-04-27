// builder.hpp
#ifndef BUILDER_H
#define BUILDER_H

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "parser.h"
#include "ABB.h"
#include "AVL.h"
#include "NIF.h"

class Builder {
private:
    Parser& parser_;
public:
    Builder(Parser& p) : parser_(p) {
        std::srand(std::time(nullptr)); // Semilla para random
    }

    AB<NIF>* buildTree() {
        AB<NIF>* tree;
        if (parser_.isAVL())
            tree = new AVL<NIF>(parser_.isTrace());
        else
            tree = new ABB<NIF>();

        if (parser_.getInitMode() == "manual") {
            // árbol vacío
        }
        else if (parser_.getInitMode() == "random") {
            for (int i = 0; i < parser_.getSize(); ++i) {
                std::string random_nif = generateRandomNIF();
                NIF nif(random_nif);
                tree->insertar(nif);
                std::cout << "Insertado random: " << random_nif << std::endl;
            }
        }
        else if (parser_.getInitMode() == "file") {
            std::ifstream file(parser_.getFilename());
            if (!file.is_open()) {
                std::cerr << "Error al abrir fichero " << parser_.getFilename() << std::endl;
                return tree;
            }
            std::string line;
            int count = 0;
            while (std::getline(file, line) && count < parser_.getSize()) {
                if (line.empty()) continue;
                NIF nif(line);
                tree->insertar(nif);
                std::cout << "Insertado desde fichero: " << line << std::endl;
                count++;
            }
            file.close();
        }

        return tree;
    }

private:
    std::string generateRandomNIF() {
        std::string nif;
        for (int i = 0; i < 8; ++i) {
            nif += '0' + (std::rand() % 10);
        }
        nif += 'A' + (std::rand() % 26);
        return nif;
    }
};

#endif // BUILDER_HPP
