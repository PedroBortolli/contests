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
	int n;
	scanf("%d", &n);
	scanf(" %s", s);
	int ans = 0;
	string ret = "AA";
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			char aux[3];
			aux[0] = i;
			aux[1] = j;
			aux[2] = 0;
			string fnd = aux;
			//cout << fnd << endl;
			int cont = 0;
			for (int k = 0; k < n-1; k++) {
				char aux2[3];
				aux2[0] = s[k];
				aux2[1] = s[k+1];
				aux2[2] = 0;
				string lul = aux2;
				//cout << lul << endl;
				if (fnd == lul) {
					cont++;
				}
			}
			if (cont > ans) {
				ans = cont;
				ret = fnd;
			}
		}
	}	
	cout << ret << endl;
	return 0;
}