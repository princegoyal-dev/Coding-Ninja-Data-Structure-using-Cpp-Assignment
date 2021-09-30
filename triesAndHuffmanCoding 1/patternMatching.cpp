#include <bits/stdc++.h>

using namespace std;

class TrieNode {
    public :

        char data;
        TrieNode **children;

        TrieNode(char data) {
            this -> data = data;
            children = new TrieNode*[26];
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
};

class Trie {
    TrieNode *root;
    public :

        Trie() {
            root = new TrieNode('\0');
        }
        void insertWord(TrieNode *root, string word) {
            if(word.size() == 0) {
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
            for(int i = 0; i < word.size(); i++) {
                insertWord(root, word.substr(i));
            }
        }
        
        bool search(TrieNode *root, string word) {
            if(word.length() == 0) {
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

};
int main() {
    Trie root;

    int size;
    cin >> size;

    for(int i = 0; i < size; i++) {
        string str;
        cin >> str;
        root.insertWord(str);
    }

    string word;
    cin >> word;
    bool result = root.search(word);
    cout << boolalpha << result;

    return 0;
}