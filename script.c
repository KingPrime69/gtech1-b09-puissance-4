//rajouter les commandes et mettre la navigation texte pendant le jeux
//essaye avec lecture de hit en %d et mettre quand 0 passer en mode txt
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define NBL 100
#define NBC 100

int loop;
int line;
int slide[NBC];
int hit;
char tokens[] = "ox";
int init = 0;
char end[5]= "fin";
char request[10] = "wait";
char start[10] = "jouer";
char norm[10] = "regles";
char head[5] = "menu";
char tab[NBL][NBC];
int count;
int player = 0;
int* L;
int* C;
int add;


void title(char* heading){
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
  printf("%s", heading);
  printf("\n");
  for(count=0; count<15; count++)
    printf("_");
  printf("\n\n");
}

void grill(void) {
  C = malloc(sizeof(int));
  printf("nombre de colone ?\n");
  scanf("%d", C);
  L = malloc(sizeof(int));
  printf("nombre de ligne ?\n");
  scanf("%d", L);
  for(int l=0; l<*L; l++) {
    for(int c=0; c<*C; c++) {
      tab[l][c] = '.';
    }
  }
}

void show_grill(void){
  title("  Puissance 4");
  for(int l=0; l<*L; l++){
    printf("\n");
    for(int c=0; c<*C; c++) {
      printf("|%c", tab[l][c]);
    }
    printf("|");
  }
  printf("\n");
  for(int c=1; c<*C+1; c++)
    printf("|%d", c);
  printf("|\n");
}

void menu(void){
  for(count=0; count<15; count++)
    title("    -Menu");
  printf("Choissisez un sommaire:\n");
  printf("-jouer (lancera la partie)\n");
  printf("-régles (affichera les régles et commandes du jeu)\n");
}

void rule(void){
  title(" Règles du jeux");
  printf("Les règles du puissance 4 sont simple le but est d'être le premiers à aligner 4 jetons horizontalement, ve\
\rticalement ou diagonalement.\n");
  title("   Commandes");
  printf("écrire les comandes pour naviguer dans le jeux\n");
}

void player_stroke(int playerAction, int next){
  add = *L-1;
  tab[add-next][playerAction] = tokens[player];
  slide[playerAction]++;
}

void pawn(){
  for (int l=0; l<line; l++){
    slide[l] = 0;
  }
  printf("\n");
}

void game(){
  grill();
  show_grill();
  loop = 1;
  while(loop == 1){
    hit = 0;
    pawn();
    printf("Ou voulez vous placez votre pion?\n");
    scanf("%s", &hit);
    if(hit>48 && hit <=*C+48){
      hit =hit-48;
      player_stroke(hit-1, slide[hit-1]);
      show_grill();
      player = !player;
    }
    else{
      printf("Seul les chiffres de 1 à 7 sont acceptable");
    }
  }
}

void main(void){
  if(init == 0){
    menu();
    init = 1;
  }
  while(init == 1){
    scanf("%10s", request);
    if(strcmp(request, start) == 0){
      game();
    }
    else if(strcmp(request, norm) == 0){
      rule();
    }
    else if(strcmp(request, head) == 0){
      menu();
    }
    else if(strcmp(request, end) == 0){
      init = 0;
    }
    else{
      printf("\ntapez une commande valide !\n");
    }
  }
}
