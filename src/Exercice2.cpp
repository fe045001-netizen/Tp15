#include <iostream>
#include <stdexcept> 
#include <limits>
#include <sstream>


using namespace std;

class File {
private:
    int* donnees;
    int debut, fin, taille, capacite;

public:
    File(int cap) : capacite(cap), taille(0), debut(0), fin(-1) {
    donnees = new int[capacite];
   }
    ~File() {
    delete[] donnees;
   }
  
    void enfiler(int val){
    if (taille == capacite) throw runtime_error("File pleine");
    fin = (fin + 1) % capacite;
    donnees[fin] = val;
    taille++;
}

    int defiler() {
    if (taille == 0) throw runtime_error("File vide !");
    int val = donnees[debut];
    debut = (debut + 1) % capacite;
    taille--;
    return val;
}
    bool estVide() const {
    return taille == 0;
}
 bool estPleine() const {
        return taille >= capacite;
}
    void afficher() const{
    for (int i = 0; i < taille; i++) {
        int index = (debut + i) % capacite;
        cout << donnees[index] << " ";
    }
    cout << endl;
}
};
int main() {
    File file(5); 
    int choix, valeur;

    do {
        cout << "1. Enfiler " << endl;
        cout << "2. Defiler " << endl;
        cout << "3. Afficher la file" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

          switch (choix) {
         case 1: {
    cout << "Entrez une ou plusieurs valeurs a ajouter (separees par des espaces) : ";
    string ligne;
    getline(cin >> ws, ligne);
    istringstream iss(ligne);
    int v;
    while (iss >> v) {
        try {
            file.enfiler(v);
            cout << v << " ajoute !" << endl;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
            break;
        }
    }
    break;
}



            case 2:
                try {
                    cout << "Element retire : " << file.defiler() << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;

            case 3:
                file.afficher();
                break;

            case 4:
                cout << "Fin du programme." << endl;
                break;

            default:
                cout << "Choix invalide." << endl;
        }

    } while (choix != 4);

    return 0;
}
