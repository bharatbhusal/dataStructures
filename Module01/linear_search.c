#include <stdio.h>
void read(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}
int linear_search(int a[], int s, int t)
{
    for (int i = 0; i < s; i++)
        if (a[i] == t)
            return i;
    return -1;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    read(array, size);
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);
    int index = linear_search(array, size, target);
    if (index == -1)
        printf("%d is not present in the given array.\n", target);
    else
        printf("%d is found in index %d(position %d) in the given array.\n", target, index, index + 1);
    return 0;
}