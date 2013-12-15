#define nume "carte"

#ifndef INFOARENA
#define fisier "../ONIS/" nume
#define DBG
#else
#define fisier nume
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

ifstream f(fisier".in");
ofstream g(fisier".out");

#ifdef DBG
#define g cout
#endif

using namespace std;

#include <unordered_set>
#include <sstream>

const int MAX_LENGTH = 3005;

int n, dp[MAX_LENGTH];
string s;
unordered_set <string> Hash;

#define BUF_SIZE 4096
char buf[BUF_SIZE];
int pos = BUF_SIZE;

inline char getChar(FILE *f) {
    if (pos == BUF_SIZE) {
        fread(buf, 1, BUF_SIZE, f);
        pos = 0;
    }
    return buf[pos++];
}

inline int read(FILE *f) {
    int result = 0;
    char c;
    do {
        c = getChar(f);
    } while (!isdigit(c));
    
    do {
        
        result = 10 * result + c - '0';
        c = getChar(f);
    } while (isdigit(c));
    
    return result;
}


void init() {
    Hash.clear();
}

void read() {
    f >> s;
    f >> n;
    
    for (int i = 1; i <= n; i++) {
        string word;
        f >> word;
        Hash.insert (word);
    }
    
    for (int i = 0; i < s.size(); i++)
        dp[i + 1] = i + 1;
}

void solve() {
    for (int i = 0; i < s.size(); i++) {
        string tmp;
        
        for (int j = i; j < s.size(); j++) {
            tmp += s[j];
            if (Hash.find (tmp) != Hash.end())
                dp[j + 1] = min (dp[i], dp[j + 1]);
            dp[j + 1] = min (dp[j + 1], dp[j] + 1);
        }
    }
    
    g << dp[s.size()] << '\n';
}

int main() {
    int Teste;
    
    f >> Teste;
    while (Teste--) {
        init();
        read();
        solve();
    }
    
    return 0;
}