#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[111];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2*n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+2*n);

	int res = INT_MAX;
	for (int i = 0; i < 2*n-1; i++) {
		for (int j = i+1; j < 2*n; j++) {
			vector <int> a;
			for (int k = 0; k < 2*n; k++) {
				if (k == i or k == j) continue;
				a.pb(v[k]);
			}
			int ans = 0;
			for (int k = 1; k < 2*n-2; k+=2) {
				ans += (a[k]-a[k-1]);
			}
			res = min(res, ans);
		}
	}
	printf("%d\n", res);
	return 0;
}