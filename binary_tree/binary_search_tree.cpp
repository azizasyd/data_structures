#include <bits/stdc++.h>

//           14
//          /  \
//         4    16
//        / \     \
//       3   10    17
//      /   /  \    \
//     1   9   12   20
//      \
//       2

struct Node{
    int value;
    Node *left, *right;
    Node(int val) : value(val), left(nullptr), right(nullptr){}
};

Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }

    if(val < root->value){
        root->left = insert(root->left, val); // make left node the root
    }

    if(val > root->value){
        root->right = insert(root->right, val);
    }

    return root;
}

void VLR(Node* root){
    if(root == nullptr){
        return;
    }

    std::cout << root->value << " ";

    VLR(root->left);
    VLR(root->right);
}

void delete_node(Node* root){
    if(root == nullptr){
        return;
    }

    delete_node(root->left);
    delete_node(root->right);
    delete root;
}

int main(){
    int n;
    std::cin >> n;

    Node* root = nullptr;
    for(int i = 0; i < n; ++i){
        int num;
        std::cin >> num;

        root = insert(root, num);
    }

    VLR(root);
    delete_node(root);

    return 0;
}