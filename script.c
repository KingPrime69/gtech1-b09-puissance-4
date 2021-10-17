#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define NBL 6
#define NBC 7

char request[10] = "wait";
char start[10] = "jouer";
char norm[10] = "regles";
char tab[NBL][NBC];
char i;
char u;
int count;

void init(void) {
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
  printf("  PUISSANCE 4\n");
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      tab[i][u] = '|';
      printf("%s",*tab);
      tab[i][u] = '.';
      printf("%s", *tab);
    }
    tab[i][u] = '|';
    printf("%s", *tab);
    printf("\n");
  }
  for(count=1; count != 8; count++){
    printf("|");
    printf("%d", count);
  }
  printf("|");
  printf("\n");
}

void menu(void){
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
  printf("     -MENU\n");
  printf("-Régles du jeu\n");
  printf("-Lancer la partie\n");
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n\n");
  printf("Choissisez un sommaire\n");
  printf("-jouer (lancera la partie)\n");
  printf("-régles (affichera les régles et commandes du jeu)\n");
}

void rule(void){
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
  printf("Règles du jeu\n");
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
}

void main(void){
  menu();
  scanf("%10s", request);
  if(strcmp(request, start) == 0){
    init();
  }
  else if(strcmp(request, norm) == 0){
    rule();
  }
  else{
    printf("erreur");
  }
}
	
