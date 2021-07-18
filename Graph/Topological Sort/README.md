### Resources

1) [usaco.guide](https://usaco.guide/gold/toposort?lang=cpp)
2) [DP Concept of Topological Sort](https://usaco.guide/gold/toposort?lang=cpp#dynamic-programming) \
   One useful property of directed acyclic graphs is, as the name suggests, that no cycles exist. 
   If we consider each node in the graph as a state, 
   we can perform dynamic programming on the graph if we process the states in an order that guarantees for every edge u->v that u is processed before v.
   Fortunately, this is the exact definition of a topological sort!
   
   Eg Problem: Longest Flight Route (CSES), Game Routes (CSES) 


### Important problem which can be seolved using topological sort 
[Unacademy Pulkit Chhabra (at the end of video)](https://unacademy.com/class/topological-sorting-on-directed-graphs/8IXI7CXE)

#### Problem 1:
We are given some variables and inequalities:

Variables = a, b, c, x, y

Inequalities = \
x > y \
a < x \
b > a \
b < y \
c > x \
c > y

Print any solution or say it is impossible.

#### Solution 1:
Use the inequalities as directed edges (x > y means edge y->x and a < x means edge a->x) and do topo sort. \
Now assign values as 1 to n to the sorted variables (where n = res vector length)

Let res vector = [c, a, x, b, y] \
Then possible solution can be: c = 1, a = 2, x = 3, b = 4, y = 5



#### Problem 2:
We are given some variables and inequalities which also involve constants:

Variables = a, b, c

Inequalities = \
a < 5 \
a > b \
b > c \
1 < c < 3

Print any solution or say it is impossible.

#### Solution 2:
We can treat these constant as new variables and treat these as nodes.

Let constant array = [5, 1, 3] \
Sort this array = [1, 3, 5] \
Now assign variable to these: \
1 = d \
3 = e \
5 = f

Also since 1 < 3 and 3 < 5 \
We have to include these inequalities also: \
d < e and e < f

Thus new set of variables = a, b, c, d, e, f

And new set of inequalities = \
a < f \
a > b \
b > c \
d < c and  c < e \
d < e \
e < f

Use the inequalities as directed edges (a > b means edge b->a) and do topo sort. \
Now assign values as 1 to n to the sorted variables (where n = res vector length)

Let res vector = [c, a, b, f, e, d]
