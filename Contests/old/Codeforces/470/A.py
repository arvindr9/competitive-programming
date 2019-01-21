R, C = list(map(int, input().split()))
layout = []
for i in range(R):
    layout.append(list(input()))
possible = True
for i in range(R):
    for j in range(C):
        if layout[i][j] == 'S':
            if i > 0:
                if layout[i - 1][j] == 'W':
                    possible = False
                elif layout[i - 1][j] != 'S':
                    layout[i - 1][j] = 'D'
            if j > 0:
                if layout[i][j - 1] == 'W':
                    possible = False
                elif layout[i][j - 1] != 'S':
                    layout[i][j - 1] = 'D'
            if i < R - 1:
                if layout[i + 1][j] == 'W':
                    possible = False
                elif layout[i + 1][j] != 'S':
                    layout[i + 1][j] = 'D'
            if j < C - 1:
                if layout[i][j + 1] == 'W':
                    possible = False
                elif layout[i][j + 1] != 'S':
                    layout[i][j + 1] = 'D'
            if not possible:
                break
            
    if not possible:
        break
if possible:
    print("Yes")
    for i in range(R):
        line = ""
        for j in range(C):
            line += str(layout[i][j])
        print(line)
else:
    print("No")
