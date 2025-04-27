#ifndef NODOAVL_H
#define NODOAVL_H

#include "node.h"

template<class Key>
class NodoAVL : public NodoB<Key> {
private:
    int bal;
public:
    NodoAVL(const Key& d, NodoB<Key>* i = nullptr, NodoB<Key>* dch = nullptr, int b = 0)
        : NodoB<Key>(d, i, dch), bal(b) {}

    int& get_bal() { return bal; }
};

#endif // NODOAVL_H
