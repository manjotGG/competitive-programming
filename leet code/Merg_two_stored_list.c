#include <stdio.h>
#include <stdlib.h>

// Definition of linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy.next;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to insert at end
struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    if (head == NULL) return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    // Creating list1: 1 -> 2 -> 4
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 2);
    list1 = insertEnd(list1, 4);

    // Creating list2: 1 -> 3 -> 4
    list2 = insertEnd(list2, 1);
    list2 = insertEnd(list2, 3);
    list2 = insertEnd(list2, 4);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(merged);

    return 0;
}