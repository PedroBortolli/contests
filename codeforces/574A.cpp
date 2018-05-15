#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <int> s;
int main() {
	int n, x, y;
	scanf("%d", &n);
	scanf("%d", &x);
	for (int i = 1; i < n; i++) {
		scanf("%d", &y);
		s.insert(-y);
	}

	int ans = 0;
	while (1) {
		y = -*(s.begin());
		if (x > y) break;
		ans++;
		x++;
		y--;
		s.erase(s.begin());
		s.insert(-y);
	}

	printf("%d\n", ans);
	return 0;
}

2
3
4
6
8
9
12
15
16


75 50 = 25


150
---
100

75
50

25
10

15 5    
5  15


1