/* 
Binary search list by Nelson Rocha <nffrocha@gmail.com>  24/04/2003
This is just an example how to use binary search through an array, you can use bsearch() function in you program
if you want, just keep credits alive, this is distributed under the terms of GPL.
The function only work for integer data, but you can adapt it easily.
Guess what, clib already have a binary search function, you should use it instead, the name is bsearch()
*/


#include <stdio.h>

#define MAX 100

/* Usage:
    binsearch() return 1 if found or 0 if not found, it accepts two arguments, the first one is the array to look,
    the second is the number to look for, the third is the variable to save the position where it was found,
    that variable argument need to be passed by reference.
    Note that the array need to be sorted or else this method will not work, instead you should use linear search.
    
    It's very easy to implemente, look that this example:
    1 5 10 12 14 20 27 28 29 30
    
    we need to look if 12 is on list, and retrieve the position.
    we have then
    1 5 10 12 14
    then we find middle again, 10 in this case
    1 5 10
    middle 5
    1 10
    middle is 10, 10 is on inicio then arr[inicio] is the position we are looking for.

*/

int binsearch (int arr[], int v, int *s) {
    int inicio, fim, meio;
    inicio = 0;
    fim = MAX;
    while (inicio < fim) {
	meio = (int) ((inicio + fim) / 2);
	if (v <= arr[meio])
	    fim = meio;
	else
	    inicio = meio + 1;
    }
    *s = arr[inicio];
    return arr[inicio] == v;
}

int main () {
    int i, save, num;
    int arr[MAX];
    for (i = 0; i <= MAX; i++)
	arr[i] = i;
    scanf ("%d", &num);
    if (binsearch(arr, num, &save))
	printf ("Encontrou na posição %d\n", save);
    else
	printf ("não encontrou\n");
    return 0;    
}
