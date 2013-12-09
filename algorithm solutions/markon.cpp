#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 500000;

int n, m, x;
vector<int> graph[MAXN + 1];
bool notgood[MAXN + 1];
bool visited[MAXN + 1];
int neighbours[MAXN + 1];
int cost[MAXN + 1];
vector<int> solution;

void bfs(int start)
{
    visited[start] = true;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()) {
        int node = Q.front();
        for(auto &x: graph[node]) {
            neighbours[x]--;
        }
        if(neighbours[node] < cost[node] || !cost[node]) { //good
            for(auto &x: graph[node]){
                if(!visited[x]){
                    Q.push(x);
                    visited[x] = true;
                }
            }
        }
        else { //not good
            notgood[node] = true;
        }
        for(auto &x: graph[node]){
            if(notgood[x] && neighbours[x] < cost[x]) { //now's all good
                notgood[x] = false;
                for(auto &y: graph[x]){
                    if(!visited[y]){
                        Q.push(y);
                        visited[y] = true;
                    }
                }
            }
        }

        solution.push_back(node);
        Q.pop();
    }
}
int main()
{
    ifstream fin("markon.in");
    ofstream fout("markon.out");
    
    fin >> n >> m >> x;
    
    for (int i = 0; i < n; i ++) {
        fin >> cost[i+1];
    }
    for (int i = 0; i < m; i ++) {
        int x, y;
        fin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < n; i ++) {
        neighbours[i+1] = graph[i+1].size();
    }

    bfs(x);
    
    fout << solution.size() << '\n';
    
    // for_each(solution.begin(), solution.end(), [&](int node) {
    //     fout << node << '\n';
    // } );
    for(auto &node: solution) {
        fout << node << '\n';
    }
    return 0;
}

