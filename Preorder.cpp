#include <iostream>
using namespace std;

const int MAX = 100;

class PreorderTree {
    struct Node {
        int data;
        Node *left, *right;
        Node(int v) : data(v), left(nullptr), right(nullptr) {}
    };
    Node *root = nullptr;
    int count = 0;
    void destroy(Node *n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
    void preorder(Node *n) {
        if (!n) return;
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
public:
    ~PreorderTree() { destroy(root); }
    void insert(int v) {
        if (count >= MAX) {
            cout << "Tree is full.\n";
            return;
        }
        Node *n = new Node(v);
        count++;
        if (!root) {
            root = n;
            return;
        }
        Node *q[MAX];
        int front = 0, rear = 0;
        q[rear++] = root;
        while (front < rear) {
            Node *cur = q[front++];
            if (!cur->left) {
                cur->left = n;
                return;
            }
            q[rear++] = cur->left;
            if (!cur->right) {
                cur->right = n;
                return;
            }
            q[rear++] = cur->right;
        }
    }
    void preorderRecursive() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Pre-order (recursive): ";
        preorder(root);
        cout << "\n";
    }
    void preorderIterative() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *st[MAX];
        int top = -1;
        st[++top] = root;
        cout << "Pre-order (iterative): ";
        while (top >= 0) {
            Node *cur = st[top--];
            cout << cur->data << " ";
            if (cur->right) st[++top] = cur->right;
            if (cur->left) st[++top] = cur->left;
        }
        cout << "\n";
    }
};

int main() {
    PreorderTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Pre-order traversal (recursive)\n";
        cout << "3. Pre-order traversal (iterative)\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tree.insert(val);
            cout << "Inserted " << val << ".\n";
            break;
        case 2:
            tree.preorderRecursive();
            break;
        case 3:
            tree.preorderIterative();
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
