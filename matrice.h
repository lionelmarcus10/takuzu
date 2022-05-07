//
// Created by Lionel on 06/04/2022.
//

#ifndef UNTITLED6_MATRICE_H
#define UNTITLED6_MATRICE_H
#include <stdbool.h>
// creer un mask
// creer une fonction qui verifie la matrice rempli ( lignes , colonnes , identité entre les lignes et aussi entre les colonnes)

int** create_matrice(int n, int** M);
int** create_masque(int n, int** M);
int ** remplir_matrice_solution(int **M,int n);
bool verif_colonnes_matrice( int** M, int n,bool indice);
bool comparer_liste(int n,int **M1, int **M2);
bool rejouer();
int menu();
int** choix_menu(int a);
bool veri_lignes_matrice( int** M, int n,bool indice);
void afficher_matrice(int** M,int n);
bool verif_identique( int** M, int n);
bool coup_correct(int **M,int n,bool indice);
int ** remplir_grille_jeux(int **M,int n);
int** create_mat_masq(int n, int **M)
#endif //UNTITLED6_MATRICE_H
