#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll solve_flor( ll n ) {
    // Encontra a maior potencia de 3 menor ou igual a n
    ll pot = 1;
    while ( pot * 3 <= n ) {
        pot *= 3;
    }

    ll x = n - pot;

    // Primeira metade do bloco [pot, 2 * pot)
    if ( x < pot ) {
        return 2 * pot + x;
    }

    // Segunda metade do bloco [2 * pot, 3 * pot)
    ll y = x - pot;
    return 3 * pot + 3 * y;
}

int main(){ _
    ll n; cin >> n;

    // Calcula e imprime a quantidade de sementes devolvidas apos uma oferenda
    cout << solve_flor( n ) << endl;

    return 0;
}