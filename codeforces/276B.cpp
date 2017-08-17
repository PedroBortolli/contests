#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1005];
int f[30];
int main() {
	scanf(" %s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
		f[s[i]-'a']++;

	int odd = 0;
	for (int i = 0; i < 26; i++)
		if (f[i]%2) odd++;

	if (odd == 0 or odd%2) printf("First\n");
	else printf("Second\n");
	return 0;
}