#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
static const int arr_size = 50;

// client
class client
{
private:
    string nom;
    string prenom;
    string adrs;
    string tel;
    int id_c;
public:
    static int s_id_c;
    client(string nom = "", string prenom = "", string adrs = "", string tel = "")
    {
        this->nom = nom;
        this->prenom = prenom;
        this->adrs = adrs;
        this->tel = tel;
        s_id_c++;
        this->id_c = s_id_c;
    }
    friend ostream &operator<<(ostream& os, const client& c);
    friend istream &operator>>(istream &is, client &c);
    int getId();
    string getNom();
};
ostream &operator<<(ostream& os, const client& c);
istream &operator>>(istream &is, client &c);


// chambre
class chambre
{
private:
    int prix;
    bool reserve;
    int capacity;
    int id_ch;
public:
    static int s_id_ch;
    chambre(int prix = 0, bool reserve = false, int capacity = 0){
        this->prix = prix;
        this->reserve = reserve;
        this->capacity = capacity;
        s_id_ch++;
        this->id_ch = s_id_ch;
    }
    friend ostream &operator<<(ostream& os, const chambre& c);
    friend istream &operator>>(istream &is, chambre &c);
    int comparer(const chambre &ch);
    bool getReserve();
    void setReserve(bool);
    int getId();
};
ostream &operator<<(ostream& os, const chambre& c);
istream &operator>>(istream &is, chambre &c);


// date
class date
{
private:
    int day;
    int month;
    int year;
public:
    date(int day = 0, int month = 0, int year = 0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int getYear();
    friend ostream &operator<<(ostream &os, const date &dt);
    friend istream &operator>>(istream &is,date &dt);
    friend bool operator<(const date&, const date&);
    friend bool operator>(const date &d, const date &d1);
    friend int operator-(const date& d, const date& d1);
    friend bool operator==(const date& d, const date& d1);
};
ostream &operator<<(ostream &os, const date &dt);
istream &operator>>(istream &is,date &dt);
bool operator<(const date &, const date &);
bool operator>(const date &d, const date &d1);


// reservation
class reservation
{
private:
    int nbr_ch;
    string etat;
    chambre *t_ch;
    client c;
    date date_debut_res, date_fin_res;
    int id_res;
public:
    static int s_id_res;
    reservation(int nbr_ch = 0, string etat = "", chambre *t_ch = nullptr, client c = client(), date date_debut_res = date(), date date_fin_res = date())
    {
        this->nbr_ch = nbr_ch;
        if (nbr_ch < 8)
        {
            t_ch = new chambre[nbr_ch];
        }else
            t_ch = new chambre[7];
        
        for (int i = 0; i < this->nbr_ch; i++)
        {
            this->t_ch[i] = t_ch[i];
            t_ch[i].setReserve(true);
        }
        this->etat = etat;
        if (this->etat != "non valide" || this->etat != "valide" || this->etat != "annule")
            this->etat = "non valide";
        this->c = c;
        this->date_debut_res = date_debut_res;
        this->date_fin_res = date_fin_res;
        s_id_res++;
        this->id_res = s_id_res;
    }
    void ajouter(chambre&);
    friend ostream &operator<<(ostream& os, const reservation& r);
    friend istream &operator>>(istream& is, reservation& r);
    int duree();
    void supprimer_ch(chambre);
    void setEtat(string);
    string getEtat();
    client getClient();
    int getId();
    int getNbr_ch();
    chambre* getT_ch();
    date getDate_debut_res();
    date getDate_fin_res();
};
ostream &operator<<(ostream &os, const reservation &r);
istream &operator>>(istream &is, reservation &r);
reservation& tester_client(reservation *,int n);
reservation& tester_rsrv(reservation *,int n);
void ajouter_rsrv(reservation r, reservation *t, int& n);
void alter_ch(reservation r, reservation *t, int n);
void delete_rsrv(reservation r, reservation *t, int& n);
void show_rsrv(reservation *t, int n);
reservation *today_created_rsrv(reservation *t, int &n);
reservation *today_expire_rsrv(reservation *t, int &n);
void cancel_today_rsrv(reservation *t, int n);
void delete_id_rsrv(reservation *t, int &n);
void delete_cl_rsrv(reservation *t, int &n);


//menus
void menu();
void menu_ch();
void menu_c();
void menu_r();