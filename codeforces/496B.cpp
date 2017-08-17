#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[1005];
int aux[1005];
char s[1005];
int main() {
	int n;
	scanf("%d", &n);
	string ans;
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		v[i] = s[i]-'0';
	}
	for (int i = 0; i < n; i++) {
		ans += (v[i]+'0');
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 10; k++) {
			string str;
			for (int j = 0; j < n; j++) {
				v[j]++;
				v[j] %= 10;
				str += (v[j]+'0');
			}
			if (str < ans) ans = str;
		}
		aux[0] = v[n-1];
		for (int j = 1; j < n; j++)
			aux[j] = v[j-1];
		for (int j = 0; j < n; j++)
			v[j] = aux[j];
	}

	cout << ans << endl;
	return 0;
}