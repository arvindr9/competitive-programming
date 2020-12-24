t = int(input())

for case in range(t):
    a = list(map(int, input().split()))
    sm = sum(a)
    if sm % 9 == 0:
        k = sm // 9
        mn = min(a)
        if mn >= k:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")


'''
case 2:

sum % 9 == 0
mn >= k?
calc total number of shots

min >= total shots / 7

9 divides sum
sum = 9k
total number of shots: 7k
min >= 7k / 3
'''