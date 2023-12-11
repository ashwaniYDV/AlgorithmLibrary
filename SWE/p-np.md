# P, NP, NP-complete

- A problem is in class `P` if its solution may be *found* in polynomial time.
- A problem is in class `NP` if its solution may be *verified* in polynomial time.
- A problem in `P` is in `NP` by definition, but the converse may not be the case.
- `NP`-complete is a family of `NP` problems for which you know that if one of them has a polynomial solution then everyone of them has.
- Examples of `NP`-complete problems: traveling salesman, knapsack, graph coloring.
- Once you've reduced a problem to `NP`-complete, you know to give up on an efficient fast algorithm and to start looking at approximations.
- For `NP`-complete problems, no polynomial-time algorithms are known for solving them (although they can be verified in polynomial time).
- The most notable characteristic of `NP`-complete problems is that no fast solution to them is known.
- `NP`-hard: non-deterministic polynomial time.
