#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *find_cycle_start(Node *head) {
    Node *slow = head;
    Node *fast = head;

    /* Phase 1: find a meeting point inside the cycle. */
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            /* Phase 2: move one pointer to head; advance both one step. */
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(void) {
    int count;
    printf("Number of nodes: ");
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Invalid node count.\n");
        return 1;
    }

    Node **nodes = NULL;
    if (count > 0) {
        nodes = (Node **)malloc((size_t)count * sizeof(Node *));
        if (nodes == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    printf("Enter %d node values separated by spaces: ", count);

    for (int i = 0; i < count; ++i) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        if (nodes[i] == NULL) {
            printf("Memory allocation failed.\n");
            for (int j = 0; j < i; ++j) free(nodes[j]);
            free(nodes);
            return 1;
        }
        if (scanf("%d", &nodes[i]->value) != 1) {
            printf("Invalid node value.\n");
            for (int j = 0; j <= i; ++j) free(nodes[j]);
            free(nodes);
            return 1;
        }
        nodes[i]->next = NULL;
    }

    for (int i = 0; i + 1 < count; ++i) nodes[i]->next = nodes[i + 1];

    int cycle_index;
    printf("Cycle start index (0-based, -1 for no cycle): ");
    if (scanf("%d", &cycle_index) != 1 || cycle_index < -1 || cycle_index >= count) {
        printf("Invalid cycle start index.\n");
        for (int i = 0; i < count; ++i) free(nodes[i]);
        free(nodes);
        return 1;
    }
    if (count > 0 && cycle_index >= 0) nodes[count - 1]->next = nodes[cycle_index];

    Node *head = count > 0 ? nodes[0] : NULL;
    Node *cycle_start = find_cycle_start(head);
    if (cycle_start == NULL) {
        printf("Cycle detected: No\n");
    } else {
        int start_index = 0;
        while (nodes[start_index] != cycle_start) ++start_index;
        printf("Cycle detected: Yes\n");
        printf("Cycle starts at index %d, value %d\n", start_index, cycle_start->value);
    }

    /* Break a possible cycle before freeing the nodes. */
    if (count > 0) nodes[count - 1]->next = NULL;
    for (int i = 0; i < count; ++i) free(nodes[i]);
    free(nodes);
    return 0;
}
