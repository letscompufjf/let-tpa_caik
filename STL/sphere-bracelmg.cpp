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
    int t;cin >> t;
    while(t--){
        string a, b;cin >> a >> b;
        string c; while(c.size() < a.size() + b.size()) c += b;
        string d = b;
        reverse(d.begin(), d.end());
        int e = c.size() * 2;
        while(c.size() < e) c += d;
        cout << (c.find(a) != string::npos ? 'S' : 'N') << endl;
    }
    return 0;
}
