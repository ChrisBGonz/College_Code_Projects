#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

Node* buildHuffmanTree(vector<char>& characters, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    for (size_t i = 0; i < characters.size(); i++) {
        pq.push(new Node(characters[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* mergedNode = new Node('\0', left->frequency + right->frequency);
        mergedNode->left = left;
        mergedNode->right = right;

        pq.push(mergedNode);
    }

    return pq.top();
}

void generateHuffmanCodes(Node* root, string code, vector<string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->character != '\0') {
        huffmanCodes[root->character] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string userInput;
    vector<int> freq(256, 0);

    cout << "Enter text below:" << endl;
    getline(cin, userInput);
    
    /*
     Example text:
     "We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness."
     */

    for (char c : userInput) {
        int ascii = static_cast<int>(c);
        freq[ascii]++;
    }

    vector<char> characters;
    vector<int> characterFreq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            characters.push_back(static_cast<char>(i));
            characterFreq.push_back(freq[i]);
        }
    }

    Node* huffmanTree = buildHuffmanTree(characters, characterFreq);

    vector<string> huffmanCodes(256, "");
    generateHuffmanCodes(huffmanTree, "", huffmanCodes);

    for (size_t i = 0; i < characters.size(); i++) {
        cout << "\nCharacter: " << characters[i] << "\tFrequency: " << characterFreq[i] << "\tHuffman Code: " << huffmanCodes[characters[i]] << endl;
    }

    cout << endl;
    
    return 0;
}
