#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 32416187567
#define cte 10002
#define MAX ULLONG_MAX


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
        
    int n,k;
    cin>>n>>k;

    if(k%2==0){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)cout<<'.';
        cout<<endl;
        cout<<'.';
        for(int i=0;i<k/2;i++)cout<<"#";
        for(int i=k/2+1;i<n;i++)cout<<'.';
        cout<<endl;
        cout<<'.';
        for(int i=0;i<k/2;i++)cout<<"#";
        for(int i=k/2+1;i<n;i++)cout<<'.';
        cout<<endl;
        for(int i=0;i<n;i++)cout<<'.';
        cout<<endl;
    }

    if(k%2==1){
        if(k==(n-2)){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
            cout<<'.';
            for(int i=0;i<k;i++)cout<<"#";
            for(int i=k+1;i<n;i++)cout<<'.';
            cout<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
        }
        else if(k==1){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
            for(int i=0;i<n/2;i++)cout<<'.';
            cout<<'#';
            for(int i=0;i<n/2;i++)cout<<'.';
            cout<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
        }
        else if(k>=5){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
            cout<<'.';
            for(int i=0;i<(k+1)/2;i++)cout<<"#";
            for(int i=k/2+1;i<n-1;i++)cout<<'.';
            cout<<endl;
            cout<<".#.";
            for(int i=0;i<k/2-1;i++)cout<<'#';
            for(int i=k/2+1;i<n-1;i++)cout<<'.';
            cout<<endl;
            for(int i=0;i<n;i++)cout<<'.';
            cout<<endl;
        }
        else cout<<"NO"<<endl;

    }
    
    return 0;

}
