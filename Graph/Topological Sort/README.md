### Important problem which can be seolved using topological sort

Problem 1: \
We are given some variables and inequalities:

Variables = a, b, c, x, y

Inequalities = 
x > y \
a < x \
b > a \
b < y \
c > x \
c > y

Print any solution or say it is impossible.

Solution 1: \
Use the inequalities as directed edges (x > y means edge y->x and a < x means edge a->x) and do topo sort. \
Now assign values as 1 to n to the sorted variables (where n = res vector length)
