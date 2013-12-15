//#define DBG

#include <iostream>
using namespace std;

#define Cell pair<int,int>
#define x first
#define y second

const int K_MAX = 10;
const int dx[] = {0,1,0,1},
          dy[] = {0,0,1,1};

int table[1<<K_MAX][1<<K_MAX];
int k;
int tromino = 0;

void cover(Cell top, Cell missing, int size)
{
    if (size == 2) {
        for(int i = 0; i < 4; ++i){
            if(top.x + dx[i] != missing.x || top.y + dy[i] != missing.y)
                table[top.x + dx[i]][top.y + dy[i]] = tromino;
        }
        
        tromino++;
        
        return;
    }
    if (missing.x < top.x + size/2) {
        if(missing.y < top.y + size/2) {
            Cell half = make_pair(top.x + size/2, top.y + size/2);
            
            table[half.x][half.y] = table[half.x - 1][half.y] = table[half.x][half.y - 1] = tromino++;
            
            cover(top, missing, size/2);
            cover(make_pair(top.x,half.y), make_pair(half.x - 1, half.y), size/2);
            cover(make_pair(half.x, top.y), make_pair(half.x, half.y - 1), size/2);
            cover(make_pair(half.x, half.y), make_pair(half.x, half.y), size/2);
        }
        else {
            Cell half = make_pair(top.x + size/2, top.y + size/2);
            
            table[half.x][half.y] = table[half.x - 1][half.y - 1] = table[half.x][half.y - 1] = tromino++;
            
            cover(top, make_pair(half.x - 1, half.y - 1), size/2);
            cover(make_pair(top.x,half.y), missing, size/2);
            cover(make_pair(half.x, top.y), make_pair(half.x, half.y - 1), size/2);
            cover(make_pair(half.x, half.y), make_pair(half.x, half.y), size/2);
        }
    }
    else {
        if(missing.y < top.y + size/2){
            Cell half = make_pair(top.x + size/2, top.y + size/2);
            
            table[half.x][half.y] = table[half.x - 1][half.y - 1] = table[half.x - 1][half.y] = tromino++;
            
            cover(top, make_pair(half.x - 1, half.y - 1), size/2);
            cover(make_pair(top.x,half.y), make_pair(half.x - 1, half.y), size/2);
            cover(make_pair(half.x, top.y), missing, size/2);
            cover(make_pair(half.x, half.y), make_pair(half.x, half.y), size/2);        }
        else {
            Cell half = make_pair(top.x + size/2, top.y + size/2);
            
            table[half.x][half.y - 1] = table[half.x - 1][half.y - 1] = table[half.x - 1][half.y] = tromino++;
            
            cover(top, make_pair(half.x - 1, half.y - 1), size/2);
            cover(make_pair(top.x,half.y), make_pair(half.x - 1, half.y), size/2);
            cover(make_pair(half.x, top.y), make_pair(half.x, half.y - 1), size/2);
            cover(make_pair(half.x, half.y), missing, size/2);        }
    }
}
int main()
{
    cout<<"k: ";cin>>k;
    cout<<"missing cell: ";
    Cell missing;
    cin>>missing.x>>missing.y;
    missing.x--;
    missing.y--;
    
    memset(table, -1, sizeof(table));
    
    table[missing.x][missing.y] = tromino++;
    
    cover(make_pair(0,0), missing, 1<<k);
    
    for (int i = 0; i < (1<<k); i ++) {
        for (int j = 0; j < (1<<k); j ++) {
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}