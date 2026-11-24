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

    vector<string> vet(n);
    for(int i = 0; i < n; i++)
        cin >> vet[i];

    for(int i = 0; i < n; i++)
    {
        if(vet[i].size() > 10)
            cout << vet[i][0] << vet[i].substr(1, vet[i].size() - 2).size() << vet[i][vet[i].size() - 1] << endl;
        else
            cout << vet[i] << endl;
    }

    return(0);
}
