row=[1,-1,0,0]
col=[0,0,1,-1]

def valid(x, y, list):
    if x<0 or y<0 or x>=len(list[0]) or y>=len(list) or list[x][y]==1:
        return 0
    return 1

def bfs(src, dest, list):
    visited={}
    q = []
    q.append(src)
    while len(q):
        node=q.pop(0)
        x=node[0]
        y=node[1]
        dist=node[2]
        if x==dest[0] and y==dest[1]:
            return dist
        if node in visited:
            continue

        visited[node]=1
        for i in range(4):
            x1=x+row[i]
            y1=y+col[i]
            if valid(x1, y1, list)==1:
                q.append((x1, y1, dist+1))
    return -1

def solution():
    list=[[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
    source=(0,0,1)
    destination=(len(list)-1, len(list[0])-1, 0)
    print(bfs(source, destination, list))

solution()
