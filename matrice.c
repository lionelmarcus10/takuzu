//
// Created by Lionel on 06/04/2022.
//

#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>


int** create_matrice(int n, int** M)
{
    int i =0;
    M = (int**) malloc(n * sizeof(int*));
    for(i;i<n;i++){
        *(M+i) = (int*) malloc(n * sizeof(int));
    }
    printf("Matrice created \n");
    return M;
}
bool comparer_liste(int n,int **M1, int **M2)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(M1[i][j]!=M2[i][j])
            {
                return false;
            }

        }
    }
    return true;
}

bool rejouer()
{
    int a;
    do {
        printf("Saisir:\n0 - Pour arreter de jouer\n1 - Pour rejouer");
        scanf("%d", &a);
    }while(a!=0 && a!=1);
    if(a == 1)
        return true;
    return false;
}

int menu()
{
    int a;
    do {
        printf("Saisir: \n1 - Pour choisir la taille de la grille\n2 - Pour saisir manuellement un masque\n3 - Pour generer automatiquement un masque \n4 - Pour jouer");
        scanf("%d", &a);
    }while(a!=1 && a!=2 && a!=3 && a!=4);
    return a;
}

/* -------------------------- */

//afficher_matrice()

//afficher_ligne()

// remplir matrice solution 8*8 , 16*16

// remplir matrice jeux() 4*4 , 8*8 , 16 * 16

// afficher_colonne()

// determiner bon coup

// verifier matrice ligne saisie

// verifier matrice colonne saisie

// verifier matrice colonnes saisie

// verifier lignes identique

// verifier colonnes identique

// partie 3 -- generateur de grille mask et grille jeux + grille solution

//



/* -------------------------- */

bool verif_lignes_matrice( int** M, int n)
{
    int i,somme0,somme1,j;
    bool inc=true;
    //parcours lignes
    for(i=0; i< n; i++) {
        // parcourir les cases des lignes pour trouver le nombre de zero et de 1
        somme0 = 0;
        somme1 = 0;
        for (j = 0; j < n; j++) {

            if (M[i][j] == 0)
                somme0 += 1;

            if (M[i][j]== 1)
                somme1 += 1;
        }

        // si le nombre de zero et de 1 est correct, verifier si il n'y a pas plus de 2 chiffres consecutives
        if (somme0 == somme1) {
            int k;
            for(k=0;k<(n-2);k++){
                if ((M[i][k] == M[i][k+1]) && (M[i][k] == M[i][k+2])) {
                    printf("%d = %d  = %d pour k = %d donc ligne %d  pas valide \n", M[i][k], M[i][k+1], M[i][k+2],k+1,i+1);
                    inc = false;
                    break;
                }
            }
        }else {
            printf("La ligne %d n'a pas le meme nombre de 0 et de 1\n", i + 1);
            inc = false;
        }
    }
    if(inc == false)
        return false;
    return true;
}


int ** remplir_matrice_solution(int **M,int n){
    switch(n){
        case 4:{
            *(*(M+0)+0) = 1;
            *(*(M+0)+1) = 0;
            *(*(M+0)+2) = 0;
            *(*(M+0)+3) = 1;

            *(*(M+1)+0) = 1;
            *(*(M+1)+1) = 0;
            *(*(M+1)+2) = 1;
            *(*(M+1)+3) = 0;

            *(*(M+2)+0) = 0;
            *(*(M+2)+1) = 1;
            *(*(M+2)+2) = 1;
            *(*(M+2)+3) = 0;

            *(*(M+3)+0) = 0;
            *(*(M+3)+1) = 1;
            *(*(M+3)+2) = 0;
            *(*(M+3)+3) = 1;
            return M;
            break;
        }
        case 8:{

            break;

        }
        // le default est pour la matrice 16 * 16
        defaulf:{

            break;
        }
    }
}