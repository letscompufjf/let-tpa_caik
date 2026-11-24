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

// Função para verificar se uma dada matriz transformada do pergaminho é válida no terreno
bool isValid(const vector<string> &terreno, const vector<string> &pergaminho_trans)
{
    int tn = (int)terreno.size();
    int tm = (int)terreno[0].size();
    int pn = (int)pergaminho_trans.size();
    int pm = (int)pergaminho_trans[0].size();

    // Se as dimensões não coincidirem, esta orientação não se alinha ao terreno
    if(tn != pn || tm != pm)
        return false;

    // Verifica se cada dragão ('.') do pergaminho cai em uma célula livre ('.') do terreno
    for(int i = 0; i < tn; i++)
    {
        for(int j = 0; j < tm; j++)
        {
            if(pergaminho_trans[i][j] == '.')
            {
                if(terreno[i][j] == '#')
                    return false; // Caiu em um obstáculo
            }
        }
    }

    return true;
}

// Gera uma rotação de 90 graus no sentido horário
vector<string> rotate90(const vector<string> &mat)
{
    int n = (int)mat.size();
    int m = (int)mat[0].size();
    vector<string> rot(m, string(n, ' '));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            rot[j][n - 1 - i] = mat[i][j];
    }

    return rot;
}

// Gera uma reflexão horizontal (virar o pergaminho ao contrário)
vector<string> flipHorizontal(const vector<string> &mat)
{
    int n = (int)mat.size();
    int m = (int)mat[0].size();
    vector<string> flipped = mat;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            flipped[i][j] = mat[i][m - 1 - j];
    }

    return flipped;
}

int main()
{ _
    int n, m;
    if(!(cin >> n >> m))
        return(0);

    vector<string> terreno(n);
    for(int i = 0; i < n; i++)
        cin >> terreno[i];

    // O pergaminho inicial é idêntico ao terreno fornecido
    vector<string> pergaminho = terreno;

    int valid_ways = 0;

    // Geramos as 4 rotações normais (sem virar)
    vector<string> atual = pergaminho;
    for(int r = 0; r < 4; r++)
    {
        if(isValid(terreno, atual))
            valid_ways++;

        atual = rotate90(atual);
    }

    // Geramos as 4 rotações após virar o pergaminho (reflexão horizontal)
    atual = flipHorizontal(pergaminho);
    for(int r = 0; r < 4; r++)
    {
        if(isValid(terreno, atual))
            valid_ways++;

        atual = rotate90(atual);
    }

    cout << valid_ways << endl;

    return(0);
}
