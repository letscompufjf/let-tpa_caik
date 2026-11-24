#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<string> vet(n);

    for(int i = 0; i < n; i ++)
    {
        cin >> vet[i];
    }

    for(int i = 0; i < n; i ++)
    {
        if(vet[i].size() > 10)
            cout << vet[i][0] << vet[i].substr(1, (vet[i].size() - 2)).size() << vet[i][(vet[i].size() - 1)] << endl; 
        else
            cout << vet[i] << endl;
    }

    return 0;
}