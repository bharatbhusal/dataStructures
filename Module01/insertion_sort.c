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

// Insertion Sort code
void insertion_sort(int a[], int s)
{
    printf("Sorting Array.\n");
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

// Driver
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    read(array, size);
    show(array, size);
    insertion_sort(array, size);
    show(array, size);
    return 0;
}