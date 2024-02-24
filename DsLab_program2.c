#include <stdio.h>
#include <stdlib.h>

void linearSearch(int arr[], int size, int element);
void insertElement(int **arr, int *size, int element, int position);
void deleteElement(int **arr, int *size, int position);
void reverseArray(int arr[], int size);
void updateArray(int arr[], int size);

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, element, position;

    do {
        printf("\nMenu:\n1. Linear Search\n2. Insert Element\n3. Delete Element\n4. Reverse Array\n5. Update Array\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                linearSearch(arr, size, element);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(&arr, &size, element, position);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(&arr, &size, position);
                break;
            case 4:
                reverseArray(arr, size);
                printf("Array reversed successfully.\n");
                break;
            case 5:
                updateArray(arr, size);
                printf("Array updated successfully.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    free(arr);

    return 0;
}

void linearSearch(int arr[], int size, int element) {
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            printf("Element %d found at position %d.\n", element, i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element %d not found in the array.\n", element);
}

void insertElement(int **arr, int *size, int element, int position) {
    *arr = (int*)realloc(*arr, (*size + 1) * sizeof(int));

    for (int i = *size; i > position; --i)
        (*arr)[i] = (*arr)[i - 1];

    (*arr)[position] = element;
    (*size)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

void deleteElement(int **arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position! Deletion failed.\n");
        return;
    }

    for (int i = position; i < *size - 1; ++i)
        (*arr)[i] = (*arr)[i + 1];

    *arr = (int*)realloc(*arr, (*size - 1) * sizeof(int));
    (*size)--;
    printf("Element at position %d deleted successfully.\n", position);
}

void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; ++i) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void updateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0)
            arr[i] += 5;
        else
            arr[i] *= 2;
    }
}
