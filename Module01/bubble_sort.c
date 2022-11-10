#include <stdio.h>

// To read to array content form user
void read(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// To display the content of the Array
void show(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// To swap two elements of the array using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort function
void bubble_sort(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        int check = 0;
        for (int j = 0; j < s - 1; j++)
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                check = 1;
            }
        if (check == 0)
            break;
    }
}

// Driver
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    read(array, size);
    printf("ARRAY BEFORE SORT:\n");
    show(array, size);
    bubble_sort(array, size);
    printf("ARRAY AFTER SORT: \n");
    show(array, size);
    return 0;
}