#include <stdio.h>
#include <stdlib.h>

#define NBL 6
#define NBC 7

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
void main(void){
  init();
}
	
