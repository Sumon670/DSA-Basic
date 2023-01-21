//tc=O(n*m) & sc = O(n*m)
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;
        TrieNode(char ch){
            data = ch;
            for (int i=0; i<26; i++){
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie (char ch){
            root = new TrieNode(ch);
        }
        void InsertUtil(TrieNode* root, string word){
            //base case
            if (word.length() == 0){
                root->isTerminal = true;
                return;
            }
            int index = word[0]-'a'; //assumption words in caps
            TrieNode* child;
            //present
            if (root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                //absent
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }
            //recursion
            InsertUtil(child,word.substr(1));
        }
        void InsertWord (string word){
            InsertUtil(root,word);
        }
        void lcp (string str, string &ans){
            for (int i=0; i<str.length();i++){
                char ch = str[i];
                if (root->childCount == 1){
                    ans.push_back(ch);
                    //age bara dho
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else{
                    break;
                }
                if (root->isTerminal){
                    break;
                }
            }
        }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie* t = new Trie('\0');
    //insert all strings
    for (int i=0; i<n; i++){
        t->InsertWord(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first,ans);
    return ans;
}

//tc=O(n*m) and sc=O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    //for traversing all the characters of the first string
    for (int i=0; i<arr[0].size();i++){
        char c = arr[0][i];
        bool match = true;
        //for comparing other string
        for (int j=0; j<n; j++){
            //not match
            if (arr[j].size()<i || c != arr[j][i]){
                match = false;
                break;
            }
        }
        if (match == false){
            break;
        }
        else{
            ans.push_back (c);
        }
    }
    return ans;
}


