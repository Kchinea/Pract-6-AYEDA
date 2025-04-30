#ifndef ABB_H
#define ABB_H

#include "AB.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  bool insertar(const Key& k) override {
    return insertar_rec(this->raiz, k);
  }

  bool buscar(const Key& k) const override {
    return buscar_rec(this->raiz, k);
  }

 protected:
  bool insertar_rec(NodoB<Key>*& nodo, const Key& k) {
    if (!nodo) {
      nodo = new NodoB<Key>(k);
      return true;
    }
    if (k == nodo->get_dato()) {
      return false;
    }
    if (k < nodo->get_dato()) {
      return insertar_rec(nodo->get_izdo(), k);
    } else {
      return insertar_rec(nodo->get_dcho(), k);
    }
  }

  bool buscar_rec(NodoB<Key>* nodo, const Key& k) const {
    if (!nodo) return false;
    if (k == nodo->get_dato()) return true;
    if (k < nodo->get_dato()) return buscar_rec(nodo->get_izdo(), k);
    else return buscar_rec(nodo->get_dcho(), k);
  }
};

#endif
