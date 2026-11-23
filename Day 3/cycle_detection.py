class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def find_cycle_start(head):
    slow = head
    fast = head

    # Phase 1: find a meeting point inside the cycle.
    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            break
    else:
        return None

    # Phase 2: move one pointer to head. Advance both one step.
    slow = head
    while slow is not fast:
        slow = slow.next
        fast = fast.next

    return slow


count = int(input("Number of nodes: "))
if count < 0:
    raise ValueError("Number of nodes cannot be negative.")

values = list(map(int, input("Enter node values separated by spaces: ").split())) if count else []
if len(values) != count:
    raise ValueError(f"Please enter exactly {count} node values.")

nodes = [Node(value) for value in values]
for i in range(count - 1):
    nodes[i].next = nodes[i + 1]

cycle_index = int(input("Cycle start index (0-based, -1 for no cycle): "))
if cycle_index < -1 or cycle_index >= count:
    raise ValueError("Cycle start index must be -1 or a valid node index.")
if count > 0 and cycle_index >= 0:
    nodes[-1].next = nodes[cycle_index]

head = nodes[0] if nodes else None
cycle_start = find_cycle_start(head)

if cycle_start is None:
    print("Cycle detected: No")
else:
    start_index = nodes.index(cycle_start)
    print("Cycle detected: Yes")
    print(f"Cycle starts at index {start_index}, value {cycle_start.value}")
