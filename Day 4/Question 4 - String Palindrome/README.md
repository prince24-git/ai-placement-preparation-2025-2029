# Day 4 - Question 4: String Palindrome

## Problem
Check whether a string reads the same forward and backward.

This solution ignores letter case and skips spaces and punctuation. For example, `A man, a plan, a canal: Panama!` is treated as a palindrome. It compares characters directly without building a reversed or cleaned copy.

## Optimized two-pointer approach
1. Put one pointer at the start and one at the end.
2. Skip characters that are not letters or digits.
3. Compare the current characters without case sensitivity.
4. If they differ, return false. If they match, move both pointers inward.
5. If the pointers meet or cross, return true.

## Complexity
- Time: **O(n)** worst case, where `n` is the input length. Each pointer only moves inward.
- Extra space: **O(1)**. The algorithm does not create a second string.

A reverse-copy solution also takes O(n) time, but needs O(n) additional space.

## Timing with `time.h`
The C and C++ programs measure the palindrome check with `clock()` and divide elapsed clock ticks by `CLOCKS_PER_SEC`. This reports CPU time for that run. Very short inputs may show `0.000000000` because the operation is faster than the timer resolution. A measured duration is an observation for one machine and input; Big-O comes from analyzing how the number of operations grows as `n` grows.

Python and Java do not use the C `time.h` header; the timing requirement is implemented in the C and C++ versions.

## Example
- Input: `A man, a plan, a canal: Panama!`
- Output: `Palindrome`

## Run from `D:\Placement AI Cluster 2025-2029`

```cmd
python ".\Day 4\Question 4 - String Palindrome\string_palindrome.py"

gcc ".\Day 4\Question 4 - String Palindrome\string_palindrome.c" -o ".\Day 4\Question 4 - String Palindrome\string_palindrome.exe"
".\Day 4\Question 4 - String Palindrome\string_palindrome.exe"

g++ ".\Day 4\Question 4 - String Palindrome\string_palindrome.cpp" -o ".\Day 4\Question 4 - String Palindrome\string_palindrome_cpp.exe"
".\Day 4\Question 4 - String Palindrome\string_palindrome_cpp.exe"

javac ".\Day 4\Question 4 - String Palindrome\StringPalindrome.java"
java -cp ".\Day 4\Question 4 - String Palindrome" StringPalindrome
```
