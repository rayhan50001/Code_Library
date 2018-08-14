 #include<bits/stdc++.h>
 using namespace std;
 int arr[1000001];
 int main()
 {
    int tt,kk=1;
    cin>>tt;
    while(tt--){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int c=0;
    for(int i=0; i<n; i++)
    {
        int pre=arr[i];
        c=1;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]-pre==1)
            {
                c++;
                pre=arr[j];
            }
            else break;
        }
        if(c>1)break;
    }
    cout<<"Case "<<kk++<<": ";
    if(c>1)cout<<"Yes\n";
    else cout<<"No\n";
    }
 }
