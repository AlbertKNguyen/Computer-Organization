#include <stdio.h>

void swap (int *px, int *py, int* temp) {
    *temp = *px;
    *px = *py;
    *py = *temp;
}

int* proc(int a, int b)
    int sum = 0;
    return &sum;
}

int main () {
    int a = 1, b = 2;
    int *x = proc(3,4);
    swap(&a,&b,x);
}