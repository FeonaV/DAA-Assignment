#include <iostream>
using namespace std;

const int MAX = 100;

class InorderTree {
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
    void inorder(Node *n) {
        if (!n) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
public:
    ~InorderTree() { destroy(root); }
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
    void inorderRecursive() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "In-order (recursive): ";
        inorder(root);
        cout << "\n";
    }
    void inorderIterative() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *st[MAX];
        int top = -1;
        Node *cur = root;
        cout << "In-order (iterative): ";
        while (cur || top >= 0) {
            while (cur) {
                st[++top] = cur;
                cur = cur->left;
            }
            cur = st[top--];
            cout << cur->data << " ";
            cur = cur->right;
        }
        cout << "\n";
    }
};

int main() {
    InorderTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. In-order traversal (recursive)\n";
        cout << "3. In-order traversal (iterative)\n4. Quit\n";
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
            tree.inorderRecursive();
            break;
        case 3:
            tree.inorderIterative();
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
