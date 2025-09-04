#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global arrays to store books
#define MAX_LIVRES 100
#define MAX_TITRE 100
#define MAX_AUTEUR 100

char titres[MAX_LIVRES][MAX_TITRE];
char auteurs[MAX_LIVRES][MAX_AUTEUR];
float prix[MAX_LIVRES];
int quantite[MAX_LIVRES];
int nbLivres = 0;
int choix;

// Function declarations
int afficherMenu();
void generateChoix(int choix);
void ajouterLivre();
void affichertous();
void afficherLivre(char rechercheTitre[]);
void mettreAjour(char titre[]);
void Supprimer(char titre[]);
void afficherTotal();
void pause();

int main() {
    do {
        system("cls");
        choix = afficherMenu();
        generateChoix(choix);
    } while (choix != 0);

    return 0;
}

int afficherMenu() {

    printf("\n\tMenu : \n");
    printf("1. Ajouter un Livre au Stock\n");
    printf("2. Afficher Tous les Livres Disponibles\n");
    printf("3. Rechercher un livre par son titre.\n");
    printf("4. Mettre a Jour la Quantité d'un Livre\n");
    printf("5. Supprimer un Livre du Stock\n");
    printf("6. Afficher le Nombre Total de Livres en Stock\n");
    printf("0. Exit\n");
    printf("Entrez le Choix : ");
    scanf("%d", &choix);

    return choix;
}

void generateChoix(int choix) {
    char rechercheTitre[100];
    char titre[100];
    switch (choix) {
        case 1:
            ajouterLivre();
            break;
        case 2:
            affichertous();
            break;
        case 3:
            printf("Enterz titre de Livre : ");
            getchar();
            fgets(rechercheTitre, MAX_TITRE, stdin);
            afficherLivre(rechercheTitre);
            break;
        case 4:
            printf("Enterz titre de Livre : ");
            getchar();
            fgets(titre, MAX_TITRE, stdin);
            mettreAjour(titre);
            break;
        case 5:
            printf("Enterz titre de Livre : ");
            getchar();
            fgets(titre, MAX_TITRE, stdin);
            Supprimer(titre);
            break;
        case 6:
            afficherTotal();
            break;
        case 0:
            printf("\nSortie...\n");
            break;
        default:
            printf("\nChoix invalide, veuillez réessayer.\n");
            break;
    }
}

void ajouterLivre() {
    int n;
    printf("Combien de livres voulez-vous ajouter ? ");
    scanf("%d", &n);

    if (nbLivres + n >= MAX_LIVRES) {
        printf("Stock plein! Impossible d'ajouter un nouveau livre.\n");
        pause();
        return;
    }

    for (int i = 0;i < n;i++){

        printf("------------------Entez les valeur de la %d livre \n", i + 1 );

        getchar();
        printf("Entrez le titre du livre : ");
        fgets(titres[nbLivres], MAX_TITRE, stdin);


        printf("Entrez l'auteur du livre : ");
        fgets(auteurs[nbLivres], MAX_AUTEUR, stdin);


        printf("Entrez le prix du livre : ");
        scanf("%f", &prix[nbLivres]);

        printf("Entrez la quantité en stock : ");
        scanf("%d", &quantite[nbLivres]);

        nbLivres++;
    }

    printf("Livre ajoute avec succes !\n");
}

// fonction pour afficher un seul livre par sa titre
void afficherLivre(char rechercheTitre[]){
    int found = 0;
    for(int i = 0; i < nbLivres; i++){
        char tempTitre[MAX_TITRE];
        strcpy(tempTitre, titres[i]);

        if(strcmp(tempTitre, rechercheTitre) == 0){
            printf("--------------------------------------\n");
            printf("Titre   : %s\n", titres[i]);
            printf("Auteur  : %s\n", auteurs[i]);
            printf("Prix    : %.2f\n", prix[i]);
            printf("Quantité: %d\n", quantite[i]);
            printf("--------------------------------------\n");
            found = 1;
        }
    }
    if(found != 1){
        printf("\nIl n'y a pas de livre avec ce titre \n");
    }
    pause();
}

// fonction pour afficher tous les livres de la bibliothèque
void affichertous(){
    if(nbLivres < 0){
        printf("il n/'y a pas de livre à afficher !!");
        return;
    }

    for(int i = 0; i < nbLivres;i++){
        if(nbLivres == 1){
            printf("--------------------------------------\n");
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %f\n", prix[i]);
            printf("Quantité: %d\n", quantite[i]);
            printf("--------------------------------------\n");


        }else{
            printf("--------------------------------------\n");
            printf("le %d Livre : \n", i+1);
            printf("Titre : %s\n", titres[i]);
            printf("Auteur : %s\n", auteurs[i]);
            printf("Prix : %f\n", prix[i]);
            printf("Quantité: %d\n", quantite[i]);
            printf("--------------------------------------\n");

        }


    }
    pause();
}

void mettreAjour(char titre[]){
    int found = 0;
    int newquantite;
    for(int i = 0;i < nbLivres; i++){
        char tempTitre[MAX_TITRE];
        strcpy(tempTitre, titres[i]);

        if(strcmp(tempTitre, titre) == 0){
            printf("Quantite precedent: %d\n", quantite[i]);
            printf("Entrez Nouvelle Quantite :");
            scanf("%d", &quantite[i]);
            newquantite = quantite[i];
            found = 1;
            printf("la nouvelle Quantite est : %d\n", newquantite);
        }
    }
    if(found != 1){
        printf("\nIl n'y a pas de livre avec ce titre \n");
    }
    pause();
}
void Supprimer(char titre[]){
    char deletedLivre[MAX_TITRE];
    for(int i = 0; i < nbLivres;i++){

        strcpy(deletedLivre, titres[i]);

        if(strcmp(deletedLivre, titre) == 0){
                for(int j = i;j< nbLivres -1; j++){
                    strcpy(titres[j], titres[j + 1]);
                    strcpy(auteurs[j], auteurs[j + 1]);
                    prix[j] = prix[j + 1];
                    quantite[j] = quantite[j + 1];
                }
                nbLivres--;
        }
    }
    printf("You have deleted the book ");
    pause();
}
void afficherTotal(){

    if(nbLivres > 0){
        printf("le Nombre Total de Livres en Stock est : %d\n", nbLivres);
    }
    else{
        printf("Il n'y a pas de livre avec ce titre \n");
    }
    pause();
}
void pause(){
    printf("\nAppuyez sur Entrée pour revenir au menu...");
    getchar();
    getchar();
}
