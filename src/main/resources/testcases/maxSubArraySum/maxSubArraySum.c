#include <stdio.h>
int maxSubArraySum(int a[], int size);

int main(){
int a[] = {3, -5, 2, 1, 1, 6};
int sum = maxSubArraySum(a,6);
printf("%d", sum);
}

int maxSubArraySum(int a[], int size) 
{
    int globalMax = -32767; 
    int localMax = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        localMax = localMax + a[i]; 
        if (globalMax > localMax) 
            globalMax = localMax; 
  
        if (localMax < 0) 
            localMax = 0; 
    } 
    return globalMax; 
}

