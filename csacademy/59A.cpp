#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <char, int> mp;
char s[100005];
int main() {
	int n;
	scanf("%d", &n);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (mp[s[i]] == 1) {
			printf("%c\n", s[i]);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}