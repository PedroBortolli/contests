#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, j, n) for (int i = j; i < n; ++i)


vector <int> childs[1000];
int nos[1000];

int n, done = 0, ans = 0;

void dfs(int node = 0, bool print = false) {
	if (print) {
		done++;
		if (done < ans) cout << nos[node] << " ";
		else cout << nos[node] << endl;
	}
	else {ans++;}
	for (int a : childs[node]) {
		dfs(a, print);
		if (print) {
			done++;
			if (done < ans) cout << nos[node] << " ";
			else cout << nos[node] << endl;
		}
		else ans++;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	rep(i, n) cin >> nos[i];
	if (n == 1) {cout << 1 << endl; cout << nos[0] << endl;}
	else {
		FOR(i, 1, n) {
			int j = i-1;
			while (j >= 0 and nos[i]%nos[j]) {
				--j;
			}
			if (j == -1) {cout << -1 << endl; return 0;}
			else childs[j].push_back(i);
		}
		dfs (0);
		cout << ans << endl;
		dfs(0, true);
	}

	return 0;
}