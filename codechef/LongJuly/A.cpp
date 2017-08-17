#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <string> v;
char s[1000];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		v.clear();
		int n = 0;
		while (scanf(" %s", s) != EOF) {
			int len = strlen(s);
			s[0] = toupper(s[0]);
			for (int i = 1; i < len; i++)
				s[i] = tolower(s[i]);
			string str = s;
			v.pb(str);
			n++;
			char c = getchar();
			if (c == '\n') break;
		}

		if (n == 1) printf("%s", s);
		else {
			for (int i = 0; i < n-1; i++) {
				char c = toupper(v[i][0]);
				string idk = "";
				idk += c;
				idk += ".";
				v[i] = idk;
			}
			for (auto a : v)
				cout << a << " ";
		}
		cout << endl;
	}
	return 0;
}