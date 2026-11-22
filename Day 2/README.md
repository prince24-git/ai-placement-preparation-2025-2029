# Day 2 — Tower of Hanoi

## Problem
There are three rods: A (source), B (auxiliary), and C (destination), and n disks of different sizes stacked on rod A. Move the full stack to rod C.

## Rules
1. Move only one disk at a time.
2. Only the top disk of a rod can be moved.
3. Never place a larger disk on a smaller disk.

## Recursive approach
To move n disks from source to destination:
1. Move n - 1 disks from source to auxiliary.
2. Move the largest disk from source to destination.
3. Move n - 1 disks from auxiliary to destination.

Base case: when n = 1, move that disk directly.

## Minimum moves
The recurrence is T(n) = 2T(n - 1) + 1, with T(1) = 1.
Therefore, the minimum number of moves is 2^n - 1.

Examples: 1 disk → 1 move; 2 disks → 3 moves; 3 disks → 7 moves.

## Complexity
- Time: O(2^n), because the program prints 2^n - 1 moves.
- Auxiliary space: O(n), due to the recursion call stack.
- If counting the printed output itself, output space is O(2^n).

## Real-world connections
The puzzle is mainly used to teach recursion and analyze exponential algorithms. Its move sequence is related to Gray-code patterns, which are useful in error-resistant position encoding and some state enumeration tasks. The puzzle's transfer rules can also model constrained rearrangement/planning problems, though the classic Tower of Hanoi program is mostly an educational model rather than a common production tool.

## Files
- tower_of_hanoi.py — Python
- tower_of_hanoi.c — C
- tower_of_hanoi.cpp — C++
