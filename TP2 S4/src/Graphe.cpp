#include "Graphe.h"

#include "Graphe.h"
#include <fstream>
#include <queue>
#include <stack>

Graphe::Graphe(std::string cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if(!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    ifs >> m_estOriente;
    if(ifs.fail()) {
        throw std::runtime_error("Probl�me de lecture de l'orientation du graphe.");
    }
    int ordre;
    ifs >> ordre;
    if(ifs.fail()) {
        throw std::runtime_error("Probl�me de lecture de l'ordre du graphe.");
    }
    int taille;
    ifs >> taille;
    if(ifs.fail()) {
        throw std::runtime_error("Probl�me de lecture de la taille du graphe.");
    }
    for(int i=0; i<ordre; ++i) {
        m_sommets.push_back(new Sommet(i));
    }
    int num1, num2;
    for(int i=0; i<taille; ++i) {
        ifs >> num1 >> num2;
        if(ifs.fail()) {
            throw std::runtime_error("Probl�me de lecture d'un.e arc/ar�te.");
        }
        m_sommets[num1]->addSuccesseur(m_sommets[num2]);
        if(!m_estOriente && num1 < num2) {
            m_sommets[num2]->addSuccesseur(m_sommets[num1]);
        }
    }
}

Graphe::~Graphe() {
    for(auto addrSommet : m_sommets) {
        delete addrSommet;
    }
}

void Graphe::afficher() const {
    std::cout << std::endl << "Graphe ";
    std::cout << (m_estOriente ? "orient�" : "non orient�") << std::endl;
    std::cout << "Ordre : " << m_sommets.size() << std::endl;
    std::cout << "Liste d'adjacences : " << std::endl;
    for(auto addrSommet : m_sommets) {
        addrSommet->afficher();
        std::cout << std::endl;
    }

}

// Algo parcoursBFS(s0)
std::vector<int> Graphe::BFS(int numero_s0) const {
    // 1. Tous les sommets sont blancs (non d�couverts)
    std::vector<int> couleurs((int) m_sommets.size(), 0);
    // 2. Cr�er une file vide
    std::queue<const Sommet*> file;
    std::vector<int> predecesseurs((int) m_sommets.size(), -1);
    // 3. Enfiler s0 ; s0 devient gris
    file.push(m_sommets[numero_s0]);
    couleurs[numero_s0] = 1; // 0 = blanc, 1 = gris, 2 = noir
    const Sommet* s;
    // 4. Tant que la file n�est pas vide :
    while(!file.empty()) {
        // 4.1 D�filer le prochain sommet s de la file (Traitement �ventuel sur s)
        s = file.front();
        file.pop();
        // 4.2 Pour chaque successeur s� blanc (non d�couvert) de s :
        for(auto succ : s->getSuccesseurs()) {
            if(couleurs[succ->getNumero()] == 0) { // blanc
                // 4.2.1 Enfiler s�; s� devient gris
                file.push(succ);
                couleurs[succ->getNumero()] = 1; // gris
                // 4.2.2 Noter que s est le pr�d�cesseur de s�
                predecesseurs[succ->getNumero()] = s->getNumero();
            }
        }
        // 4.3 s devient noir (explor�)
        couleurs[s->getNumero()] = 2;
    }
    return predecesseurs;
}


// Algo parcoursDFS(s0)
std::vector<int> Graphe::DFS(int numero_s0) const {
    // 1. Tous les sommets sont blancs (non d�couverts)
    std::vector<int> couleurs((int) m_sommets.size(), 0);
    // 2. Cr�er une pile vide
    std::stack<const Sommet*> pile;
    std::vector<int> predecesseurs((int) m_sommets.size(), -1);
    // 3. Empiler s0 ; s0 devient gris
    pile.push(m_sommets[numero_s0]);
    couleurs[numero_s0] = 1; // 0 = blanc, 1 = gris, 2 = noir
    const Sommet* s;
    // 4. Tant que la pile n�est pas vide :
    while(!pile.empty()) {
        // 4.1 D�filer le prochain sommet s de la pile (Traitement �ventuel sur s)
        s = pile.top();
        pile.pop();
        // 4.2 Pour chaque successeur s� blanc (non d�couvert) de s :
        for(auto succ : s->getSuccesseurs()) {
            if(couleurs[succ->getNumero()] == 0) { // blanc
                // 4.2.1 Enfiler s�; s� devient gris
                pile.push(succ);
                couleurs[succ->getNumero()] = 1; // gris
                // 4.2.2 Noter que s est le pr�d�cesseur de s�
                predecesseurs[succ->getNumero()] = s->getNumero();
            }
        }
        // 4.3 s devient noir (explor�)
        couleurs[s->getNumero()] = 2;
    }
    return predecesseurs;
}




// composantes connexes
std::vector<std::vector<int>> Graphe:: connexe()const {
    std::vector<std::vector<int>> composantconnexe;
    int sommchch =0;
    int nbcomposantsconnexes = 0;
    while(sommchch < 15)
    {
        size_t i=0,e=0;
        while(composantconnexe[i][e] != sommchch)
        {

            if(e > composantconnexe[i].size())
            {
                e =0;
                i++;
            }
            if(i > composantconnexe.size())
            {
                e=0;
                i=0;
                sommchch++;
            }

            e++;
        }



    // 1. Tous les sommets sont blancs (non d�couverts)
    std::vector<int> couleurs((int) m_sommets.size(), 0);
    // 2. Cr�er une pile vide
    std::stack<const Sommet*> pile;
    std::vector<int> predecesseurs((int) m_sommets.size(), -1);
    // 3. Empiler s0 ; s0 devient gris
    pile.push(m_sommets[sommchch]);
    couleurs[sommchch] = 1; // 0 = blanc, 1 = gris, 2 = noir
    const Sommet* s;
    // 4. Tant que la pile n�est pas vide :
    while(!pile.empty()) {
        // 4.1 D�filer le prochain sommet s de la pile (Traitement �ventuel sur s)
        s = pile.top();
        pile.pop();
        // 4.2 Pour chaque successeur s� blanc (non d�couvert) de s :
        for(auto succ : s->getSuccesseurs()) {
            if(couleurs[succ->getNumero()] == 0) { // blanc
                // 4.2.1 Enfiler s�; s� devient gris
                pile.push(succ);
                couleurs[succ->getNumero()] = 1; // gris
                // 4.2.2 Noter que s est le pr�d�cesseur de s�
                predecesseurs[succ->getNumero()] = s->getNumero();
            }
        }
        // 4.3 s devient noir (explor�)
        couleurs[s->getNumero()] = 2;
        composantconnexe[nbcomposantsconnexes].push_back(s->getNumero());
    }
    }
    return composantconnexe;
}
