#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* bulitTree(Node* root){

    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=bulitTree(root->left);
    cout<<"Enter data for inserting in right "<<endl;
    root->right=bulitTree(root->right);
    return root;


}

void levelOrderTraversal(Node* root){

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){//purana level complete traverse ho chuka hn
            cout<<endl;
            if(!q.empty()){// queue has still some childs
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
             if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(Node* &root){

    queue<Node*>q;
    cout<<"Enter data for root node:"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){

            temp->left=new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node for:"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){

            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }

}


int main(){

    Node* root=NULL;
    // build from level order treversal
    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);





    //creation of tree
    // root=bulitTree(root);


    // //level order traversal method
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout<<"level order traversal method"<<endl;
    // levelOrderTraversal(root);

    // inorder(root);
    // cout<<endl;

    // preorder(root);
    // cout<<endl;

    // postorder(root);



    return 0;
}