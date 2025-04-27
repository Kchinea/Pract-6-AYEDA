// main.cpp
#include <iostream>

#include "parser.h"
#include "builder.h"
#include "menu.h"
#include "NIF.h"

int main(int argc, char* argv[]) {
    Parser parser(argc, argv);
    Builder builder(parser);

    AB<NIF>* tree = builder.buildTree();
    std::cout << *tree;
    menu(tree);
    delete tree;
}
