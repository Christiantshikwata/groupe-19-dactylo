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


int remplissageTableau(int nbreMot)
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
    int nombreTotaleDeMot = nbreMot; // Remplacez 10 par le nombre de mots que vous voul


    printf("%s Vous devriez orthographier correctement ces mots; \n",j[0].nom);
    for (int i = 0; i < nombreTotaleDeMot; i++)
    {
        int indiceDuTableauAleatoire = rand() % numeroDeMot;
        printf("mots %d : %s\n", i+1, words[indiceDuTableauAleatoire]);

        char saisieUtilisateur[tailleMaximumDuMot];
        scanf("%s", saisieUtilisateur);
        while (strcmp(saisieUtilisateur, words[indiceDuTableauAleatoire]) != 0)
        {
            printf("Erreur, rÃ©essayez le mot %d\n", i+1);
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

    printf("saisissez le nom du joueur nÂ°1\n\n");
    scanf("%s",j[0].nom);
    printf("saisissez le nom du joueur nÂ°2\n\n");
    scanf("%s",j[1].nom);
    return nbreMot;
}
int demarrageDeLapartie()
{

}


float calculTemps()

{
    struct joueur j[2];
    int nbreMot;
    nbreMot=demarrageDuJeux(nbreMot);
    float time;

    for (int i=0; i<2; i++)
    {
        clock_t start_time = clock();
        remplissageTableau(nbreMot);
        clock_t current_time = clock();
        time = (float)(current_time - start_time) / CLOCKS_PER_SEC;
        j[i].score=time;
    }
    printf("%f sec %f",j[0].score,j[1].score);
    if (j[0].score>j[1].score)
    {
        printf("%s a gagner contre %s avec %f",j[0].nom,j[1].nom,j[0].score);
    }
    else if(j[0].score<j[1].score)
    {
        printf("%s a gagner contre %s avec %f",j[1].nom,j[0].nom,j[1].score);
    }
    else
    {
        printf("%s  %s ont gagner a egalite avec %f",j[0].nom,j[1].nom,j[0].score);
    }
    return 1;
}

/*void afficherCalculTemps(int i)
{
    struct joueur j[2];
    for (int i=0; i<2; i++)
    {
        j[i].score=calculTemps();
    }
    printf("%f sec %f",j[0].score,j[1].score);
}*/

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
