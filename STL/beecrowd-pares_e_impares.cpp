#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> pares, impares;
    
    for(int i = 0; i < n; i ++)
    {
        int x; cin >> x;

        if(x % 2 == 0)
            pares.push_back(x);
        else
            impares.push_back(x);
    }

    sort(pares.begin(), pares.end());
    sort(impares.begin(), impares.end(), greater<>());

    for(int i = 0; i < pares.size(); i ++)
        cout << pares[i] << endl;

    for(int i = 0; i < impares.size(); i ++)
        cout << impares[i] << endl;

    return 0;
}