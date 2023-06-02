#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* head;

// 원형 리스트 순서대로 출력
void print_list(ListNode* head) {
    ListNode* p;
    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d ->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d ->\n", p->data);
 
}
// 원형 리스트 처음 노드 삽입
ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        head->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}
// 원형 리스트 끝 노드 삽입
ListNode* insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        head->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

// 원형 리스트 처음 노드 삭제
ListNode* delete_first(ListNode* head) {
    if (head == NULL) return head;
    else if (head->link == head) {
        head = NULL;
        //head->link = NULL;
        return head;
    }
    ListNode* ptr = head->link;
    head->link = ptr->link;
    free(ptr);
    return head;
}

//원형 리스트 마지막 노드 삭제
ListNode* delete_last(ListNode* head) {
    if (head == NULL) return head;
    else if (head->link == head) {
    
        head = NULL;
       // head->link = NULL;
        free(head);
        return head;
    }
    ListNode* pre = head;
    ListNode* ptr = head;
    do {
        pre = pre->link;
    } while (pre->link != ptr);
    pre->link = head->link;
    head = pre;
    free(ptr);
    return head;
}



void select(int inputSel) {
    element data;
 
    switch (inputSel) {
    case 1:
        printf("enter the Number:");
        scanf_s("%d",&data);
        head=insert_first(head, data);

        //print_list(head);
        break;

    case 2:

        printf("enter the Number:");
        scanf_s("%d", &data);
        head= insert_last(head, data);

        break;
    case 3:

        printf("First Node has been deleted");
        head= delete_first(head);

        break;
    case 4:
        printf("Last Node has been deleted");
       head= delete_last(head);
        break;
    case 5:
        print_list(head);
        break;
    case 6:
        exit(1);
        break;
    }
}
int main() {

    int exit = 1;
    int inputSel;
    head = (ListNode*)malloc(sizeof(ListNode));
    head = NULL;
 
    // ListNode* head = NULL;
   // head=insert_first(head, 1);
    //delete_last(head);
    //insert_first(head, 1);
    while (exit) {
     
        printf("****menu****\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print List\n");
        printf("(6) Exit\n");
        printf("Enter the menu:");
        scanf_s("%d", &inputSel);
        if (inputSel < 7 && inputSel>0) {
            select(inputSel);
        }
        else {

            printf("not correct number! try again\n");
        }
        printf("\n");
        

    }
}