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

struct DSU {
    vector<int> parent;
    vector<int> parity;

    DSU(int n)
    {
        parent.resize(n + 1);
        parity.assign(n + 1, 0);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find_set(int v)
    {
        if(v == parent[v])
            return v;

        return parent[v] = find_set(parent[v]);
    }

    void unite_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);

        if(a != b)
        {
            parent[b] = a;
            parity[a] ^= parity[b];
        }
    }
};

int main()
{ _
    int n, m; cin >> n >> m;

    vector<int> v(n + 2, 0);
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    // Vetor de diferencas modulo 2: cada intervalo [L, R] altera apenas d[L] e d[R + 1]
    DSU dsu(n + 1);
    for(int i = 1; i <= n + 1; i++)
        dsu.parity[i] = v[i] ^ v[i - 1];

    // Conecta os extremos L e R + 1 de cada dispositivo
    for(int i = 0; i < m; i++)
    {
        int l, r; cin >> l >> r;
        dsu.unite_sets(l, r + 1);
    }

    // Cada componente conexa deve ter quantidade par de bits ativos (paridade 0)
    bool ok = true;
    for(int i = 1; i <= n + 1; i++)
    {
        if(dsu.find_set(i) == i && dsu.parity[i] != 0)
        {
            ok = false;
            break;
        }
    }

    if(ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return(0);
}
