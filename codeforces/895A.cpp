#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[444];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int ans = 360;
	for (int i = 0; i < n; i++) {
		int pos = i, cur = 0;
		for (int j = 0; j < n; j++) {
			cur += v[pos++];
			if (pos == n) pos = 0;
			ans = min(ans, abs(360-2*cur));
		}
	}

	printf("%d\n", ans);
	return 0;
}