#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matriz(5, vector<int>(5, 0));
    int n = -1, m = -1;

    for(int i = 0; i < 5; i ++)
    {
        for(int j = 0; j < 5; j ++)
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

    return 0;
}