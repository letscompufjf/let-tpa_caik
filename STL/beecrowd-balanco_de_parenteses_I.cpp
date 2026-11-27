#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string linha;

    while(getline(cin , linha))
    {
        stack<char> st;
        bool ok = true;

        for (char c : linha)
        {
            if( c == '(')
            {
                st.push(c);
            } 
            else if (c == ')')
            {
                if (st.empty())
                {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()) ok = false;
        
        cout << (ok ? "correct" : "incorrect") << '\n';
    }

    return 0;
}   