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
bool coup_valide(int ** M,int n);
int** choix_menu1(int taille);
int ask_taille();
bool verif_lignes_matrice( int** M, int n,bool indice);
void afficher_matrice(int** M,int );
bool verif_identique( int** M, int n,bool indice);
bool coup_correct(int **M,int n,bool indice);
int ** remplir_grille_jeux(int **M,int n);
int ** remplir_matrice_solution(int **M,int n);
int ** remplir_grille_masque(int **M,int n);
bool ligne_remplie(int **M,int ligne ,int n);
bool colonne_remplie(int**M, int colonne, int n);
int** create_matby_masq(int n, int **M);
bool verif_cases_tableau(int **M,int ligne, int n);
bool verif_remp_matrice(int **M, int n);
void except_indice(int **M, int n, bool indice);
int** remplir_mat_user(int n, int** M,int ** jeux_grille);
bool verif_mnr_rules(int **M, int n,bool indice);
int **copy_mat(int** new,int ** copy,int n);
void tobinary(int * T,int number ,int taille);
void automatic_resolution(int taille);
void brute_sol(int taille);
void solutions(int* matligne,int taille);
int sol_len(int taille);
int** gen_matrice_sol_auto(int taille, bool indice);
void affiche_ligne_sol(int taille);
#endif //UNTITLED6_MATRICE_H
