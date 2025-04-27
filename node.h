#ifndef NODE_H
#define NODE_H

template<class Key>
class NodoB {
protected:
    Key dato;
    NodoB* izdo;
    NodoB* dcho;
public:
    NodoB(const Key& d, NodoB* i = nullptr, NodoB* dch = nullptr)
        : dato(d), izdo(i), dcho(dch) {}

    Key& get_dato() { return dato; }
    NodoB*& get_izdo() { return izdo; }
    NodoB*& get_dcho() { return dcho; }
};

#endif // NODOB_HPP
