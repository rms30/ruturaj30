#include <iostream>
using namespace std;

struct Node
{
int data;
Node *left, *right;
bool isThreaded;

Node(int value)
{
data = value;
left = right = nullptr;
isThreaded = false;
}
};

Node* insert(Node* root, int value)
{
if (root == nullptr)
{
return new Node(value);
}

if (value < root->data)
{
root->left = insert(root->left, value);
}

else
{
if (root->right == nullptr || root->isThreaded)
{
Node* newNode = new Node(value);
newNode->right = root->right;
newNode->isThreaded = true;
root->right = newNode;
root->isThreaded = false;
}

else
{
root->right = insert(root->right, value);
}
}
return root;
}

Node* leftmost(Node* node)
{
while (node && node->left)
{
node = node->left;
}
return node;
}

void inorder(Node* root)
{
Node* curr = leftmost(root);
while (curr)
{
cout << curr->data << " ";
if (curr->isThreaded)
{
curr = curr->right;
}

else
{
curr = leftmost(curr->right);
}
}
}

void preorder(Node* root)
{
Node* curr = root;
while (curr)
{
cout << curr->data << " ";
if (curr->left)
{
curr = curr->left;
}

else if (curr->isThreaded)
{
curr = curr->right;
}

else
{
curr = leftmost(curr->right);
}
}
}

int main()
{
Node* root =NULL;
root = insert(root, 20);
root = insert(root, 10);
root = insert(root, 30);
root = insert(root, 5);
root = insert(root, 15);
root = insert(root, 25);
root = insert(root, 35);

cout << "In-order Traversal: ";
inorder(root);
cout << "\nPre-order Traversal: ";
preorder(root);
return 0;
} 