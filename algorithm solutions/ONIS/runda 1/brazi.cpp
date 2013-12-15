#include <fstream>
#include <cstring>
#include <string>
#include <map>
 
using namespace std;
 
ifstream f("brazi.in");
ofstream g("brazi.out");
 
const int MAX_N = 15;
 
int n, ls[MAX_N], rs[MAX_N], root[MAX_N];
string s;
 
map <string, int> Hash;
 
void init() {
    memset (root, 0, sizeof(root));
    memset (ls, 0, sizeof(ls));
    memset (rs, 0, sizeof(rs));
    memset (root, 0, sizeof(root));
    s.clear();
}
 
void dfs (int nod) {
    if (!nod)
        return;
     
    if (ls[nod] && rs[nod])
        s += '3';
    else if (ls[nod] && !rs[nod])
        s += '1';
    else if (!ls[nod] && rs[nod])
        s += '2';
    else if (!ls[nod] && !rs[nod])
        s += '0';
     
    dfs (ls[nod]);
    dfs (rs[nod]);
}
 
void go() {
    int radacina;
     
    f >> n;
     
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
         
        f >> a >> b >> c;
        if (c == 0)
            ls[a] = b;
        else
            rs[a] = b;
        root[b] = 1;
    }
     
    for (int i = 1; i <= n; i++)
        if (!root[i])
            radacina = i;
         
    dfs (radacina);
     
    if (Hash.find (s) == Hash.end()) {
        g << 0 << '\n';
        Hash[s] = 1;
    } else {
        g << Hash[s] << '\n';
        Hash[s]++;
    }
}
 
int main() {
    int T;
     
    f >> T;
    for (int i = 1; i <= T; i++) {
        init();
        go();
    }
     
    return 0;
}