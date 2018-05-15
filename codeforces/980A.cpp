#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[105];
int main() {
	int l = 0, p = 0;
	scanf(" %s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '-') l++;
		else p++;
	}
	
	if (p == 0) printf("YES\n");
	else if (l%p == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}