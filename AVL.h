// avl.hpp
#ifndef AVL_H
#define AVL_H

#include "ABB.h"
#include "nodeAVL.h"

template<class Key>
class AVL : public ABB<Key> {
private:
    bool traza;
public:
    AVL(bool trace = false) : traza(trace) {}

    bool insertar(const Key& k) override {
        bool crece = false;
        return insertar_rec((NodoAVL<Key>*&)this->raiz, k, crece);
    }

protected:
    bool insertar_rec(NodoAVL<Key>*& nodo, const Key& k, bool& crece) {
        if (!nodo) {
            nodo = new NodoAVL<Key>(k);
            crece = true;
            return true;
        }
        if (k == nodo->get_dato()) {
            crece = false;
            return false;
        }
        bool result;
        if (k < nodo->get_dato()) {
            result = insertar_rec((NodoAVL<Key>*&)nodo->get_izdo(), k, crece);
            if (crece) ajustar_izquierda(nodo, crece);
        } else {
            result = insertar_rec((NodoAVL<Key>*&)nodo->get_dcho(), k, crece);
            if (crece) ajustar_derecha(nodo, crece);
        }
        return result;
    }

    void ajustar_izquierda(NodoAVL<Key>*& nodo, bool& crece) {
        switch (nodo->get_bal()) {
            case 1:
                nodo->get_bal() = 0;
                crece = false;
                break;
            case 0:
                nodo->get_bal() = -1;
                crece = true;
                break;
            case -1:
                if (traza) {
                    std::cout << "Desbalanceo II en nodo " << nodo->get_dato() << "\n";
                }
                rotacion_II(nodo);
                crece = false;
                break;
        }
    }

    void ajustar_derecha(NodoAVL<Key>*& nodo, bool& crece) {
        switch (nodo->get_bal()) {
            case -1:
                nodo->get_bal() = 0;
                crece = false;
                break;
            case 0:
                nodo->get_bal() = 1;
                crece = true;
                break;
            case 1:
                if (traza) {
                    std::cout << "Desbalanceo DD en nodo " << nodo->get_dato() << "\n";
                }
                rotacion_DD(nodo);
                crece = false;
                break;
        }
    }

    void rotacion_II(NodoAVL<Key>*& nodo) {
        NodoAVL<Key>* aux = (NodoAVL<Key>*)nodo->get_izdo();
        nodo->get_izdo() = aux->get_dcho();
        aux->get_dcho() = nodo;
        nodo->get_bal() = 0;
        nodo = aux;
    }

    void rotacion_DD(NodoAVL<Key>*& nodo) {
        NodoAVL<Key>* aux = (NodoAVL<Key>*)nodo->get_dcho();
        nodo->get_dcho() = aux->get_izdo();
        aux->get_izdo() = nodo;
        nodo->get_bal() = 0;
        nodo = aux;
    }
};

#endif // AVL_HPP
