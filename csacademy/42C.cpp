#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005], ans[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i < n; i++) {
		if (v[i]) {
			if (i+v[i]-1 < n) {
				ans[i+v[i]-1] = max(ans[i+v[i]-1], v[i]);
			}
		}
	}

	for (int i = n-1; i >= 1; i--) {
		ans[i] = max(ans[i], ans[i+1]-1);
	}

	for (int i = 1; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}