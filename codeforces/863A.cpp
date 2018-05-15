#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[111];
int n;
int check(int x) {
	string str = "";
	for (int i = 0; i < x; i++) {
		str += '0';
	}
	for (int i = 0; i < n; i++) {
		str += s[i];
	}
	int len = (int)str.length();
	int j = len-1;
	int ok = 1;
	for (int i = 0; i < len/2; i++) {
		if (str[i] != str[j]) {
			ok = 0;
			break;
		}
		j--;
	}
	return ok;
}

int main() {
	scanf(" %s", s);
	n = strlen(s);
	for (int i = 0; i < 100; i++) {
		int x = check(i);
		if (x) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}