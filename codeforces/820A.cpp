#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int c, vo, v1, a, l;
	scanf("%d %d %d %d %d", &c, &vo, &v1, &a, &l);
	int ans = 0;

	int ok = 0;
	int able = v1;
	while (c > 0) {
		if (ok) {
			vo += a;
			if (vo > v1) vo = v1;
		}
		int read = vo-l*ok;
		if (read > v1) read = v1;
		c -= read;
		ok = 1;
		ans++;
	}

	printf("%d\n", ans);
	return 0;
}