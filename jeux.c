
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

int remplissageTableau(int nbreMot, struct joueur j[2])
{
    char mots[nombreMaximumDesMots][tailleMaximumDuMot];
    int numeroDeMot = 0;
    FILE* notreBanqueDemot = fopen("banqueDeMot.txt", "r");

    if (notreBanqueDemot == NULL)
    {
        printf("il est impossible pour nous d'ouvrir ce fichier !\n");
        return 1;
    }

    while (fscanf(notreBanqueDemot, "%s", mots[numeroDeMot]) != EOF && numeroDeMot < nombreMaximumDesMots)
    {
        numeroDeMot++;
    }

    fclose(notreBanqueDemot);

    srand(time(NULL)); // l'Initialisation du générateur de nombres aléatoires
    int nombreTotaleDeMot = nbreMot;

    printf("%s Vous devriez orthographier correctement ces mots; \n", j[0].nom);
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
    return 0;
}

void demarrageDuJeux(int *nbreMot, struct joueur j[2])
{
    printf("=============================    bienvenue a vous dans notre jeux demarrer la partie    ==============================\n\n");
    printf("+++++++++++++++++++++++++++++++    saisissez le nombre de mot que vous voudrez       ++++++++++++++++++++++++++++++++++++\n\n");
    scanf("%d", nbreMot);

    printf("saisissez le nom du joueur n°1\n\n");
    scanf("%s", j[0].nom);
    printf("saisissez le nom du joueur n°2\n\n");
    scanf("%s", j[1].nom);

}

float calculTemps()
{
    char reponse;
    struct joueur j[2];
    int nbreMot;
    demarrageDuJeux(&nbreMot, j);
    float time;
    FILE* repertoireVictoire = fopen("score.txt","a");

    for (int i=0; i<2; i++)
    {   system("cls");
        clock_t start_time = clock();
        remplissageTableau(nbreMot, j);
        clock_t current_time = clock();
        time = (float)(current_time - start_time) / CLOCKS_PER_SEC;
        j[i].score=time;
    }
    printf("%f sec %f\n\n",j[0].score,j[1].score);
    if (j[0].score<j[1].score)
    {
        printf("%s a gagner contre %s avec %2f\n\n",j[0].nom,j[1].nom,j[0].score);
        fprintf(repertoireVictoire,"%s a gagner contre %s avec %2f secondes\n\n",j[0].nom,j[1].nom,j[0].score);
    }
    else if(j[0].score>j[1].score)
    {
        printf("%s a gagner contre %s avec %2f\n\n",j[1].nom,j[0].nom,j[1].score);
        fprintf(repertoireVictoire,"%s a gagner contre %s avec %2f secondes\n\n",j[1].nom,j[0].nom,j[1].score);
    }
    else
    {
        printf("%s  %s ont gagner a egalite avec %2f\n\n",j[0].nom,j[1].nom,j[0].score);
        fprintf(repertoireVictoire,"%s %s ont gagner a egalite avec avec %2f secondes\n\n",j[0].nom,j[1].nom,j[0].score);
    }
    fclose(repertoireVictoire);
    printf("voulez vous jouer une autre partie? (y/n)  : \n");
    scanf("%s",&reponse);
    if(reponse=='y')
    {   system("cls");
        calculTemps();
    }else{return 0;}

}


