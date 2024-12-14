#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert a node into the BST
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int value) {
    if (!root) return root;
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp && temp->left) temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search a value in the BST
bool search(Node* root, int value) {
    if (!root) return false;
    if (value == root->data) return true;
    return value < root->data ? search(root->left, value) : search(root->right, value);
}

// In-order traversal (Display tree)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Depth of the tree
int depth(Node* root) {
    if (!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

// Mirror image of the tree
void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Create a copy of the tree
Node* copyTree(Node* root) {
    if (!root) return nullptr;
    Node* newNode = new Node(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

// Display parent nodes with their child nodes
void displayParents(Node* root) {
    if (!root) return;
    if (root->left) cout << "Parent: " << root->data << " -> Left Child: " << root->left->data << endl;
    if (root->right) cout << "Parent: " << root->data << " -> Right Child: " << root->right->data << endl;
    displayParents(root->left);
    displayParents(root->right);
}

// Display leaf nodes
void displayLeaves(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) cout << root->data << " ";
    displayLeaves(root->left);
    displayLeaves(root->right);
}

// Level-wise display of the tree
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Search for a value
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    // Display tree in-order
    cout << "In-order: ";
    inorder(root);
    cout << endl;

    // Display depth of tree
    cout << "Depth of tree: " << depth(root) << endl;

    // Display mirror image of the tree
    mirror(root);
    cout << "In-order after mirror: ";
    inorder(root);
    cout << endl;

    // Create a copy of the tree
    Node* rootCopy = copyTree(root);
    cout << "In-order of copied tree: ";
    inorder(rootCopy);
    cout << endl;

    // Display all parents with their child nodes
    cout << "Parents with their child nodes:" << endl;
    displayParents(root);

    // Display leaf nodes
    cout << "Leaf nodes: ";
    displayLeaves(root);
    cout << endl;

    // Display tree level-wise
    cout << "Level-wise tree: ";
    levelOrder(root);
    cout << endl;

    // Delete a node
    root = deleteNode(root, 40);
    cout << "In-order after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}