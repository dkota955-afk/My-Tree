#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* prev;
    Node* next;

    Node(int nilai){
        val = nilai;
        prev = nullptr;
        next = nullptr;
    }
};
class Queue{
private:
    Node* data[100];
    int front;
    int rear;
public:
    Queue(){
        front = 0;
        rear = 0;
    }bool empty(){
        return front == rear;
    }void enqueue(Node* node){
        data[rear++] = node;
    }Node* dequeue(){
        return data[front++];
    }int size(){
        return rear - front;
    }
};
class BST{
private:
    Node* root;
    Node* insertBST(Node* root,int nilai){
        if(root == nullptr)
            return new Node(nilai);
        if(nilai < root->val)
            root->prev = insertBST(root->prev,nilai);
        else
            root->next = insertBST(root->next,nilai);
        return root;
    }
    void preorder(Node* root){
        if(root == nullptr) return;
        cout<<root->val<<" ";
        preorder(root->prev);
        preorder(root->next);
    }
    void inorder(Node* root){
        if(root == nullptr) return;
        inorder(root->prev);
        cout<<root->val<<" ";
        inorder(root->next);
    }
    void postorder(Node* root){
        if(root == nullptr) return;
        postorder(root->prev);
        postorder(root->next);
        cout<<root->val<<" ";
    }
    void BFS(Node* root){
        if(root == nullptr) return;
        Queue q;
        q.enqueue(root);
        int level = 0;
        while(!q.empty()){
            int jumlahNode = q.size();
            cout<<"Level "<<level<<" : ";
            for(int i=0;i<jumlahNode;i++){
                Node* current = q.dequeue();
                cout<<current->val<<" ";
                if(current->prev != nullptr)
                    q.enqueue(current->prev);
                if(current->next != nullptr)
                    q.enqueue(current->next);
            }
            cout<<endl;
            level++;
        }
    }
    void hapusTree(Node* root){
        if(root == nullptr)
            return;
        hapusTree(root->prev);
        hapusTree(root->next);
        delete root;
    }
public:
    BST(){
        root = nullptr;
    }
    ~BST(){
        hapusTree(root);
    }
    void insert(int nilai){
        root = insertBST(root,nilai);
    }
    void tampilTraversal(){
        cout<<"\n==============================";
        cout<<"\nHASIL TRAVERSAL";
        cout<<"\n==============================\n";
        cout<<"\nPreorder  (Root-L-R) : ";
        preorder(root);
        cout<<"\nInorder   (L-Root-R) : ";
        inorder(root);
        cout<<"\nPostorder (L-R-Root) : ";
        postorder(root);

        cout<<"\n\n==============================";
        cout<<"\nBFS / LEVEL ORDER";
        cout<<"\n==============================\n";
        BFS(root);
    }
};
int main(){
    BST tree;
    int jumlah;
    cout<<"================================\n";
    cout<<" PROGRAM BINARY SEARCH TREE\n";
    cout<<"================================\n";
    cout<<"Masukkan jumlah data : "; cin>>jumlah;
    cout<<"\nMasukkan data BST\n";
    for(int i=0;i<jumlah;i++){
        int input;
        cout<<"Data ke-"<<i+1<<" : "; cin>>input;
        tree.insert(input);
    }
    tree.tampilTraversal();
    return 0;
}
