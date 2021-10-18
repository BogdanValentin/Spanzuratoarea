#include <iostream>
#include <cstring>
using namespace std;

void desenrand1()
{
    cout << "__ __ __" << endl;
}
void desenrand2(int x)
{
    if (x == 0) // 0 fara lat
        cout << "|       " << endl;
    else if (x == 1) // 1 cu lat
        cout << "|      |" << endl;
}
void desenrand3(int x)
{
    if (x == 0) // 0 fara nimic
        cout << "|       " << endl;
    else if (x == 1) // 1 cu cap
        cout << "|      O" << endl;
}
void desenrand4(int x)
{
    if (x == 0) // 0 fara nimic
        cout << "|         " << endl;
    else if (x == 1) // 1 doar corp
        cout << "|      |  " << endl;
    else if (x == 2) // 2 corp+mana dreapta
        cout << "|      |\\" << endl;
    else if (x == 3) // 3 corp+mana dreapta+mana stanga
        cout << "|     /|\\" << endl;
}
void desenrand5(int x)
{
    if (x == 0) // 0 fara nimic
        cout << "|         " << endl;
    else if (x == 1) // 1 doar corp
        cout << "|       \\" << endl;
    else if (x == 2) // 2 corp+mana dreapta
        cout << "|     / \\" << endl;
}
void desenrand6()
{
    cout << "|         " << endl;
}
void desene(int greseli) // desene pentru fiecare numar de greseli. (as putea si aici sa fac niste mini desene).
{
    switch (greseli) {

    case 0:
        desenrand1();
        desenrand2(0);
        desenrand3(0);
        desenrand4(0);
        desenrand5(0);
        desenrand6();
        break;

    case 1:
        desenrand1();
        desenrand2(0);
        desenrand3(1);
        desenrand4(0);
        desenrand5(0);
        desenrand6();
        break;

    case 2:
        desenrand1();
        desenrand2(0);
        desenrand3(1);
        desenrand4(1);
        desenrand5(0);
        desenrand6();
        break;

    case 3:
        desenrand1();
        desenrand2(0);
        desenrand3(1);
        desenrand4(2);
        desenrand5(0);
        desenrand6();
        break;

    case 4:
        desenrand1();
        desenrand2(0);
        desenrand3(1);
        desenrand4(3);
        desenrand5(0);
        desenrand6();
        break;

    case 5:
        desenrand1();
        desenrand2(0);
        desenrand3(1);
        desenrand4(3);
        desenrand5(1);
        desenrand6();
        break;

    case 6:
        desenrand1();
        desenrand2(0);
        desenrand3(1);
        desenrand4(3);
        desenrand5(2);
        desenrand6();
        break;

    case 7:
        desenrand1();
        desenrand2(1);
        desenrand3(1);
        desenrand4(3);
        desenrand5(2);
        desenrand6();
        break;
    }
}
int main()
{
    int greseli, aparitii, counter = 0;
    unsigned int i;                                                 // am declarat unsigned pt ca apareau niste avertismente.
    char cuvant[50], cuvantascuns[50], litera, stopper, literegresite[50];

    do
    {
        if (counter > 0)                                            // de cate ori am jucat pana acum (de cand am deschis consola).
        {
            for (i = 0; i < 50; i++)
                cuvantascuns[i] = '\0';                               // dam clear la cuvantascuns.
            for (i = 1; i <= 15; i++)
                cout << "\n\n\n\n\n";                                 // dam clear la consola.
        }

        cout << "Bun venit la jocul Spanzuratoarea!\nScrieti cuvantul: \n";
        cin.getline(cuvant, 50);
        for (i = 0; i < strlen(cuvant); i++)
        {
            cuvantascuns[i] = '*';                                  //cuvantul ascuns va fi de forma "****** **** ****".
            if (cuvant[i] >= 65 && cuvant[i] <= 90)                 // daca litera de pe poz i este majuscula
                cuvant[i] = cuvant[i] + 32;                         // o facem mica pentru a fi comparata mai usor.
            if (cuvant[i] == ' ')
                cuvantascuns[i] = ' ';                              // atentie ca spatiile sunt luate ca atare, nu drept caractere ce trebuie ghicite.
        }

        cuvantascuns[strlen(cuvant)] = '\0';                          //ultimul caracter este adaugat fortat pentru a delimita sirul (apar buguri ciudate fara acest pas cum ar fi simboluri nonsense).

        greseli = 0;                                                // contor ce ne ajuta la stabilirea desenului si cand sa ne oprim (la 7 greseli este spanzurat).

        while (greseli <= 6 && strchr(cuvantascuns, '*') != NULL)     // daca avem mai putin de 7 greseli si inca mai sunt caractere necunoscute continuam.
        {
            for (i = 1; i <= 15; i++)
                cout << "\n\n\n\n\n";                                 // dam clear la consola.
            desene(greseli);                                        // afisam desen
            cout << endl;
            cout << cuvantascuns << endl;
            if (greseli > 0)
            {
                cout << "Litere gresite: ";
                for (int i = 1; i <= greseli; i++)
                    cout << literegresite[i] << " ";
            }

            cout << endl;

            cout << "Litera dvs.:";
            cin >> litera;                                            // citim litera ghicita.
            aparitii = 0;
            for (unsigned int i = 0; i < strlen(cuvant); i++)
                if (cuvant[i] == litera)
                {
                    aparitii++;
                    cuvantascuns[i] = litera;                       // daca litera apare in poz i o adaugam in cuvantascuns.
                }
            if (aparitii == 0)                                       // daca litera ghicita nu apare niciodata inseamna ca e gresita.
            {
                greseli++;
                literegresite[greseli] = litera;
            }

        }

        if (greseli == 7)                                            // daca pierdem jocul aratam desenul final si ce cuvant era.
        {
            for (i = 1; i <= 15; i++)
                cout << "\n\n\n\n\n";
            desene(greseli);
            cout << endl;
            cout << "Cuvantul era " << cuvant << "." << endl;
        }
        else                                                        // daca castigam jocul aratam desenul la care am ramas si ce cuvant era
        {
            for (i = 1; i <= 15; i++)
                cout << "\n\n\n\n\n";
            desene(greseli);
            cout << endl;
            cout << "Cuvantul era " << cuvant << "." << endl;
        }

        cout << "Doriti sa jucati in continuare? (Y/N)\n";            // acceptam o litera drept raspuns.
        cin >> stopper;                                               // daca litera nu este Y,y,N sau n atunci eroare si recitim.
        while (stopper != 'Y' && stopper != 'y' && stopper != 'N' && stopper != 'n')
        {
            cout << "Eroare\n";
            cout << "Doriti sa jucati in continuare? (Y/N)\n";
            cin >> stopper;
        }
        if (counter == 0)                                            // nu are rost sa contorizam daca jucam mai mult de 2 ori, testul e doar pt a da clear la consola
            counter++;

        cin.ignore();                                               // necesar pt a citi cu getline mai sus
    } while (stopper == 'y' || stopper == 'Y');                       // daca stopper este y sau Y reluam jocul.

    cout << endl << "Merci de joc :D" << endl;

    return 0;
}
