#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, a, b, x, ans = 0, ok = 1, ava = 0;
	scanf("%d %d %d", &n, &a, &b);
	int sing = a, doub = b;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 1) {
			if (sing > 0) sing--;
			else {
				if (doub > 0) {
					doub--;
					ava++;
				}
				else if (ava > 0) ava--;
				else ans++;
			}
		}
		else {
			if (doub > 0) doub--;
			else ans+=2;
		}
	}

	printf("%d\n", ans);
	return 0;
}