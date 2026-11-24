# Day 4 - Substring Search with KMP

## Problem
Given a main string and a pattern, determine whether the pattern occurs inside the main string.

## Algorithm
The Knuth-Morris-Pratt (KMP) algorithm avoids rechecking text characters after a mismatch. It first builds an LPS array: for each pattern position, LPS stores the length of the longest proper prefix that is also a suffix. On a mismatch, the pattern uses this information to shift while the text index stays in place.

## Complexity
- Time: O(n + m), where n is the main string length and m is the pattern length. Since a possible match requires m <= n, this is O(n) in terms of the main string length.
- Extra space: O(m) for the LPS array.

An empty pattern is treated as a match. A pattern longer than the main string is not a match.

## Example
Main string: `abxabcabcaby`
Pattern: `abcaby`
Result: `Substring found`

## Files
- `substring_search.c` - C
- `substring_search.cpp` - C++
- `SubstringSearch.java` - Java
- `substring_search.py` - Python

