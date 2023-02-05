#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAILLE_MOT_SECRET 12

char lireCharactere () {
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while (getchar() != '\n');
        return caractere;
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

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]){
    int i = 0;
    int bonnelettre = 0;

    while(motSecret[i]!= '\0'){
        if (lettre == motSecret[i]){
            bonnelettre = 1;
            lettreTrouvee[i]= 1;
        }

    }
    return bonnelettre;
}

int main() {
    char lettre = 0, motSecret[] = "PAMPLEMOUSSE";
    int lettreTrouvee[TAILLE_MOT_SECRET] = {0}, coupsRestants = 10, i = 0;

    while (coupsRestants > 0 && !gagne(lettreTrouvee)){
        printf("\n Il vous reste %d coups à jouer\n", coupsRestants);
        printf("\nDevinez le mot!\n");
        for(i = 0; i < TAILLE_MOT_SECRET; i++){
            if (lettreTrouvee[i]){
                printf("%c", motSecret[i]);
            }else{
                printf("*");
            }
        }
        printf("Proposez une lettre: \n\n");
        lettre = lireCharactere();
        if (!rechercheLettre(lettre,motSecret,lettreTrouvee)){
            coupsRestants--;
    }

    }
    if (gagne(lettreTrouvee)){
        printf("GG!\n");
    } else {
        printf("Trop nul :(\n");
    }
    return 0;
}

  



