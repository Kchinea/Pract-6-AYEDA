#ifndef AB_H
#define AB_H

#include <queue>
#include <iostream>
#include "node.h"

template<class Key>
class AB {
  protected:
    NodoB<Key>* raiz;
  public:
    AB() : raiz(nullptr) {}
    virtual ~AB() {}
    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;
    void inorden() const {
      inorden_rec(raiz);
      std::cout << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const AB<Key>& tree) {
      if (!tree.raiz) {
        os << "Nivel 0: [.]";
        return os;
      }
      std::queue<NodoB<Key>*> q;
      q.push(tree.raiz);
      int nivel = 0;
      while (!q.empty()) {
        int n = q.size();
        os << "Nivel " << nivel++ << ": ";
        for (int i = 0; i < n; ++i) {
          NodoB<Key>* node = q.front();
          q.pop();
          if (node) {
            os << "[" << node->get_dato() << "] ";
            q.push(node->get_izdo());
            q.push(node->get_dcho());
          } else {
            os << "[.] ";
            q.push(nullptr);
            q.push(nullptr);
          }
        }
        os << "\n";
        bool allNull = true;
        std::queue<NodoB<Key>*> temp(q);
        while (!temp.empty()) {
          if (temp.front() != nullptr) {
            allNull = false;
            break;
          }
          temp.pop();
        }
        if (allNull) break;
      }
      return os;
    }

  private:
    void inorden_rec(NodoB<Key>* nodo) const {
      if (nodo) {
        inorden_rec(nodo->get_izdo());
        std::cout << nodo->get_dato() << " ";
        inorden_rec(nodo->get_dcho());
      }
    }
};

#endif
