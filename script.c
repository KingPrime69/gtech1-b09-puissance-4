//rajouter les commandes et mettre la navigation texte pendant le jeux
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define NBL 100
#define NBC 100

char com[10] = "commandes";
int login = 1;
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
char norm[10] = "régles";
char head[5] = "menu";
int count;
int player = 0;
int* L;
int* C;
char resume[10] = "reprendre";
char restart[10] = "rejouer";

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

void show_grill_D(void){
  title("  Pussance 4");
  for(int l=0; l<*L; l++){
    printf("\n");
    for(int c=0; c<*C; c++) {
      if(c == 0)
        printf("| %c", tab[l][c]);
      else
        printf(" | %c", tab[l][c]);
    }
    printf(" |");
  }
  printf("\n");
  for(int c=1; c<*C+1; c++){
    if(c>10)
      printf("| %d", c);
    else if(c == 1)
      printf("| %d", c);
    else
      printf(" | %d", c);
  }
  printf("|\n");
}

void grill(void){
  while(login == 1){
    C = malloc(sizeof(int));
    printf("nombre de colone ?\n");
    scanf("%d", C);
    L = malloc(sizeof(int));
    printf("nombre de ligne ?\n");
    scanf("%d", L);
    if(*C == 0 || *L == 0){
      printf("Veuillez saisir un nombre au dessu de 0\n");
      while((*C = getchar()) != '\n' && *C != EOF && (*L = getchar()) != '\n' && *L != EOF);
      free(C);
      free(L);
      login = 1;
    }
    else{
      for(int l=0; l<*L; l++) {
        for(int c=0; c<*C; c++) {
          tab[l][c] = '.';
        }
      }
      for (int l=0; l<*L; l++){
        slide[l] = 0;
      }
      if(*C>=10)
        show_grill_D();
      else
        show_grill();
      login = 0;
    }
  }
}

void menu(void){
  for(count=0; count<15; count++)
    title("    -Menu");
  printf("Choissisez un sommaire:\n");
  printf("-jouer (lancera la partie)\n");
  printf("-régles (affichera les régles)\n");
  printf("-commandes (affichera la liste des commandes de navigation)\n"); 
}

void rule(void){
  title(" Règles du jeux");
  printf("Les règles du puissance 4 sont simple le but est d'être le premiers à aligner 4 jetons horizontalement, verticalement ou diagonalement.\n");
}

void control(void){
  title("   Commandes");
  printf("DANS LE MENU :\n\n");
  printf("jouer = lance la partie\n");
  printf("rejouer = redémarre une nouvelle partie\n");
  printf("règles = permets d'afficher les règles(valable pendant une partie)\n");
  printf("commandes = permets d'afficher ce que vous voyez<3\n");
  printf("fin = arrête le programme(valable aussi en jeux)\n\n");
  printf("EN JEUX :\n\n");
  printf("0 = permet de passer en mode commande texte\n");
  printf("reprendre = permets de quitter le mode commande\n");
  printf("menu = mets fin à la partie et renvoie à l'écran d'accueil\n");
}

void player_stroke(int playerAction, int next){
  add = *L-1;
  tab[add-next][playerAction] = tokens[player];
  slide[playerAction]++;
}

void game(){
  grill();
  loop = 1;
  while(loop == 1){
    while((hit = getchar()) != '\n' && hit != EOF);
    printf("\nOu voulez vous placez votre pion?\n");
    scanf("%d", &hit);
    printf("%d\n", hit);
    if(hit == 0){
      init = 1;
      while(init == 1){
        printf("vous êtes en mode commande\n");
        scanf("%s", request);
        if(strcmp(request, restart) == 0){
          free(L);
          free(C);
          login = 1;
          game();
        }
        else if(strcmp(request, norm) == 0){
          rule();
        }
        else if(strcmp(request, head) == 0){
          menu();
          loop = 0;
        }
        else if(strcmp(request, resume) == 0){
          show_grill();
          init = 0;
        }
        else if(strcmp(request, end) == 0){
          init = 0;
          free(L);
          free(C);
          loop = 0;
        }
	else if(strcmp(request, com) == 0){
	  control();
	}
	else{
          printf("\ntapez une commande valide !\n");
        }
      }
    }      
    else if(hit>=1 && hit <=*C){
      player_stroke(hit-1, slide[hit-1]);
      if(*C>=10)
        show_grill_D();
      else
        show_grill();
      player = !player;
    }
  else
    printf("Seul les chiffres de 1 à %d sont acceptable", *C);
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
    else if(strcmp(request, com) == 0){
      control();
    }
    else{
      printf("\ntapez une commande valide !\n");
    }
  }
}
