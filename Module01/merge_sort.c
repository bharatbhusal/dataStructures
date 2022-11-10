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

// Merge Function
void merge(int a[], int l, int m, int r)
{
    int i = 0, j = 0, k = l, n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    int left[n1], right[n2];
    for (int x = 0; x < n1; x++)
        left[x] = a[l + x];
    for (int x = 0; x < n2; x++)
        right[x] = a[m + 1 + x];
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            a[k] = left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort Function
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
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
    printf("ARRAY BEFORE SORT: \n");
    show(array, size);
    merge_sort(array, 0, size - 1);
    printf("ARRAY AFTER SORT: \n");
    show(array, size);
    return 0;
}