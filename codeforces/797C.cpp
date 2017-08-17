#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[100005];
map <char, int> f;
int main()
{
	scanf(" %s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) 
		f[s[i]]++;

	stack <char> st;
	for (int i = 0; i < n; i++) {
		st.push(s[i]);
		f[s[i]]--;
		while (!st.empty()) {
			char c = st.top();
			int ok = 1;
			for (int i = 'a'; i < c; i++) {
				if (f[i]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				printf("%c", c);
				st.pop();
			}
			else break;
		}
	}

	while (!st.empty()) {
		printf("%c", st.top());
		st.pop();
	}

	return 0;
}