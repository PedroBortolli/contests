inp = list(map(int, input().split()))
w = inp[0]
m = inp[1]
v = []

for i in range(101):
	print(w**i)
	v.append(w**i)

for i in range(101):
	for j in range(101):
		print(v[i]+m)
		print(v[j])
		print("")
		if (v[i]+m == v[j]):
			print("YES")
			exit()

print("NO")