#include "project.h"

int reservation::s_id_res = 0;

//ajouter chambre a reservation
void reservation::ajouter(chambre& ch){
    for (int i = 0; i < nbr_ch; i++)
    {
        if (t_ch[i].getId() == ch.getId())
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\nchambre existe deja\n";
            SetConsoleTextAttribute(hConsole, 6);
            return;
        }
    }
    
    if (ch.getReserve())
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\nchambre est deja reserve\n";
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    if (nbr_ch > 6)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\nnombre maximum des chambres atteint\n";
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    ch.setReserve(true);
    t_ch[nbr_ch] = ch;
    nbr_ch++;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "\nchambre ajoutee avec succes\n" << endl;
    SetConsoleTextAttribute(hConsole, 6);
}

//cout
ostream &operator<<(ostream &os, const reservation &r){
    os  << "id de reservation : " << r.id_res 
        << "\nclient : \n" << r.c
        << "\netat : " << r.etat 
        << "\nnombre de chambre : " << r.nbr_ch
        << "\nchambres : \n";
    for (int i = 0; i < r.nbr_ch; i++)
    {
        os << r.t_ch[i] << "\n";
    }
    os << "date de debut : " << r.date_debut_res;
    os << "\ndate de fin : " << r.date_fin_res;
    return os;
}

//cin
istream &operator>>(istream& is, reservation& r){
    cout << "reservation " << r.id_res << " : " << endl;


    //client
    cout << "client : \n";
    is >> r.c;


    //etat
    cout << "entrez l'etat : ";
    getline(is >> ws,r.etat);
    while (r.etat != "non valide" && r.etat != "valide"){
        SetConsoleTextAttribute(hConsole, 12);
        cout << "etat peut etre soit non valide ou valide\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "entrez l'etat : ";
        getline(is >> ws,r.etat);    
    }


    //nombres des chambres
    cout << "entrez le nombre des chambres : ";
    is >> r.nbr_ch;
    while (r.nbr_ch <= 0)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "nombre de chambre doit etre superiure strictement a zero\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "entrez le nombre des chambres : ";
        is >> r.nbr_ch;
    }
    while (r.nbr_ch > 7)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "nombre de chambres ne doit pas depasser 7 chambres\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "entrez le nombre des chambres : ";
        is >> r.nbr_ch;
    }


    //tableau des chambres
    r.t_ch = new chambre[r.nbr_ch];
    cout << "entrez les chambres : \n";
    for (int i = 0; i < r.nbr_ch; i++){
        is >> r.t_ch[i];
        r.t_ch[i].setReserve(true);
    }


    // date debut
    time_t rawtime = time(NULL);
    tm *today = localtime(&rawtime);
    date d((today->tm_mday), (today->tm_mon + 1), (today->tm_year + 1900));

    cout << "entrez la date de debut de reservation : \n";
    is >> r.date_debut_res;

    while (r.date_debut_res < d)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "la date de debut de reservation doit etre superieure ou egal la date d'aujourd'hui\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "entrez la date de debut de reservation : \n";
        is >> r.date_debut_res;
    }

    
    //date fin
    cout << "entrez la date de fin de reservation : \n";
    is >> r.date_fin_res;
    while (r.date_fin_res < r.date_debut_res)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "la date de la fin doit etre plus grande que la date de debut\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "entrez la date de fin de reservation : \n";
        is >> r.date_fin_res;
    }

    return is;
}

//duree d'une reservation
int reservation::duree(){
    return date_fin_res - date_debut_res;
}

//supprimer chambre du reservation
void reservation::supprimer_ch(chambre ch){
    if (!ch.getReserve()){
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\nchambre n'est pas reserve\n" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }

    if (this->nbr_ch < 2)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\nil y a qu'une seule chambre dans cette reservation\n" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        return;
    }
    

    for (int i = 0; i < nbr_ch; i++)
    {
        if (ch.getId() == t_ch[i].getId())
        {
            t_ch[i].setReserve(false);
            for (int j = i; j < nbr_ch; j++)
                t_ch[j] = t_ch[j+1];
            nbr_ch--;
            SetConsoleTextAttribute(hConsole, 2);
            cout << "\nchambre supprimee avec succes\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            return;
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nchambre n'existe pas dans la reservation\n" << endl;
    SetConsoleTextAttribute(hConsole, 6);
}

//changer l'etat
void reservation::setEtat(string s){
    if (s == "non valide" || s == "valide" || s == "annule")
        this->etat = s;
}

//etat du reservation
string reservation::getEtat(){
    return etat;
}

//client du reservation
client reservation::getClient(){
    return c;
}

//id du reservation
int reservation::getId(){
    return id_res;
}

//nombre du chambre dans une reservation
int reservation::getNbr_ch(){
    return nbr_ch;
}

//tableau des chambres d'une reservation
chambre* reservation::getT_ch(){
    return this->t_ch;
}

//date de debut d'une reservation
date reservation::getDate_debut_res(){
    return date_debut_res;
}

//date de fin d'une reservation
date reservation::getDate_fin_res(){
    return date_fin_res;
}

//si client existe dans un tableau de reservation
reservation r1;
reservation& tester_client(reservation *t, int n){
    string nom;
    cout << "entrez le nom du client : ";
    cin >> nom;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getClient().getNom() == nom)
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << "\nce client a effectue une reservation\n";
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\ninformation sur la reservation : \n\n";
            return t[i];
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nce client n'a effectue aucun reservation\n\n";
    SetConsoleTextAttribute(hConsole, 6);
    return r1;
}

//si reservation existe dans un tableau
reservation& tester_rsrv(reservation* t, int n){
    int id;
    cout << "entrez id du reservation : ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getId() == id)
        {
            cout << "\ninformation sur la reservation : \n\n";
            return t[i];
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\ncette reservation n'a ete pas effectue\n\n";
    SetConsoleTextAttribute(hConsole, 6);
    return r1;
}

//ajouter reservation a un tableau
void ajouter_rsrv(reservation r,reservation *t, int& n){
    for (int i = 0; i < n; i++)
    {
        if (t[i].getId() == r.getId())
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "reservation existe deja";
            SetConsoleTextAttribute(hConsole, 6);
            return;
        }
    }

    t[n] = r;
    n++;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "reservation ajoutee avec succes";
    SetConsoleTextAttribute(hConsole, 6);
}

//modifier une chambre d'une reservation du tableau
void alter_ch(reservation r, reservation *t, int n){
    int id;
    cout << "\nentrer l'id de chambre a modifier : ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getId() == r.getId())
        {
            for (int j = 0; j < t[i].getNbr_ch(); j++)
            {
                if (t[i].getT_ch()[j].getId() == id)
                {
                    chambre c;
                    cout << "nouvelle chambre : \n";
                    cin >> c;
                    c.setReserve(true);
                    t[i].getT_ch()[j] = c;
                    return;
                }
            }
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\nchambre n'existe pas dans la reservation donne\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            return;
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nreservation n'existe pas dans ce tableau\n";
    SetConsoleTextAttribute(hConsole, 6);
}

//supprimer une reservation du tableau
void delete_rsrv(reservation r,reservation *t, int& n){
    for (int i = 0; i < n; i++)
    {
        if (r.getId() == t[i].getId())
        {
            for (int j = i; j < arr_size-1; j++)
                t[j] = t[j+1];
            n--;
            SetConsoleTextAttribute(hConsole, 2);
            cout << "\nreservation supprimee avec succes" << endl;
            SetConsoleTextAttribute(hConsole, 6);
            return;
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nreservation n'existe pas dans ce tableau\n";
    SetConsoleTextAttribute(hConsole, 6);
}

//afficher tous les reservation du tableau
void show_rsrv(reservation *t ,int n){
    for (int i = 0; i < n; i++)
        cout << t[i] << endl << endl << endl;
}

//retourne tableau des reservation crée aujourd'hui
reservation* today_created_rsrv(reservation* t,int &n){
    // date d'aujourd'hui
    time_t rawtime = time(NULL);
    tm* today = localtime(&rawtime);
    date d((today->tm_mday),(today->tm_mon + 1),(today->tm_year + 1900));

    reservation* tr = new reservation[n];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getDate_debut_res() == d && t[i].getEtat() != "annule")
        {
            tr[c] = t[i];
            c++;
        }
    }
    n = c;
    return tr;
}

//retourne tableau des reservation qui vont expirer aujourd'hui
reservation *today_expire_rsrv(reservation *t, int &n)
{
    // date d'aujourd'hui
    time_t rawtime = time(NULL);
    tm *today = localtime(&rawtime);
    date d((today->tm_mday), (today->tm_mon + 1), (today->tm_year + 1900));

    reservation *tr = new reservation[n];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getDate_fin_res() == d && t[i].getEtat() != "annule")
        {
            tr[c] = t[i];
            c++;
        }
    }
    n = c;
    return tr;
}

//annule les reservation qui vont expirer aujourd'hui
void cancel_today_rsrv(reservation* t, int n){
    reservation* tr = today_expire_rsrv(t,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tr[i].getId() == t[j].getId())
            {
                t[i].setEtat("annule");
            }
        }
    }
}

//supprimer reservation par id
void delete_id_rsrv(reservation* t, int& n){
    int id;
    cout << "\nentrer l'id de reservation a supprime : ";
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getId() == id)
        {
            delete_rsrv(t[i],t,n);
            return;
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nreservation n'existe pas !";
    SetConsoleTextAttribute(hConsole, 6);
}

//supprimer reservation par nom du client
void delete_cl_rsrv(reservation* t, int& n){
    string nom;
    cout << "\nentrer le nom du client de reservation a supprime : ";
    cin >> nom;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getClient().getNom() == nom)
        {
            delete_rsrv(t[i],t,n);
            return;
        }
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\nreservation n'existe pas !";
    SetConsoleTextAttribute(hConsole, 6);
}