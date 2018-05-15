#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1005];
int mp[222];

string best = "-1";

void work(int a, int b, int c) {
	//printf("Cheguei com %d %d %d\n", a, b, c);
	mp[a+'0']--;
	mp[b+'0']--;
	mp[c+'0']--;

	int add = 12;
	string temp = "";
	for (int i = 1; i < 10; i++) {
		if (mp[i+'0']) {
			add = i;
			temp += (i+'0');
			mp[i+'0']--;
			break;
		}
	}

	//printf("add = %d\n", add);
	if (add == 12) goto here;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < mp[i+'0']; j++)
			temp += (i+'0');
	}

	temp += (a+'0');
	temp += (b+'0');
	temp += (c+'0');

	if (best == "-1") {
		//printf("oi\n");
		best = temp;
	}
	else {
		//printf("oii\n");
		best = min(best, temp);
	}

	mp[add+'0']++;
	here:;
	mp[a+'0']++;
	mp[b+'0']++;
	mp[c+'0']++;
}

int main() {
	int x;
	scanf(" %s", s);
	int n = strlen(s);
	if (n == 1) {
		if (s[0] == '0' or s[0] == '8') printf("%c\n", s[0]);
		else printf("-1\n");
		return 0;
	}

	if (n == 2) {
		int x = (s[0]-'0')*10 + (s[1]-'0');
		int y = (s[1]-'0')*10 + (s[0]-'0');
		if (x%8 == 0 && y%8 == 0) {
			if (x < y) {
				if (s[0] != '0') printf("%c%c\n", s[0], s[1]);
				else printf("%c%c\n", s[1], s[0]);
			}
			else {
				if (s[1] != '0') printf("%c%c\n", s[1], s[0]);
					else printf("%c%c\n", s[0], s[1]);
			}
		}
		else if (x%8 == 0 && s[0] != '0') printf("%c%c\n", s[0], s[1]);
		else if (y%8 == 0 && s[1] != '0') printf("%c%c\n", s[1], s[0]);
		else printf("-1\n");
		return 0;
	}


	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j && mp[i+'0'] >= 2) {}
			else if (i == j) continue;
			if (mp[i+'0'] && mp[j+'0']) {}
			else continue;
			for (int k = 0; k < 10; k++) {
				if (k == i && k == j) {
					if (mp[k+'0'] >= 3) {}
					else continue;
				}
				else if (k == i) {
					if (mp[k+'0'] >= 2) {}
					else continue;
				}
				else if (k == j) {
					if (mp[k+'0'] >= 2) {}
					else continue;
				}
				else if (mp[k+'0']) {}
				else continue;
				int y = i*100 + j*10 + k;
				if (y%8 == 0) {
					if (n == 3) {
						if (y >= 100) {
							string aux = to_string(y);
							if (best == "-1") best = aux;
							else best = min(best, aux);
						}
					}
					work(i, j, k);
				}
			}
		}
	}

	cout << best << endl;
	return 0;
}