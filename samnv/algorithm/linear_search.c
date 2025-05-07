#include "stdio.h"
#include "string.h"

/**
    *@brief tìm vị trí xuất hiện đầu tiên
            tìm vị trí xuất hiện cuối cùng
            đếm số lần xuất hiện của phần tử
*/
int linear_search(int a[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(x == a[i])
            return 1;
    }
    
    return 0;
}

int main(const int argc, const char *argv[])
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("co xuat hien so x, %d\n", linear_search(a, n, x));
    return 0;
}

