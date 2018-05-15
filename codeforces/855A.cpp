#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <string, int> mp;
int main() {
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (mp[str]) cout << "YES" << endl;
		else cout << "NO" << endl;
		mp[str] = 1;
	}

	return 0;
}