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

void build_order(int l, int r, vector<int> &ans)
{
    // Intervalo vazio nao possui posicoes para inserir
    if(l > r)
        return;

    // Escolhe o meio para manter sub-blocos equilibrados
    int mid = l + (r - l) / 2;
    ans.pb(mid);

    // Preenche recursivamente a esquerda e a direita
    build_order(l, mid - 1, ans);
    build_order(mid + 1, r, ans);
}

int main()
{ _
    int n, c; cin >> n >> c;

    // Calcula o custo minimo interno para formar um bloco contiguo de tamanho k
    vector<ll> g(c + 1, 0);
    for(int k = 2; k <= c; k++)
    {
        int a = (k - 1) / 2;
        int b = (k - 1) - a;
        g[k] = g[a] + g[b] + a + b;
    }

    // Numero maximo de blocos separaveis por ao menos 1 espaco vazio
    int m = min(c, n - c + 1);

    // Divide c copos em m blocos o mais equilibrados possivel
    int base = c / m;
    int rem = c % m;

    ll total_cost = 0;
    vector<int> blocks(m);
    for(int i = 0; i < m; i++)
    {
        blocks[i] = base + (i < rem ? 1 : 0);
        total_cost += g[blocks[i]];
    }

    // Monta a sequencia de posicoes deixando pelo menos 1 slot livre entre blocos
    vector<int> ans;
    ans.reserve(c);

    int cur = 1;
    for(int i = 0; i < m; i++)
    {
        int sz = blocks[i];
        build_order(cur, cur + sz - 1, ans);
        cur += sz + 1;
    }

    cout << total_cost << endl;
    for(int i = 0; i < (int)ans.size(); i++)
    {
        if(i > 0)
            cout << ' ';

        cout << ans[i];
    }
    cout << endl;

    return(0);
}
