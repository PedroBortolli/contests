#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

string s, a, b;
int main() {
	cin >> s;
	cin >> a;
	cin >> b;

	int ns = s.length();
	int na = a.length();
	int nb = b.length();

	string ans = ""; 
	for (int i = 0; i < ns; i++) {
		string str = "";
		for (int j = i; j < i+na; j++) {
			str += s[j];
		}
		if (str == a && str.length() == na) {
			ans += b;
			i = i+na-1;
			continue;
		}
		string strr = "";
		for (int j = i; j < i+nb; j++) {
			strr += s[j];
		}
		if (strr == b && strr.length() == nb) {
			ans += a;
			i = i+nb-1;
			continue;
		}
		ans += s[i];
	}
	cout << ans << endl;
	return 0;
}