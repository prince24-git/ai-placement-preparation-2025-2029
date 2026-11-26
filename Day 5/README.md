# Day 5 - Lexicographical String Sorting

## Problem
Read `n` strings (one string per line) and print them in ascending lexicographical order. Comparisons are case-sensitive (`A` and `a` are different).

## Basic approach
The programs use Bubble Sort: compare neighboring strings and swap them when they are out of order. Stop early if a pass makes no swaps.

## Example
Input:
```text
5
banana
Apple
mango
apple
cherry
```
Output:
```text
Apple
apple
banana
cherry
mango
```

## Complexity
Let `n` be the number of strings and `L` the maximum number of characters inspected in one comparison.

- Bubble Sort time: `O(n^2 * L)` worst case. Already sorted input exits after one pass: `O(n * L)`.
- Extra sorting space: `O(1)`; the input strings themselves take space proportional to their total length.
- Optimized library sort: `O(n log n)` string comparisons, or up to `O(n log n * L)` character work. Try replacing Bubble Sort with the language's built-in sort after understanding this version.

The C example accepts up to 100 strings, each up to 255 characters.
