#include "project.h"

int client::s_id_c = 0;

ostream &operator<<(ostream &os, const client &c){
    os << "\tclient " << c.id_c << " :";
    os << "\n\t\tnom du client : " << c.nom;
    os << "\n\t\tprenom du client : " << c.prenom;
    os << "\n\t\tadresse du client : " << c.adrs;
    os << "\n\t\tnumero de telephone du client : " << c.tel;
    return os;
}

istream &operator>>(istream& is, client &c){
    cout << "\tclient " << c.id_c << " :";
    cout << "\n\t\tentrez le nom client : ";
    is >> c.nom;
    cout << "\t\tentrez le prenom du client : ";
    is >> c.prenom;
    cout << "\t\tentrez l'adresse du client : ";
    is >> c.adrs;
    bool check = true;
    while(check){
        cout << "\t\tentrez le numero du telephone : ";
        is >> c.tel;

        for (size_t i = 0; i < c.tel.length(); i++)
        {
            if (!isdigit(c.tel[i]))
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\t\tnumero du telephone invalide \n";
                SetConsoleTextAttribute(hConsole, 6);
                check = true;
                break;
            }else check = false;
        }

        if (c.tel.length() != 10 && check == false)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\tnumero du telephone doit contenir 10 characteres. \n";
            SetConsoleTextAttribute(hConsole, 6);
            check = true;
        }
        else if (c.tel.length() == 10 && check == false)
            check = false;
    }
    return is;
}

int client::getId(){
    return id_c;
}

string client::getNom(){
    return nom;
}