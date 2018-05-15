#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int ans = 0, x;
	for (int i = 0; i < 3; i++) {
		int mn = 10000;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &x);
			mn = min(mn, x);
		}
		ans += mn;
	}	

	printf("%d\n", ans);
	return 0;
}