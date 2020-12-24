n, k = list(map(int, input().split()))
rem_time = 240 - k
ans = 0
for i in range(n + 1):
    if 5 * (i) * (i + 1) // 2 <= rem_time:
        ans = i
print(ans)