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

int partition(int a[], int l, int r)
{
    int p = a[r];
    int runner = l;
    for (int i = l; i < r; i++)
    {
        if (a[i] <= p)
        {
            swap(&a[i], &a[runner]);
            runner++;
        }
    }
    swap(&a[runner], &a[r]);
    return runner;
}

void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int index = partition(a, l, r);
        quick_sort(a, l, index - 1);
        quick_sort(a, index + 1, r);
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
    quick_sort(array, 0, size - 1);
    printf("\nARRAY AFTER SORT: \n");
    show(array, size);
    return 0;
}