a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
max1 = min(a, d)
max2 = min([b, c, d])
case1 = min([d - max1, b, c])
case2 = min([d - max2, a])
# print(f"max1: {max1}, max2: {max2}")
ans1 = max1 * e + case1 * f
ans2 = max2 * f + case2 * e
print(max(ans1, ans2))