t = int(input())

for case in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    res = []
    for i in range((n + 1) // 2):
        res.append(a[i])
        if i != (n + 1) // 2 - 1 or n % 2 == 0:
            res.append(a[n - 1 - i])
    res = list(map(str, res))
    print(" ".join(res))