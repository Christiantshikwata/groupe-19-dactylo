#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nombreMaximumDesMots 500
#define tailleMaximumDuMot 40

typedef struct joueur
{
    char nom[50];
    float score;
};
typedef struct listeDeNosMot
{
    char mot[50];
};

int remplissageTableau(int nbreMot, struct joueur j[2])
{
    char mots[nombreMaximumDesMots][tailleMaximumDuMot];
    int numeroDeMot = 0;
    FILE* file = fopen("banqueDeMot.txt", "r");

    if (file == NULL)
    {
        printf("il est impossible pour nous d'ouvrir ce fichier !\n");
        return 1;
    }

    while (fscanf(file, "%s", mots[numeroDeMot]) != EOF && numeroDeMot < nombreMaximumDesMots)
    {
        numeroDeMot++;
    }

    fclose(file);

    srand(time(NULL)); // Initialiser le générateur de nombres aléatoires
    int nombreTotaleDeMot = nbreMot;
    int i=0;

        printf("%s Vous devriez orthographier correctement ces mots; \n", j[i].nom);
        for (; i < nombreTotaleDeMot; i++)
        {
            int indiceDuTableauAleatoire = rand() % numeroDeMot;
            printf("mots %d : %s\n", i+1, mots[indiceDuTableauAleatoire]);

            char saisieUtilisateur[tailleMaximumDuMot];
            scanf("%s", saisieUtilisateur);
            while (strcmp(saisieUtilisateur, mots[indiceDuTableauAleatoire]) != 0)
            {
                printf("Erreur, reessayez le mot %d\n", i+1);
                scanf("%s", saisieUtilisateur);
            }

        /*printf("%s Vous devriez orthographier correctement ces mots; \n", j[0].nom);
        for (int i = 0; i < nombreTotaleDeMot; i++) {
            int indiceDuTableauAleatoire = rand() % numeroDeMot;
            printf("mots %d : %s\n", i+1, mots[indiceDuTableauAleatoire]);

            char saisieUtilisateur[tailleMaximumDuMot];
            scanf("%s", saisieUtilisateur);
            while (strcmp(saisieUtilisateur, mots[indiceDuTableauAleatoire]) != 0) {
                printf("Erreur, reessayez le mot %d\n", i+1);
                scanf("%s", saisieUtilisateur);
            }*/
    }
    return 0;
}

int demarrageDuJeux(int nbreMot)
{
    struct joueur j[2];
    printf("=============================    bienvenue a vous dans notre jeux demarrer la partie    ==============================\n\n");
    printf("+++++++++++++++++++++++++++++++    saisissez le nombre de mot que vous voudrez       ++++++++++++++++++++++++++++++++++++\n\n");
    scanf("%d", &nbreMot);

    printf("saisissez le nom du joueur n°1\n\n");
    scanf("%s", j[0].nom);
    printf("%s\n", j[0].nom);
    printf("saisissez le nom du joueur n°2\n");
    scanf("%s", j[1].nom);
    printf("%s\n", j[1].nom);
    remplissageTableau(nbreMot,j);
    return nbreMot;
}

float calculTemps(struct joueur j[2])

{
    int nbreMot;
    nbreMot=demarrageDuJeux(nbreMot);
    float time;

    for (int i=0; i<2; i++)
    {
        clock_t start_time = clock();
        remplissageTableau(nbreMot,j);
        clock_t current_time = clock();
        time = (float)(current_time - start_time) / CLOCKS_PER_SEC;
        j[i].score=time;
    }
    printf("%f sec %f",j[0].score,j[1].score);
    if (j[0].score<j[1].score)
    {
        printf("%s a gagner contre %s avec %f",j[0].nom,j[1].nom,j[0].score);
    }
    else if(j[0].score>j[1].score)
    {
        printf("%s a gagner contre %s avec %f",j[1].nom,j[0].nom,j[1].score);
    }
    else
    {
        printf("%s  %s ont gagner a egalite avec %f",j[0].nom,j[1].nom,j[0].score);
    }
    return 1;
}
/*

int remplissageTableau(int nbreMot )
{
    struct joueur j[2];
    char mots[nombreMaximumDesMots][tailleMaximumDuMot];
    int numeroDeMot = 0;
    FILE* file = fopen("banqueDeMot.txt", "r");

    if (file == NULL)
    {
        printf("il est impossible pour nous d'ouvrir ce fichier !\n");
        return 1;
    }

    while (fscanf(file, "%s", mots[numeroDeMot]) != EOF && numeroDeMot < nombreMaximumDesMots)
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
        printf("mots %d : %s\n", i+1, mots[indiceDuTableauAleatoire]);

        char saisieUtilisateur[tailleMaximumDuMot];
        scanf("%s", saisieUtilisateur);
        while (strcmp(saisieUtilisateur, mots[indiceDuTableauAleatoire]) != 0)
        {
            printf("Erreur, reessayez le mot %d\n", i+1);
            scanf("%s", saisieUtilisateur);
        }
    }
    return j[0].nom,j[1].nom;
}

int demarrageDuJeux(int nbreMot,char j[0].nom,j[1].nom)
{
    struct joueur j[2];
    printf("=============================    bienvenue a vous dans notre jeux demarrer la partie    ==============================\n\n");
    printf("+++++++++++++++++++++++++++++++    saisissez le nombre de mot que vous voudrez       ++++++++++++++++++++++++++++++++++++\n\n");
    scanf("%d",&nbreMot);

    printf("saisissez le nom du joueur n°1\n\n");
    scanf("%s",j[0].nom);
    printf("%s\n",j[0].nom);
    printf("saisissez le nom du joueur n°2\n\n");
    scanf("%s",j[1].nom);
    remplissageTableau(nbreMot);
    return nbreMot,j[0].nom,j[1].nom;
};
*/



/*void afficherCalculTemps(int i)
{
    struct joueur j[2];
    for (int i=0; i<2; i++)
    {
        j[i].score=calculTemps();
    }
    printf("%f sec %f",j[0].score,j[1].score);
}*/

