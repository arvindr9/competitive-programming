ans_to_arr = {}

def solve(mn, m):
    try:
        q1 = m[mn]
    except KeyError:
        q1 = 0
    try:
        q2 = m[mn + 1]
    except KeyError:
        q2 = 0
    try:
        q3 = m[mx]
    except KeyError:
        q3 = 0
    if q2 - (q2 % 2) > 2 * min(q1, q3):
        ans = q1 + (q2 % 1) + q3
        q_1 = q1 + int((q2 - (q2 % 2))/2)
        q_2 = q2 % 2
        q_3 = q3 + int((q2 - (q2 % 2))/2) 
        arr = []
        for i in range(q_1):
            arr.append(mn)
        for i in range(q_2):
            arr.append(mn + 1)
        for i in range(q_3):
            arr.append(mn + 2)
            ans_to_arr[ans] = arr
    else:
        ans = q1 + q3 - 2 * min(q1, q3) + q2
        q_1 = q1 - min(q1, q3)
        q_2 = q2 + 2 * min(q1, q3)
        q_3 = q3 - min(q1, q3)
        arr = []
        for i in range(q_1):
            arr.append(mn)
        for i in range(q_2):
            arr.append(mn + 1)
        for i in range(q_3):
            arr.append(mn + 2)
        ans_to_arr[ans] = arr
    return ans
    



n = int(input())
arr = list(map(int, input().split()))
m = {}
mn = 200000
mx = -200000



for i in arr:
    try:
        m[i] += 1
    except KeyError:
        m[i] = 1
    mx = max(mx, i)
    mn = min(mn, i)


r = mx - mn
if r == 2:
    ans = solve(mn, m)
    print(ans)
    arr = ans_to_arr[ans]
    s = ""
    for i in arr:
        s += f"{i} "
    print(s[:len(s) - 1])
elif r == 1:
    ans = len(arr)
    print(ans)
    s = ""
    for i in arr:
        s += f"{i} "
    print(s[:len(s) - 1])
elif r == 0:
    ans = len(arr)
    print(ans)
    s = ""
    for i in arr:
        s += f"{i} "
    print(s[:len(s) - 1])