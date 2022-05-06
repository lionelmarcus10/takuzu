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
        for(int k=0;k<n;k++){
            M[i][k] = -1;
        }
    }
    return M;
}
bool comparer_liste(int n,int **M1, int **M2)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(M1[i][j]!=M2[i][j])
                return false;
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
    do{
        printf("\nSaisir: \n1 - Resoudre une grille\n2-  Résoudre automatiquement une grille de Takuzu\n3- Générer une grille de Takuzu");
    }while(a!=1 && a!=2 && a!=3);
    switch(a){
        case 1:{
            int taille,b;
            do{
                printf("\nChoisir la taille de la grille : \n \t1- 4*4\n\t2- 8*8\n\t3- 16*16\nSaisir un numero: ");
                scanf("%d",&taille);
            }while(taille != 1 && taille != 2 && taille !=3);

            do {
                printf("\nSaisir: \n\t1 - Pour saisir manuellement un masque\n\t2 - Pour generer automatiquement un masque \n\t3 - Pour jouer");
                scanf("%d", &b);
            }while(b!=1 && b!=2 && b!=3);
            break;
        }
        case 2:{
            break;
        }
        default:{
            break;
        }
    }
    return a;
}


void afficher_matrice(int ** M, int n){
    int j ;
    printf("\n");
    for (int i = 0; i <n; i++)
        {
            
            for (j = 0; j <n; j++)
            {
                
                printf("%d \t", M[i][j]);
            }
            printf("\n");
        }
}
/* -------------------------- */

// remplir matrice solution 16*16

// remplir matrice jeux() 4*4 , 8*8 , 16 * 16

// determiner bon coup

// verifier lignes identique

// verifier colonnes identique

// partie 3 -- generateur de grille mask et grille jeux + grille solution

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
bool verif_colonnes_matrice( int** M, int n)
{
    int i,somme0,somme1,b;
    bool inc=true;
    //parcours colonne 
    for(i=0; i< n; i++) {
        somme0 = 0;
        somme1 = 0;
        for (b = 0; b < n; b++) {
            // parcourir les cases des colonnes pour trouver le nombre de zero et de 1
            if (M[b][i] == 0)
                somme0 += 1;

            if (M[b][i] == 1)
                somme1 += 1;

        }

        // si le nombre de zero et de 1 est correct, verifier si il n'y a pas plus de 2 chiffres consecutives
        if (somme0 == somme1) {
            int k;
            for (k = 0; k < (n - 2); k++) {
                if ((M[k][i] == M[k + 1][i]) && (M[k][i] == M[k + 2][i])) {
                    printf("%d = %d  = %d donc la colonne %d  n'est pas valide \n", M[k][i], M[k + 1][i], M[i][k + 2],
                           i + 1);
                    inc = false;
                    break;
                }
            }
        } else {
            printf("La colonne %d n'a pas le meme nombre de 0 et de 1\n", i + 1);
            inc = false;
        }
    }
    if(inc == false)
        return false;
    return true;
}


bool verif_identique( int** M, int n)
{
    int i, j,k,sl, sc;
    bool inc = false;
    // lignes identique
    //parcours ligne principale
    for(i=0;i<n-1;i++){
        //parcours ligne secondaire
        for(j=i+1;j<n;j++){
            //parcours colonnes
            sl = 0;
            for(k=0;k<n;k++){
                if(M[i][k] == M[j][k])
                    sl++;
            }
            if(sl==n){
                printf("Les lignes %d et %d sont identique\n",i+1,j+1);
                inc = false;
            }
        }
    }

    //colonne identique
    // parcours colonne principale
    for(i=0;i<n-1;i++){
        //parcours colonne secondaire
        for(j=i+1;j<n;j++){
            //parcours lignes
            sc = 0;
            for(k=0;k<n;k++){
                if(M[k][i] == M[k][j])
                    sc++;
            }
            if(sc==n){
                printf("Les colonnes %d et %d sont identique\n",i+1,j+1);
                inc = false;
            }
        }
    }


    if(inc == true)
        return true;
    return false;
}

bool coup_correct(int ** M,int n){
    //verif conditions
    bool fconditions_line = verif_lignes_matrice(M,n);
    bool fconditions_col = verif_colonnes_matrice(M,n);
    // verif identique
    bool sconditions = verif_identique(M,n);
    if(fconditions_line == false || fconditions_col == false || sconditions == false)
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

            *(*(M+0)+0) = 1;
            *(*(M+0)+1) = 0;
            *(*(M+0)+2) = 1;
            *(*(M+0)+3) = 1;
            *(*(M+0)+4) = 0;
            *(*(M+0)+5) = 1;
            *(*(M+0)+6) = 0;
            *(*(M+0)+7) = 0;

            *(*(M+1)+0) = 1;
            *(*(M+1)+1) = 0;
            *(*(M+1)+2) = 1;
            *(*(M+1)+3) = 0;
            *(*(M+1)+4) = 1;
            *(*(M+1)+5) = 0;
            *(*(M+1)+6) = 0;
            *(*(M+1)+7) = 1;

            *(*(M+2)+0) = 0;
            *(*(M+2)+1) = 1;
            *(*(M+2)+2) = 0;
            *(*(M+2)+3) = 1;
            *(*(M+2)+4) = 1;
            *(*(M+2)+5) = 0;
            *(*(M+2)+6) = 1;
            *(*(M+2)+7) = 0;
            
            *(*(M+3)+0) = 0;
            *(*(M+3)+1) = 1;
            *(*(M+3)+2) = 0;
            *(*(M+3)+3) = 1;
            *(*(M+3)+4) = 0;
            *(*(M+3)+5) = 1;
            *(*(M+3)+6) = 1;
            *(*(M+3)+7) = 0;

            *(*(M+4)+0) = 1;
            *(*(M+4)+1) = 0;
            *(*(M+4)+2) = 1;
            *(*(M+4)+3) = 0;
            *(*(M+4)+4) = 0;
            *(*(M+4)+5) = 1;
            *(*(M+4)+6) = 0;
            *(*(M+4)+7) = 1;

            *(*(M+5)+0) = 0;
            *(*(M+5)+1) = 1;
            *(*(M+5)+2) = 0;
            *(*(M+5)+3) = 0;
            *(*(M+5)+4) = 1;
            *(*(M+5)+5) = 0;
            *(*(M+5)+6) = 1;
            *(*(M+5)+7) = 1;

            *(*(M+6)+0) = 0;
            *(*(M+6)+1) = 0;
            *(*(M+6)+2) = 1;
            *(*(M+6)+3) = 1;
            *(*(M+6)+4) = 0;
            *(*(M+6)+5) = 1;
            *(*(M+6)+6) = 1;
            *(*(M+6)+7) = 0;

            *(*(M+7)+0) = 1;
            *(*(M+7)+1) = 1;
            *(*(M+7)+2) = 0;
            *(*(M+7)+3) = 0;
            *(*(M+7)+4) = 1;
            *(*(M+7)+5) = 0;
            *(*(M+7)+6) = 0;
            *(*(M+7)+7) = 1;
            return M;
            break;
        }
        // le default est pour la matrice 16 * 16
        defaulf:{
            break;
        }
    }
}

int ** remplir_grille_jeux(int **M,int n){
    switch(n){
        case 4:{
            M[0][0] = 1;
            M[1][3] = 1;
            M[2][0] = 0;
            M[2][3] = 1;
            M[2][2] = 1;
            M[3][1] = 0;
            return M;
            break;
        }
        case 8:{
            M[0][0] = 1;
            M[0][2] = 1;
            M[0][3] = 1;
            M[0][5] = 1;
            M[0][7] = 0;

            M[1][2] = 1;

            M[2][0] = 0;
            M[2][7] = 0;

            M[3][0] = 0;
            M[3][2] = 0;
            M[3][5] = 1;
            M[3][6] = 1;

            M[4][0] = 1;
            M[4][4] = 0;
            M[4][7] = 1;

            M[5][4] = 1;

            M[6][1] = 0;
            M[6][2] = 1;
            M[6][3] = 1;
            M[6][4] = 0;
            M[6][5] = 1;

            M[7][1] = 1;
            M[7][3] = 0;
            M[7][6] = 0;

            return M;
            break;
        }
        default:{
            break;
        }
    }
}