//
// Created by Lionel on 06/04/2022.
//

#ifndef UNTITLED6_MATRICE_H
#define UNTITLED6_MATRICE_H
#include <stdbool.h>
// creer un mask
// creer une fonction qui verifie la matrice rempli ( lignes , colonnes , identité entre les lignes et aussi entre les colonnes)

int** create_matrice(int n, int** M);
int ** remplir_matrice_solution(int **M,int n);
bool verif_colonnes_matrice( int** M, int n);
bool comparer_liste(int n,int **M1, int **M2);
bool rejouer();
int menu();
bool veri_lignes_matrice( int** M, int n);
void afficher_matrice(int** M,int n);
#endif //UNTITLED6_MATRICE_H
