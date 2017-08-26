#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

string str, s;
int ans = 1111;
void check(string a) {
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++) {
		x += (a[i]-'0');
		y += (a[i+3]-'0');
	}
	if (x != y) return;
	int cont = 0;
	for (int i = 0; i < 6; i++) {
		if (a[i] != str[i]) cont++;
	}
	ans = min(ans, cont);
} 

int main() {
	cin >> str;
	s = "000000";
	for (int i = 0; i < 1000000; i++) {
		check(s);
		s[5]++;
		int p = 5;
		while (1) {
			if (p < 0) break;
			if (s[p] > '9') {
				s[p] = '0';
				s[--p]++;
			}
			else break;
		}
		if (s[5] > '9') {
			s[5] = '0';
			s[4]++;
			if (s[4] > '9') {
				s[4] = '0';
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}