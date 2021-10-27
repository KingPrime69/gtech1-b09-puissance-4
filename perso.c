#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define NBL 100
#define NBC 100

int tab[NBL][NBC];
int add;
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
int count;
int player = 0;
int* L;
int* C;
char restart[10] = "rejouer";
char unpause[10] = "reprendre";


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

void grill(void){
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
  for (int l=0; l<*L; l++){
    slide[l] = 0;
  }
}

void show_grill(void){
  title("  Pussance 4");
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

void game(){
  grill();
  show_grill();
  loop = 1;
  while(loop == 1){
    hit = 0;
    printf("\nOu voulez vous placez votre pion?\n");
    scanf("%d", &hit);
    printf("%c\n", hit);
    if(hit == -1){
      init = 1;
      while(init == 1){
	printf("vous êtes en mode commande\n");
	scanf("%s", request);
	if(strcmp(request, restart) == 0){
	  game();
	  free(L);
	  free(C);
	}
	else if(strcmp(request, norm) == 0){
	  rule();
	}
	else if(strcmp(request, head) == 0){
	  menu();
	  loop = 0;
	}
	else if(strcmp(request, unpause) == 0){
	  init = 0;
	}
	else if(strcmp(request, end) == 0){
	  init = 0;
	  free(L);
	  free(C);
	}
	else{
	  printf("\ntapez une commande valide !\n");
	}
      }
    }
    else if(hit == 0){
      printf("couille");
    }
    else if(hit>=1 && hit <=*C){
      player_stroke(hit-1, slide[hit-1]);
      show_grill();
      player = !player;
    }
    else
      printf("Seul les chiffres de 1 à %d sont acceptable", *C);     
  }
}

int main(){  
  if(init == 0){
    menu();
    init = 1;
  }
  while(init == 1){
    scanf("%10s", request);
    if(strcmp(request, start) == 0){
      game();
      init = 0;
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
