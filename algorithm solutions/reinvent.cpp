#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 500000;

int n, m, x;
vector<int> graph[MAXN + 1];
bool visited[MAXN + 1];
int from[MAXN + 1];
int dist[MAXN + 1];
int main()
{
    ifstream fin("reinvent.in");
    ofstream fout("reinvent.out");
    
    fin >> n >> m >> x;
    
    for (int i = 0; i < m; i ++) {
        int x, y;
        fin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> Q;
    for (int i = 0; i < x; i ++) {
        int x;
        fin >> x;
        Q.push(x);
        from[x] = x;
    }
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(auto &x: graph[node]) {
            if(!from[x]){
                Q.push(x);
                from[x] = from[node];
                dist[x] = dist[node] + 1;
            }
            else if(from[x] != from[node]){ //answer
                fout << dist[x] + dist[node] + 1 << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}

