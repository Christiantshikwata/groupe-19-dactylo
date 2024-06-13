#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nombreMaximumDesMots 500
#define tailleMaximumDuMot 40
enum choix {demarrer=1,configuration,aide};
typedef struct joueur
{
    char nom[50];
    float score;
};
typedef struct listeDeNosMot
{
    char mot[50];
};


int remplissageTableau()
{
    struct joueur j[2];
    char words[nombreMaximumDesMots][tailleMaximumDuMot];
    int numeroDeMot = 0;
    FILE* file = fopen("banqueDeMot.txt", "r");

    if (file == NULL)
    {
        printf("il est impossible pour nous d'ouvrir ce fichier !\n");
        return 1;
    }

    while (fscanf(file, "%s", words[numeroDeMot]) != EOF && numeroDeMot < nombreMaximumDesMots)
    {
        numeroDeMot++;
    }

    fclose(file);

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires
    int nombreTotaleDeMot = demarrageDuJeux(10); // Remplacez 10 par le nombre de mots que vous voulez
    printf("%s Vous devriez orthographier correctement ces mots; \n",j[0].nom);
    for (int i = 0; i < nombreTotaleDeMot; i++)
    {
        int indiceDuTableauAleatoire = rand() % numeroDeMot;
        printf("mots %d : %s\n", i+1, words[indiceDuTableauAleatoire]);

        char saisieUtilisateur[tailleMaximumDuMot];
        scanf("%s", saisieUtilisateur);
        while (strcmp(saisieUtilisateur, words[indiceDuTableauAleatoire]) != 0)
        {
            printf("Erreur, réessayez le mot %d\n", i+1);
            scanf("%s", saisieUtilisateur);
        }
    }
    return 0;
}

int demarrageDuJeux(int nbreMot)
{
    struct joueur j[2];
    printf("=============================bienvenue a vous dans notre jeux demarrer la partie==============================\n\n");
    printf("+++++++++++++++++++++++++++++++saisissez le nombre de mot que vous voudrez++++++++++++++++++++++++++++++++++++\n\n");
    scanf("%d",&nbreMot);

    printf("saisissez le nom du joueur n°1\n\n");
    scanf("%s",j[0].nom);
    printf("saisissez le nom du joueur n°2\n\n");
    scanf("%s",j[1].nom);
    return nbreMot;
}
int demarrageDeLapartie()
{

}

void accueilMenu()
{
    //calculTemps();
    int nbreMot;
    enum choix des = demarrer;
    printf("1.demarrer \n"
           "2.configuration \n"
           "3.aide\n");
    scanf("%d",&des);
    switch(des)
    {
    case demarrer:
        system("cls");
        demarrageDuJeux(nbreMot);
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

float calculTemps()
{
    float time;
    clock_t start_time = clock();
    remplissageTableau();
    clock_t current_time = clock();
    time = (float)(current_time - start_time) / CLOCKS_PER_SEC;
    return time;
}

void afficherCalculTemps(int i)
{
    struct joueur j[2];
    j[i].score=calculTemps();
    printf("%f sec",j[i].score);
}

void pageDaccueil()
{
    printf("UDBL dactylogiciel\n");
    clock_t start_time=clock();
    clock_t current_time=clock();

    while((double)(current_time-start_time)/CLOCKS_PER_SEC < 2)
    {
        current_time=clock();

    }
    system("cls");
}
