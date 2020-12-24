n = int(input())
a = list(map(int, input().split()))
min_elt = 105
max_elt = 0
max_ind = -1
min_ind = -1
for i in range(n):
    if a[i] > max_elt:
        max_elt = a[i]
        max_ind = i
    if a[i] < min_elt:
        min_elt = a[i]
        min_ind = i
if min_ind in [0, n - 1] or max_ind in [0, n - 1]:
    print(n - 1)
else:
    mn = min(min_ind, max_ind)
    mx = max(min_ind, max_ind)
    ans = max(mx, (n - 1) - mn)
    print(ans)