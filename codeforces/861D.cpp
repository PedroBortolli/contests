#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

unordered_map <string, int> mp;
char s[70005][12];
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < 9; j++) {
			string str = "";
			for (int k = j; k < 9; k++) {
				str += s[i][k];
				if (mp[str] && mp[str] != i+1) mp[str] = INT_MAX;
				else mp[str] = i+1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		set <pair <int, string> > st;
		for (int j = 0; j < 9; j++) {
			string str = "";
			for (int k = j; k < 9; k++) {
				str += s[i][k];
				if (mp[str] == i+1) st.insert({k-j+1, str});
			}
		}
		cout << st.begin()->second << "\n";
	}
	return 0;
}