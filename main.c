#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "matrice.h"



int main()
{
    bool replay = false;

    do{

       int vie = 3;
       bool resolved = false;
       int menu_num = menu();
       if(menu_num == 1){
           bool restriction = false;
           int taille = ask_taille();

           //-----------------------------------------------------
           int **grille_jeux = choix_menu1(taille);
           int ** temporary;
           temporary = create_matrice(taille,temporary);
           temporary = remplir_grille_jeux(temporary,taille);
           restriction = comparer_liste(taille,grille_jeux,temporary);
           temporary = copy_mat(temporary,grille_jeux,taille);
           //-----------------------------------------------------
           if(restriction == true){
               printf("\n Pour cette partie, toute les solutions ne sont pas acceptes.\nVous devez trouver une solution precise\n");
               // boucle du jeux
               printf("\n\n Debut de la partie\n\n");

               do{

                    afficher_matrice(temporary,taille);
                    temporary = remplir_mat_user(taille,temporary,grille_jeux);

                    if(verif_remp_matrice(temporary,taille) == true){
                        if(coup_correct(temporary,taille,true) == false){
                            vie--;
                            if(vie > 0){
                                printf("\nIl vous reste %d VIE",vie);
                                coup_correct(temporary,taille,true);
                            }else{
                                printf("\nIl ne vous reste plus de vie");
                            }

                        }else{
                             if(coup_valide(temporary,taille) == false){
                                printf("\nCoup valide mais incorrect !\n");
                             }else{
                                printf("\n\nVous avez trouve la solution\n\n");
                                resolved = true;
                                break;
                            }
                        }

                    }else{

                        if(verif_mnr_rules(temporary,taille,false) == false){
                            vie--;
                            if(vie > 0){
                                verif_mnr_rules(temporary,taille,true);
                                coup_correct(temporary,taille,true);
                                printf("\npeut etre que votre matrice n'est pas completement rempli");
                                printf("\nIl vous reste %d vie",vie);
                            }
                            if(vie==0)
                                printf("\nIl ne vous reste plus de vie");
                        }

                    }
                   printf("\n La nouvelle matrice apres votre coup est : \n");
                }while(vie!=0);
                
                if(vie == 0 && resolved == false)
                    printf("\n echec dans la resolution de la grille.");
                printf("\n\n Fin de la partie\n\n");

           }else{
                // jouer boucle
                printf("\n\n Debut de la partie\n\n");
                do{
                    afficher_matrice(temporary,taille);
                    temporary = remplir_mat_user(taille,temporary,grille_jeux);
                    if(verif_remp_matrice(temporary,taille) == true){

                        if(coup_correct(temporary,taille,false) == false){
                            vie--;
                            if(vie > 0){
                                printf("\nIl vous reste %d vie",vie);
                                coup_correct(temporary,taille,true);
                            }else{
                                printf("\nIl ne vous reste plus de vie");
                                break;
                            }

                        }else{
                            printf("\nVous avez gagne");
                            resolved = true;
                            break;
                        }
                    }else{

                        if(verif_mnr_rules(temporary,taille,false) == false){
                            vie--;
                            if(vie > 0){
                                verif_mnr_rules(temporary,taille,true);
                                coup_correct(temporary,taille,true);
                                printf("\npeut etre que votre matrice n'est pas complètement rempli");
                                printf("\nIl vous reste %d",vie);
                            }else{
                                printf("Il ne vous reste plus de vie");
                                break;
                            }

                        }
                    }
                    printf("\n La nouvelle matrice apres votre coup est : \n");

                }while(vie!=0);
                if(vie == 0 && resolved == false)
                printf("\n echec dans la resolution de la grille.");
                printf("\n\n Fin de la partie\n\n");
           }
       }
       else{
           if(menu_num == 2){
               int taille = ask_taille();
               automatic_resolution(taille);

           }else{
               int taille = ask_taille();
               int choix;
               printf("\nSaisir :\n \n 1- Pour la generation de lignes (ou de colonnes) valides en fonction de la taille de la grille choisie (4x4 ou 8x8 ou 16*16)\n2- Construction d une grille complete valide a partir des lignes et colonnes valides\n\n");

               do{
                   printf("\nSaisir : ");
                   int b = scanf("%d",&choix);
                   if(b != 1){
                       fflush(stdin);
                   }
               }while(choix != 1 && choix !=2);
               // menu
               if(choix == 1){
                   affiche_ligne_sol(taille);
               }else{
                   if(taille == 16){
                       brute_sol(taille);
                   }else{
                       gen_matrice_sol_auto(taille,true);
                   }
               }
           }
       }
       replay = rejouer();
    }while(replay == true);
    printf("\nMerci d'avoir joue");
    return 0;
}