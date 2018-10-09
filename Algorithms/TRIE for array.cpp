struct TRIE{
  struct node{
    int c;
    map<int,int>a;
    bool endofthe;
  };
  node TREE[100001];
  int nodes;
  void new_node()
  {
    TREE[nodes].endofthe=false;
    TREE[nodes].c = 0;
    TREE[nodes].a.clear();
    nodes++;
  }
  void init()
  {
    nodes = 0;
    new_node();
  }
  int INSERT(vector<int>s)
  {
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i)
    {
      int id = s[i];
      if(TREE[cur_node].a.find(id)==TREE[cur_node].a.end())
      {
        TREE[cur_node].a[id] = nodes;
        new_node();
      }
      cur_node = TREE[cur_node].a[id];
    }
    TREE[cur_node].endofthe=true;
  }
  int SEARCH(vector<int>s)
  {
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i)
    {
      int id = s[i];
      if(TREE[cur_node].a.find(id)==TREE[cur_node].a.end())
      {
         return false;
      }
      cur_node = TREE[cur_node].a[id];
    }
    return (cur_node!=0 && TREE[cur_node].endofthe);
  }
};
TRIE tree;
