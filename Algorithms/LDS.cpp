int LDS(vector<int> a)
{
    reverse(a.begin(), a.end());
    int n = a.size();
    vector<int> d;
    for(int i = 0;i<n;i++)
    {
        int x = a[i];
        vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}
