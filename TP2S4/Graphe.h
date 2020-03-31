#ifndef GRAPHE_H
#define GRAPHE_H


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
    std::vector<int> DFS(int numero_s0) const;
    std::vector<int> Connexe() const;
    std::vector<int> nombredeChaines ()const;
};


#endif // GRAPHE_H
