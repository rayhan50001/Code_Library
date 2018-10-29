#include<stdio.h>
int arr[100001];
int dp[100001][31];
int l[100001];
int r[100001];
int color[100001];
/*--------------------------STACK-----------------------------------*/
const int MAXSIZE = 1000001;
int stack[MAXSIZE];
int top = -1;

int isempty() {

   if(top <= -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top >= MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

void pop()
{
   if(!isempty())
   {
      top = top - 1;
   }
}

void push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   }
}
/*------------------------------------STACK_END------------------------*/
long long max(long long a, long long b)
{
   if(a>b)return a;
   else return b;
}
int main()
{
    int n,c;
    while(scanf("%d %d",&n,&c)==2 && n && c)
    {
        int i,j;
        for(i=1; i<=n; i++)scanf("%d",&arr[i]);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&color[i]);
            for(j=0; j<c; j++)
            {
                if(j==color[i])dp[i][j]=dp[i-1][j]+1;
                else dp[i][j]=dp[i-1][j];
            }
        }
        arr[0] = arr[n+1] = 0;
        push(0);
        for (i = 1; i <= n; i++) {
            while (arr[i] <= arr[peek()])
            {
             pop();
            }
            l[i] = peek() + 1, push(i);
        }
        while(!isempty())
        {
            pop();
        }
        push(n+1);
        for (i = n; i >= 1; i--) {
            while (arr[i] <= arr[peek()])
            {
            pop();
            }
            r[i] = peek() - 1, push(i);
        }
        while(!isempty())
        {
            pop();
        }
        long long ans=0;
        for(int i=1; i<=n; i++)
        {
            int hbe=1;
            for(int j=0; j<c; j++)
            {
                if((dp[r[i]][j]-dp[l[i]-1][j])==0)
                {
                    hbe=0;
                    break;
                }
            }
            if(hbe==1)
            {
            long long val=(long long)(r[i]-l[i]+1)*(long long)arr[i];
            ans=max(ans,val);
            }
        }
        printf("%lld\n",ans);
    }
}
