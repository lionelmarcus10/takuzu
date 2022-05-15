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
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

// permet de remplir une grille jeux a travers des informations données par le joeur
int** remplir_mat_user(int n, int** M,int** jeux_grille)
{

    char res;
    do{

        int lig, col, val;
        do{
            printf("\nVeuillez saisir le numero de la ligne de la case que vous voulez editer: ");
            int b = scanf("%d",&lig);
            if(b != 1){
                fflush(stdin);
            }
        }while(lig <= 0 || lig > n);
        lig--;
        do{
            printf("\nVeuillez saisir le numero de la colonne de la case que vous voulez editer: ");
            int b = scanf("%d",&col);
            if(b != 1){
                fflush(stdin);
            }
        }while(col <= 0 || col > n);
        col--;
        do{
            printf("\nQuelle valeur voulez vous saisir (0 ou 1 ) : ");
            int b = scanf("%d",&val);
            if(b != 1){
                fflush(stdin);
            }
        }while(val != 0 && val != 1);

        if(jeux_grille[lig][col] != -1){
            printf("\nVeuillez saisir d'autres coordonnees de cases car celle ci fait partie de la grille de jeux par defaut\n");
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

// creer une matrice / grille carrée de taille n*n
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

// permet de creer une grille masque a partir des informations données par le joueur
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
            int b = scanf("%d",&nb);
            if(b != 1){
                fflush(stdin);
            }
        }while(nb >6);
    }
    else
    {
        if(n==8){
            do{
                printf("\nCombien de cases visibles voulez vous avoir (pas plus 28) ?");
                int b = scanf("%d",&nb);
                if(b != 1){
                    fflush(stdin);
                }
            }while(nb >28);
        }else{
            do{
                printf("\nCombien de cases visibles voulez vous avoir (pas plus 126) ?");
                int b = scanf("%d",&nb);
                if(b != 1){
                    fflush(stdin);
                }
            }while(nb >126);
        }
    }
    for(int i=0; i < nb; i++)
    {
        do{
            printf("\nVeuillez saisir le numero de la ligne du masque que vous voulez afficher: ");
            int b = scanf("%d",&lig);
            if(b != 1){
                fflush(stdin);
            }
        }while(lig <= 0 || lig > n);

        do{
            printf("\nVeuillez saisir le numero de la colonne du masque que vous voulez afficher: ");
            scanf("%d", &col);
        }while(col <= 0 || col > n);

        M[lig-1][col-1] = 1;
    }
    return M;
}

// permet de creer une grille jeux a partir d'une grille masque
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
                        
                        M[i][j]= rand() % 2;
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
        afficher_matrice(M,n);
    }while(cond == true);
    return M;
}

// permet de creer automatiquement une grille masque
int** create_masque_auto(int n, int** M)
{
    srand(time(NULL));
    int nb, lig, col;
    //M = (int**) malloc(n * sizeof(int*));

    for(int p ; p < n ; p++)
    {
        //*(M+p) = (int*) malloc(n * sizeof(int));
        for(int k = 0; k < n; k++)
        {
            M[p][k] = 0;
        }
    }
    if(n==4)
    {
        for(int l=0; l < 6; l++)
        {

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
                int i = rand() % 8;
                int j = rand() % 8;
                M[i][j]=1;
            }
        }else{
            for(int h=0; h < 126; h++)
            {
                int i = rand() % 16;
                int j = rand() % 16;
                M[i][j]=1;
            }
        }

        
    }
    return M;
}

// permet de comparer deux matrices / grilles
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

// demande si le joueur veut rejouer ou pas
bool rejouer()
{
    int a;
    do {
        printf("\nSaisir:\n\n0 - Pour arreter de jouer\n1 - Pour rejouer\n Saisir :");
        int b = scanf("%d",&a);
        if(b != 1){
            a = -1;
            fflush(stdin);
        }
    }while(a!=0 && a!=1);
    if(a == 1)
        return true;
    return false;
}

// menu principale
int menu()
{
    int a;
    do{
        printf("\nSaisir: \n\n1 - Resoudre une grille\n2-  Resoudre automatiquement une grille de Takuzu\n3- Generer une grille de Takuzu\n");
        printf("\nSaisir : ");
        int b = scanf("%d",&a);
        if(b != 1){
            fflush(stdin);
        }
        printf("\n");
    }while(a!=1 && a!=2 && a!=3);

    return a;
}

// demander la taille de la grille
int ask_taille(){
    int taille;
    do{
        printf("\nChoisir la taille de la grille : \n \t1- 4*4\n\t2- 8*8\n\t3- 16*16\nSaisir un numero: ");
        int b = scanf("%d",&taille);
        if(b != 1){
            fflush(stdin);
            taille = -1;
        }
    }while(taille != 1 && taille != 2 && taille !=3);

    if(taille == 1)
        return 4;
    if(taille == 2)
        return 8;
    return 16;
}

// menu secondaire de l'option 1 du menu principale
// elle retourne une matrice en fonction des choix du joeur et celle pourra etre utilisé dans le jeux
int** choix_menu1(int taille){
    int **M;
    int fb;

    do {
         printf("\nSaisir: \n\t1 - Pour saisir manuellement un masque\n\t2 - Pour generer automatiquement un masque \n\t3 - Pour jouer\n saisir : ");
        int b = scanf("%d",&fb);
        if(b != 1){
            fflush(stdin);
        }
    }while(fb!=1 && fb!=2 && fb!=3);
    switch(fb){
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
            M = create_matrice(taille,M);
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

// permet d'afficher une matrice / une grille ( qu'elle soit solution, jeux , masque , rempli ou pas rempli)
void afficher_matrice(int ** M, int n){
    int j ;
    printf("\n");
    if(n==4) {
        printf("\tA\tB\tC\tD\n");
    }
    else{
        if(n==8)
        {
            printf("\tA\tB\tC\tD\tE\tF\tG\tH\n");
        }
        if(n==16)
        {
            printf("\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\tK\tL\tM\tN\tO\tP\n");
        }
    }
    for (int i = 0; i <n; i++)
    {
        printf("%d \t",i+1);
        for (j = 0; j <n; j++)
        {
            printf("%d \t", M[i][j]);
        }
        printf("\n");
    }
}



// verifie si les lignes respectent les regles de takuzu
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
                    inc = false;
                    if(indice == true){
                        printf("%d = %d  = %d pour k = %d donc ligne %d  pas valide\n", M[i][k], M[i][k+1], M[i][k+2],k+1,i+1);

                        if(M[i][k]==0)
                        {
                            printf("Entre deux 0, il ne peut y avoir qu'un 1");
                            printf("A gauche,a droite d’une serie de deux 0, il ne peut y avoir qu’un 1 ");
                        }
                        else{
                            printf("Entre deux 1, il ne peut y avoir qu'un 0 ");
                            printf("A gauche,a droite d’une serie de deux 1, il ne peut y avoir qu’un 0 ");
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

// verifie si les colonnes respectent les règles de takuzu
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
        if (somme0 == somme1 && somme0+somme1==n ){
            int k;
            for (k = 0; k < (n - 2); k++) {
                if (M[k][i] == M[k + 1][i] && M[k][i] == M[k + 2][i]) {
                    inc = false;
                    if (indice == true) {
                        printf("%d = %d  = %d donc la colonne %d  n'est pas valide \n", M[k][i], M[k + 1][i],
                               M[i][k + 2], i + 1);

                        if (M[k][i] == 0) {
                            printf("Entre deux 0, il ne peut y avoir qu'un 1");
                            printf("Au dessus,en dessous d’une serie de deux 0, il ne peut y avoir qu’un 1");
                        } else {
                            printf("Entre deux 1, il ne peut y avoir qu'un 0");
                            printf("Au dessus,en dessous d’une serie de deux 1, il ne peut y avoir qu’un 0");
                        }
                    }
                    break;
                }
            }
        } else {
            if (indice == true)
                printf("La colonne %d n'a pas le meme nombre de 0 et de 1\n", i + 1);
            inc = false;
        }
    }
    if (inc == false)
        return false;
    return true;
}

// verifie si il y'a des lignes et ou des colonnes identiques dans la grille jeux / matrice
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
                inc = true;
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
                inc = true;
            }
        }
    }
    if(inc == true)
        return true;
    return false;
}

// verifie si la grille est une grille solution
bool coup_correct(int ** M,int n, bool indice){
    
    //verif conditions
    bool fconditions_line = verif_lignes_matrice(M,n,indice);
    bool fconditions_col = verif_colonnes_matrice(M,n,indice);
    // verif identique
    except_indice(M, n, indice);
    bool sconditions = verif_identique(M,n,indice);
    if(fconditions_line == true && fconditions_col == true && sconditions == false)
        return true;
    return false;
}

// verifie si un coup est valide ( si il correspond a la grille imposé dans le menu 1 - 3
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

// grille solution des grilles imposé dans le menu  1 - 3
// dans le menu 1- 3 l'utilisateur doit trouver une grille solution precise

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

//grille jeux des grilles imposé dans le menu  1 - 3
// dans le menu 1- 3  l'utilisateur doit trouver une grille solution precise
int ** remplir_grille_jeux(int **M,int n){
    switch(n){
        case 4:{
            M[0][0] = 1;
            M[1][2] = 1;
            M[2][0] = 0;
            M[2][3] = 0;
            M[2][2] = 1;
            M[3][1] = 1;
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


// grille masque des grilles solutions imposé dans le menu  1 - 3
// dans le menu 1- 3  l'utilisateur doit trouver une grille solution precise
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


// verifie si une matrice / grille est totalement rempli ou pas
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

// verifier si il manque 2 cases dans une ligne
// permettra de detecter des situations pour afficher l'indice 5 ( du pdf de presentation du projet )
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

// verifier si il manque 2 cases dans une colonne
// permettra de detecter des situations pour afficher l'indice 5 ( du pdf de presentation du projet )
bool verif_cases_col_tableau(int **M,int colonne, int n)
{
    int j, cpt;
    cpt = 0;
    for(j=0 ; j < n ; j++){
        if(M[j][colonne] == -1)
        {
            cpt +=1; 
        }
    }
    if( cpt == 2)
        return true ; 
    return false; 
}

// verifie si une ligne est completement rempli ou pas
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

bool colonne_remplie(int**M, int colonne, int n){
    int j, cpt;
    cpt = 0;
    for(j= 0; j< n; j++)
    {
        if(M[j][colonne]==0 || M[j][colonne]== 1)
        {
            cpt++;
        }
    }
    if( cpt == n)
        return true;
    return false; 
    
}

// permet d'afficher l'indice 5 du pdf
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
                            // afficher la ligne principale
                            for(int g = 0; g < n; g++){
                                printf(" %d ",M[i][g]);
                            }
                            // afficher la ligne secondaire
                            for(int g = 0; g < n; g++){
                                printf(" %d ",M[j][g]);
                            }                            
                            
                            printf("\n Veuillez remplir de telle sorte à ce que la ligne %d ne ressemble pas a la ligne  %d",i+1,j+1);
                        }
                    }
                }
            }
        }

        bool first_col, second_col;
        int cpt3, cpt4;
        
        //parcourir la colonne principale
        for(i=0 ; i < n ; i++){
            
            first_col = colonne_remplie(M,i ,n);
            // parcourir la colonne secondaire
            for(j=0;j<n;j++){
                //verifier si la colonne est remplie
                if(first_col == true){
                    //verifier si la colonne secondaire a deux cases en moins
                    second_col = verif_cases_col_tableau(M,j,n);
                    if(second_col == true){
                        //compare colonne principale avec la colonne a la position secondaire
                        for(int k=0;k<n;k++){
                            if(M[k][i] == M[k][j])
                                cpt3++;
                            if(M[k][j] == -1)
                                cpt4++;
                        }
                        if(cpt3 == n-2 && cpt4 == 2){
                            // afficher la colonne principale
                            for(int g = 0; g < n; g++){
                                printf(" %d ",M[g][i]);
                            }
                            // afficher la colonne secondaire
                            for(int g = 0; g < n; g++){
                                printf(" %d ",M[g][j]);
                            }                            
                            
                            printf("\n Veuillez remplir de telle sorte à ce que la ligne %d ne ressemble pas a la ligne  %d",i+1,j+1);
                        }
                    }
                }
            }
        }
    }
}


// verifier si certaines règles du takuzu sont respecté meme si la grille n'est pas totalement rempli
// permet de verifier si 3 nombres identiques se suivent sur une ligne ou sur une colonne
bool verif_mnr_rules(int **M, int n,bool indice){

    // verif 3 chiffres consecutifs identiques dans une ligne
    int i, j;
    for(i=0;i<n;i++){

        for(j=0;j<n-2;j++){
            if(M[i][j] == M[i][j+1] && M[i][j] == M[i][j+2] && M[i][j] != -1){
                if(indice ==true ){
                    printf("%d = %d  = %d pour donc ligne %d  pas valide\n", M[i][j], M[i][j+1], M[i][j+2],i+1);
                }
                return false;
            }
        }
    }

    // verif 3 chiffres consecutifs identiques dans une colonne
    for(i=0;i<n;i++){
        for(j=0;j<n-2;j++){
            if(M[j][i] == M[j+1][i] && M[j][i] == M[j+2][i] && M[j][i] != -1){
                if(indice ==true ){
                    printf("%d = %d  = %d donc la colonne %d n'est pas valide\n", M[j][i], M[j+1][i], M[j+2][i],i+1);
                }
                return false;
            }
        }
    }

    // si ligne ou col rempli verif si mmeme nombre de 0 et 1
    return true;
}

// copier toutes les valeurs contenus dans une matrice vers une autre matrice
int **copy_mat(int** new,int ** copy,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            new[i][j] = copy[i][j];
        }
    }
    return new;
}


// convertir un nombre en binaire et le mettre dans un tableau
void tobinary(int * T,int number ,int taille){

    int i = 1;
    for(i;i<=taille;i++){
        T[taille-i]=number%2;
        number =number/2;
    }
    i--;
}
//--------------------------------------------------------------------------------------------------------------------------------
/*

 0 - 15  || 6
 0 - 255 || 32
 0 - 65535 || 1296

 */

// ce soir ( menu 2 : automatiquement ou imposé matrice )
// ce soir menu 2 imposé finir
// finir generateur de mat
// remplir ligne sans remplir case predefini
// verif cases col tableau
// generer matrice solution
// resoudre a partir de grille masque saisi
// resoudre a partir de grille masque automatique
// resoudre grille predefinie
// remplir grille masque et grille solution et grille jeux du 16*16

//--------------------------------------------------------------------------------------------------------------------------------


int ** remplir_une_ligne(int**M,int * matrice_ligne,int ligne,int taille){
    for(int i=0;i<taille;i++){
        M[ligne][i] = matrice_ligne[i];
    }
    return  M;
}

// generer automatiquement une matrice / grille solution pour une taille donné
// optimiser et optimiser aussi le menu
int** gen_matrice_sol_auto(int taille, bool indice){

    int sol_taille = sol_len(taille);
    int temp[sol_taille];

    srand(time(NULL));

    //tableau contenant toute les solutions
    int * sol = (int*) malloc(sizeof(int)*sol_taille);

    solutions(sol,taille);

    int ** M;
    M = create_matrice(taille,M);


    int* matrice_sol = (int*) malloc(sizeof(int)*taille);

    do{
        // generer automatiquement une suite de nombre qui en binaire sont solution d'une ligne

        for(int j=0;j<taille;j++){
            matrice_sol[j] = sol[rand()% sol_taille];

            // verifier si elle appartien deja a matrice sol ou pas à partir de j = 1

            // tant que oui, chercher a attribuer une autre valeur et checker

        }
        //------------------------------------------------------
        for(int l=0;l<taille;l++){

            tobinary(temp,matrice_sol[l],taille);

            // a partir de 1 checker si le nombre n'est pas deja dans une ligne

            //

            // remplir chaque ligne par un nombre
            M = remplir_une_ligne(M,temp,l,taille);
        }
    }while(coup_correct(M,taille,false) == false);
    if(indice == true){
        printf("\nGeneration de nombre...\n");
        Sleep(2500);
        printf("\nLes nombres generes sont :");
        Sleep(800);
        for(int g=0;g<taille;g++){
            printf(" %d ",matrice_sol[g]);
            Sleep(800);
        }
        printf("\n");
        Sleep(1000);
        printf("\nAffichage de la grille avec les nombres binaires integres ligne par ligne\n");
        Sleep(1000);
        afficher_matrice(M,taille);
    }
    return M;


}

// intègre dans un tableau toute les lignes solutions pour une grille en fonction de sa taille
void solutions(int * matligne ,int taille){
    switch(taille){
        case 4:{
            int sol[6]= {3,5,6,9,10,12};
            for(int i=0;i<6;i++){
                matligne[i] = sol[i];
            }
            break;
        }
        case 8:{
            int sol[34] = {43,45,51,53,54,75,77,83,85,86,89,90,101,102,105,106,108,147,149,150,153,154,165,166,169,170,172,178,180,201,202,204,210,212};
            for(int i=0;i<34;i++){
                matligne[i] = sol[i];
            }
            break;
        }
        default:{
            int sol[1296] = {9435, 9563, 9579, 9581, 9627, 9643, 9645, 9651, 9653, 9654, 9819, 9835, 9837, 9883, 9899, 9901, 9907, 9909, 9910, 9931, 9933, 9939, 9941, 9942, 9945, 9946, 10587, 10603, 10605, 10651, 10667, 10669, 10675, 10677, 10678, 10843, 10859, 10861, 10907, 10923, 10925, 10931, 10933, 10934, 10955, 10957, 10963, 10965, 10966, 10969, 10970, 11051, 11053, 11059, 11061, 11062, 11083, 11085, 11091, 11093, 11094, 11097, 11098, 11109, 11110, 11113, 11114, 11116, 11419, 11435, 11437, 11443, 11445, 11446, 11467, 11469, 11475, 11477, 11478, 11481, 11482, 11563, 11565, 11571, 11573, 11574, 11595, 11597, 11603, 11605, 11606, 11609, 11610, 11621, 11622, 11625, 11626, 11628, 11667, 11669, 11670, 11673, 11674, 11685, 11686, 11689, 11690, 11692, 11698, 11700, 12891, 12907, 12909, 12955, 12971, 12973, 12979, 12981, 12982, 13003, 13005, 13011, 13013, 13014, 13017, 13018, 13099, 13101, 13107, 13109, 13110, 13131, 13133, 13139, 13141, 13142, 13145, 13146, 13157, 13158, 13161, 13162, 13164, 13467, 13483, 13485, 13491, 13493, 13494, 13515, 13517, 13523, 13525, 13526, 13529, 13530, 13611, 13613, 13619, 13621, 13622, 13643, 13645, 13651, 13653, 13654, 13657, 13658, 13669, 13670, 13673, 13674, 13676, 13715, 13717, 13718, 13721, 13722, 13733, 13734, 13737, 13738, 13740, 13746, 13748, 13899, 13901, 13907, 13909, 13910, 13913, 13914, 13925, 13926, 13929, 13930, 13932, 13971, 13973, 13974, 13977, 13978, 13989, 13990, 13993, 13994, 13996, 14002, 14004, 14025, 14026, 14028, 14034, 14036, 18779, 18795, 18797, 18843, 18859, 18861, 18867, 18869, 18870, 19035, 19051, 19053, 19099, 19115, 19117, 19123, 19125, 19126, 19147, 19149, 19155, 19157, 19158, 19161, 19162, 19243, 19245, 19251, 19253, 19254, 19275, 19277, 19283, 19285, 19286, 19289, 19290, 19301, 19302, 19305, 19306, 19308, 19611, 19627, 19629, 19635, 19637, 19638, 19659, 19661, 19667, 19669, 19670, 19673, 19674, 19755, 19757, 19763, 19765, 19766, 19787, 19789, 19795, 19797, 19798, 19801, 19802, 19813, 19814, 19817, 19818, 19820, 19859, 19861, 19862, 19865, 19866, 19877, 19878, 19881, 19882, 19884, 19890, 19892, 21083, 21099, 21101, 21147, 21163, 21165, 21171, 21173, 21174, 21195, 21197, 21203, 21205, 21206, 21209, 21210, 21291, 21293, 21299, 21301, 21302, 21323, 21325, 21331, 21333, 21334, 21337, 21338, 21349, 21350, 21353, 21354, 21356, 21659, 21675, 21677, 21683, 21685, 21686, 21707, 21709, 21715, 21717, 21718, 21721, 21722, 21803, 21805, 21811, 21813, 21814, 21835, 21837, 21843, 21845, 21846, 21849, 21850, 21861, 21862, 21865, 21866, 21868, 21907, 21909, 21910, 21913, 21914, 21925, 21926, 21929, 21930, 21932, 21938, 21940, 22091, 22093, 22099, 22101, 22102, 22105, 22106, 22117, 22118, 22121, 22122, 22124, 22163, 22165, 22166, 22169, 22170, 22181, 22182, 22185, 22186, 22188, 22194, 22196, 22217, 22218, 22220, 22226, 22228, 22827, 22829, 22835, 22837, 22838, 22859, 22861, 22867, 22869, 22870, 22873, 22874, 22885, 22886, 22889, 22890, 22892, 22931, 22933, 22934, 22937, 22938, 22949, 22950, 22953, 22954, 22956, 22962, 22964, 23115, 23117, 23123, 23125, 23126, 23129, 23130, 23141, 23142, 23145, 23146, 23148, 23187, 23189, 23190, 23193, 23194, 23205, 23206, 23209, 23210, 23212, 23218, 23220, 23241, 23242, 23244, 23250, 23252, 23333, 23334, 23337, 23338, 23340, 23346, 23348, 23369, 23370, 23372, 23378, 23380, 23396, 25755, 25771, 25773, 25779, 25781, 25782, 25803, 25805, 25811, 25813, 25814, 25817, 25818, 25899, 25901, 25907, 25909, 25910, 25931, 25933, 25939, 25941, 25942, 25945, 25946, 25957, 25958, 25961, 25962, 25964, 26003, 26005, 26006, 26009, 26010, 26021, 26022, 26025, 26026, 26028, 26034, 26036, 26187, 26189, 26195, 26197, 26198, 26201, 26202, 26213, 26214, 26217, 26218, 26220, 26259, 26261, 26262, 26265, 26266, 26277, 26278, 26281, 26282, 26284, 26290, 26292, 26313, 26314, 26316, 26322, 26324, 26923, 26925, 26931, 26933, 26934, 26955, 26957, 26963, 26965, 26966, 26969, 26970, 26981, 26982, 26985, 26986, 26988, 27027, 27029, 27030, 27033, 27034, 27045, 27046, 27049, 27050, 27052, 27058, 27060, 27211, 27213, 27219, 27221, 27222, 27225, 27226, 27237, 27238, 27241, 27242, 27244, 27283, 27285, 27286, 27289, 27290, 27301, 27302, 27305, 27306, 27308, 27314, 27316, 27337, 27338, 27340, 27346, 27348, 27429, 27430, 27433, 27434, 27436, 27442, 27444, 27465, 27466, 27468, 27474, 27476, 27492, 27795, 27797, 27798, 27801, 27802, 27813, 27814, 27817, 27818, 27820, 27826, 27828, 27849, 27850, 27852, 27858, 27860, 27941, 27942, 27945, 27946, 27948, 27954, 27956, 27977, 27978, 27980, 27986, 27988, 28004, 28050, 28052, 28068, 37467, 37483, 37485, 37531, 37547, 37549, 37555, 37557, 37558, 37579, 37581, 37587, 37589, 37590, 37593, 37594, 37675, 37677, 37683, 37685, 37686, 37707, 37709, 37715, 37717, 37718, 37721, 37722, 37733, 37734, 37737, 37738, 37740, 38043, 38059, 38061, 38067, 38069, 38070, 38091, 38093, 38099, 38101, 38102, 38105, 38106, 38187, 38189, 38195, 38197, 38198, 38219, 38221, 38227, 38229, 38230, 38233, 38234, 38245, 38246, 38249, 38250, 38252, 38291, 38293, 38294, 38297, 38298, 38309, 38310, 38313, 38314, 38316, 38322, 38324, 38475, 38477, 38483, 38485, 38486, 38489, 38490, 38501, 38502, 38505, 38506, 38508, 38547, 38549, 38550, 38553, 38554, 38565, 38566, 38569, 38570, 38572, 38578, 38580, 38601, 38602, 38604, 38610, 38612, 39211, 39213, 39219, 39221, 39222, 39243, 39245, 39251, 39253, 39254, 39257, 39258, 39269, 39270, 39273, 39274, 39276, 39315, 39317, 39318, 39321, 39322, 39333, 39334, 39337, 39338, 39340, 39346, 39348, 39499, 39501, 39507, 39509, 39510, 39513, 39514, 39525, 39526, 39529, 39530, 39532, 39571, 39573, 39574, 39577, 39578, 39589, 39590, 39593, 39594, 39596, 39602, 39604, 39625, 39626, 39628, 39634, 39636, 39717, 39718, 39721, 39722, 39724, 39730, 39732, 39753, 39754, 39756, 39762, 39764, 39780, 42139, 42155, 42157, 42163, 42165, 42166, 42187, 42189, 42195, 42197, 42198, 42201, 42202, 42283, 42285, 42291, 42293, 42294, 42315, 42317, 42323, 42325, 42326, 42329, 42330, 42341, 42342, 42345, 42346, 42348, 42387, 42389, 42390, 42393, 42394, 42405, 42406, 42409, 42410, 42412, 42418, 42420, 42571, 42573, 42579, 42581, 42582, 42585, 42586, 42597, 42598, 42601, 42602, 42604, 42643, 42645, 42646, 42649, 42650, 42661, 42662, 42665, 42666, 42668, 42674, 42676, 42697, 42698, 42700, 42706, 42708, 43307, 43309, 43315, 43317, 43318, 43339, 43341, 43347, 43349, 43350, 43353, 43354, 43365, 43366, 43369, 43370, 43372, 43411, 43413, 43414, 43417, 43418, 43429, 43430, 43433, 43434, 43436, 43442, 43444, 43595, 43597, 43603, 43605, 43606, 43609, 43610, 43621, 43622, 43625, 43626, 43628, 43667, 43669, 43670, 43673, 43674, 43685, 43686, 43689, 43690, 43692, 43698, 43700, 43721, 43722, 43724, 43730, 43732, 43813, 43814, 43817, 43818, 43820, 43826, 43828, 43849, 43850, 43852, 43858, 43860, 43876, 44179, 44181, 44182, 44185, 44186, 44197, 44198, 44201, 44202, 44204, 44210, 44212, 44233, 44234, 44236, 44242, 44244, 44325, 44326, 44329, 44330, 44332, 44338, 44340, 44361, 44362, 44364, 44370, 44372, 44388, 44434, 44436, 44452, 45643, 45645, 45651, 45653, 45654, 45657, 45658, 45669, 45670, 45673, 45674, 45676, 45715, 45717, 45718, 45721, 45722, 45733, 45734, 45737, 45738, 45740, 45746, 45748, 45769, 45770, 45772, 45778, 45780, 45861, 45862, 45865, 45866, 45868, 45874, 45876, 45897, 45898, 45900, 45906, 45908, 45924, 46227, 46229, 46230, 46233, 46234, 46245, 46246, 46249, 46250, 46252, 46258, 46260, 46281, 46282, 46284, 46290, 46292, 46373, 46374, 46377, 46378, 46380, 46386, 46388, 46409, 46410, 46412, 46418, 46420, 46436, 46482, 46484, 46500, 46665, 46666, 46668, 46674, 46676, 46692, 46738, 46740, 46756, 51499, 51501, 51507, 51509, 51510, 51531, 51533, 51539, 51541, 51542, 51545, 51546, 51557, 51558, 51561, 51562, 51564, 51603, 51605, 51606, 51609, 51610, 51621, 51622, 51625, 51626, 51628, 51634, 51636, 51787, 51789, 51795, 51797, 51798, 51801, 51802, 51813, 51814, 51817, 51818, 51820, 51859, 51861, 51862, 51865, 51866, 51877, 51878, 51881, 51882, 51884, 51890, 51892, 51913, 51914, 51916, 51922, 51924, 52005, 52006, 52009, 52010, 52012, 52018, 52020, 52041, 52042, 52044, 52050, 52052, 52068, 52371, 52373, 52374, 52377, 52378, 52389, 52390, 52393, 52394, 52396, 52402, 52404, 52425, 52426, 52428, 52434, 52436, 52517, 52518, 52521, 52522, 52524, 52530, 52532, 52553, 52554, 52556, 52562, 52564, 52580, 52626, 52628, 52644, 53835, 53837, 53843, 53845, 53846, 53849, 53850, 53861, 53862, 53865, 53866, 53868, 53907, 53909, 53910, 53913, 53914, 53925, 53926, 53929, 53930, 53932, 53938, 53940, 53961, 53962, 53964, 53970, 53972, 54053, 54054, 54057, 54058, 54060, 54066, 54068, 54089, 54090, 54092, 54098, 54100, 54116, 54419, 54421, 54422, 54425, 54426, 54437, 54438, 54441, 54442, 54444, 54450, 54452, 54473, 54474, 54476, 54482, 54484, 54565, 54566, 54569, 54570, 54572, 54578, 54580, 54601, 54602, 54604, 54610, 54612, 54628, 54674, 54676, 54692, 54857, 54858, 54860, 54866, 54868, 54884, 54930, 54932, 54948, 55589, 55590, 55593, 55594, 55596, 55602, 55604, 55625, 55626, 55628, 55634, 55636, 55652, 55698, 55700, 55716, 55881, 55882, 55884, 55890, 55892, 55908, 55954, 55956, 55972, 56100};
            for(int i=0;i<1296;i++){
                matligne[i] = sol[i];
            }
            break;
        }
    }
}

// retourne le nombre de ligne solution possible pour une taille donné de grille (permet de faire des range dans d'autres fonctions)
int sol_len(int taille){
    if(taille == 4){
        return 6;
    }else{
        if(taille == 8){
            return 34;
        }else{
            return 1296;
        }

    }
}


// afficher toute les solutions possible pour une ligne
void affiche_ligne_sol(int taille){

    int sol_taille = sol_len(taille);
    int sol[sol_taille];
    int * allsol = (int*) malloc(sizeof(int)*sol_taille);
    solutions(allsol,taille);
    printf("\nil y'a en tout %d solutions possible pour une ligne ou une colonne\n",sol_taille);
    printf("\nToute les solutions possibles pour une ligne ou une colonne sont : \n\n");
    Sleep(3000);
    for(int z =0;z<sol_taille;z++){
        tobinary(sol,allsol[z],taille);
        printf("%d |--->  ",allsol[z]);
        for(int v=0;v<taille;v++){
            printf(" %d ",sol[v]);
        }
        printf("\n");
    }
}

// resoudre une matrice aléatoirement
void automatic_resolution(int taille){

    int **M,**sol;
    M = create_matrice(taille,M);
    sol = create_matrice(taille,sol);


    afficher_matrice(M,taille);
    sol = gen_matrice_sol_auto(taille,false);
    // generer aleatoirement
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille;j++){
            if(M[i][j] ==-1)
                M[i][j]= rand() % 2;
        }
    }
    // comparer
    do{
        for(int i=0;i<taille;i++){
            for(int j=0;j<taille;j++){
                if(M[i][j] != sol[i][j])
                    M[i][j]= rand() % 2;
            }
        }
        printf("\nchargement du coup...\n");
        Sleep(1300);
        afficher_matrice(M,taille);
    }while(comparer_liste(taille,M,sol) == false);
}





//--------------------------------------------------------------------------------------------------------------------------------------------
// permet de generer toute les combinaisons possible pour une matrice 16*16
void brute_sol(int taille){

    int taille_sol = sol_len(taille);
    int * sol = (int*) malloc(sizeof(int)*taille_sol);
    solutions(sol,taille);

    int ** M;
    M = create_matrice(taille,M);

    int temp[taille_sol];

    // 1
    for(int a=0;a<taille;a++){
        tobinary(temp,sol[a],taille);
        remplir_une_ligne(M,temp,a,taille);
        // 2
        for(int b=0;b<taille;b++){
            tobinary(temp,sol[b],taille);
            remplir_une_ligne(M,temp,b,taille);
            // 3
            for(int c=0;c<taille;c++){
                tobinary(temp,sol[c],taille);
                remplir_une_ligne(M,temp,c,taille);
                //4
                for(int d=0;d<taille;d++){
                    tobinary(temp,sol[d],taille);
                    remplir_une_ligne(M,temp,d,taille);
                    //5
                    for(int e=0;e<taille;e++){
                        tobinary(temp,sol[e],taille);
                        remplir_une_ligne(M,temp,e,taille);
                        //6
                        for(int f=0;f<taille;f++){
                            tobinary(temp,sol[f],taille);
                            remplir_une_ligne(M,temp,f,taille);
                            // 7
                            for(int g=0;g<taille;g++){
                                tobinary(temp,sol[g],taille);
                                remplir_une_ligne(M,temp,g,taille);
                                // 8
                                for(int h=0;h<taille;h++){
                                    tobinary(temp,sol[h],taille);
                                    remplir_une_ligne(M,temp,h,taille);
                                    // 9
                                    for(int i=0;i<taille;i++){
                                        tobinary(temp,sol[i],taille);
                                        remplir_une_ligne(M,temp,i,taille);
                                        // 10
                                        for(int j=0;j<taille;j++){
                                            tobinary(temp,sol[j],taille);
                                            remplir_une_ligne(M,temp,j,taille);
                                            // 11
                                            for(int k=0;k<taille;k++){
                                                tobinary(temp,sol[k],taille);
                                                remplir_une_ligne(M,temp,k,taille);
                                                // 12
                                                for(int l=0;l<taille;l++){
                                                    tobinary(temp,sol[l],taille);
                                                    remplir_une_ligne(M,temp,l,taille);
                                                    // 13
                                                    for(int m=0;m<taille;m++){
                                                        tobinary(temp,sol[m],taille);
                                                        remplir_une_ligne(M,temp,m,taille);
                                                        // 14
                                                        for(int n=0;n<taille;n++){
                                                            tobinary(temp,sol[n],taille);
                                                            remplir_une_ligne(M,temp,n,taille);
                                                            // 15
                                                            for(int o=0;o<taille;o++){
                                                                tobinary(temp,sol[o],taille);
                                                                remplir_une_ligne(M,temp,o,taille);
                                                                // 16
                                                                for(int p=0;p<taille;p++){
                                                                    tobinary(temp,sol[p],taille);
                                                                    remplir_une_ligne(M,temp,p,taille);
                                                                    if(coup_correct(M,taille,false) == true){
                                                                        afficher_matrice(M,taille);
                                                                        printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",sol[a],sol[b],sol[c],sol[d],sol[e],sol[f],sol[g],sol[h],sol[i],sol[j],sol[k],sol[l],sol[m],sol[n],sol[o],sol[p]);
                                                                        break;
                                                                    }else{
                                                                        printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",sol[a],sol[b],sol[c],sol[d],sol[e],sol[f],sol[g],sol[h],sol[i],sol[j],sol[k],sol[l],sol[m],sol[n],sol[o],sol[p]);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }
}