## Resources

CF Blog: https://codeforces.com/blog/entry/61364

TC Blog: https://www.topcoder.com/community/competitive-programming/tutorials/binary-indexed-trees/

Hackerearth: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

take U forward:
- https://youtu.be/9uaXG62Y8Uw
- https://youtu.be/nuUspQ7ORXE

Shubh Coding:
- [PART 1 -Binary Indexed Tree/Fenwick Tree From Scratch](https://youtu.be/G_lpEUUsZj4)
- [PART - 2 | BINARY INDEXED TREE | Advanced Data Structure | Hard and Medium Problems Discussed |](https://youtu.be/WmDEZbTHN5c)

<hr />

## Range operations [(cp-algorithms.com)](https://cp-algorithms.com/data_structures/fenwick.html#toc-tgt-8)
A Fenwick tree can support the following range operations:

1. Point Update and Range Query

This is just the ordinary Fenwick tree as explained above.

2. Range Update and Point Query

Using simple tricks we can also do the reverse operations: increasing ranges and querying for single values.

Let the Fenwick tree be initialized with zeros. 

Suppose that we want to increment the interval [l,r] by x. 

We make two point update operations on Fenwick tree which are add(l, x) and add(r+1, -x).

3. Range Updates and Range Queries

To support both range updates and range queries we will use two BITs namely B1[] and B2[], initialized with zeros.

Suppose that we want to increment the interval [l,r] by the value x. 

Similarly as in the previous method, we perform two point updates on B1: add(B1, l, x) and add(B1, r+1, -x). 

And we also update B2.

```
def add(b, idx, x):
    while idx <= N:
        b[idx] += x
        idx += idx & -idx

def range_add(l,r,x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)

def sum(b, idx):
    total = 0
    while idx > 0:
        total += b[idx]
        idx -= idx & -idx
    return total

def prefix_sum(idx):
    return sum(B1, idx)*idx -  sum(B2, idx)

def range_sum(l, r):
    return prefix_sum(r) - prefix_sum(l-1)
```
