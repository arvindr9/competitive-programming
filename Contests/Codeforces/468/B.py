n, a, b = list(map(int, input().split()))
if (a <= n / 2 and b > n / 2) or (b <= n / 2 and a > n / 2):
    print("Final!")
elif abs(a - b) == 1:
    print(1)
else:
    i = 1 
    while abs(a - b) > 1:
        a = int(a / 2)
        b = int(b / 2)
        i += 1
    print(i)
