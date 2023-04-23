#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// define the node class for the binary tree
class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// define a comparator for the priority queue
class Compare {
public:
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// build the Huffman tree and generate the Huffman code
map<char, string> buildHuffmanTree(map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    map<char, string> huffmanCode;
    stack<pair<Node*, string>> st;
    st.push(make_pair(pq.top(), ""));
        while (!st.empty()) {
        Node* currNode = st.top().first;
        string currCode = st.top().second;
        st.pop();
        if (currNode->left == nullptr && currNode->right == nullptr) {
            huffmanCode[currNode->ch] = currCode;
        } else {
            if (currNode->left != nullptr) {
                st.push(make_pair(currNode->left, currCode + "0"));
        }
            if (currNode->right != nullptr) {
                st.push(make_pair(currNode->right, currCode + "1"));
        }
        }
    }
    return huffmanCode;
}

// print the Huffman code
void printHuffmanCode(map<char, string>& huffmanCode) {
    for (auto& p : huffmanCode) {
        cout << p.first << ":" << p.second << endl;
    }
}

int main() {
    map<char, int> freq = {};
    for (int i=0; i<6; i++) {
        char ch = 'A' + i;
        int f;
        cin >> f;
        freq[ch] = f;
    }
    auto huffmanCode = buildHuffmanTree(freq);
    printHuffmanCode(huffmanCode);
    return 0;
}
