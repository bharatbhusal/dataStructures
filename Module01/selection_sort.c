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
    printf("Content of the Array:\n");
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

// Selection Sort Code
void selection_sort(int a[], int s)
{
    printf("Sorting the Array.\n");
    for (int i = 0; i < s - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < s; j++)
            if (a[j] < a[index])
                index = j;
        if (index != i)
            swap(&a[i], &a[index]);
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
    show(array, size);
    selection_sort(array, size);
    show(array, size);
    return 0;
}