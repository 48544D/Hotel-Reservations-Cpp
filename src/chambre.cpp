#include "project.h"

int chambre::s_id_ch = 0;

ostream &operator<<(ostream &os, const chambre &c)
{
    cout << "\tchambre " << c.id_ch << " :"
         << "\n\t\tprix de chambre : " << c.prix 
         << "\n\t\tetat : " << boolalpha << c.reserve 
         << "\n\t\tcapacite : " << c.capacity;
    return os;
}

istream &operator>>(istream &is, chambre&c){
    cout << "\tchambre " << c.id_ch << " :";
    cout << "\n\t\tentrez le prix de la chambre : ";
    is >>c.prix;
    cout << "\t\tentrez la capacite : ";
    is >> c.capacity;
    return is;
}

int chambre::comparer(const chambre &ch)
{
    return (this->id_ch > ch.id_ch) ? 1 : (this->id_ch < ch.id_ch) ? -1
                                                                   : 0;
}

bool chambre::getReserve()
{
    return reserve;
}

void chambre::setReserve(bool reserve){
    this->reserve = reserve;
}

int chambre::getId(){
    return id_ch;
}