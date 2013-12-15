#define nume "pufu"
 
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
 
using namespace std;
 
ifstream fin(fisier".in");
ofstream fout(fisier".out");
 
#ifdef DBG
#define fout cout
#endif
 
unordered_map<string,int> H;
 
 
int main()
{
    int n,t;
    fin >> t;
    for(;t;--t){
        fin>>n;
        H.clear();
        for(int i=0;i<n;++i){
            string s;
            fin>>s;
            if(H.find(s) == H.end()){
                H[s] = 1;
            }
            else H[s]++;
        }
        fout<<H["ciocolata"]<<' '<<H["cascaval"]<<' '<<H["sare"]<<'\n';
    }
     
     
    return 0;
}
