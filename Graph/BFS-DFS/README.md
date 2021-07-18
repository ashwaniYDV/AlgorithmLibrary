### Google Interview

1) 
A grid is given, some cells are land(1) and others are water(0), you have to tell the size of the largest connected land component where adjacent horizontal and vertical lands are connected.

Solution: just find the connected components using dfs or bfs.


Follow Up: Now assume that if some water is trapped within a connected land continent(component) then you can take it as included in that component and it will also let you connect to other lands horizontally and vertically now you have to tell the size of the largest continent. 

Solution: find all the waters that are not trapped within any land continent by doing dfs/bfs from the boundary waters. then you can just consider the remaining waters as land. :) and again compute the connected components.
