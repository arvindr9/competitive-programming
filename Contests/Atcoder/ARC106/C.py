n, m = list(map(int,input().split()))
if n == 1 and m == 0:
    print(2, 4)
elif m < 0:
    print(-1)
elif m > n - 2:
    print(-1)
elif m == 0:
    for i in range(n):
        print(3 * i + 2, 3 * i + 4)
else:
    print(1, 6)
    for i in range(n - 1):
        print(3 * i + 2, 3 * i + 4)