#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int value;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int value){
    this->value = value;
    this->leftChild = NULL;
    this->rightChild = NULL;

    }
};

string inorder_traverse(TreeNode * root,string &str){
    if(root == NULL) return "";
    inorder_traverse(root->leftChild,str);
    str+= (to_string(root->value)+ " ");
    inorder_traverse(root->rightChild,str);
    return str;
}
TreeNode *inset_binary_search_tree(TreeNode * root, int value){
    TreeNode * newNode = new TreeNode(value);
    if(root == NULL){
        root = newNode;
        return root;
    }

    if(value < root->value){
        root->leftChild = inset_binary_search_tree(root->leftChild,value);
    }else if(value > root->value){
        root->rightChild = inset_binary_search_tree(root->rightChild,value);
    }

    return root;

}

TreeNode * searchBST(TreeNode * root,int value){
    if(root == NULL){
        return NULL;
    }
    if(root->value == value){
        cout<<root->value;
        return root;
    }
    else if(root->value > value){
         cout<<root->value<<"->";
        searchBST(root->leftChild,value);
    }else{
         cout<<root->value<<"->";
        searchBST(root->rightChild,value);
    }

}

TreeNode * inorder_succeser(TreeNode * root,int value){
    TreeNode * tmp = root;
    while(tmp->leftChild != NULL){
        tmp = tmp->leftChild;
    }

    return tmp;
}

TreeNode *deleteNode(TreeNode *root, int value){
    if(value < root->value){
        root->leftChild = deleteNode(root->leftChild,value);
    }else if(value > root->value){
        root->rightChild = deleteNode(root->rightChild,value);

    }else{
        if(root->leftChild == NULL){
            TreeNode *tmp = root->rightChild;
            free(root);
            return tmp;
        }else if(root->rightChild == NULL){
            TreeNode *tmp = root->leftChild;
            free(root);
            return tmp;
        }else{
            TreeNode * tmp = inorder_succeser(root->rightChild,value);
            root->value = tmp->value;
            root->rightChild = deleteNode(root->rightChild,tmp->value);

        }

    }


return root;
}

int main(){
    int n;
    cin>>n;
    TreeNode * root = NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        root = inset_binary_search_tree(root,value);
    }
    string binarySearch = "";
    binarySearch = inorder_traverse(root,binarySearch);
    cout<<binarySearch<<endl;

    int key;
    cin>>key;
    if(searchBST(root,key) == NULL) cout<<endl<<"Value is not found in the tree"<<endl;
    else cout<<endl<<"Value is found"<<endl;

    cout<<endl<<"Enter the value for delete"<<endl;
    int delVal;
    cin>>delVal;
    root = deleteNode(root,delVal);
    string afterDel = "";
    binarySearch = inorder_traverse(root,afterDel);
    cout<<"After Delete :";
    cout<<afterDel<<endl;




return 0;
}
