x = int(input())
y = x
ans1 = 0
ans2 = 0
while (x%10 != 0):
	x -= 1
	ans1 += 1

while (y%10 != 0):
	y += 1
	ans2 += 1

if (ans1 < ans2): print(x)
else: print(y)