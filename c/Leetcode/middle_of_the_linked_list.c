#include "Header.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;


struct ListNode* middleNode(struct ListNode* head) {
    if (!head->next)
        return head;
    ListNode *runner = head, *walker = head;

    while (runner && runner->next)
    {
        runner = runner->next->next;
        walker = walker->next;
    }

    return walker;
}

