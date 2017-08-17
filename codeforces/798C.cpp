#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005], seen[100005];

int gcd(int x, int y) {
	if (y == 0) return abs(x);
	return gcd(y, x%y);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int prev = v[0];
	int ans = 0;
	int ok = 1;
	for (int i = 1; i < n; i++) {
		int x = gcd(prev, v[i]);
		if (x <= 1) {
			ok = 0;
			break;
		}
		prev = x;
	}

	if (ok) {
		printf("YES\n0\n");
		return 0;
	}

	for (int i = 1; i < n; i++) {
		if (v[i]%2 != 0 && v[i-1]%2 != 0 && !seen[i] && !seen[i-1]) {
			ans++;
			seen[i] = 1;
			seen[i-1] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (v[i]%2 != 0 && !seen[i]) ans += 2;
	}

	printf("YES\n%d\n", ans);
}