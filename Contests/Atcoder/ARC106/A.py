three_powers = [3]
five_powers = [5]
while three_powers[-1] < int(1e18):
    three_powers.append(three_powers[-1]*3)
while five_powers[-1] < int(1e18):
    five_powers.append(five_powers[-1]*5)

n = int(input())

a = len(three_powers)
b = len(five_powers)

done = False

for i in range(a):
    for j in range(b):
        if (three_powers[i] + five_powers[j] == n):
            print(i + 1, j + 1)
            done = True
            break

if not done:
    print(-1)
