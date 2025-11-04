#include <iostream>
#include <vector>
#include <stdexcept> 
#include <algorithm> 
using namespace std;
template <typename T>
class Pile {
private:
    vector<T> elements; 
public:
    void empiler(const T& element) {
        elements.push_back(element);
    }
    
    T depiler() {
        if (estVide())
            throw runtime_error(" Pile vide !");
        T sommetElem = elements.back();
        elements.pop_back();
        return sommetElem;
    }

    T sommet() const {
        if (estVide())
            throw runtime_error(" Pile vide !");
        return elements.back();
    }

    bool estVide() const {
        return elements.empty();
    }

    void inverser() {
        reverse(elements.begin(), elements.end());
    }

    void afficher() const {
        cout << "[ ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
            cout << *it << " ";
        cout << "]" << endl;
    }
};

int main() {
    try {
        Pile<int> pileInt;
        pileInt.empiler(15);
        pileInt.empiler(23);
        pileInt.empiler(33);
        cout << "Pile d'entiers : ";
        pileInt.afficher();

        cout << "Sommet : " << pileInt.sommet() << endl;

        pileInt.inverser();
        cout << "Après inversion : ";
        pileInt.afficher();

        pileInt.depiler();
        cout << "Après depilage : ";
        pileInt.afficher();
        
        Pile<string> pileStr;
        pileStr.empiler("Omar");
        pileStr.empiler("Safaa");
        pileStr.empiler("Marwa");
        cout << "\nPile de chaines : ";
        pileStr.afficher();

        Pile<double> pileDouble;
        pileDouble.empiler(1.3);
        pileDouble.empiler(2.1);
        cout << "\nPile de doubles : ";
        pileDouble.afficher();

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

