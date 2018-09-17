#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
vector<pair<int,int> >zero,pos,neg;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)zero.push_back({0,i});
        if(arr[i]>0)pos.push_back({arr[i],i});
        if(arr[i]<0)neg.push_back({arr[i],i});
    }
    if(neg.size()%2==1)
    {
        if(pos.size()==0)
        {
            int last_pos=-1;
            if(zero.size()==1)last_pos=zero[0].second+1;
            else
            {
                for(int i=1; i<zero.size(); i++)
                {
                    cout<<1<<" "<<zero[i-1].second+1<<" "<<zero[i].second+1<<endl;
                    last_pos=zero[i].second+1;
                }
            }
            if(last_pos==-1)
            {
                if(neg.size()>1)
                {
                    sort(neg.begin(),neg.end());reverse(neg.begin(),neg.end());
                    cout<<2<<" "<<neg[0].second+1<<endl;
                    for(int i=2; i<neg.size(); i++)
                    {
                        cout<<1<<" "<<neg[i-1].second+1<<" "<<neg[i].second+1<<endl;
                    }
                }
            }
            else
            {
               if(neg.size()==1)
               {
                   cout<<1<<" "<<neg[0].second+1<<" "<<last_pos<<endl;
               }
               else
               {
                   sort(neg.begin(),neg.end());reverse(neg.begin(),neg.end());
                   cout<<1<<" "<<neg[0].second+1<<" "<<last_pos<<endl;
                   cout<<2<<" "<<last_pos<<endl;
                   for(int i=2; i<neg.size(); i++)
                   {
                       cout<<1<<" "<<neg[i-1].second+1<<" "<<neg[i].second+1<<endl;
                   }
               }
            }
        }
        else
        {
            int last_pos=-1;
            if(zero.size()==1)last_pos=zero[0].second+1;
            else
            {
                for(int i=1; i<zero.size(); i++)
                {
                    cout<<1<<" "<<zero[i-1].second+1<<" "<<zero[i].second+1<<endl;
                    last_pos=zero[i].second+1;
                }
            }
            if(last_pos==-1)
            {
                if(neg.size()==1)
                {
                    cout<<2<<" "<<neg[0].second+1<<endl;
                    for(int i=1; i<pos.size(); i++)
                    {
                        cout<<1<<" "<<pos[i-1].second+1<<" "<<pos[i].second+1<<endl;
                    }
                }
                else
                {
                    sort(neg.begin(),neg.end());reverse(neg.begin(),neg.end());
                    cout<<2<<" "<<neg[0].second+1<<endl;
                    for(int i=2; i<neg.size(); i++)
                    {
                        cout<<1<<" "<<neg[i-1].second+1<<" "<<neg[i].second+1<<endl;
                    }
                    for(int i=0; i<pos.size(); i++)
                    {
                        cout<<1<<" "<<pos[i].second+1<<" "<<neg[neg.size()-1].second+1<<endl;
                    }
                }
            }
            else
            {
                if(neg.size()==1)
                {
                    cout<<1<<" "<<neg[0].second+1<<" "<<last_pos<<endl;
                    cout<<2<<" "<<last_pos<<endl;
                    for(int i=1; i<pos.size(); i++)
                    {
                        cout<<1<<" "<<pos[i-1].second+1<<" "<<pos[i].second+1<<endl;
                    }
                }
                else
                {
                    sort(neg.begin(),neg.end());reverse(neg.begin(),neg.end());
                    cout<<1<<" "<<neg[0].second+1<<" "<<last_pos<<endl;
                    cout<<2<<" "<<last_pos<<endl;
                    for(int i=2; i<neg.size(); i++)
                    {
                        cout<<1<<" "<<neg[i-1].second+1<<" "<<neg[i].second+1<<endl;
                        last_pos=neg[i].second+1;
                    }
                    for(int i=0; i<pos.size(); i++)
                    {
                        cout<<1<<" "<<pos[i].second+1<<" "<<last_pos<<endl;
                    }
                }
            }
        }
    }
    else if(neg.size()>=1 && neg.size()%2==0)
    {
        if(zero.empty())
        {
            int last_pos=-1;
            for(int i=1; i<neg.size(); i++)
            {
                cout<<1<<" "<<neg[i-1].second+1<<" "<<neg[i].second+1<<endl;
                last_pos=neg[i].second+1;
            }
            for(int i=0; i<pos.size(); i++)
            {
                cout<<1<<" "<<pos[i].second+1<<" "<<last_pos<<endl;
            }
        }
        else
        {
            int last_pos=-1;
            if(zero.size()==1)
            {
                cout<<2<<" "<<zero[0].second+1<<endl;
            }
            else
            {
                for(int i=1; i<zero.size(); i++)
                {
                    cout<<1<<" "<<zero[i-1].second+1<<" "<<zero[i].second+1<<endl;
                    last_pos=zero[i].second+1;
                }
                cout<<2<<" "<<last_pos<<endl;
            }
            last_pos=-1;
            for(int i=1; i<neg.size(); i++)
            {
                cout<<1<<" "<<neg[i-1].second+1<<" "<<neg[i].second+1<<endl;
                last_pos=neg[i].second+1;
            }
            for(int i=0; i<pos.size(); i++)
            {
                cout<<1<<" "<<pos[i].second+1<<" "<<last_pos<<endl;
            }
        }
    }
    else
    {
        if(pos.size()>=1)
        {
            if(zero.size()==1)cout<<2<<" "<<zero[0].second+1<<endl;
            else
            {
                int last_pos=-1;
                for(int i=1; i<zero.size(); i++)
                {
                    cout<<1<<" "<<zero[i-1].second+1<<" "<<zero[i].second+1<<endl;
                    last_pos=zero[i].second+1;
                }
                cout<<2<<" "<<last_pos<<endl;
            }
            for(int i=1; i<pos.size(); i++)
            {
                cout<<1<<" "<<pos[i-1].second+1<<" "<<pos[i].second+1<<endl;
            }
        }
        else
        {
            for(int i=1; i<zero.size(); i++)
            {
                cout<<1<<" "<<zero[i-1].second+1<<" "<<zero[i].second+1<<endl;
            }
        }
    }
}

