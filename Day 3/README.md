# Day 3 - Detect a Cycle in a Linked List

This implementation uses Floyd's cycle detection algorithm, also called the slow and fast pointer method. It both detects whether a cycle exists and reports the node where the cycle begins.

## How it works

1. Start `slow` and `fast` at the head.
2. Move `slow` one node and `fast` two nodes until they meet or `fast` reaches the end.
3. If they meet, reset `slow` to the head.
4. Move both pointers one node at a time. Their next meeting point is the cycle start.

## Example input

```text
Number of nodes: 8
Enter node values separated by spaces: 1 2 3 4 5 6 7 8
Cycle start index (0-based, -1 for no cycle): 3
```

The tail points back to index 3, so the result is: cycle detected, start index 3, value 4.

Use `-1` for the cycle index to create a list with no cycle. The index is zero-based.

## Complexity

- Detection and cycle-start search: O(n) time.
- Auxiliary space for Floyd's algorithm: O(1).
- The programs also create n nodes as input data, which takes O(n) storage.

## Files

- `cycle_detection.py` - Python
- `cycle_detection.c` - C
- `cycle_detection.cpp` - C++
