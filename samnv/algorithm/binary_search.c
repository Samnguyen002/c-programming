#include "stdio.h"
#include "string.h"
#include "stdlib.h"

// /*kiểm tra bộ xử lý của hệ điều hành*/
// int main() {
//     #if defined(_WIN64) || defined(__x86_64__)
//         printf("64-bit system\n");
//     #elif defined(_WIN32) || defined(__i386__)
//         printf("32-bit system\n");
//     #else
//         printf("Unknown architecture\n");
//    #endif
//     printf ("%d", sizeof(long int));
//     return 0;
// }

//sap xep tang dan
int comparison(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;

    return *x-*y;
}

int binary_search(int a[], int n, int x)
{
    int left = 0;
    int right = n-1;

    while(left <= right)
    {
        int mid = (left + right)/2;
        
        if(a[mid] == x)
        {
            printf("tim thay x o index %d trong mang sap xep\n", mid);
            return 1;
        }
        else if(a[mid] > x)
        {
            right = mid - 1;
        }
        else if(a[mid] < x)
        {
            left = mid + 1;
        }
    }

    return 0;
}

int main(const int argc, const char *argv[])
{
    int n;
    int x;
    scanf("%d %d", &n, &x);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(a[0]), comparison);

    binary_search(a, n, x);
    return 0;
}


