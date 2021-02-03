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

## Special operations
```
1. Point Update and Range Query
This is just the ordinary Fenwick tree as explained above.

2. Range Update and Point Query
Using simple tricks we can also do the reverse operations: increasing ranges and querying for single values.

Let the Fenwick tree be initialized with zeros. 
Suppose that we want to increment the interval [l,r] by x. 
We make two point update operations on Fenwick tree which are add(l, x) and add(r+1, -x).
```
