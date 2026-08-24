/*
**Inversions**

Given a permutation p_i of n elements, find for each i the number of j such that j<i and p_j>p_i.

**Input**

The first line contains the number n (1≤n≤10^5), the second line contains n numbers p_i.
It is guaranteed that p_i form a permutation of numbers from 1 to n.

**Output**

Print n numbers, the i-th number is equal to the number of j such that j<i and p_j>p_i.

**Example**

Input
```
5
4 1 3 5 2
```

Output
```
0 1 1 0 3
```*/