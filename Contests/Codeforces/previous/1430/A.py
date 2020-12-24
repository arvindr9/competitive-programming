t = int(input())

for case in range(t):
    n = int(input())
    if n == 3:
        print(1, 0, 0)
    elif n == 5:
        print(0, 1, 0)
    elif n == 7:
        print(0, 0, 1)
    elif n % 3 == 0:
        print(n // 3, 0, 0)
    elif n >= 7:
        if (n - 5) % 3 == 0:
            print((n - 5) // 3, 1, 0)
        else:
            print((n - 7) // 3, 0, 1)
    else:
        print(-1)