#include <stdio.h>
int main(){

int x = 2;
int *p = &x;

int **q;
*q = p;

int *r;
r= *q;

int *s;
s = p;

int w = **q;

return 0;
}
