#include <iostream>
#include <vector>

struct Node {
    int value;
    Node *next;

    explicit Node(int v) : value(v), next(nullptr) {}
};

Node *find_cycle_start(Node *head) {
    Node *slow = head;
    Node *fast = head;

    // Phase 1: find a meeting point inside the cycle.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Phase 2: reset one pointer to head; advance both one step.
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    int count;
    std::cout << "Number of nodes: ";
    if (!(std::cin >> count) || count < 0) {
        std::cout << "Invalid node count.\n";
        return 1;
    }

    std::vector<Node *> nodes;
    nodes.reserve(count);
    std::cout << "Enter " << count << " node values separated by spaces: ";
    for (int i = 0; i < count; ++i) {
        int value;
        if (!(std::cin >> value)) {
            std::cout << "Invalid node value.\n";
            for (Node *node : nodes) delete node;
            return 1;
        }
        nodes.push_back(new Node(value));
    }

    for (int i = 0; i + 1 < count; ++i) nodes[i]->next = nodes[i + 1];

    int cycle_index;
    std::cout << "Cycle start index (0-based, -1 for no cycle): ";
    if (!(std::cin >> cycle_index) || cycle_index < -1 || cycle_index >= count) {
        std::cout << "Invalid cycle start index.\n";
        for (Node *node : nodes) delete node;
        return 1;
    }
    if (count > 0 && cycle_index >= 0) nodes.back()->next = nodes[cycle_index];

    Node *head = count > 0 ? nodes.front() : nullptr;
    Node *cycle_start = find_cycle_start(head);
    if (cycle_start == nullptr) {
        std::cout << "Cycle detected: No\n";
    } else {
        int start_index = 0;
        while (nodes[start_index] != cycle_start) ++start_index;
        std::cout << "Cycle detected: Yes\n";
        std::cout << "Cycle starts at index " << start_index
                  << ", value " << cycle_start->value << '\n';
    }

    // Break a possible cycle before freeing the nodes.
    if (!nodes.empty()) nodes.back()->next = nullptr;
    for (Node *node : nodes) delete node;
    return 0;
}
