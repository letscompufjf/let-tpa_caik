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

    vector<pair<int, int>> bota(61, {0, 0});

    for(int i = 0; i < n; i ++)
    {
        int tamanho;
        char pe;

        cin >> tamanho >> pe;

        if(pe == 'E') bota[tamanho].f ++;
        else bota[tamanho].s ++;
    }

    int pares = 0;

    for(const auto& [esq, dir] : bota)
        pares += min(esq, dir);

    cout << pares << endl;

    return(0);
}