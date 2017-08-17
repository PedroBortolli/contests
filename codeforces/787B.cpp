#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <int, int> mp;
int main() {
	int n, m, k, ok, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		mp.clear();
		scanf("%d", &k);
		ok = 0;
		for (int j = 0; j < k; j++) {
			scanf("%d", &x);
			mp[x]++;
			if (mp[-x] > 0) ok = 1;
		}
		if (!ok) {
			printf("YES\n");
			return 0;
		}
	}	

	printf("NO\n");
	return 0;
}