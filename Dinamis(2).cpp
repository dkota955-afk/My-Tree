#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;   // lebih kecil dari parent
    TreeNode* right;  // lebih besar dari parent

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Fungsi insert BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);   // kiri = lebih kecil
    } else if (val > root->val) {
        root->right = insert(root->right, val); // kanan = lebih besar
    }

    return root;
}

// Tampilkan tree secara visual (rotated)
void printTree(TreeNode* root, string prefix = "", bool isLeft = true) {
    if (root == nullptr) return;

    printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
    cout << prefix << (isLeft ? "└── " : "┌── ") << root->val << endl;
    printTree(root->left, prefix + (isLeft ? "    " : "│   "), true);
}

// Traversal In-Order (hasilnya terurut)
void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// Traversal Pre-Order
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Traversal Post-Order
void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    TreeNode* root = nullptr;
    int n, val;

    cout << "=== Binary Search Tree ===" << endl;
    cout << "Masukkan jumlah node: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << "Masukkan nilai ROOT (awal): ";
        } else {
            cout << "Masukkan nilai node ke-" << (i + 1) << ": ";
        }
        cin >> val;
        root = insert(root, val);
    }

    cout << "\n=== Struktur Tree ===" << endl;
    printTree(root);

    cout << "\n=== Traversal ===" << endl;
    cout << "In-Order   (terurut)  : "; inOrder(root);   cout << endl;
    cout << "Pre-Order  (root dulu): "; preOrder(root);  cout << endl;
    cout << "Post-Order (root akhir): "; postOrder(root); cout << endl;

    return 0;
}
