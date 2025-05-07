#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*khởi tạo node*/
typedef struct node {
    //Data của node này, bao nhiêu data cũng đc
    int data;
    //pointer trỏ đến node tiếp theo
    struct node *next;          //chỗ này vẫn phải dùng struct node vì khi complie chưa biết đc node_t là gì ở đoạn này
}node_t;

//function tạo node mới
node_t *newNode(int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));    //node mới được khởi tạo thêm
    if(new_node == NULL)
    {
        printf("Lỗi malloc()");
        return NULL;
    }
    //khởi tạo giá trị bên đầu cho node mới
    new_node->data = data;  //data này là data cho node mới
    new_node->next = NULL;  //trỏ đến NULL trước để chưa trỏ đến đâu, bởi vì node cuối cùng phải trỏ đến NULL,
    return new_node;
}

//duyệt qua linked list: in ra dữ liệu của linked list đó
void traverse_list(node_t *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);

        //chuyển sang node tiếp theo
        head = head->next;
    }
}

int main(const int argc, const char *argv[])
{
    //tạo node đầu tiên
    node_t *head = newNode(10);
    //các node tiếp theo trong liên kết
    // head->next = newNode(20);
    // head->next->next = newNode(30);
    // head->next->next->next = newNode(40);
    // head->next->next->next->next = newNode(50);

    head->next = newNode(20);
    node_t *node_2 = head->next;
    head->next->next = newNode(30);
    node_t *node_3 = head->next->next ;
    head->next->next->next = newNode(40);
    node_t *node_4 = head->next->next->next;
    head->next->next->next->next = newNode(50);
    node_t *node_5 = head->next->next->next->next;

    printf("2 %p\n2 %p\n3 %p\n3 %p\n4 %p\n4 %p\n",node_2, head->next, node_3, head->next->next, node_4, head->next->next->next);
    traverse_list(head);
    return 0;
}