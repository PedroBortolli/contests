#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

string s[55];
map <string, int> mp;
set <int> ava;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		ava.insert(i);

	for (int i = 0; i < n; i++) {
		if (mp[s[i]]) continue;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				if (ava.find(j) == ava.end()) {
					printf("No\n");
					return 0;
				}
				else ava.erase(j);
			}
		}
		mp[s[i]] = 1;
	}

	printf("Yes\n");
	return 0;
}