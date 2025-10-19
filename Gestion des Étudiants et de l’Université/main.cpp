#include <iostream>
#include <string>
using namespace std;

class Universite {
private:
    string nom;

public:

    Universite(const string& n) : nom(n) {
        cout << "[Cr�ation Universit�] " << nom << endl;
    }


    void afficherNom() const {
        cout << "Universit� : " << nom << endl;
    }


    string getNom() const { return nom; }
};


class Etudiant {
private:
    string nom;
    int age;
    Universite* universite;
    static int nbEtudiants;

public:
    // Constructeur
    Etudiant(const string& n, int a, Universite* u)
        : nom(n), age(a), universite(u) {
        nbEtudiants++;
        cout << "[Cr�ation �tudiant] " << nom << " (" << age << " ans)" << endl;
    }

    // Destructeur
    ~Etudiant() {
        nbEtudiants--;
        cout << "[Suppression �tudiant] " << nom << endl;
    }


    void afficher() const {
        cout << "�tudiant : " << nom
             << " | �ge : " << age
             << " | " << "Universit� : " << universite->getNom()
             << endl;
    }


    static void afficherTotal() {
        cout << "Nombre total d'�tudiants : " << nbEtudiants << endl;
    }
};


int Etudiant::nbEtudiants = 0;


int main() {
    cout << "=== D�but du programme ===" << endl;

    Universite u("Universit� de Casablanca");

    Etudiant e1("Amine", 20, &u);
    Etudiant e2("Sara", 21, &u);
    Etudiant e3("Hiba", 22, &u);

    cout << "\n--- Liste des �tudiants ---" << endl;
    e1.afficher();
    e2.afficher();
    e3.afficher();

    cout << "\n--- Statistiques ---" << endl;
    Etudiant::afficherTotal();

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
