#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> vet(n, 0);
    
    for(int i = 0; i < n; i ++)
    {
        cin >> vet[i];
    }

    auto it = min_element(vet.begin(), vet.end());

    cout << "Menor valor: " << *it << "\n";
    cout << "Posição: " << (it - vet.begin()) << endl;

    return 0;
}