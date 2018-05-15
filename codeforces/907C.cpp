#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int cant[444];
char s[100005];
int main() {
	int q, end = 0, ans = 0;
	char op;
	scanf("%d", &q);
	while (q--) {
		scanf(" %c %s", &op, s);
		if (end) {
			if (op != '.') ans++;
			continue;
		}
		int n = strlen(s);
		set <char> st;
		if (op == '!') {
			for (int i = 0; i < n; i++) {
				st.insert(s[i]);
			}
			for (int i = 'a'; i <= 'z'; i++) {
				if (st.find(i) == st.end()) {
					cant[i] = 1;
				}
			}
		}
		if (op == '.') {
			for (int i = 0; i < n; i++) {
				cant[s[i]] = 1;
			}
		}
		if (op == '?') {
			cant[s[0]] = 1;
		}
		int ava = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (!cant[i]) ava++;
		}

		if (ava == 1) end = 1;
	}

	printf("%d\n", max(0, ans-1));
	return 0;
}