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

typedef pair<ll, ll> pt;

void solve()
{
    string str; cin >> str;

    // Guarda segmentos nao-direcionados ja visitados como {ponto_menor, ponto_maior}
    set<pair<pt, pt>> visited;

    ll x = 0, y = 0;
    ll ans = 0;

    for(char ch : str)
    {
        ll nx = x;
        ll ny = y;

        if(ch == 'N')
            ny++;
        else if(ch == 'S')
            ny--;
        else if(ch == 'E')
            nx++;
        else if(ch == 'W')
            nx--;

        pt p1 = {x, y};
        pt p2 = {nx, ny};

        if(p2 < p1)
            swap(p1, p2);

        pair<pt, pt> seg = {p1, p2};

        // 5 segundos na primeira passagem pelo segmento, 1 segundo se ja visitado
        if(visited.find(seg) == visited.end())
        {
            visited.insert(seg);
            ans += 5;
        }
        else
            ans += 1;

        x = nx;
        y = ny;
    }

    cout << ans << endl;
}

int main()
{ _
    int t; cin >> t;

    while(t--)
        solve();

    return(0);
}
