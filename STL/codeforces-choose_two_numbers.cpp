#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n; cin >> n;
    vector<int> a(n);

    for(int &x : a) cin >> x;

    int m; cin >> m;
    vector<int> b(m);

    for(int &x : b) cin >> x;

    cout << *max_element(a.begin(), a.end()) << " " << *max_element(b.begin(), b.end()) << endl;

    return(0);
}
