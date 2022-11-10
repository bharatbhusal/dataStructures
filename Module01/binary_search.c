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

// Binary Search code
int binary_search(int a[], int l, int r, int t)
{
    int m = l + (r - l) / 2;
    if (t == a[m])
        return m;
    else if (t < a[m])
        return binary_search(a, l, m - 1, t);
    else
        return binary_search(a, m + 1, r, t);
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
    if (target >= array[0] && target <= array[size - 1])
    {
        int index = binary_search(array, 0, size - 1, target);
        printf("%d is found in index %d(position %d) in the given array.\n", target, index, index + 1);
    }
    else
        printf("%d is not present in the given array.\n", target);
    return 0;
}