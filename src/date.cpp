#include "project.h"

int date::getYear()
{
    return this->year;
}

ostream &operator<<(ostream &os, const date &dt)
{
    os << dt.day << '/' << dt.month << '/' << dt.year;
    return os;
}

istream &operator>>(istream &is, date &dt){
    cout << "\tentrer le jour : ";
    is >> dt.day;
    while(dt.day > 31)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\tincorrect jour !\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\tentrer le jour : ";
        is >> dt.day;
    }

    cout << "\tentrez le mois : ";
    is >> dt.month;
    while (dt.month > 12)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\tincorrect mois !\n";
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\tentrer le mois : ";
        is >> dt.month;
    }

    cout << "\tentrez l'annee : ";
    is >> dt.year;

    return is;
}

bool operator<(const date& d, const date& d1){
    if (d.year < d1.year)
        return true;
    else if (d.month < d1.month && d.year == d1.year)
        return true;
    else if (d.day < d1.day && d.year == d1.year && d.month == d1.month)
        return true;
    return false;
}

bool operator>(const date& d, const date& d1){
    if (d.year > d1.year)
        return true;
    if (d.month > d1.month && d.year == d1.year)
        return true;
    if (d.day > d1.day && d.year == d1.year && d.month == d1.month)
        return true;
    return false;
}

int operator-(const date& d, const date& d1){
    int t[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int nbr_d = d.year * 365 + d.day;
    for (int i = 0; i < d.month - 1; i++)
    {
        nbr_d += t[i];
    }

    if (d.year%4 == 0 && d.year%400 == 0 && d.year%100 != 0 && d.month > 1)
    {
        nbr_d += 1;
    }
    
    int nbr_d1 = d1.year * 365 + d1.day;
    for (int i = 0; i < d1.month - 1; i++)
    {
        nbr_d1 += t[i];
    }

    if (d1.year%4 == 0 && d1.year%400 == 0 && d1.year%100 != 0 && d.month > 1)
    {
        nbr_d1 += 1;
    }
    
    return abs(nbr_d - nbr_d1);
}

bool operator==(const date& d, const date& d1){
    return !(d - d1);
}