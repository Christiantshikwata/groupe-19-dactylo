#include "jeux.h"
#include "configuration.h"
#include "accueil.h"
#include "windows.h"

int main()
{
    /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0 | BACKGROUND_INTENSITY);*/
    system("color 80");
    pageDaccueil();
    //accueilMenu();
    //ajoutDesMots();
    //
    //modeDaccesAdministrateur();
    //calculTemps(0);
    //demarrageDuJeux(nbreMot);
    //remplissageTableau();
    return 0;
}
