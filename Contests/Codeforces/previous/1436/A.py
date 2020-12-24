t = int(input())

for case in range(t):
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    s = sum(a)
    if s == m:
        print("YES")
    else:
        print("NO")