n = int(input())

v = []
ans = 0
if (n%2 != 0):
	v.append("7")
	n -= 3

while (n > 0):
	v.append("1")
	n -= 2


for i in range(len(v)):
	print(v[i], end="")