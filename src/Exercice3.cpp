#include <iostream>
#include <list>
#include <string>
using namespace std;

class TableHachage {
private:
    int capacite;                        
    list<pair<int, string>>* table;      
    int hachage(int cle) const {
        return cle % capacite;
    }
public:
   TableHachage(int taille) : capacite(taille) {
        table = new list<pair<int, string>>[capacite];
    }

    ~TableHachage() {
        delete[] table;
    }

    void inserer(int cle, const string& valeur) {
        int index = hachage(cle);
        for (auto& p : table[index]) {
            if (p.first == cle) {
                p.second = valeur;
                cout << "Cle" << cle << " mise a jour avec " << valeur << endl;
                return;
            }
        }
        table[index].push_back({cle, valeur});
    }

    string rechercher(int cle) const {
        int index = hachage(cle);
        for (const auto& p : table[index]) {
            if (p.first == cle) return p.second;
        }
        return ""; 
    }


    void supprimer(int cle) {
        int index = hachage(cle);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == cle) {
                table[index].erase(it);
                cout << "Cle " << cle << " supprimee" << endl;
                return;
            }
        }
        cout << "Cle " << cle << " non trouvee" << endl;
    }

    void afficher() const {
        for (int i = 0; i < capacite; i++) {
            cout << "[" << i << "] : ";
            for (const auto& p : table[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }
};
int main() {
    TableHachage table(5);

    table.inserer(1, "Omar");
    table.inserer(2, "Safaa");     
    table.inserer(3, "Marwa");

    table.afficher();

    cout << "Cle 1 : " << table.rechercher(1) << endl;

    table.supprimer(3);

    table.afficher();

    return 0;
}

