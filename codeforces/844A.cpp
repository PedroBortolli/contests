#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1111];
map <char, int> mp;
int main() {
	scanf(" %s", s);
	int n = strlen(s);
	int k, cont = 0, free = 0;
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		if (!mp[s[i]]) cont++;
		else free++;
		mp[s[i]] = 1;
	}

	if (cont+free >= k) printf("%d\n", max(0, k-cont));
	else printf("impossible\n");
	return 0;
}