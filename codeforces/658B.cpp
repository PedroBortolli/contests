#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int t[150005];
vector <pii> v;
int main() {
	int n, k, q, ty, id;
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);	

	while (q--) {
		scanf("%d %d", &ty, &id);
		if (ty == 1) {
			if (v.size() < k) {
				v.pb(mp(t[id], id));
				sort(v.begin(), v.end());
			}
			else {
				int x = v[0].first;
				if (t[id] > x) {
					v[0].first = t[id];
					v[0].second = id;
					sort(v.begin(), v.end());
				}
			}
		}
		else {
			int ok = 0;
			for (int i = 0; i < v.size(); i++) {
				if (v[i].second == id) {
					ok = 1;
				}
			}
			if (ok) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}