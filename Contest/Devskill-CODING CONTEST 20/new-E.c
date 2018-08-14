#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int fastIn()
{
    register int c = getchar();
    int x;
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());

    if(c=='-')
    {
        neg = 1;
        c = getchar();
    }

    for(; c>47 && c<58 ; c = getchar())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
    return x;
}
int prime[869600];
int mp[13333339];
int len=0;
void seive()
{
    int i,j;
    for(i=3; i<=13333334; i+=2)
    {
        if(mp[i]==0)
        {
            prime[len++]=i;
            for(j=i*2; j<=13333334; j+=i)
            {
                mp[j]=1;
            }
        }
    }
}
int ch_no[26825930];
int lim=200000000;
int p=0;
void calc()
{
    int lenn=584;
    int i,j,k;
   for(i=0; i<=lenn; i++)
   {
       int first_len=(int)sqrt((double)lim/(double)prime[i]);
       for(j=i+1; prime[j]<=first_len && j<len; j++)
       {
               int t=prime[i]*prime[j];
               int second_len=(int)((double)lim/(double)t);
               for(k=j+1; prime[k]<=second_len && k<len; k++)
               {
                     ch_no[p++]=t*prime[k];
               }
       }
   }
}
}
int upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
  seive();
  calc();
  quickSort(ch_no, 0, p-1);
  int tt=fastIn();

  while(tt--)
  {
      int l=fastIn();
      int r=fastIn();
      int low=lower_bound(ch_no,p,l);
      int high=upper_bound(ch_no,p,r);
      printf("Case %d: %d\n",kk++,high-low);
  }
}
