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

void insertion_sort(int a[], int s)
{
    for (int i = 1; i < s; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
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
    insertion_sort(array, size);
    printf("\nARRAY AFTER SORT: \n");
    show(array, size);
    return 0;
}