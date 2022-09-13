#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }


};
void level_order(TreeNode * root)
{
    if(root == NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        TreeNode *save = q.front();
        q.pop();
        if(save!=NULL)
        {
            cout<<save->value<<" ";
            if(save->left!=NULL) q.push(save->left);
            if(save->right!=NULL) q.push(save->right);
        }
        else
        {
            if(!q.empty()) q.push(NULL);

        }
    }

}
void level_order_reverse(TreeNode* root)
{
    if(root == NULL) return;
    queue<TreeNode *>q;
    stack<TreeNode *>st;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *save = q.front();
        q.pop();
        st.push(save);
        if(save->right!=NULL) q.push(save->right);
        if(save->left!=NULL) q.push(save->left);
    }
    while(!st.empty())
    {
        root = st.top();
        cout<<root->value<<" ";
        st.pop();
    }
}

void zigzag_order(TreeNode * root){
    if(root == NULL) return;
    stack<TreeNode*>s1,s2;
    s1.push(root);
    while(!s1.empty()||!s2.empty()){
        while(!s1.empty()){
            TreeNode * save = s1.top();
            s1.pop();
            cout<<save->value<<" ";
            if(save->left != NULL) s2.push(save->left);
            if(save->right != NULL) s2.push(save->right);
        }
        while(!s2.empty()){
            TreeNode * save2 = s2.top();
            s2.pop();
            cout<<save2->value<<" ";
            if(save2->left != NULL) s1.push(save2->left);
            if(save2->right != NULL) s1.push(save2->right);
        }
    }

}



float get_average(vector<int>v){
    float sum = 0;
    int x = 0;
    for(int i=0;i<v.size();i++){
        sum += (float)v[i];
        x++;
    }
    return sum/x;
}
void get_level_order_val(TreeNode * root,vector<vector<int>> &v)
{
    if(root==NULL) return;
    queue<TreeNode*>q;
    vector<int>t;
    q.push (root);
    t.push_back(root->value);
    v.push_back(t);
    t.clear();
    q.push (NULL);
    while (!q.empty())
    {
        TreeNode *save = q.front();
        q.pop();
        if (save != NULL)
        {
            if (save->left != NULL)
            {
                q.push (save->left);
                t.push_back(save->left->value);
            }
            if (save->right != NULL)
            {
                q.push (save->right);
                t.push_back(save->right->value);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push (NULL);
                v.push_back(t);
                t.clear();
            }

        }

    }

}

void average_level(TreeNode* root){
    vector<vector<int>> v;
    get_level_order_val(root,v);
    for(int i=0; i<v.size(); i++)
    {
        cout<<get_average(v[i])<<" ";
    }
    cout<<endl;
}




int main()
{
    int n;
    cin>>n;
    TreeNode *fastNode[n];
    for(int i=0; i<n; i++)
    {
        fastNode[i] = new TreeNode(-1);
    }
    for(int i=0; i<n; i++)
    {
        int root,left,right;
        cin>>root>>left>>right;

        fastNode[i]->value = root;

        if(left > n-1||right > n-1)
        {
            cout<<"Invalid index"<<endl;
            break;
        }
        if(left != -1)
        {
            fastNode[i]->left = fastNode[left];
        }
        if(right != -1)
        {
            fastNode[i]->right = fastNode[right];
        }
    }
    level_order(fastNode[0]);
    cout<<endl;
    level_order_reverse(fastNode[0]);
    cout<<endl;
    zigzag_order(fastNode[0]);


    return 0;
}

/*


9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1




*/
