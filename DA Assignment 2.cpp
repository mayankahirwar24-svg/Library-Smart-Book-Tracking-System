#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node safely
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert book ID in BST safely
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Display sorted book IDs
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search a Book ID
bool search(Node* root, int key) {
    if (root == nullptr) return false;

    if (root->data == key) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    Node* root = nullptr;
    int choice, id;

    while (true) {
        cout << "\nSMART BOOK TRACKING SYSTEM\n";
        cout << "1. Store returned Book ID\n";
        cout << "2. Check if a Book ID has been returned\n";
        cout << "3. Display all returned Book IDs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            root = insert(root, id);
            break;

        case 2:
            cout << "Enter Book ID to check: ";
            cin >> id;
            if (search(root, id))
                cout << "BOOK ID is Available!\n";
            else
                cout << "BOOK ID is not Available!\n";
            break;

        case 3:
            cout << "Returned Book IDs (sorted): ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
