#include "project.h"

client* c = new client[arr_size];
reservation *r = new reservation[arr_size];
chambre* ch = new chambre[arr_size];
int nbr_ch = 0, nbr_c = 0, nbr_r = 0;

//main menu
void menu()
{
    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n-----Menu principal-----\n\n";
        SetConsoleTextAttribute(hConsole, 6);
        SetConsoleTextAttribute(hConsole, 6);
        int choice;
        cout << "1- menu des chambres\n"
             << "2- menu des clients\n"
             << "3- menu des reservations\n"
             << "votre choix : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            menu_ch();
            break;

        case 2:
            menu_c();
            break;

        case 3:
            menu_r();
            break;
            
        default:
            system("cls");
            exit(0);
        }
    }
}

//chambre menu
void menu_ch()
{
    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n-----Menu des chambres-----\n";
        SetConsoleTextAttribute(hConsole, 6);
        int choice;
        cout << "\n1- ajouter une nouvelle chambre\n"
             << "2- afficher tous les chambres\n"
             << "3- suprrimer une chambre par id\n"
             << "votre choix : ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Ajout des chambres-----\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_ch > 50)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nnombre maximum des chambres atteint";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int n;
            cout << "\nentrer le nombre des chambres a ajouter : ";
            cin >> n;
            while (n > 50)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nil ne faut pas depasser 50 chambres\n";
                SetConsoleTextAttribute(hConsole, 6);
                cout << "entrer le nombre des chambres a ajouter : ";
                cin >> n;
            }
            cout << endl;

            for (int i = nbr_ch; i < (nbr_ch+n); i++)
            {
                cin >> ch[i];
            }

            SetConsoleTextAttribute(hConsole, 2);
            cout << endl << "chambre ajoute\n\n";

            nbr_ch += n;

            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 2:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Affichage des chambres-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_ch == 0)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de chambres\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }
            
            for (int i = 0; i < nbr_ch; i++)
            {
                cout << ch[i] << endl;
            }
            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 3:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Supprimer chambre par id-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_ch < 1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de chambre\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int id;
            cout << "\nentrer l'id de chambre a supprime : ";
            cin >> id;
            for (int i = 0; i < nbr_ch; i++)
            {
                if (ch[i].getId() == id)
                {
                    for (int j = i; j < arr_size-1; j++)
                    {
                        ch[j] = ch[j + 1];
                    }
                    nbr_ch--;
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "\nchambre " << id << " supprimer\n\n";
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    menu_ch();
                }
            }
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\nchambre n'existe pas !\n\n";
            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        default:
            menu();
        }
    }
}

//client menu
void menu_c(){
    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n-----Menu des clients-----\n";
        SetConsoleTextAttribute(hConsole, 6);
        int choice;
        cout << "\n1- Ajouter un client\n"
             << "2- Afficher tous les clients\n"
             << "3- Supprimer des clients\n"
             << "votre choix : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Ajout des clients-----\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_c > 50)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nnombre maximum des clients atteint";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int n;
            cout << "\nentrer le nombre des clients a ajouter : ";
            cin >> n;
            while (n > 50)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nil ne faut pas depasser 50 clients\n";
                SetConsoleTextAttribute(hConsole, 6);
                cout << "entrer le nombre des clients a ajouter : ";
                cin >> n;
            }

            cout << endl;

            for (int i = nbr_c; i < (nbr_c + n); i++)
            {
                cin >> c[i];
            }
            nbr_c += n;
            SetConsoleTextAttribute(hConsole, 2);
            cout << "client ajoute\n\n";
            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 2:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Affichage des clients-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_c == 0){
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de client\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }
            for (int i = 0; i < nbr_c; i++)
            {
                cout << c[i] << endl;
            }

            cout << endl;

            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 3:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Supprimer des clients-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_c < 1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de client\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int choix;
            cout << "\n1- supprimer client par id"
                 << "\n2- supprimer client par nom"
                 << "\nvotre choix : ";
            cin >> choix;
            switch (choix)
            {
            case 1:
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, 9);
                cout << "\n-----Supprimer des clients-----\n\n";
                SetConsoleTextAttribute(hConsole, 6);
                int id;
                cout << "\nentrer l'id de client a supprime : ";
                cin >> id;
                for (int i = 0; i < nbr_c; i++)
                {
                    if (c[i].getId() == id)
                    {
                        for (int j = i; j < arr_size-1; j++)
                        {
                            c[j] = c[j+1];
                        }
                        nbr_c--;
                        SetConsoleTextAttribute(hConsole, 2);
                        cout << "\nclient " << id << " supprimer\n\n";
                        SetConsoleTextAttribute(hConsole, 14);
                        system("pause");
                        SetConsoleTextAttribute(hConsole, 6);
                        menu_c();
                    }
                }
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nclient n'existe pas !\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            case 2:
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, 9);
                cout << "\n-----Supprimer des clients-----\n\n";
                SetConsoleTextAttribute(hConsole, 6);
                string nom;
                cout << "\nentrer le nom de client a supprime : ";
                cin >> nom;
                for (int i = 0; i < nbr_c; i++)
                {
                    if (c[i].getNom() == nom)
                    {
                        for (int j = i; j < arr_size-1; j++)
                        {
                            c[j] = c[j+1];
                        }
                        nbr_c--;
                        SetConsoleTextAttribute(hConsole, 2);
                        cout << "\nclient " + nom + " supprimer\n\n";
                        SetConsoleTextAttribute(hConsole, 14);
                        system("pause");
                        SetConsoleTextAttribute(hConsole, 6);
                        menu_c();
                    }
                }
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nclient n'existe pas !\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            default:
                break;
            }
            break;
        }

        default:
            menu();
            break;
        }
    }
}

//reservation menu
void menu_r(){
    while (true)
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 9);
        cout << "\n-----Menu de reservation-----\n";
        SetConsoleTextAttribute(hConsole, 6);
        int choice;
        cout << "\n1- ajouter une reservation\n"
             << "2- afficher les reservations\n"
             << "3- supprimer une reservation\n"
             << "4- afficher les reservations qui vont expirer aujourd'hui\n"
             << "5- afficher les reservations creent aujourd'hui\n"
             << "6- rechercher une reservation\n"
             << "7- modifier une reservation\n"
             << "votre choix :";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Ajout des reservations-----\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_r > 50)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nnombre maximum des reservations atteint\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int n;
            cout << "\nentrer le nombre des reservation a ajouter : ";
            cin >> n;
            while (n > 50)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\nil ne faut pas depasser 50 resservations\n\n";
                SetConsoleTextAttribute(hConsole, 6);
                cout << "entrer le nombre des resservation a ajouter : ";
                cin >> n;
            }

            for (int i = nbr_r; i < (nbr_r + n); i++)
            {
                cin >> r[i];
                cout << endl;
            }
            nbr_r += n;
            SetConsoleTextAttribute(hConsole,2);
            cout << "reservation ajoute\n\n";
            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 2:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Affichage des reservations-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);

            if (nbr_r == 0)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de reservation\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            show_rsrv(r,nbr_r);

            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 3:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Supprimer des reservations-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_r < 1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de reservation\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int choix;
            cout << "\n1- supprimer reservation par id"
                 << "\n2- supprimer reservation par nom du client"
                 << "\nvotre choix : ";
            cin >> choix;
            switch (choix)
            {
                case 1:
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << "\n-----Supprimer une reservation par id-----\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    delete_id_rsrv(r,nbr_r);
                    cout << endl;
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    break;
                }
                
                case 2:
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << "\n-----Supprimer une reservation par nom de client-----\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    delete_cl_rsrv(r,nbr_r);
                    cout << endl;
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    break;
                }

                default:
                    break;
            }
            break;
        }

        case 4:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Reservations qui vont expirer aujourd'hui-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);

            int nbr_e = nbr_r;
            reservation *tr = today_expire_rsrv(r, nbr_e);

            if (nbr_e == 0){
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de reservation\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            show_rsrv(tr,nbr_e);

            int choix;
            cout << "\n1- annuler ces reservations"
                 << "\nvotre choix : ";
            cin >> choix;
            switch (choix)
            {
            case 1:
                cancel_today_rsrv(r,nbr_r);
                break;
            
            default:
                break;
            }
            break;
        }

        case 5:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Reservations creent aujourd'hui-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);

            int nbr_e = nbr_r;
            reservation *tr = today_created_rsrv(r, nbr_e);

            if (nbr_e == 0){
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de reservation\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            show_rsrv(tr,nbr_e);
            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);
            break;
        }

        case 6:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Recherche d'une reservation-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_r < 1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de reservation\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            int choix;
            cout << "\n1- recherche reservation par id"
                 << "\n2- recherche reservation par client"
                 << "\nvotre choix : ";
            cin >> choix;
            switch (choix)
            {
            case 1:
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, 9);
                cout << "\n-----Recherche d'une reservation par id-----\n\n";
                SetConsoleTextAttribute(hConsole, 6);
                reservation &rs = tester_rsrv(r, nbr_r);
                date d;
                if (rs.getDate_debut_res() == d)
                {
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    system("cls");
                    break;
                }
                cout << rs << endl << endl;
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }
            case 2:
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, 9);
                cout << "\n-----Recherche d'une reservation par client-----\n\n";
                SetConsoleTextAttribute(hConsole, 6);
                reservation &rs = tester_client(r, nbr_r);
                date d;
                if (rs.getDate_debut_res() == d)
                {
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    system("cls");
                    break;
                }
                cout << rs << endl << endl;
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }
            default:
                break;
            }
            break;
        }
        
        case 7:
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Modification d'une reservation-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);
            if (nbr_r < 1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "\tpas de reservation\n\n";
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                break;
            }

            reservation& rs = tester_rsrv(r, nbr_r);
            date d;
            if (rs.getDate_debut_res() == d)
            {
                SetConsoleTextAttribute(hConsole, 14);
                system("pause");
                SetConsoleTextAttribute(hConsole, 6);
                system("cls");
                break;
            }
            cout << rs << endl << endl;
            SetConsoleTextAttribute(hConsole, 14);
            system("pause");
            SetConsoleTextAttribute(hConsole, 6);


            system("cls");
            SetConsoleTextAttribute(hConsole, 9);
            cout << "\n-----Modification d'une reservation-----\n\n";
            SetConsoleTextAttribute(hConsole, 6);


            int choix;
            cout << "\n1- ajouter une chambre a une reservation"
                 << "\n2- supprimer une chambre d'une reservation"
                 << "\n3- modifier une chambre d'une reservation"
                 << "\n4- modifier l'etat d'une reservation"
                 << "\nvotre choix : ";
            cin >> choix;
            
            switch (choix)
            {
                case 1:{
                    system("cls");
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << "\n-----Ajouter une chambre d'une reservation-----\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    chambre c;
                    cin >> c;
                    rs.ajouter(c);
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    break;
                }

                case 2:
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << "\n-----Supprimer une chambre d'une reservation-----\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    int id;
                    cout << "entrez id du chambre : ";
                    cin >> id;
                    for (int i = 0; i < rs.getNbr_ch(); i++)
                    {
                        if (rs.getT_ch()[i].getId() == id)
                        {
                            rs.supprimer_ch(rs.getT_ch()[i]);
                            SetConsoleTextAttribute(hConsole, 14);
                            system("pause");
                            SetConsoleTextAttribute(hConsole, 6);
                            break;
                        }
                    }
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "\nchambre n'existe pas dans la reservation\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    break;
                }

                case 3:
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << "\n-----Modifier une chambre d'une reservation-----\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    alter_ch(rs,r,nbr_r);
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    break;
                }

                case 4:
                {
                    system("cls");
                    SetConsoleTextAttribute(hConsole, 9);
                    cout << "\n-----Modifer l'etat d'une reservation-----\n\n";
                    SetConsoleTextAttribute(hConsole, 6);
                    string etat;
                    cout << "entrer l'etat : ";
                    getline(cin >> ws, etat);
                    while (etat != "non valide" && etat != "valide" && etat != "annule")
                    {
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "etat peut etre soit annule , non valide ou valide\n";
                        SetConsoleTextAttribute(hConsole, 6);
                        cout << "entrez l'etat : ";
                        getline(cin >> ws, etat);
                    }
                    rs.setEtat(etat);

                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "\netat modifie\n\n";
                    SetConsoleTextAttribute(hConsole, 14);
                    system("pause");
                    SetConsoleTextAttribute(hConsole, 6);
                    break;
                }               
                default:
                    break;
            }
            break;
        }

        default:
            menu();
            break;
        }
    }
    
}