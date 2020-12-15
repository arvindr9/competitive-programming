t = int(input())

for case in range(t):
    n = int(input())
    st = input()
    if len(st) < 4:
        print("NO")
        continue
    # print("prefix: ", st[-])
    if '2020' in [st[-4:], st[0] + st[-3:], st[:2] + st[-2:], st[:3] + st[-1], st[:4]]:
        print("YES")
        continue
    print("NO")