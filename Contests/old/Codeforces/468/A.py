a = int(input())
b = int(input())
mid = int((a+b)/2)
d1 = abs(mid - a)
d2 = abs(b - mid)
ans = (d1)* (d1 + 1) / 2 + (d2) * (d2 + 1) / 2
print(int(ans))
