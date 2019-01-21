n = int(input())
arr = list(map(int, input().split()))

ans = {}

def solve(t):
    cost = 0
    for num in arr:
        if num > t:
            cost += (num - (t + 1))
        elif num < t:
            cost += ((t - 1) - num)
    if cost not in ans:
        ans[cost] = [str(t)]
    else:
        ans[cost].append(str(t))
    return cost

mincost = 90000000000
for t in range(1, 101):
    mincost = min(mincost, solve(t))
print(ans[mincost][0], mincost)