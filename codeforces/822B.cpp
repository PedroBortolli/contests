#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1005], t[1005];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	scanf(" %s", s);
	scanf(" %s", t);

	vector <int> vans;
	vector <int> v;
	int ans = INT_MAX;
	for (int i = 0; i <= m-n; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (t[i+j] != s[j]) {
				cur++;
				v.pb(j+1);
			}
		}
		if (cur < ans) {
			ans = cur;
			vans.clear();
			for (auto a : v)
				vans.pb(a);
		}
		v.clear();
	}

	printf("%d\n", ans);
	for (auto a : vans)
		printf("%d ", a);
	printf("\n");

	return 0;
}