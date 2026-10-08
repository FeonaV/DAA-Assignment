#include <iostream>
using namespace std;

const int MAX = 100;

class BinaryTree {
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
    int maxOf(int a, int b) { return a > b ? a : b; }
    int height(Node *n) {
        return n ? 1 + maxOf(height(n->left), height(n->right)) : 0;
    }
public:
    ~BinaryTree() { destroy(root); }
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
    void levelOrder() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *q[MAX];
        int front = 0, rear = 0;
        q[rear++] = root;
        cout << "Level-order: ";
        while (front < rear) {
            Node *cur = q[front++];
            cout << cur->data << " ";
            if (cur->left) q[rear++] = cur->left;
            if (cur->right) q[rear++] = cur->right;
        }
        cout << "\n";
    }
    bool search(int key) {
        if (!root) return false;
        Node *q[MAX];
        int front = 0, rear = 0;
        q[rear++] = root;
        while (front < rear) {
            Node *cur = q[front++];
            if (cur->data == key) return true;
            if (cur->left) q[rear++] = cur->left;
            if (cur->right) q[rear++] = cur->right;
        }
        return false;
    }
    int height() { return height(root); }
    int countNodes() { return count; }
};

int main() {
    BinaryTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Display (level-order)\n3. Search\n";
        cout << "4. Height of tree\n5. Count nodes\n6. Quit\n";
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
            tree.levelOrder();
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            if (tree.search(val)) cout << val << " found in the tree.\n";
            else cout << val << " not found.\n";
            break;
        case 4:
            cout << "Height of tree: " << tree.height() << "\n";
            break;
        case 5:
            cout << "Number of nodes: " << tree.countNodes() << "\n";
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
