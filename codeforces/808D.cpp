#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <ll> bef, aft;
int v[100005];
int main() {
	int n;
	scanf("%d", &n);
	ll b = 0, a = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		b += v[i];
		aft.insert(v[i]);
	}

	for (int i = 0; i < n; i++) {
		a += v[i];
		b -= v[i];
		if (a == b) {
			printf("YES\n");
			return 0;
		}
		aft.erase(aft.find(v[i]));
		bef.insert(v[i]);
		if (i == 0 or i == n-1 or (abs(a-b))%2) continue;
		ll dif = (a-b)/2;
		if (dif < 0) {
			if (aft.find(-dif) != aft.end()) {
				printf("YES\n");
				return 0;
			}
		}
		else if (bef.find(dif) != bef.end()) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}