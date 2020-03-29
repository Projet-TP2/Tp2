//
// Created by Antoine Hintzy on 16/03/2020.
//

#ifndef TP2_TG_GRAPHE_H
#define TP2_TG_GRAPHE_H

#include <iostream>
#include <vector>
#include <string>
#include "Sommet.h"

class Graphe {
private:
    bool m_estOriente;
    std::vector<Sommet*> m_sommets;
public:
    Graphe(std::string cheminFichierGraphe);
    ~Graphe();
    void afficher() const;
    std::vector<int> BFS(int numero_s0) const;
};


#endif //TP2_TG_GRAPHE_H
