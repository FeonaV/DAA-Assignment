#include <iostream>
using namespace std;

const int MAX = 100;

class PostorderTree {
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
    void postorder(Node *n) {
        if (!n) return;
        postorder(n->left);
        postorder(n->right);
        cout << n->data << " ";
    }
public:
    ~PostorderTree() { destroy(root); }
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
    void postorderRecursive() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Post-order (recursive): ";
        postorder(root);
        cout << "\n";
    }
    void postorderIterative() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *s1[MAX], *s2[MAX];
        int top1 = -1, top2 = -1;
        s1[++top1] = root;
        while (top1 >= 0) {
            Node *cur = s1[top1--];
            s2[++top2] = cur;
            if (cur->left) s1[++top1] = cur->left;
            if (cur->right) s1[++top1] = cur->right;
        }
        cout << "Post-order (iterative): ";
        while (top2 >= 0) cout << s2[top2--]->data << " ";
        cout << "\n";
    }
};

int main() {
    PostorderTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Post-order traversal (recursive)\n";
        cout << "3. Post-order traversal (iterative)\n4. Quit\n";
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
            tree.postorderRecursive();
            break;
        case 3:
            tree.postorderIterative();
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
