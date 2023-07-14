#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value)
        {
            this->value=value;
            this->left=NULL;
            this->right=NULL;
        }
};
Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if(val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node*> q;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            Node* p = q.front();
            q.pop();
            int l,r;
            cin >> l >> r;
            Node* myleft;
            Node* myright;
            if(l == -1)
            {
                myleft = NULL;
            }
            else
            {
                myleft = new Node(l);
            }
            if(r==-1)
            {
                myright = NULL;
            }
            else
            {
                myright = new Node(r);
            }
            p->left = myleft;
            p->right = myright; 
        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
        }
    }
    return root;
}
int count_node(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int l = count_node(root->left);
    int r = count_node(root->right);
    return l + r + 1;
}
int main()
{
    Node* root = input_tree();
    cout << count_node(root) << endl;
    return 0;
}