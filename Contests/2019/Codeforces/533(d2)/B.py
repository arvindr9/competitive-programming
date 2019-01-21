n, k = list(map(int, input().split()))
s = input()

counts = {}

def addToDict(char, cnt):
    if char not in counts:
        counts[char] = [cnt]
    else:
        counts[char].append(cnt)

def ways(c):
    res = 0
    for num in counts[c]:
        res += num // k
    return res


cnt = 0
curChar = ''
for c in s:
    if c != curChar:
        addToDict(curChar, cnt)
        curChar = c
        cnt = 0
    cnt += 1
if cnt:
    addToDict(curChar, cnt)

ans = 0
for c in counts:
    ans = max(ans, ways(c))

print(ans)
