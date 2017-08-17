#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int ar[300005];
vector <int> v[300005];
multiset <int> s;
int main() {
	int n, x, y,cur = 0, mx = -INT_MAX;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
		ar[i] += 2;
		mx = max(mx, ar[i]);
		s.insert(ar[i]);
	}

	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}

	int ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		s.erase(s.find(ar[i]));
		s.insert(ar[i]-2);
		for (auto a : v[i]) {
			if (ar[a]-1 < mx-2) continue;
			s.erase(s.find(ar[a]));
			s.insert(ar[a]-1);
		}
		ans = min(ans, *(s.rbegin()));
		s.erase(s.find(ar[i]-2));
		s.insert(ar[i]);
		for (auto a : v[i]) {
			if (ar[a]-1 < mx-2) continue;
			s.erase(s.find(ar[a]-1));
			s.insert(ar[a]);
		}
	}

	printf("%d\n", ans);
	return 0;
}