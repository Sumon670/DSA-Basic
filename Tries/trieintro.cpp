//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char ch){
            data = ch;
            for (int i=0; i<26; i++){
                children[i]=NULL;
            }
            isTerminal = false;
        }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void InsertUtil(TrieNode* root, string word){
        //base case
        if (word.length() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'A'; //assumption words in caps
        TrieNode* child;
        //present
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //recursion
        InsertUtil(child,word.substr(1));
    }
    void InsertWord (string word){
        InsertUtil(root,word);
    } 
    void RemoveUtill (TrieNode* root, string word){
        //base case
        if (word.length()==0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        //present
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            root->isTerminal = false;
            return;
        } 
        RemoveUtill(child,word.substr(1));
    }
    void RemoveWord (string word){
        RemoveUtill (root,word);
    }
    bool searchUtill(TrieNode* root, string word){
        //base case
        if (word.length()==0){
            return root->isTerminal;
        }
        TrieNode* child;
        int index = word[0]-'A';
        //present
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            return false;
        }
        //recursion
        return searchUtill(child,word.substr(1));
    }
    bool searchWord (string word){
        return searchUtill(root,word);
    }
};
int main()
{
    Trie *t = new Trie();
    t->InsertWord("ARM");
    t->InsertWord("DO");
    t->InsertWord("TIME");
    cout<<"Present or not "<<t->searchWord("DO")<<endl;
    t->RemoveWord("DO");
    cout<<"Present or not "<<t->searchWord("DO")<<endl;
    return 0;
}