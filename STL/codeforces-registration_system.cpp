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

    map<string, int> reg;

    for(int i = 0; i < n; i ++)
    {
        string nome; cin >> nome;

        reg[nome] ++;

        if(reg[nome] > 1)
        {
            string nnome = nome + to_string(reg[nome] - 1);

            reg[nnome];

            cout << nnome;
        }
        else
            cout << "OK";
        
        cout << endl;   
    }

    return(0);
}