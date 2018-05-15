#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

unordered_map <int, int> f;
int v[1005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		f[v[i]]++;
	}

	int ans = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int old = v[i];
			int prev = v[j];
			if ((i == j) or (old == 0 && prev == 0)) continue;
			f[old]--;
			f[prev]--;
			int cur = 2;
			vector <int> ch;
			ch.pb(old);
			ch.pb(prev);
			while (1) {
				if (f[old+prev]) {
					ch.pb(old+prev);
					cur++;
					f[old+prev]--;
					int aux = old;
					old = prev;
					prev = aux+prev;
				}
				else break;
			}
			for (auto a : ch) {
				f[a]++;
			}
			ans = max(ans, cur);
		}
	}

	printf("%d\n", max(ans, f[0]));
	return 0;
}