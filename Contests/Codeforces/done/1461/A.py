t = int(input())

alphabet = 'abc'

while len(alphabet) < 1000:
    alphabet += alphabet

for case in range(t):
    n, k = list(map(int, input().split()))
    print(alphabet[:n])