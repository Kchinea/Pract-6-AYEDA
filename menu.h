#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "AB.h"

template<typename Key>
void menu(AB<Key>* tree) {
    int opcion = -1;
    while (opcion != 0) {
        std::cout << "\n[0] Salir\n[1] Insertar clave\n[2] Buscar clave\n[3] Mostrar inorden\nOpcion: ";
        std::cin >> opcion;
        if (opcion == 1) {
            Key valor;
            std::cout << "Introducir clave: ";
            std::cin >> valor;
            if (tree->insertar(valor))
                std::cout << "Insertado correctamente.\n";
            else
                std::cout << "No se pudo insertar (duplicado).\n";
            std::cout << *tree;
        }
        else if (opcion == 2) {
            Key valor;
            std::cout << "Introducir clave: ";
            std::cin >> valor;
            if (tree->buscar(valor))
                std::cout << "Clave encontrada.\n";
            else
                std::cout << "Clave no encontrada.\n";
        }
        else if (opcion == 3) {
            std::cout << "Recorrido inorden: ";
            tree->inorden();
        }
    }
}

#endif // MENU_HPP
