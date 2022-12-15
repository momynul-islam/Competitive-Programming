#include <bits/stdc++.h>

using namespace std;

class node{
public:
    bool isTerminal;
    node *child[26];
    node(){
        isTerminal = false;
        for(int i=0; i<26; i++) child[i] = NULL;
    }
};

void add(string word,node *root){
    int n = word.size();
    for(int i=0; i<n; i++){
        if(root->child[word[i] - 'A'] == NULL)
            root->child[word[i] - 'A'] = new node();
        root = root->child[word[i] - 'A'];
    }
    root->isTerminal = true;
}

bool search(string word,node *root){
    int n = word.size();
    for(int i=0; i<n; i++){
        if(root->child[word[i] - 'A'] == NULL) return false;
        root = root->child[word[i] - 'A'];
    }
    return root->isTerminal;
}

int main(){
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NO");
    dict.push_back("NOT");
    dict.push_back("NEWS");
    dict.push_back("NEW");

    node *root = new node();
    for(int i=0; i<dict.size(); i++){
        add(dict[i],root);
    }

    string s;
    cin >> s;
    while(s != "Q"){
        cout << (bool) search(s,root) << endl;
        cin >> s;
    }

}
