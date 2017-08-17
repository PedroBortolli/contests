#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <int> s[105];
int v[105];
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			s[i].insert(x);
		}
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			int lo = -1, hi = -1;
			for (auto a : s[i]) {
				if (s[j].find(a) != s[j].end()) {
					if (lo == -1) lo = a;
					hi = a;
				}
			}

			int conti = 0, contj = 0;
			for (auto a : s[i]) {
				if (a < lo or a > hi) conti++;
			}
			for (auto a : s[j]) {
				if (a < lo or a > hi) contj++;
			}

			if (conti == contj) {
				v[i]++;
				v[j]++;
			}
			else if (conti > contj) v[i] += 2;
			else v[j] += 2;
		}
	}

	set <pii> ans;
	for (int i = 0; i < n; i++) {
		ans.insert(mp(-v[i], i));
	}

	for (auto a : ans)
		printf("%d\n", a.second+1);

	return 0;
}