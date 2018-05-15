#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e4+5;
char s[N], aux[5];
int n, dp[N][2];
set <string> res;

int go(int id, int prev) {
	if (id >= n) return 1;
	if (id == n-1) return 0;
	if (prev >= 0 && dp[id][prev] != -1) return dp[id][prev];
	int ans = 0;
	if (prev <= 0) {
		if (id <= n-3) {
			aux[0] = s[id];
			aux[1] = s[id+1];
			aux[2] = s[id+2];
			aux[3] = 0;
			if (go(id+3, 1)) {
				ans++;
				aux[0] = s[id];
				aux[1] = s[id+1];
				aux[2] = s[id+2];
				aux[3] = 0;
				string temp = "";
				temp += aux[0];
				temp += aux[1];
				temp += aux[2];
				res.insert(temp);
			}
		}
		if (prev == -1 || s[id] != s[id-2] || s[id+1] != s[id-1]) {
			aux[0] = s[id];
			aux[1] = s[id+1];
			aux[2] = 0;
			if (go(id+2, 0)) {
				aux[0] = s[id];
				aux[1] = s[id+1];
				aux[2] = 0;
				ans++;
				string temp = "";
				temp += aux[0];
				temp += aux[1];
				res.insert(temp);
			}
		}
	}
	else {
		if (id <= n-3 && (s[id] != s[id-3] || s[id+1] != s[id-2] || s[id+2] != s[id-1])) {
			aux[0] = s[id];
			aux[1] = s[id+1];
			aux[2] = s[id+2];
			aux[3] = 0;
			if (go(id+3, 1)) {
				ans++;
				aux[0] = s[id];
				aux[1] = s[id+1];
				aux[2] = s[id+2];
				aux[3] = 0;
				string temp = "";
				temp += aux[0];
				temp += aux[1];
				temp += aux[2];
				res.insert(temp);
			}
		}
		aux[0] = s[id];
		aux[1] = s[id+1];
		aux[2] = 0;
		if (go(id+2, 0)) {
			aux[0] = s[id];
			aux[1] = s[id+1];
			aux[2] = 0;
			ans++;
			string temp = "";
			temp += aux[0];
			temp += aux[1];
			res.insert(temp);
		}
	}
	if (prev == -1) return ans;
	else return dp[id][prev] = ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s;
	n = strlen(s);
	memset(dp, -1, sizeof(dp));
	for (int i = 5; i < n; i++) {
		go(i, -1);
	}

	cout << (int)res.size() << endl;
	for (auto a : res)
		cout << a << endl;
	return 0;
}