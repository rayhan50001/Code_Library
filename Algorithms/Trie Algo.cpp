#include<bits/stdc++.h>
using namespace std;
struct trienode{
    struct trienode *child[26];
    bool endofword;
    int c;
};
struct trienode *newnode(void)
{
    struct trienode *pnode = new trienode;
    pnode->endofword=false;
    for(int i=0; i<26; i++)
    {
        pnode->child[i]=NULL;
    }
    return pnode;
};
void Insert(struct trienode *root,string s)
{
    struct trienode *root_node=root;
    for(int i=0; i<s.size(); i++)
    {
        int index=s[i]-'a';
        if(!root_node->child[index])
        {
            root_node->child[index]=newnode();
        }
        root_node=root_node->child[index];
    }
    root_node->endofword=true;
    root_node->c++;
}
bool Search(struct trienode *root,string s)
{
    struct trienode *root_node=root;
    for(int i=0; i<s.size(); i++)
    {
        int index=s[i]-'a';
        if(!root_node->child[index])
            return false;
        root_node=root_node->child[index];
    }
    if((root_node!=NULL && root_node->endofword))
    return root_node->c;
}
int main()
{
    int n;
    cin>>n;
    struct trienode *root = newnode();
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        Insert(root,s);
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        string s;
        cin>>s;
        if(Search(root,s))
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
}
