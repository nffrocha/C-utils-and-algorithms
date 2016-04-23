/* Insertion sort example by CoolMaster, coolmaster@gameover.co.pt www.bubix.net/~coolmaster 24/04/2003 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10


/*
A bit obfuscated explanation, if you're crazy enough read it

2 1 15 0 5
i = 1, valor = 1, j = 0
arr[j] > valor T
arr[j+1] = 2, arr[j] = valor
1 2 15 0 5
i = 2, valor = 15, j = 1
arr[j] > valor F
arr[j+1] = valor
1 2 15 0 5
i = 3, valor = 0, j = 2
arr[j] > valor T
arr[j+1] = arr[j] <-- arr[3] = arr[2] <-- 0 15
1 2 0 15 5
i = 3, valor = 0, j = 1
arr[j] > valor T
arr[j+1] = arr[j] <-- arr[2] = arr[1] <-- 0 2
1 0 2 15 5
i = 3, valor = 0, j = 0
arr[j] > valor T
arr[j+1] = arr[j] <-- arr[1] = arr[0] <-- 0 1

0 1 2 15 5
i = 4, valor = 15, j = 3
arr[j] > valor T
arr[j+1] = arr[j] <-- arr[4] = arr[3] <-- 5 15
i = 4, valor = 5, j = 2
arr[j] > valor F
0 1 2 5 15
*/



void isort (int arr[]) {
    int i, j, valor;
    for (i = 1; i < MAX; i++) {
	valor = arr[i];
	j = i - 1;
	while (j >= 0 && arr[j] > valor) {
	    arr[j+1] = arr[j];
	    j--;
	}
	arr[j+1] = valor;
    }
}

int main () {
    int arr[MAX], i;
    srand(time(0));
    for (i = 0; i < MAX; i++)
	arr[i] = rand()%150;
    isort(arr);
    for (i = 0; i < MAX; i++)
	printf ("%d ", arr[i]);
    printf ("\n");
    return 0;
}

