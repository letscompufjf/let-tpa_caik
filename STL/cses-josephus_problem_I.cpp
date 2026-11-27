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
    
    queue<int> q;
    
    for(int i = 1; i <= n; i ++) q.push(i);    
    
    while(!q.empty()) 
    { 
        q.push(q.front());                 
        q.pop();   
    
        cout << q.front() << ' ';          
    
        q.pop();    
    }    
    
    cout << endl;    
    
    return 0;
}