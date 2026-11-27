#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n);
    int total = 0;

    for(int& x : a) 
    {
        cin >> x;
        total += x;
    }

    sort(a.rbegin(), a.rend());

    int eu = 0, quant = 0;

    for(int i = 0; i < n; i ++)
    {
        eu += a[i];
        quant ++;

        if(eu > total - eu)
            break;
    }
    
    cout << quant << endl;

    return 0;
}