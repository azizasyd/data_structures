#include <bits/stdc++.h>

//            10
//         /    \
//       3       16
//     /   \    /   \
//    2     9  14    17
//   /     /    /      \
//  1     4    12      20

struct Node{
    int value;
    Node *left, *right;
    Node(int val) : value(val), left(nullptr), right(nullptr){}
};

Node* insert(std::vector<int> a, int left, int right){
    if(left >= right){
        return nullptr;
    }

    int mid = (left + right) / 2;
    Node* root = new Node(a[mid]);

    root->left = insert(a, left, mid);
    root->right = insert(a, mid + 1, right);

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

void delete_tree(Node* root){
    if(root == nullptr){
        return;
    }

    delete_tree(root->left);
    delete_tree(root->right);
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    Node* root = insert(a, 0, a.size());

    VLR(root);
    delete_tree(root);
}