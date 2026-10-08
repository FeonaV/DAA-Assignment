#include <iostream>
using namespace std;

class BST {
    struct Node {
        int data;
        Node *left, *right;
        Node(int v) : data(v), left(nullptr), right(nullptr) {}
    };
    Node *root = nullptr;
    bool added = false, removed = false;
    Node *insert(Node *n, int v) {
        if (!n) {
            added = true;
            return new Node(v);
        }
        if (v < n->data) n->left = insert(n->left, v);
        else if (v > n->data) n->right = insert(n->right, v);
        return n;
    }
    Node *minNode(Node *n) {
        while (n && n->left) n = n->left;
        return n;
    }
    Node *remove(Node *n, int v) {
        if (!n) return nullptr;
        if (v < n->data) n->left = remove(n->left, v);
        else if (v > n->data) n->right = remove(n->right, v);
        else {
            removed = true;
            if (!n->left) {
                Node *r = n->right;
                delete n;
                return r;
            }
            if (!n->right) {
                Node *l = n->left;
                delete n;
                return l;
            }
            Node *s = minNode(n->right);
            n->data = s->data;
            n->right = remove(n->right, s->data);
        }
        return n;
    }
    void inorder(Node *n) {
        if (!n) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
    void destroy(Node *n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
public:
    ~BST() { destroy(root); }
    bool insert(int v) {
        added = false;
        root = insert(root, v);
        return added;
    }
    bool remove(int v) {
        removed = false;
        root = remove(root, v);
        return removed;
    }
    bool search(int v) {
        Node *cur = root;
        while (cur) {
            if (v == cur->data) return true;
            cur = (v < cur->data) ? cur->left : cur->right;
        }
        return false;
    }
    void inorder() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "In-order: ";
        inorder(root);
        cout << "\n";
    }
    void minMax() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *mx = root;
        while (mx->right) mx = mx->right;
        cout << "Minimum: " << minNode(root)->data;
        cout << ", Maximum: " << mx->data << "\n";
    }
};

int main() {
    BST tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Delete\n3. Search\n4. Display (in-order)\n";
        cout << "5. Find minimum and maximum\n6. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            if (tree.insert(val)) cout << "Inserted " << val << ".\n";
            else cout << "Duplicate value; not inserted.\n";
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            if (tree.remove(val)) cout << "Deleted " << val << ".\n";
            else cout << "Value " << val << " not found.\n";
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            if (tree.search(val)) cout << val << " found in the tree.\n";
            else cout << val << " not found.\n";
            break;
        case 4:
            tree.inorder();
            break;
        case 5:
            tree.minMax();
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
