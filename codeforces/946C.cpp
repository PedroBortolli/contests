#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[100005];
int main() {
	scanf(" %s", s);
	int n = strlen(s);
	char need = 'a';
	for (int i = 0; i < n && need <= 'z'; i++) {
		if (s[i] == need) {
			need++;
			continue;
		}
		if (s[i]+1 == need) {
			s[i] = need;
			need++;
		}
	}
	if (need <= 'z') printf("-1\n");
	else printf("%s\n", s);
	return 0;
}