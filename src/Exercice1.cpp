#include <iostream>
using namespace std;
class Noeud{
 public:

    int valeur;
    Noeud* suivant;
    
    Noeud(int v) : valeur(v), suivant(NULL) {}
};
class ListeChainee{
 private:
 	   Noeud* tete;

public:
    ListeChainee(): tete(nullptr) {}
     void ajouterDebut(int valeur) {
        Noeud* nv = new Noeud(valeur);
        nv->suivant = tete;
        tete = nv;
    }
    void ajouterFin(int valeur){
    	  Noeud* nv = new Noeud(valeur);
    	if (!tete) { 
            tete = nv;
            return;
        }  
        Noeud* courant = tete;
        while(courant->suivant!=NULL){
        	courant=courant->suivant;
		}
		courant->suivant=nv;
    	
	}
    void supprimer(int valeur){
   	  if(tete == nullptr) return;
      if(tete->valeur==valeur){
       	Noeud* temp = tete;
        tete = tete->suivant;
        delete temp;
        return;
	   }
	    Noeud* courant = tete;
        while (courant->suivant && courant->suivant->valeur != valeur)
        courant = courant->suivant;	
        if (courant->suivant) {
        Noeud* temp = courant->suivant;
        courant->suivant = temp->suivant;
        delete temp;
        }
	}	
    void afficher() const {
    Noeud* courant = tete;
    while (courant != NULL) {
        cout << courant->valeur << " -> ";
        courant = courant->suivant;
    }
    cout << "NULL" << endl;
  }
  ~ListeChainee() {
    while (tete != NULL) {
        Noeud* temp = tete;
        tete = tete->suivant;
        delete temp;
    }
}
  int taille() const {
        int compteur = 0;
        Noeud* courant = tete;
        while (courant) {
            compteur++;
            courant = courant->suivant;
        }
        return compteur;
    }
};
int main() {
    ListeChainee liste;

    liste.ajouterDebut(1);
    liste.ajouterDebut(2);
    liste.ajouterFin(3);
    liste.ajouterFin(4);

    cout << "Liste  : ";
    liste.afficher();

    cout << "Taille de la liste : " << liste.taille() << endl;

    liste.supprimer(2);
    cout << "Apres suppression de 2 : ";
    liste.afficher();

    cout << "Taille finale : " << liste.taille() << endl;

    return 0;
}

