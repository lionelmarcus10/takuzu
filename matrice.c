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


int** remplir_mat_user(int n, int** M,int** jeux_grille)
{

    char res;
    do{

        int lig, col, val;
        do{
            printf("\nVeuillez saisir le numero de la ligne de la case que vous voulez editer: ");
            scanf("%d", &lig);
        }while(lig <= 0 || lig > n);
        lig--;
        do{
            printf("\nVeuillez saisir le numero de la colonne de la case que vous voulez editer: ");
            scanf("%d", &col);
        }while(col <= 0 || col > n);
        col--;
        do{
            printf("\nQuelle valeur voulez vous saisir (0 ou 1 ) : ");
            scanf("%d", &val);
        }while(val != 0 && val != 1);

        if(jeux_grille[lig][col] != -1){
            printf("\nVeuillez saisir d'autres coordonnées de cases car celle ci fait partie de la grille de jeux par défaut\n");
        }else{

            *(*(M+lig)+col) = val;
        }
        do{
            printf("\nVoulez-vous saisir une autre valeur ? \n  Y pour Oui et  N pour Non : ");
            scanf("%c",&res);
        }while(res != 'Y' && res !='N' );
    }while(res == 'Y');
    return M; 
}


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

int** create_masque(int n, int** M)
{
    int i =0;
    int nb, lig, col;
    M = (int**) malloc(n * sizeof(int*));
    for(i;i<n;i++)
    {
        *(M+i) = (int*) malloc(n * sizeof(int));
        for(int k=0;k<n;k++)
        {
            M[i][k] = 0;
        }
    }
    if(n == 4 )   
    {
        do{
            printf("\nCombien de cases visibles voulez vous avoir (pas plus 6) ?");
            scanf("%d", &nb);
        }while(nb >6);
    }
    else
    {
        if(n==8);
        do{
            printf("\nCombien de cases visibles voulez vous avoir (pas plus 28) ?");
            scanf("%d", &nb);
        }while(nb >28);
    }
    for(int i=0; i < nb; i++)
    {
        do{
            printf("\nVeuillez saisir le numero de la ligne du masque que vous voulez editer: ");
            scanf("%d", &lig);
        }while(lig <= 0 || lig > n);

        do{
            printf("\nVeuillez saisir le numero de la colonne du masque que vous voulez editer: ");
            scanf("%d", &col);
        }while(col <= 0 || col > n);

        M[lig-1][col-1] = 1;
    }
    return M;
}

int** create_matby_masq(int n, int **M)
{
    bool cond = false;
    srand(time(NULL));
    do{

        for (int i=0; i < n ; i++){
            for (int j=0; j < n; j++){
                if (M[i][j]==0)
                {
                    M[i][j]=-1;
                }
                else
                {
                    
                    if(M[i][j]==1)
                    {                    
                        
                        M[i][j]= rand() % 2;;
                    }
                }
            }
        }
        // verif lig:
        for (int i=0; i < n ; i++)
        {
            for (int k=0; k < n-2; k++)
            {
                if(M[i][k] == M[i][k+1] && M[i][k] == M[i][k+2] && M[i][k] != -1){
                    cond = true;
                    break;
                }
            }
        } 
        // verif col
        for (int i=0; i < n ; i++)
        {
            for (int k=0; k < n-2; k++)
            {
                if(M[k][i] == M[k+1][i] && M[k][i] == M[k+2][i] && M[k][i] != -1){
                    cond = true;
                    break;
                }
            }
        }
    }while(cond == true);
    afficher_matrice(M,n);
    return M;
}

int** create_masque_auto(int n, int** M)
{
    int nb, lig, col;
    M = (int**) malloc(n * sizeof(int*));
    for(int p ; p < n ; p++)
    {
        *(M+p) = (int*) malloc(n * sizeof(int));
        for(int k = 0; k < n; k++)
        {
            M[p][k] = 0;
        }
    }
    if(n==4)
    {
        for(int l=0; l < 6; l++)
        {
            srand(time(NULL));
            int i = rand() % 4;
            int j = rand() % 4;
            M[i][j]=1;
        }
    }
    else
    {
        if(n==8){
            for(int h=0; h < 28; h++)
            {
                srand(time(NULL));
                int i = rand() % 8;
                int j = rand() % 8;
                M[i][j]=1;
            }
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
        printf("\nSaisir: \n1 - Resoudre une grille\n2-  Résoudre automatiquement une grille de Takuzu\n3- Générer une grille de Takuzu\n");
        printf("Saisir : ");
        scanf("%d",&a);
    }while(a!=1 && a!=2 && a!=3);

    return a;
}

int ask_taille(){
    int taille;
    do{
        printf("\nChoisir la taille de la grille : \n \t1- 4*4\n\t2- 8*8\n\t3- 16*16\nSaisir un numero: ");
        scanf("%d",&taille);
    }while(taille != 1 && taille != 2 && taille !=3);

    if(taille == 1)
        return 4;
    if(taille == 2)
        return 8;
    return 16;
}
// choix + retour
int** choix_menu1(int taille){
    int **M;
    int b;

    do {
         printf("\nSaisir: \n\t1 - Pour saisir manuellement un masque\n\t2 - Pour generer automatiquement un masque \n\t3 - Pour jouer\n saisir : ");
         scanf("%d", &b);
    }while(b!=1 && b!=2 && b!=3);
    switch(b){
        case 1:{

                M = create_masque(taille, M);
                printf("Grille Masque\n");
                afficher_matrice(M,taille);
                M = create_matby_masq(taille,M);
                printf("Grille jeux\n");
                afficher_matrice(M,taille);
                return M;
                break;
        }
        case 2:{
                printf("Grille Masque\n");
                M = create_masque_auto(taille, M);
                afficher_matrice(M,taille);
                M = create_matby_masq(taille,M);
                printf("Grille jeux\n");
                afficher_matrice(M,taille);
                return M;
                break;
        }
        default:{

                    int ** temp;
                    temp = create_matrice(taille,temp);
                    temp = remplir_grille_masque(temp,taille);
                    M = create_matrice(taille,M);
                    M = remplir_grille_jeux(M, taille);
                    printf("Grille Masque\n");
                    afficher_matrice(temp,taille);
                    printf("Grille jeux\n");
                    afficher_matrice(M,taille);

                    return M;
                    break;
        }
    }
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

// partie 3 -- generateur de grille mask et grille jeux + grille solution

/* -------------------------- */



bool verif_lignes_matrice( int** M, int n,bool indice){
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
        if (somme0 == somme1 && somme0+somme1==n) {
            int k;
            for(k=0;k<(n-2);k++){
                if ((M[i][k] == M[i][k+1]) && (M[i][k] == M[i][k+2])) {

                    if(indice == true){
                        printf("%d = %d  = %d pour k = %d donc ligne %d  pas valide\n", M[i][k], M[i][k+1], M[i][k+2],k+1,i+1);
                        inc = false;
                        if(M[i][k]==0)
                        {
                            printf("Entre deux 0, il ne peut y avoir qu'un 1");
                            printf("A gauche,a droite d’une série de deux 0, il ne peut y avoir qu’un 1 ");
                        }
                        else{
                            printf("Entre deux 1, il ne peut y avoir qu'un 0 ");
                            printf("A gauche,a droite d’une série de deux 1, il ne peut y avoir qu’un 0 ");
                        }
                    }
                    break;
                }
            }
        }else {
            if(indice == true)
                printf("La ligne %d n'a pas le meme nombre de 0 et de 1\n", i + 1);
            inc = false;
        }
    }
    if(inc == false)
        return false;
    return true;
}

bool verif_colonnes_matrice( int** M, int n, bool indice) {
    int i, somme0, somme1, b;
    bool inc = true;
    //parcours colonne
    for (i = 0; i < n; i++) {
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
        if (somme0 == somme1 && somme0+somme1==n ) {
            int k;
            for (k = 0; k < (n - 2); k++) {
                if ((M[k][i] == M[k + 1][i]) && (M[k][i] == M[k + 2][i])) {
                    if (indice == true) {
                        printf("%d = %d  = %d donc la colonne %d  n'est pas valide \n", M[k][i], M[k + 1][i],
                               M[i][k + 2], i + 1);
                        inc = false;
                        if (M[k][i] == 0) {
                            printf("Entre deux 0, il ne peut y avoir qu'un 1");
                            printf("Au dessus,en dessous d’une série de deux 0, il ne peut y avoir qu’un 1");
                        } else {
                            printf("Entre deux 1, il ne peut y avoir qu'un 0");
                            printf("Au dessus,en dessous d’une série de deux 1, il ne peut y avoir qu’un 0");
                        }
                        break;
                    }
                }
            }
        } else {
            if (indice == true)
                printf("La colonne %d n'a pas le meme nombre de 0 et de 1\n", i + 1);
            inc = false;
        }
        if (inc == false)
            return false;
        return true;
    }
}

bool verif_identique( int** M, int n,bool indice)
{
    int i, j, k, sl, sc;
    bool inc = false;
    // lignes identique
    //parcours ligne principale
    for (i = 0; i < n - 1; i++) {
        //parcours ligne secondaire
        for (j = i + 1; j < n; j++) {
            //parcours colonnes
            sl = 0;
            for (k = 0; k < n; k++) {
                if (M[i][k] == M[j][k])
                    sl++;
            }
            if (sl == n) {
                if(indice == true)
                    printf("Les lignes %d et %d sont identique\n", i + 1, j + 1);
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
                if(indice==true)
                    printf("Les colonnes %d et %d sont identique\n",i+1,j+1);
                inc = false;
            }
        }
    }
    if(inc == true)
        return true;
    return false;
}

bool coup_correct(int ** M,int n, bool indice){
    
    //verif conditions
    bool fconditions_line = verif_lignes_matrice(M,n,indice);
    bool fconditions_col = verif_colonnes_matrice(M,n,indice);
    // verif identique
    except_indice(M, n, indice);
    bool sconditions = verif_identique(M,n,indice);
    if(fconditions_line == false || fconditions_col == false || sconditions == false)
        return false;
    return true;
}

bool coup_valide(int ** M,int n){
    bool correct = coup_correct(M,n,false);
    bool valide = false;
    int ** temp2;
    temp2 = create_matrice(n,temp2);
    temp2 = remplir_matrice_solution(temp2,n);
    if(correct == true)
        valide = comparer_liste(n,M,temp2);
    return valide;
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

int ** remplir_grille_masque(int **M,int n){
    switch(n){
        case 4:{
            M[0][0] = 1;
            M[0][1] = 0;
            M[0][2] = 0;
            M[0][3] = 0;

            M[1][0] = 0;
            M[1][1] = 0;
            M[1][2] = 1;
            M[1][3] = 0;

            M[2][0] = 1;
            M[2][1] = 0;
            M[2][2] = 1;
            M[2][3] = 1;

            M[3][0] = 0;
            M[3][1] = 1;
            M[3][2] = 0;
            M[3][3] = 0;
            return M;
            break;
        }
        case 8:{
            M[0][0] = 1;
            M[0][1] = 0;
            M[0][2] = 1;
            M[0][3] = 1;
            M[0][4] = 0;
            M[0][5] = 1;
            M[0][6] = 0;
            M[0][7] = 1;

            M[1][0] = 0;
            M[1][1] = 0;
            M[1][2] = 1;
            M[1][3] = 0;
            M[1][4] = 0;
            M[1][5] = 0;
            M[1][6] = 0;
            M[1][7] = 0;

            M[2][0] = 1;
            M[2][1] = 0;
            M[2][2] = 0;
            M[2][3] = 0;
            M[2][4] = 0;
            M[2][5] = 0;
            M[2][6] = 0;
            M[2][7] = 1;

            M[3][0] = 1;
            M[3][1] = 0;
            M[3][2] = 1;
            M[3][3] = 0;
            M[3][4] = 0;
            M[3][5] = 1;
            M[3][6] = 1;
            M[3][7] = 0;

            M[4][0] = 1;
            M[4][1] = 0;
            M[4][2] = 0;
            M[4][3] = 0;
            M[4][4] = 1;
            M[4][5] = 0;
            M[4][6] = 0;
            M[4][7] = 1;

            M[5][0] = 0;
            M[5][1] = 0;
            M[5][2] = 0;
            M[5][3] = 0;
            M[5][4] = 1;
            M[5][5] = 0;
            M[5][6] = 0;
            M[5][7] = 0;

            M[6][0] = 0;
            M[6][1] = 1;
            M[6][2] = 1;
            M[6][3] = 1;
            M[6][4] = 1;
            M[6][5] = 1;
            M[6][6] = 0;
            M[6][7] = 0;

            M[7][0] = 0;
            M[7][1] = 1;
            M[7][2] = 0;
            M[7][3] = 1;
            M[7][4] = 0;
            M[7][5] = 0;
            M[7][6] = 1;
            M[7][7] = 0;

            return M;
            break;
        }
        default:{
            break;
        }
    }
}

bool verif_remp_matrice(int **M, int n)
{
    int i, j; 
    bool res = true;
    for (i=0; i < n ; i++){
        for(j=0; j < n ; j++)
        {
            if(M[i][j]== -1)
                return false;
        }
    }
    return res;
}

bool verif_cases_tableau(int **M,int ligne, int n)
{
    int j, cpt;
    cpt = 0;
    for(j=0 ; j < n ; j++){
        if(M[ligne][j] == -1)
        {
            cpt +=1; 
        }
    }
    if( cpt == 2)
        return true ; 
    return false; 
}
// faire colonne rempli
// verif cases col tableau
bool ligne_remplie(int **M,int ligne ,int n){

    int i, cpt;
    cpt = 0;
    for(i=0 ; i < n ; i++){
        if(M[ligne][i] == 0 || M[ligne][i] == 1)
            cpt ++;
    }
    if( cpt == n)
        return true ;
    return false;
}



/*
indice5{

   comparer_ligne_entre_elles() // de la premiere a la derniere
   comparer_colonne_entre_elles() // de la premiere a la derniere

   comparaison_ligne_ou_colonne(matrice,taille){
        boucle 1 : parcours les lignes jusqu'a n
                    verifier si la ligne est remplie, 
                    si oui: 
                        verifier si ligne secondaire ( i+1) a deux cases en moins,
                        si oui
                            compare ligne principale avec la ligne a la position secondaire
                            si les 2 lignes sont identiques sauf dans les positions des cases vides:
                                afficher l'indice (le texte)
                            sinon:
                                ne rien afficher
                                passer a la ligne suivante
                        sinon
                            passer a la ligne suivante
                    sinon:
                        passer a la ligne suivante
   }
}
*/
bool verif_case_remp_vide(int i,int j, int **M){
    bool F ;
    if(M[i][j] == 0 || M[i][j] == 1){
        return true ;
    }
    return false; 
}


//  faire except indice pour les colonnes aussi
void except_indice(int **M, int n, bool indice){
    if(indice == true){
        // comparaison de ligne
        int i, j;
        int cpt1 =0;
        int cpt2 =0;
        bool first, second;
        //parcourir la ligne principale
        for(i=0 ; i < n ; i++){
            
            first = ligne_remplie(M,i ,n);
            // parcourir la ligne secondaire
            for(j=0;j<n;j++){
                // verifier si la ligne est remplie
                if(first == true){
                    //verifier si la ligne secondaire a deux cases en moins
                    second = verif_cases_tableau(M,j,n);
                    if(second == true){
                        //compare ligne principale avec la ligne a la position secondaire
                        for(int k=0;k<n;k++){
                            if(M[i][k] == M[j][k])
                                cpt1++;
                            if(M[j][k] == -1)
                                cpt2++;
                        }
                        if(cpt1 == n-2 && cpt2 == 2){
                            printf("");
                            printf("");
                            // afficher la ligne principale
                            // afficher la ligne secondaire
                            // dire a l'utilisateur de remplir de sorte a ce qu'ils ne soient pas identiques
                            printf("\n Veuillez remplir de telle sorte à ce que la ligne %d ne ressemble pas a la ligne  %d",i,i);
                        }
                    }
                }
            }
        }
    }
}



bool verif_mnr_rules(int **M, int n){

    // verif 3 chiffres consecutifs identiques dans une ligne
    int i, j;
    for(i=0;i<n;i++){

        for(j=0;j<n-2;j++){
            if(M[i][j] == M[i][j+1] && M[i][j] == M[i][j+2] && M[i][j] != -1){
                return false;
            }
        }
    }

    // verif 3 chiffres consecutifs identiques dans une colonne
    for(i=0;i<n;i++){
        for(j=0;j<n-2;j++){
            if(M[j][i] == M[j+1][i] && M[j][i] == M[j+2][i] && M[j][i] != -1){
                return false;
            }
        }
    }
    return true;
}

int **copy_mat(int** new,int ** copy,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            new[i][j] = copy[i][j];
        }
    }
    return new;
}

//----------------------------------------------------------------------------------------------------------------------------
