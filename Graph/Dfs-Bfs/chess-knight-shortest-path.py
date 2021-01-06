row=[2,2,-2,-2,1,1,-1,-1]
col=[-1,1,1,-1,2,-2,2,-2]

def valid(x, y):
    if x<0 or y<0 or x>=8 or y>=8:
        return 0
    return 1

def bfs(src, dest):
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
        for i in range(8):
            x1=x+row[i]
            y1=y+col[i]
            check=valid(x1, y1)
            if check==1:
                q.append((x1, y1, dist+1))
    return -1


print(bfs((0,7,0), (7,0,0)))
