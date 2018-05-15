#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
#define pr(x) cout << x << endl;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)


int main() {
	string s;
	cin >> s;
	vector <int> v;
	int ret = 0;
	int SZ = s.size();
	rep(i, SZ) if (s[i] == 'Q') v.pb(i);
	rep(i, v.size()) {
		FOR(j, i+1, v.size()) {
			FOR(k, v[i], v[j]+1) {
				if (s[k] == 'A') ret++;
			}
		}
	}

	pr(ret);
	return 0;
}