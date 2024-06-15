#include <stdio.h>
#include <time.h>
enum choix {demarrer=1,configuration,aide};
void pageDaccueil()
{
    printf("\n\n\n\n\n\n"
           "                                                        UDBL DACTYLOGICIEL                                                            \n\n"
           "                                                            creer par                                                                  \n\n"
           "                                                     M'POYO BIN-NDALA PASCAL                                                              \n"
           "                                                   NGONGO WA NGONGO JEAN-PHILIPE                                                           \n"
           "                                                     TSHIMBELA KASONGO JOSEPH                                                               \n"
           "                                                     NGOY TSHIKWATA CHRISTIAN                                                            \n\n\n"
           );
    clock_t start_time=clock();
    clock_t current_time=clock();

    while((double)(current_time-start_time)/CLOCKS_PER_SEC < 1)
    {
        current_time=clock();

    }
    system("cls");
    accueilMenu();
}
void accueilMenu()
{
    //calculTemps();
    int nbreMot;
    system("cls");
    enum choix des = demarrer;
    printf("\n\n\n\n\n\n\n\n\n\n"
           "                                                         1.demarrer\n\n\n"
           "                                                         2.configuration \n\n\n"
           "                                                         3.aide\n\n");
    scanf("%d",&des);
    switch(des)
    {
    case demarrer:
        system("cls");
        calculTemps();
        break;

    case configuration :
        system("cls");
        modeDaccesAdministrateur();
        break;
    case aide:
        system("cls");
        informationDuJeux();
        break;
    default:
        break;
    }
    //afficherCalculTemps();
}
