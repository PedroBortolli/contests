#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <char, int> mp;
vector <string> v;
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.pb(str);
		mp[str[0]]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		char temp = v[i][0];
		mp[temp]--;
		vector <char> add;
		add.pb(temp);
		int len = (int)v[i].size();
		int ok = 1;
		for (int j = 0; j < len; j++) {
			if (mp[v[i][j]]) {
				mp[v[i][j]]--;
				add.pb(v[i][j]);
			}
			else {
				ok = 0;
				break;
			}
		}
		if (ok) ans++;
		for (auto a : add)
			mp[a]++;
	}

	cout << ans << "\n";
	return 0;
}