class TrieNode{
public:
   TrieNode *child[26];
   bool isWord;
   TrieNode(){
    isWord = false;
    for(auto &a : child) a = nullptr;
   }
};
class Trie {
    TrieNode * root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * node = root;
        for(char c : word){
            int index = c - 'a';
            if(!node ->child[index]){
                node -> child[index] = new TrieNode();
            }
            node = node -> child[index];
        }
        node->isWord = true;
    }
    
    bool search(string word,bool prefix = false) {
        TrieNode *node = root;
        for(auto &a : word){
            int i = a - 'a';
            if(!node->child[i]) return false;
            node = node->child[i];
        }
        if(prefix == false) return node->isWord;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */