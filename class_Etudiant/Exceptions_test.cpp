#include <iostream>
#include <vector>


using namespace std;

class Etudiant {

private:
    string nom;
    string prenom;
    int id;
    string filiere;
    vector<int> notes;
    
public:
    static int nombreEtudiant;
    Etudiant(){
        this->id = nombreEtudiant++;
    }
    Etudiant(string a, string b,string c,vector<int> n) { 
        this->nom = a;
        this->prenom = b;
        this->filiere = c;
        this->id = nombreEtudiant++;
        for (int i(0); i < 3; i++)
        {
            this->notes.push_back(n[i]);
        }
    } // Constructeur avec parametre
        
    Etudiant(const Etudiant& E) { 
        this->nom = E.nom;
        this->prenom = E.prenom;
        this->filiere = E.filiere;
        this->id = nombreEtudiant++;
        for (int i(0); i < 3; i++)
        {
            this->notes.push_back(E.notes[i]);
        }
         } // Constructeur de recopie
    ~Etudiant() {} // Deconstructeur
    void afficher() const {
        cout << "===Etudiant Numero: " << this->id << endl;
        cout << "Nom: " << this->nom << endl;
        cout << "Prenom: " << this->prenom << endl;
        cout << "filiere: " << this->filiere << endl;
        cout << "Notes: " << endl;
        for (int i(0); i < this->notes.size(); i++)
        {
            cout << this->notes[i] << endl;
        }
         }
    static int nombreEtudiants(){
        return nombreEtudiant;
    }
    
    friend bool operator==(const Etudiant& E1, const Etudiant& E2) {
        if (E1.nom == E2.nom && E1.prenom == E2.prenom &&
            E1.filiere == E2.filiere && E1.notes[0] == E2.notes[0] && E1.notes[1] == E2.notes[1]
            && E1.notes[2] == E2.notes[2])
        {
            return true;
        }
        return false;
    }
};


int Etudiant::nombreEtudiant = 1;

int main()
{
    Etudiant e1("lozad", "achraf", "informatique", { 11,14,15 }), e2("asffar", "hassan", "informatique", { 15,12,17 }), e3(e2), e4("saadali", "anwar", "industriel", {12,14,10});

    e1.afficher();
    cout << endl;
    e2.afficher();
    cout << endl;
    e3.afficher();
    cout << endl;
    e4.afficher();
    cout << endl << endl;

    if (e2 == e3)
    {
        cout << "Etudiant 2 est Egale a l'Etudiant 3 \n";
    }
    if (!(e3 == e4))
    {
        cout << "Etudiant 3 n'est pas Egale a l'Etudiant 4 \n";
    }

}




