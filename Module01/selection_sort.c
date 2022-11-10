#include <stdio.h>

void read(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}

void show(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int a[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < s; j++)
        {
            if (a[j] < a[index])
                index = j;
        }
        if (index != i)
            swap(&a[i], &a[index]);
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    read(array, size);
    printf("ARRAY BEFORE SORT: \n");
    show(array, size);
    selection_sort(array, size);
    printf("\nARRAY AFTER SORT: \n");
    show(array, size);
    return 0;
}