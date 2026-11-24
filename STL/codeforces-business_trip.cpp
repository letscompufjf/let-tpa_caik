#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int k;cin >> k;
    vector<int> a(12);
    for(auto &x : a)cin >> x;
    sort(a.rbegin(),a.rend());
    for(int i = 0;i < 13;i++){
        if(k <= 0){
            cout << i << endl;
            return 0;
        }
        k -= a[i];
    }
    cout << -1 << endl;
    return 0;
}

