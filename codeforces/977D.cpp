#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[105], seen[105];
int main() {
	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	for (int i = 0; i < n; i++) {
		memset(seen, 0ll, sizeof(seen));
		seen[i] = 1;
		ll cur = v[i];
		vector <ll> ans;
		ans.pb(v[i]);
		while (1) {
			ll old = ans.size();
			for (int j = 0; j < n; j++) {
				if (seen[j]) continue;
				if (cur*2 == v[j]) {
					seen[j] = 1;
					ans.pb(v[j]);
					cur = v[j];
				}
				else if (cur%3 == 0 && cur/3 == v[j]) {
					seen[j] = 1;
					ans.pb(v[j]);
					cur = v[j];
				}
			}
			if (ans.size() == old) break;
		}
		if (ans.size() == n) {
			for (auto a : ans)
				printf("%lld ", a);
			printf("\n");
			return 0;
		}
	}	

	return 0;
}