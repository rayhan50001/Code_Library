#include<stdio.h>
int arr[100001];
int dp[100001][31];
int l[100001];
int r[100001];
int color[100001];
/*--------------------------STACK-----------------------------------*/
int MAXSIZE=1000001;
int stack[1000001];
int top = -1;

int isempty()
{

    if(top <= -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if(top >= MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

void pop()
{
    if(!isempty())
    {
        top = top - 1;
    }
}

void push(int data)
{

    if(!isfull())
    {
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
//        push(0);
//        for (i = 1; i <= n; i++) {
//            while (arr[i] <= arr[peek()])
//            {
//             pop();
//            }
//            l[i] = peek() + 1, push(i);
//        }
//        while(!isempty())
//        {
//            pop();
//        }
//        push(n+1);
//        for (i = n; i >= 1; i--) {
//            while (arr[i] <= arr[peek()])
//            {
//            pop();
//            }
//            r[i] = peek() - 1, push(i);
//        }
        long long ans=0;
        i=1;
        int tp;
        while (i <= n)
        {
            if (isempty() || arr[peek()] <= arr[i])
                push(i++);
            else
            {
                tp = peek();  // store the top index
                pop();  // pop the top
                int curr=peek();
                int hoise=1;
                for(j=0; j<c; j++)
                {
                    if((dp[curr][j]-dp[i-1][j])==0)
                    {
                        hoise=0;
                        break;
                    }
                }
                if(hoise)
                {
                    long long area_with_top = (long long)arr[tp] * (long long)(isempty() ? i : i - peek() - 1);
                    if (ans < area_with_top)
                    {
                        ans = area_with_top;
                    }
                }
            }
        }
        while(!isempty())
        {
            tp = peek();
            pop();
            int curr=peek();
            int hoise=1;
            for(j=0; j<c; j++)
            {
                if((dp[curr][j]-dp[i-1][j])==0)
                {
                    hoise=0;
                    break;
                }
            }
            if(hoise)
            {
                long long area_with_top = (long long)arr[tp] * (long long)(isempty() ? i : i - peek() - 1);

                if (ans < area_with_top)
                    ans = area_with_top;
            }
        }
        printf("%lld\n",ans);
    }
}

