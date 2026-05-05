struct ListNode {
    int val;
    struct ListNode *next;
};
#include <stdio.h>
#include <stdlib.h>
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length
    int len = 1;
    struct ListNode* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // Step 2: Make circular
    tail->next = head;

    // Step 3: Effective rotation
    k = k % len;

    // Step 4: Find new tail
    int steps = len - k;
    struct ListNode* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: Break the cycle
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}