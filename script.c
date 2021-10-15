#include <stdio.h>
#include <stdlib.h>

#define NBL 6
#define NBC 7
int line;
char tab[NBL][NBC];
int count;
char i;
char u;
void init(void) {
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
    }
  }
}

void main(void){
  init();
  while (line<=7){
      tab[i][u] = '|';
      printf("%s", *tab);
      tab[i][u] = '.';
      printf("%s", *tab);
      printf("\n");
  }
}
	
