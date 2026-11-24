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
    int p; cin >> p;

    while(p--)
    {
        string palavra; cin >> palavra;

        bool ordenada = true;
        for(int i = 1; i < (int)palavra.size(); i++)
        {
            if(tolower((unsigned char)palavra[i]) <= tolower((unsigned char)palavra[i - 1]))
            {
                ordenada = false;
                break;
            }
        }

        cout << palavra << ": " << (ordenada ? 'O' : 'N') << endl;
    }

    return(0);
}
