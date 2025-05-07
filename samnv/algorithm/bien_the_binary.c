#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//sap xep tang dan
int comparison(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;

    return *x-*y;
}

//tìm chỉ số đầu tiên của phần tử x trong mảng a đã được sắp xếp, nếu không tìm thấy trả về -1
int first(int a[], int n, int x)
{
    //khác với tìm thấy ptu, khi mid == x chưa return mà cần phải tìm xem bên trái có x không nữa
    int left = 0;
    int right = n-1;
    int res = -1;   //biến lưu giá trị tạm thời của mid khi mid == x

    while(left <= right)
    {
        int mid = (left + right)/2;
        
        if(a[mid] == x)
        {
            res = mid;      //lưu index x đầu tiên
            right = mid - 1;  //kiểm tra bên trái mid xem còn x không?
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

    return res;
}

//tìm vị trí cuối cùng thì thay vì right = mid - 1 thì là left = mid + 1
int last(int a[], int n, int x)
{
    int left = 0;
    int right = n-1;
    int res = -1;   

    while(left <= right)
    {
        int mid = (left + right)/2;
        
        if(a[mid] == x)
        {
            res = mid;      //lưu index x đầu tiên
            left = mid + 1;  //kiểm tra bên phải mid xem còn x không?
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

    return res;
}

//vị trí >= x trong mảng tăng dần -> tìm a[mid] đến khi nào mà a[mid] lơn hơn = x
int first_hon_x(int a[], int n, int x)
{
    int left = 0;
    int right = n-1;
    int res = -1;   

    while(left <= right)
    {
        int mid = (left + right)/2;
        
        if(a[mid] >= x)
        {
            res = mid;      // cập nhật
            right = mid - 1;    //tìm thêm có cái nào lớn hơn không
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}

//vị trí cuối cùng nhỏ hơn hoặc bằng x
int last_be_hon_x(int a[], int n, int x)
{
    int left = 0;
    int right = n-1;
    int res = -1;   

    while(left <= right)
    {
        int mid = (left + right)/2;
        
        if(a[mid] <= x)
        {
            res = mid;
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;
        }
    }

    return res;
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

    int first_pos_x = first(a, n, x);
    printf("vi tri x dau tien trong mang sap xep %d\n", first_pos_x);
    printf("vi tri x dau tien trong mang sap xep %d\n", last(a, n, x));
    printf("vi tri x dau tien trong mang sap xep lon hon hoac bang x %d\n", first_hon_x(a, n, x));
    printf("vi tri x dau tien trong mang sap xep nho hon hoac bang x %d\n", last_be_hon_x(a, n, x));
    return 0;
}


