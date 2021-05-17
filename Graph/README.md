# Discovery of graph theory by Euler:
Eulerian refers to the Swiss mathematician Leonhard Euler, who invented graph theory in the 18th century.

#### 7 bridges of Königsberg:
The history of graph theory may be specifically traced to 1735, when the Swiss mathematician Leonhard Euler solved the Königsberg bridge problem. The Königsberg bridge problem was an old puzzle concerning the possibility of finding a path over every one of seven bridges that span a forked river flowing past an island—but without crossing any bridge twice. Euler argued that no such path exists. His proof involved only references to the physical arrangement of the bridges, but essentially he proved the first theorem in graph theory.
![image info](https://cdn.britannica.com/77/74877-050-F5DD4C34/Leonhard-Euler-route-each-question-bridges-Swiss.jpg)

#### Euler Tour: 
Can begin and end with different nodes visiting all edges only once
#### Euler Cycle: 
Should begin and end with same node visiting all edges only once




# DFS Tree
Consider an undirected connected graph G. Here is an animation of what calling dfs(1) looks like.
```
1 function dfs(u):
2     mark u as visited
3     for each vertex v among the neighbours of u:
4         if v is not visited:
5             mark the edge uv
6             call dfs(v)
```
![DFS Tree](https://codeforces.com/predownloaded/8d/be/8dbe5d89e58b67f3d8e4d8e0e8eb3358ba921b28.png)

Let's look at the edges that were marked in line 5. They form a spanning tree of G, rooted at the vertex 1. \
We'll call these edges span-edges (forward edges); all other edges are called back-edges.

This is the DFS tree of our graph:

![DFS Tree 2](https://codeforces.com/predownloaded/8b/cc/8bccbec25c8d76a68c34303a58836756225129b1.png)

#### Observations:
1) The back-edges of the graph all connect a vertex with its descendant in the spanning tree. This is why DFS tree is so useful.
2)  A span-edge (forward-edge) uv is a bridge if and only if there exists no back-edge that connects a descendant of uv with an ancestor of uv. In other words, a span-edge uv is a bridge if and only if there is no back-edge that "passes over" uv.
3)  A back-edge is never a bridge.



# Advanced topics:
1) Bipartite Matching (Solved using flows) [Graph Thory 3: Advanced (HealthyUG aka Demoralizer aka Utkarsh Gupta)](https://unacademy.com/class/graph-theory-3-advanced/YA6ZG3XD)
