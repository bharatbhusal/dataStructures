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

void bubble_sort(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        int check = 0;
        for (int j = 0; j < s - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                check = 1;
            }
        }
        if (check == 0)
            break;
    }
}

int main()
{
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    read(array, size);
    printf("ARRAY BEFORE SORT: \n");
    show(array, size);
    bubble_sort(array, size);
    printf("\nARRAY AFTER SORT: \n");
    show(array, size);
    return 0;
}