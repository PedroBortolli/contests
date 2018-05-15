x = int(input())
h, m = map(int, input().split())
ans = 0

while (True):
	s = str(h)+str(m)
	if (s.find('7') != -1):
		print(ans)
		exit(0)
	m = m-x
	if (m < 0):
		m = m+60
		h = h-1
		if (h < 0):
			h = 23	
	ans = ans+1