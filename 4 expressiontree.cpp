#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Node structure for expression tree
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to construct tree from postfix expression
Node* constructPostfixTree(const string& postfix) {
    stack<Node*> s;
    for (char c : postfix) {
        if (c >= 'a' && c <= 'z') {  // Operand check (lowercase letters)
            s.push(new Node(c));
        } else {  // Operator
            Node* right = s.top(); s.pop();
            Node* left = s.top(); s.pop();
            Node* node = new Node(c);
            node->left = left;
            node->right = right;
            s.push(node);
        }
    }
    return s.top();  // Return root of tree
}

// Function to construct tree from prefix expression
Node* constructPrefixTree(const string& prefix) {
    stack<Node*> s;
    for (int i = prefix.size() - 1; i >= 0; i--) {  // Traverse from right to left
        char c = prefix[i];
        if (c >= 'a' && c <= 'z') {  // Operand check (lowercase letters)
            s.push(new Node(c));
        } else {  // Operator
            Node* left = s.top(); s.pop();
            Node* right = s.top(); s.pop();
            Node* node = new Node(c);
            node->left = left;
            node->right = right;
            s.push(node);
        }
    }
    return s.top();  // Return root of tree
}

// Recursive traversals
void inorderRecursive(Node* root) {
    if (root) {
        inorderRecursive(root->left);
        cout << root->data << " ";
        inorderRecursive(root->right);
    }
}

void preorderRecursive(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(Node* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->data << " ";
    }
}

// Non-recursive traversals using stacks
void inorderIterative(Node* root) {
    stack<Node*> s;
    while (root || !s.empty()) {
        while (root) {  // Go to leftmost node
            s.push(root);
            root = root->left;
        }
        root = s.top(); s.pop();
        cout << root->data << " ";
        root = root->right;
    }
}

void preorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* current = s.top(); s.pop();
        cout << current->data << " ";
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

void postorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* current = s1.top(); s1.pop();
        s2.push(current);
        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
int main() {
    string postfix = "ab+c*";
    string prefix = "*+abc";
   
    Node* rootPostfix = constructPostfixTree(postfix);  // Construct tree from postfix
    Node* rootPrefix = constructPrefixTree(prefix);    // Construct tree from prefix
   
    // Display recursive traversals
    cout << "In-order (Postfix Tree): "; inorderRecursive(rootPostfix); cout << endl;
    cout << "Pre-order (Postfix Tree): "; preorderRecursive(rootPostfix); cout << endl;
    cout << "Post-order (Postfix Tree): "; postorderRecursive(rootPostfix); cout << endl;

    cout << "In-order (Prefix Tree): "; inorderRecursive(rootPrefix); cout << endl;
    cout << "Pre-order (Prefix Tree): "; preorderRecursive(rootPrefix); cout << endl;
    cout << "Post-order (Prefix Tree): "; postorderRecursive(rootPrefix); cout << endl;

    // Display non-recursive traversals
    cout << "\nNon-recursive In-order (Postfix Tree): "; inorderIterative(rootPostfix); cout << endl;
    cout << "Non-recursive Pre-order (Postfix Tree): "; preorderIterative(rootPostfix); cout << endl;
    cout << "Non-recursive Post-order (Postfix Tree): "; postorderIterative(rootPostfix); cout << endl;

    return 0;
}