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

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // Mantem o melhor valor de (a[i] - i) a esquerda do predio atual
    ll best_left = a[0] - 0;
    ll ans = 0;

    for(int j = 1; j < n; j++)
    {
        ans = max(ans, (a[j] + j) + best_left);
        best_left = max(best_left, a[j] - j);
    }

    cout << ans << endl;

    return(0);
}
