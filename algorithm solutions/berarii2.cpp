#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 1000000;

int n, m, p;
vector<int> graph[MAXN + 1];
bool visited[MAXN + 1];

void dfs(int node)
{
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    for (auto x: graph[node]) {
        dfs(x);
    }
}
int main()
{
    ifstream fin("berarii2.in");
    ofstream fout("berarii2.out");
    
    fin >> n >> m >> p;
    
    for (int i = 0; i < m; i ++) {
        int x, y;
        fin >> x >> y;
        graph[y].push_back(x);
    }
    
    for (int i = 0; i < p; i ++) {
        int x;
        fin >> x;
        
        dfs(x);
    }
    
    vector<int> solution;
    for (int node = 1; node <= n; node ++) {
        if (!visited[node])
            solution.push_back(node);
    }
    
    fout << solution.size() << '\n';
    
    // for_each(solution.begin(), solution.end(), [&](int node) {
    //     fout << node << '\n';
    // } );
    for(auto &node: solution) {
        fout << node << '\n';
    }
    return 0;
}

