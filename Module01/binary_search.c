#include <stdio.h>

// To read to array content form user
void read(int a[], int size)
{
    printf("Elements should be sorted.\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// Binary Search code
int binary_search(int a[], int l, int r, int t)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        if (t == a[m])
            return m;
        else if (t < a[m])
            return binary_search(a, l, m - 1, t);
        else
            return binary_search(a, m + 1, r, t);
    }
    else
        return -1;
}

// Driver
int main()
{
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    read(array, size);
    printf("Enter the target element: ");
    scanf("%d", &target);
    int index = binary_search(array, 0, size - 1, target);
    if (index != -1)
        printf("%d is in index %d(position %d) in the array.\n", target, index, index + 1);
    else
        printf("%d is not present in the array.\n", target);
    return 0;
}