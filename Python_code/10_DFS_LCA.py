global g
global parent

def dfs(v , p=-1):
    parent[v] = p
    for child in g[v]:
        if child == p:
            continue
        dfs(child,v)
def path(v):
    li = []
    while(v != -1):
        li.append(v)
        v = parent[v]
    li.reverse()
    return li

if __name__ == "__main__":
    g = {}
    parent = []
    n = int(input())
    for i in range(n + 1):
        g[i] = []
    parent = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    dfs(1)
    x, y = map(int, input().split())
    x_path = path(x)
    y_path = path(y)

    mn_len = min(len(x_path), len(y_path))
    lcm = -1

    for i in range(mn_len):
        if x_path[i] == y_path[i]:
            lcm = x_path[i]
        else:
            break
    print(lcm)


#test case
# 13
# 1 2
# 1 3
# 1 13
# 2 5
# 5 6
# 5 7
# 5 8
# 8 12
# 3 4
# 4 9
# 4 10
# 10 11
