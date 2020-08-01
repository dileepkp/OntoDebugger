#include <stdio.h>
int main(){
int i;
float x[] = {1,10,20,40,60};
float y[] = {0.013,0.092,0.23,0.51,0.8};
float z[] = {0.072,0.14,0.17,0.23,0.28};

for(i = 1; i<=4; ++i)
printf("%d ,%.4f,%.4f\n",((int)x[i]), (y[i] - y[i-1]) / (x[i] - x[i-1]), (z[i] - z[i-1]) / (x[i] - x[i-1]));

printf("\n\n");
return 0;
}

