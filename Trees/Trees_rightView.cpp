#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

class levelPair
{
public:
    TreeNode *par = nullptr;
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(TreeNode *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb;
        this->rb = rb;
    }
};

void helper(TreeNode * node, int level , vector<int> &list)
{
    if(node==nullptr)
    {
        return ;
    }
    if(level==list.size())
    {
        list.push_back(node->val);
    }
    helper(node->right,level+1,list);
    helper(node->left,level+1,list);
}


vector<int> rightView(TreeNode *root)
{
   /* Logic: We have used DFS to get the rightview . Everytime you visit a level , check if the size of the list is same as the level or not because the size of the vector indicates the level , since this is right view , we first make a call to right and then to left , hence if left node exists in a level , then first the right node would be added to the vector and the size of vector would increase , hence while traversal if you ever visit the same level again none of the nodes from that particular level would be stored except the first visited right node .If there was no right and only left child exists in a particular level then the right child will be stored inside the vector. Had the question been of left view , then we would have made a call to left first and then to left , for better reference please contact , details for contacting present in github profile. 
    Ps:  Feel free to make contributions for making the logic more understandable by maybe adding images of dry run :) */
   
   
    vector<int> list;
    helper(root,0,list);
    return list;
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

       vector<int> ans = rightView(root);
    for (int i : ans)
        cout << i << endl;
}

int main()
{
    solve();
    return 0;
}