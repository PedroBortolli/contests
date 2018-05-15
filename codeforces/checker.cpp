#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1111];
char comp[1111];
int main() {
	scanf(" %[^\n]", s);
	int ok = 1;
	while (scanf(" %[^\n]", comp) != EOF) {
		if (strcmp(s, comp)) {
			ok = 0;
		}
	}
	if (ok) printf("ok ok\n");
	else printf("FUUUUDEUUUUUUUUUUUUUUUUUUUUUU\n");
	return 0;
}