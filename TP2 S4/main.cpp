#include <iostream>
#include "Graphe.h"

void afficherParcours(size_t s0, const std::vector<int>& precesseur) {
    for(size_t i = 0; i < precesseur.size(); ++i) {
        if (i != s0) {
            if(precesseur[i] != -1) {
                std::cout << i << " <--- ";
                size_t j = precesseur[i];
                while(j != s0) {
                    std::cout << j << " <--- ";
                    j = precesseur[j];
                }
                std::cout << j << std::endl;
            }
        }
    }
}

void afficherConnexe (const std::vector<std::vector<int>>& conexe)
{
    for (size_t e=0; e < conexe.size(); ++e)
    {
        std::cout << "composante connexe: ";
        for (size_t r =0; r < conexe[e].size();++r)
        {
            std::cout << conexe[e][r] << " ";
        }
        std::cout <<" "<<std::endl;
    }
}

int main() {
    size_t s0 = 0;
    Graphe g{"graphe-no-1.txt"};
    std::vector<int> arborescenceBFS;
    std::vector<int> arborescenceDFS;
    std::vector<std::vector<int>> connexxe;
    g.afficher();
    std::cout << std::endl << "BFS : Veuillez saisir le numéro du sommet initial pour la recherche du plus court chemin : ";
    std::cin >> s0;
    arborescenceBFS = g.BFS(s0);
    std::cout << "Plus courts chemins depuis le sommet " << s0 << " (BFS) : " << std::endl;
    afficherParcours(s0, arborescenceBFS);
    s0 = 0;
    std::cout << std::endl << "DFS : Veuillez saisir le numéro du sommet initial pour la recherche du plus court chemin : ";
    std::cin >> s0;
    arborescenceDFS = g.DFS(s0);
    std::cout << "Plus courts chemins depuis le sommet " << s0 << " (DFS) : " << std::endl;
    afficherParcours(s0, arborescenceDFS);
    std::cout << "affichage des composantes connexe" << std::endl;
    connexxe = g.connexe();
    std::cout << "1" << std::endl;
    afficherConnexe(connexxe);
    return 0;
}
