#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    string auteur;
    int annee;
    static int nbLivres;
public:
    // 🔹 Constructeur
    Livre(const string& t, const string& a, int an) : titre(t), auteur(a), annee(an) {
        nbLivres++;
        cout << "[Constructeur] Livre \"" << titre << "\" cree." << endl;
    }

    //  Destructeur
    ~Livre() {
        nbLivres--;
        cout << "[Destructeur] Livre \"" << titre << "\" supprime." << endl;
    }

    void afficher() const {
        cout << "Titre : " << titre
             << " | Auteur : " << auteur
             << " | Année : " << annee << endl;
    }

    // Méthode statique pour afficher le total
    static void afficherTotal() {
        cout << "Nombre total de livres : " << nbLivres << endl;
    }
};


int Livre::nbLivres = 0;

int main() {
    cout << "=== Debut du programme ===" << endl;

    Livre l1("1984", "George Orwell", 1949);
    Livre l2("Le Petit Prince", "Antoine de Saint-Exupery", 1943);
    Livre l3("L'Etranger", "Albert Camus", 1942);

    cout << "\n--- Details des livres ---" << endl;
    l1.afficher();
    l2.afficher();
    l3.afficher();

    cout << "\n--- Total actuel ---" << endl;
    Livre::afficherTotal();
    cout << "=== Fin du programme ===" << endl;
    return 0;
}
