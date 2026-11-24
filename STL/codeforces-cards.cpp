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
    string str(n, ' ');

    for(char &x : str) cin >> x;

    int zero = count(str.begin(), str.end(), 'z');
    int one = count(str.begin(), str.end(), 'n');

    while(one)
    {
        cout << "1 ";
        one--;
    }

    while(zero)
    {
        cout << "0 ";
        zero--;
    }

    cout << endl;
    
    return(0);
}