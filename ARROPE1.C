#include <stdio.h>
#include <conio.h>
#define MAX 10

void add(int arr[], int size) {
    int i;
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Elements added.\n");

    printf("\nElements in the array are:\n");
    for (i = 0; i < size; i++) {
        printf("\t%d", arr[i]);
    }
}

int del(int arr[], int size, int val) {
    int i, j, found = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            found = 1;
            for (j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--; // Adjust index after deletion
            printf("Deleted value: %d\n", val);
        }
    }
    if (found == 0) {
        printf("Value %d not found in the array.\n", val);
    }
    printf("\nElements in the array are:\n");
    for (i = 0; i < size; i++) {
        printf("\t%d", arr[i]);
    }
    return size;
}

void modify(int arr[], int size, int val) {
    int i, newVal, found = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            found = 1;
            printf("Enter new value: ");
            scanf("%d", &newVal);
            arr[i] = newVal;
            printf("Modified value at index %d: %d\n", i, arr[i]);
            break;
        }
    }
    if (found == 0) {
        printf("Value %d not found in the array.\n", val);
    }
    printf("\nElements in the array are:\n");
    for (i = 0; i < size; i++) {
        printf("\t%d", arr[i]);
    }
}

void sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nElements in the array after sorting are:\n");
    for (i = 0; i < size; i++) {
        printf("\t%d", arr[i]);
    }
}

void simplesec(int arr[], int size, int val) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            found = 1;
            printf("Value %d found at index: %d\n", val, i);
            break;
        }
    }
    if (found == 0) {
        printf("Value %d not found in the array.\n", val);
    }
}

int binary(int arr[], int size, int val) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void main() {
    int choice, val, size, result;
    int arr[MAX];
    clrscr();

    printf("Enter the size of the array (max %d): ", MAX);
    scanf("%d", &size);
    if (size <= 0 || size > MAX) {
        printf("Invalid size entered. Please enter a size between 1 and %d.\n", MAX);
    } else {
        add(arr, size);
        while (1) {
            printf("\n\n1. Delete\n2. Modify\n3. Sort\n4. Simple search\n5. Binary search\n6. Exit\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter value to delete: ");
                    scanf("%d", &val);
                    size = del(arr, size, val);
                    break;
                case 2:
                    printf("Enter value to modify: ");
                    scanf("%d", &val);
                    modify(arr, size, val);
                    break;
                case 3:
                    sort(arr, size);
                    break;
                case 4:
                    printf("Enter value you want to search: ");
                    scanf("%d", &val);
                    simplesec(arr, size, val);
                    break;
                case 5:
                    printf("Enter value you want to search: ");
                    scanf("%d", &val);
                    sort(arr, size); // Ensure the array is sorted before binary search
                    result = binary(arr, size, val);
                    if (result != -1) {
                        printf("Element is present at index %d\n", result);
                    } else {
                        printf("Element is not present in the array\n");
                    }
                    break;
                case 6:
                    exit(0);
                default:
                    printf("Invalid choice..\n");
                    break;
            }
        }
    }
    getch();
}
