n = int(input())
ro = int(input())
re = int(input())
oe = int(input())
remaining = n - 1
ans = 0
if remaining == 0:
    ans = 0
elif remaining == 1:
    ans = min(ro, re)
else:
    opt = min(ro, re)
    ans += opt
    remaining -= 1
    opt = min(opt, oe)
    ans += opt * remaining
print(ans)