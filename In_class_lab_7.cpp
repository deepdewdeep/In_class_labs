#include <iostream>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

// Inorder Traversal
void InOrderTraverse(struct Node *root) {
    if (root != NULL) {
        InOrderTraverse(root->left);
        cout << root->key << " ";
        InOrderTraverse(root->right);
    }
}

// Insert a node
struct Node *insertNode(struct Node *root, int key) {
    if (root == NULL) {
        struct Node *newNode = new struct Node;
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// Find the inorder successor of a node
struct Node *InOrderSuccessor(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node
struct Node *DeleteNode(struct Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = DeleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = DeleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            delete root;
            return temp;
        }

        struct Node *temp = InOrderSuccessor(root->right);
        root->key = temp->key;
        root->right = DeleteNode(root->right, temp->key);
    }

    return root;
}

// main code
int main() {
    struct Node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = DeleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    InOrderTraverse(root);
}