struct TRIE{
  struct node{
    int c;
    int a[15];
  };
  node TREE[100001];
  int nodes;
  void new_node()
  {
    TREE[nodes].c = 0;
    memset(TREE[nodes].a, -1, sizeof TREE[nodes].a);
    nodes++;
  }
  void init()
  {
    nodes = 0;
    new_node();
  }
  int INSERT(const string &s)
  {
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i)
    {
      int id = s[i]-'0'+1;
      if(TREE[cur_node].a[id] == -1)
      {
        TREE[cur_node].a[id] = nodes;
        new_node();
      }
      cur_node = TREE[cur_node].a[id];
      TREE[cur_node].c++;
    }
  }
  int SEARCH(const string &s)
  {
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i)
    {
      int id = s[i]-'0'+1;
      if(TREE[cur_node].a[id] == -1)
      {
         return TREE[cur_node].c;
      }
      cur_node = TREE[cur_node].a[id];
    }
    return TREE[cur_node].c;
  }
};
TRIE tree;
