#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "matrice.h"


int main()
{
    /*
    int x;
    menu();
    x=rejouer();
    */

    int n, ** G1;
    G1 = create_matrice(4,G1);
    G1 = remplir_matrice_solution(G1,4);
    bool x = veri_lignes_matrice(G1,4);
    if(x==false){
        printf("\nCe n'est pas valide");
    }else{
        printf("\nC'est valide");
    }
    return 0;

    /* grille jeux 4*4/
    int G2[4][4];
    G2[0][0]=1;
    G2[1][2]=1;
    G2[2][0]=0;
    G2[1][2]=1;
    G2[2][3]=0;
    G2[3][1]=1;
    */
    /* faire la grille jeux et la matrice 8*8 et 16*16 */
    /*int i, j, lig = 4, col = 4;
    for (i = 0; i < lig; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d \t", G1[i][j]);
        }
        printf("\n");
    }

    do {
        printf("Voulez vous une matrice 4 ou 8 ?");
        scanf("%d", &n);
    }while (n!=4 && n!=8);
    create_matrice(n, M);*/
}