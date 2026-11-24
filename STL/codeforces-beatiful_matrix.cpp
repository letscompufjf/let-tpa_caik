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
    vector<vector<int>> matriz(5, vector<int>(5, 0));
    int n = -1, m = -1;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> matriz[i][j];

            if(matriz[i][j] == 1)
            {
                n = i;
                m = j;
            }
        }
    }

    cout << (abs(n - 2) + abs(m - 2)) << endl;

    return(0);
}
