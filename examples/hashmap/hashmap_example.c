
#include "../../hashmap/ruspma_hashmap.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *a = malloc(1);
  char *t = "\nWoot\n";
  *a = '1';
  int q = 908;
  ruspma_hashmap *new = new_hashmap();
  add_to_hashmap(new, "dog", a, 1, a);
  add_to_hashmap(new, "test", &q, sizeof(int), t);
  
  printf("%i, ", new->bin_num);
  /*
  char w = 'w';
  add_to_hashmap(new, &w, 1, &w);
  char e = 'e';
  add_to_hashmap(new, &e, 1, &e);
  char r = 'r';
  add_to_hashmap(new, &r, 1, &r);
  char y = 'y';
  add_to_hashmap(new, &y, 1, &y);
  char u = 'u';
  add_to_hashmap(new, &u, 1, &u);
  char i = 'i';
  add_to_hashmap(new, &i, 1, &i);
  char o = 'o';
  add_to_hashmap(new, &o, 1, &o);
  char p = 'p';
  add_to_hashmap(new, &p, 1, &p);
  char s = 's';
  add_to_hashmap(new, &s, 1, &s);
  char d = 'd';
  add_to_hashmap(new, &d, 1, &d);
  char f = 'f';
  add_to_hashmap(new, &f, 1, &f);
  char g = 'g';
  add_to_hashmap(new, &g, 1, &g);
  char h = 'h';
  add_to_hashmap(new, &h, 1, &h);
  char j = 'j';
  add_to_hashmap(new, &j, 1, &j);
  char k = 'k';
  add_to_hashmap(new, &k, 1, &k);
  char l = 'l';
  add_to_hashmap(new, &l, 1, &l);
  char z = 'z';
  add_to_hashmap(new, &z, 1, &z);
  char x = 'x';
  add_to_hashmap(new, &x, 1, &x);
  char c = 'c';
  add_to_hashmap(new, &c, 1, &c);
  char v = 'v';
  add_to_hashmap(new, &v, 1, &v);
  char b = 'b';
  add_to_hashmap(new, &b, 1, &b);
  char n = 'n';
  add_to_hashmap(new, &n, 1, &n);
  char m = 'm';
  add_to_hashmap(new, &m, 1, &m);
  */

  /*
  int *tt = malloc(sizeof(int) * 1001);
  *tt = 1000;
  int uu;
  for(uu = 1000; uu != 2000; ++uu) {
    add_to_hashmap(new, tt, sizeof(int), tt);
    ++tt;
    *tt = uu;
    }
    int uiu = 910;
  */
  printf("%i\n", new->bin_num); 
  //printf("%s\n", (char *)get_hashmap(new, &q, sizeof(int)));
  printf("%s\n", (char *)get_hashmap(new, "test", &q, sizeof(int)));
  //printf("\n%i\n", *(int *)get_hashmap(new, &uiu, sizeof(int)));
  free(a);
  free_hashmap(new);
  //tt = tt - 1000;
  //free(tt);
  //if(get_hashmap(new, &kk, sizeof(int)) == NULL)
  //  puts("OH no!");
  //putchar(*(char *)get_hashmap(new, &v, 1));
     //printf("%i\n", *(int *)get_hashmap(new, &kk, sizeof(int)));
}
