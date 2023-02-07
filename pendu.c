#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAILLE_MOT_SECRET 12
#define MOT_SECRET "PAMPLEMOUSSE"

void lireCharactere(char* var) {
    do {
        printf("\nProposez une lettre: \n\n"); 
        scanf(" %c", var);
        if (*var >= 97 && *var <= 122) {
            //if var is in lowercase, we make it in upper case
            *var -= 32;
        }
    } while (*var < 65 && *var > 90); 
    // We loop until we have a valid character


}

void initTable(int* table, int taille) {
    // Intitializing table with 0
    int i;
    for (i=0; i < taille; i++){
        table[i] = 0;
    }
}

int gagne (int lettreTrouvee[]){

    int i = 0;
    int JoueurGagne = 1;

    for (i=0; i < TAILLE_MOT_SECRET; i++){
        if (lettreTrouvee[i] == 0){
            JoueurGagne = 0;
        }
    }

    return JoueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]) {
    int bonnelettre = 0;
    for(int i=0; i < TAILLE_MOT_SECRET; i++) {
        if (lettre == motSecret[i]){ 
            if(lettreTrouvee[i]) {
                //Player already found this letter
                bonnelettre = 2;
                break;
            }
            bonnelettre = 1;
            lettreTrouvee[i]= 1;
        }
    }
    return bonnelettre;
}

int main() {
    char lettre = 0, motSecret[] = MOT_SECRET;
    int lettreTrouvee[TAILLE_MOT_SECRET], coupsRestants = 10, i = 0;

    initTable(lettreTrouvee, TAILLE_MOT_SECRET);

    while (coupsRestants > 0 && !gagne(lettreTrouvee)){
        printf("==================================");
        printf("\nIl vous reste %d coups à jouer\n", coupsRestants);
        printf("\nDevinez le mot!\n");
        for(i = 0; i < TAILLE_MOT_SECRET; i++){
            if (lettreTrouvee[i]){
                printf("%c", motSecret[i]);
            }else{
                printf("*");
            }
        }
        lireCharactere(&lettre);
        int result = (rechercheLettre(lettre,motSecret,lettreTrouvee));  
        if (result == 0) {
            printf("Mince c'était pas ça :c\n");
            coupsRestants--;
        } else if (result == 1){
            printf("Oui ! La lettre est dedans :D\n");
        } else {
            printf("Tu as déjà trouvé cette lettre !\n");
        }

    }
    printf("==================================");
    if (gagne(lettreTrouvee)){
        printf("\nGG!\n");
    } else {
        printf("\nTrop nul :(\n");
    }
    return 0;
}

  



