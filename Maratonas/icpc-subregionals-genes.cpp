#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Ocorrencia {
    int ini;
    int fim;
    int id;
};

struct No {
    int prox[4];
    int link;
    int prox_match;
    vector<int> genes;

    No(){
        fill(prox, prox + 4, 0);
        link = 0;
        prox_match = 0;
    }
};

int char_to_idx(char ch){
    if(ch == 'A') return 0;
    if(ch == 'C') return 1;
    if(ch == 'G') return 2;
    return 3;
}

int n_seg;
vector<int> seg;

void build_seg(int n){
    n_seg = n;
    seg.assign(4 * n + 5, INF);
}

void update_seg(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] = min(seg[p], val);
        return;
    }
    int mid = (l + r) / 2;
    if(idx <= mid) update_seg(2 * p, l, mid, idx, val);
    else update_seg(2 * p + 1, mid + 1, r, idx, val);
    seg[p] = min(seg[2 * p], seg[2 * p + 1]);
}

int query_seg(int p, int l, int r, int ql, int qr){
    if(ql > r || qr < l) return INF;
    if(ql <= l && r <= qr) return seg[p];
    int mid = (l + r) / 2;
    return min(query_seg(2 * p, l, mid, ql, qr), query_seg(2 * p + 1, mid + 1, r, ql, qr));
}

int main(){ _
    string t; cin >> t;
    int g; cin >> g;

    vector<No> trie(1);
    vector<int> tam_gene(g + 1, 0);

    for(int id = 1; id <= g; id++){
        string gene; cin >> gene;
        tam_gene[id] = (int)gene.size();

        int u = 0;
        for(char ch : gene){
            int c = char_to_idx(ch);
            if(trie[u].prox[c] == 0){
                trie[u].prox[c] = (int)trie.size();
                trie.pb(No());
            }
            u = trie[u].prox[c];
        }
        trie[u].genes.pb(id);
    }

    queue<int> fila;
    for(int c = 0; c < 4; c++){
        int v = trie[0].prox[c];
        if(v != 0){
            trie[v].link = 0;
            trie[v].prox_match = 0;
            fila.push(v);
        }
    }

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        int lk = trie[u].link;
        if(!trie[lk].genes.empty()){
            trie[u].prox_match = lk;
        } else {
            trie[u].prox_match = trie[lk].prox_match;
        }

        for(int c = 0; c < 4; c++){
            int v = trie[u].prox[c];
            if(v != 0){
                trie[v].link = trie[lk].prox[c];
                fila.push(v);
            } else {
                trie[u].prox[c] = trie[lk].prox[c];
            }
        }
    }

    int n = (int)t.size();
    vector<Ocorrencia> occs;

    int u = 0;
    for(int i = 0; i < n; i++){
        int c = char_to_idx(t[i]);
        u = trie[u].prox[c];

        int temp = u;
        while(temp != 0){
            for(int id : trie[temp].genes){
                int fim = i + 1;
                int ini = fim - tam_gene[id] + 1;
                if(ini >= 1){
                    occs.pb({ini, fim, id});
                }
            }
            if(!trie[temp].genes.empty() && temp != u){
                // Ja processamos os genes deste no
            }
            temp = trie[temp].prox_match;
        }
    }

    int q; cin >> q;
    struct Consulta {
        int l;
        int r;
        int idx;
    };
    vector<Consulta> consultas(q);
    for(int i = 0; i < q; i++){
        cin >> consultas[i].l >> consultas[i].r;
        consultas[i].idx = i;
    }

    sort(occs.begin(), occs.end(), [](const Ocorrencia &a, const Ocorrencia &b){
        return a.ini > b.ini;
    });

    sort(consultas.begin(), consultas.end(), [](const Consulta &a, const Consulta &b){
        return a.l > b.l;
    });

    build_seg(n);
    vector<int> resp(q, -1);

    int ptr = 0;
    int m = (int)occs.size();
    for(const auto &cons : consultas){
        while(ptr < m && occs[ptr].ini >= cons.l){
            update_seg(1, 1, n, occs[ptr].fim, occs[ptr].id);
            ptr++;
        }
        int best = query_seg(1, 1, n, 1, cons.r);
        if(best != INF){
            resp[cons.idx] = best;
        }
    }

    for(int i = 0; i < q; i++){
        cout << resp[i] << endl;
    }

    return 0;
}