#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define nombreMaximumDesMots 500
#define tailleMaximumDuMot 40
#define MotDePasseAdmin 4525

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

int modeDaccesAdministrateur()
{
    system("cls");
    int mdp;
    printf("la configuration de la banque des mots est securiser par un code pin\n\n ");
    do
    {
        printf("veuillez saisir le mot de passe\n");
        scanf("%d",&mdp);
        system("cls");
    }
    while(mdp!= MotDePasseAdmin);
    return ajoutDesMots();
}

void ajoutDesMots()
{
    int i;
    char reponse;
    int limitesDesMotAjouter;
    struct listeDeNosMot m;
    FILE* notreBaseDeDonnee = fopen("banqueDeMot.txt","a");

    if (notreBaseDeDonnee == NULL)
    {
        printf("Erreur d'ouverture du fichier !\n");
        return;
    }


    do
    {
        system("cls");
        printf("veuillez saisir les nombres des mots à saisir : \n");
        scanf("%d",&limitesDesMotAjouter);
        printf("Vous pouvez ajouter %d mots \n",limitesDesMotAjouter);
        printf("=========================== \n");
        for (i = 0; i < limitesDesMotAjouter; i++)
        {
            printf("Ajouter le mot N- %d \n", i+1);
            scanf("%s", m.mot);
            fprintf(notreBaseDeDonnee, "%s\n", m.mot);
        }

        printf("Voulez-vous ajouter encore plus ? (y/n)\n");
        scanf(" %c", &reponse);
    }
    while (reponse == 'y');

    fclose(notreBaseDeDonnee);
    accueilMenu();
}
void informationDuJeux()
{
    int retour;
    printf("=======================================UDBL DACTILOGICIEL========================================\n\n\n"
           "DESCRIPTION: La saisie rapide au clavier est un grand atout pour les utilisateurs de l’ordinateur.\n"
           "             Ce projet consiste à proposer un logiciel d’aide à l’amélioration de la saisie rapide au \n"
           "             clavier communément appelé « Dactylogiciel ». ce jeux impose de règle qui sont les suivantes \n"
           "             pour gagner il faut ecrire dans le minimum de temps possible autant de mot que possible pour \n"
           "             avoir la victoire sur votre adversaire et gagner le nombre de mot a saisir est predefinie par \n"
           "             les deux premier joueur , les mots doivent etre orthographier correctement \n"
           "             bon jeux a vous\n\n\n");
    printf("CONCEPTEUR : M'POYO BIN-NDALA PASCAL\n"
           "             NGONGO WA NGONGO JEAN-PHILIPE\n"
           "             TSHIMBELA KASONGO JOSEPH\n"
           "             NGOY TSHIKWATA CHRISTIAN\n\n\n\n");
    printf("VERSION    : Vo 1.00.0\n\n\n\n");
    printf("CREATION   : DU 01 JUIN 2024 AU 15 JUIN 2024\n\n\n\n");

    printf("===========================TAPER LA TOUCHE < 1 > POUR UN RETOUR EN ARRIERE=====================================\n");
    scanf("%d",&retour);
    if (retour == 1)
    {
        system("cls");
        accueilMenu();
    }

}
