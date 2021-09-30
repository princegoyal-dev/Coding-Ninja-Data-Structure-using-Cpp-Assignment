#include <bits/stdc++.h>
#include "trieNode.cpp"

using namespace std;

class Trie {
    TrieNode *root;
    public :
        Trie() {
            root = new TrieNode('\0');
        }
        void insertWord(TrieNode *root, string word) {
            if(word.size() == 0) {
                root -> isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
            TrieNode *child;
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else {
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }
            insertWord(child, word.substr(1));
        }
        
        void insertWord(string word) {
            insertWord(root, word);
        }

        bool search(TrieNode *root, string word) {
            if(word.length() == 0 && root -> isTerminal == true) {
                return true;
            }
            int index = word[0] - 'a';
            if(root -> children[index] != NULL) {
                return search(root -> children[index], word.substr(1));
            } else return false;
        }

        bool search(string word) {
            return search(root, word);
        }

        void remove(TrieNode *root, string word) {
            if(word.size() == 0) {
                root -> isTerminal = false;
                return;
            }
            TrieNode *child;
            int index = word[0] - 'a';
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            } else {
                return;
            }
            remove(child, word.substr(1));

            if(child -> isTerminal == false) {
                for(int i = 0; i < 26; i++) {
                    if(child -> children[i] != NULL) {
                        return;
                    }
                }
                delete child;
                root -> children[index] = NULL;
            }
        }
        void remove(string word) {
            remove(root, word);
        }
};

int main() {
    Trie root;
    
    root.insertWord("prince");
    cout << root.search("prince");
    
    // root.insertWord("goyal");
    cout << root.search("goyal");

    root.remove("prince");
    cout << root.search("prince");
    return 0;
}