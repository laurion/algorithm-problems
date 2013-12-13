#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class TrieNode {
public:
    int words;
    int prefixes;
    string name;
    map<char, TrieNode*> edges;

    TrieNode() {
        words = 0;
        prefixes = 0;
    }

    bool isWord() {
        return !name.empty();
    }
    void insert(char* word, const char* full_name);
    void query(char* word, string& result);
};
void TrieNode::insert(char* word, const char* full_name)
{
    if (!*word) {
        name = full_name;
        return;
    }
    *word = tolower(*word);
    prefixes++;
    if (edges.find(*word) == edges.end()) {
        edges[*word] = new TrieNode();
    }
    edges[*word]->insert(word+1, full_name);
}
void TrieNode::query(char *word, string& result)
{
    if(!*word) {
        if(isWord()) {
            result = name;
        }
        else {
            edges.begin()->second->query(word, result);
        }
        return;
    }
    *word = tolower(*word);
    if (edges.find(*word) == edges.end()) {
        result = "";
        return;
    }
    if (isWord()) result = name;
    edges[*word]->query(word + 1, result);
}

void typeahead(const vector<string> &usernames, const vector<string> &queries) {
    TrieNode* trie = new TrieNode();
    for (vector<string>::const_iterator it = usernames.begin(), stop = usernames.end(); it != stop; ++it) {
        char word[it->size() + 1];
        strcpy(word, it->c_str());
        trie->insert(word, it->c_str());
    }
    for (vector<string>::const_iterator it = queries.begin(), stop = queries.end(); it != stop; ++it) {
        char word[it->size() + 1];
        strcpy(word, it->c_str());
        string result;
        trie->query(word, result);
        if (result.empty()) {
            cout << -1 << '\n';
        } else {
            cout << result << '\n';
        }
    }
}

#include <fstream>
#include <time.h>
int main(int argc, const char * argv[])
{
    vector<string> usernames, queries;
    int n, m;
    double beg = clock();
    //freopen("typeahead.in", "r", stdin);
    ifstream fin("typeahead.in");
    fin>>n>>m;
    for (int i = 0; i < n; ++i) {
        string x;
        fin>>x;
        usernames.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        string x;
        fin>>x;
        queries.push_back(x);
    }
    typeahead(usernames, queries);
    cout << (clock()-beg)/1000000;
    return 0;
}

