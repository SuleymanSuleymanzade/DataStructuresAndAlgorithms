
mx =[ [0,3,0,0,0],
      [1,0,0,0,0],
      [0,2,0,4,0],
      [0,0,5,0,0],
      [4,1,0,0,0],
      [3,3,4,5,6],
      [0,0,0,3,1]
]

dp = [[0] * (len(mx[0])) for _ in range(len(mx))]
for i in range(1, len(mx)):
    dp[i][0] = dp[i-1][0] + mx[i][0]
for j in range(1, len(mx[0])):
               dp[0][j] = dp[0][j-1] + mx[0][j]

for i in range(1, len(mx)):
    for j in range(1, len(mx[0])):
        dp[i][j] = mx[i][j] + max(dp[i][j-1], dp[i-1][j])

path = [(mx[len(mx)-1][len(mx[0]) -1], (len(mx)-1, len(mx[0])-1))] 

i,  j = len(mx) - 1, len(mx[0]) - 1
while i and j:
    if dp[i-1][j] > dp[i][j-1]:
        path.append(( mx[i-1][j], (i-1, j)))
        i -= 1
    elif dp[i][j-1] > dp[i-1][j]:
        path.append((mx[i][j-1], (i, j-1)))
        j-=1
    while j and not i:
        path.append((mx[0][j], (0, j )))
        j-=1
    while i and not j:
        path.append((mx[i][0], (i, 0)))
        i -= 1
path.append((mx[0][0], (0, 0)))
path = path[::-1]
for i in path:
    print(i)

