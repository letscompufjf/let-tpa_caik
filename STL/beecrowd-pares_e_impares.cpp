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

    vector<int> pares, impares;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;

        if(x % 2 == 0)
            pares.push_back(x);
        else
            impares.push_back(x);
    }

    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end(), greater<>());

    for(int i = 0; i < (int)pares.size(); i++)
        cout << pares[i] << endl;

    for(int i = 0; i < (int)impares.size(); i++)
        cout << impares[i] << endl;

    return(0);
}
