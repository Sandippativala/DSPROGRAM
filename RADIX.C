#include <stdio.h>
#include <conio.h>

#define MAX 10

int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[MAX]; 
    int count[10] = {0}; 
    int i,j,k,l;

    for (i = 0; i < n; i++) {
	count[(arr[i] / exp) % 10]++;
    }

    for (j = 1; j < 10; j++) {
	count[j] += count[j - 1];
    }

    for (k = n - 1; k >= 0; k--) {
	output[count[(arr[k] / exp) % 10] - 1] = arr[k];
	count[(arr[k] / exp) % 10]--;
    }

    for (l = 0; l < n; l++) {
	arr[l] = output[l];
    }
}

void radixSort(int arr[] int n) {
    int max = getMax(arr, n);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void main() {
    int arr[MAX], n, i;

    clrscr(); 

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n); 

    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    getch(); 
}