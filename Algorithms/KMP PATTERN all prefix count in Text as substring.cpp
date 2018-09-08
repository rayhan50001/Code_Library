#include<bits/stdc++.h>
using namespace std;
#define yes cerr<<"yes\n";
int pref[1000010];
char pat[1000010];
char text[1000010];
int cnt[100001];
void kmp(char *s)
{
 int n=strlen(s);
 int j=0,i=1;
 pref[0]=0;
    while (i<n)
    {
        if (pat[i]==pat[j])
        {
            j++;
            pref[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = pref[j-1];
            }
            else
            {
                pref[i] = 0;
                i++;
            }
        }
    }
}
void search(char *text,char *pat)
{
    int N=strlen(text);
    int M=strlen(pat);
    int i = 0; // index for text[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == text[i]) {
            cnt[j]++;
            j++;
            i++;
        }

        if (j == M) {
            j = pref[j - 1];
        }

        else if (i < N && pat[j] != text[i]) {
            if (j != 0)
                j = pref[j - 1];
            else
                i = i + 1;
        }
    }
 //yes
 //cerr<<"ss\n";
 //for(int i=0; i<M; i++)cout<<cnt[i]<<" ";
 //cerr<<endl;
 for(int i=M-1; i>1; i--)
 {
    int idx=pref[i];
    cnt[idx]+=cnt[i];
 }
}
int main()
{
    cin>>text;
    cin>>pat;
    kmp(pat);
    for(int i=0; i<strlen(pat); i++)cout<<pref[i]<<" ";
    //cerr<<"yes\n";
    cout<<endl;
    search(text,pat);
    cout<<endl;
    for(int i=0; i<strlen(pat); i++)cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}
