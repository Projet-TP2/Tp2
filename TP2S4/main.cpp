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

void afficherConnexe (const std::vector<int> conexe)
{
    int rpz = conexe[(int)conexe.size()-1];
    for(int z =0; z< rpz ; z++){

            std::cout<< "composante connexe numéro"<< z+1 << ": " ;


            for(int r =0; r< (int)conexe.size()-1; r++){

                if(conexe[r]==z)
                    {
                    std::cout << r<< "\t ";
                    }

    }
    std::cout << " ;" << std::endl;

}
}

void chaineEulerienne (std::vector<int> grapheConnex, Graphe unGraphe)
{
    int nbConnex =grapheConnex[(int)grapheConnex.size()-1];
    int nbSuccImpaire=0;

    for (int a =0; a<nbConnex;a++)
    {
        for(int b=0; b<(int)grapheConnex.size()-1;b++)
        {
            if(grapheConnex[b]==a)
            {
                nbSuccImpaire = nbSuccImpaire+(unGraphe.nombredeChaines()[b]%2);

            }
        }
        if(nbSuccImpaire == 0 || nbSuccImpaire ==2)
        {

            std::cout <<"il y a une chaine eulerienne composer de: ";
            for(int c=0; c<(int)grapheConnex.size()-1;c++)
            {
                if(grapheConnex[c]==a)
                {
                    std::cout<< c << "\t";
                }
            }
            std::cout << "\t" <<std::endl;
        }
        nbSuccImpaire=0;
    }


}


int main() {
    size_t s0 = 0;
    Graphe graphique{"graphe-no-1.txt"};
    std::vector<int> arborescenceBFS;
    std::vector<int> arborescenceDFS;
    std::vector<int> connexxe;

    graphique.afficher();


    std::cout << std::endl << "BFS : Veuillez saisir le numéro du sommet initial pour la recherche du plus court chemin : ";
    std::cin >> s0;
    arborescenceBFS = graphique.BFS(s0);
    std::cout << "Plus courts chemins depuis le sommet " << s0 << " (BFS) : " << std::endl;
    afficherParcours(s0, arborescenceBFS);
    s0 = 0;
    std::cout << std::endl << "DFS : Veuillez saisir le numéro du sommet initial pour la recherche du plus court chemin : ";
    std::cin >> s0;
    arborescenceDFS = graphique.DFS(s0);
    std::cout << "Plus courts chemins depuis le sommet " << s0 << " (DFS) : " << std::endl;
    afficherParcours(s0, arborescenceDFS);

    connexxe = graphique.Connexe();

    afficherConnexe(connexxe);

    chaineEulerienne(connexxe,graphique);

    return 0;
}
