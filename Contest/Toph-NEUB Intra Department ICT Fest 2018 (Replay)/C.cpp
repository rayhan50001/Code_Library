#include <stdio.h>
#include <math.h>
#define MAX 5*100000
int tree[MAX] = {0};
int lazy[MAX] = {-1};
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != -1)
    {
        tree[si] = (se-ss+1)*lazy[si];//add
        if (ss != se)
        {
            lazy[si*2 + 1]   = lazy[si];//add
            lazy[si*2 + 2]   = lazy[si];//add
        }
        lazy[si] = -1;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
        tree[si] = (se-ss+1)*diff;

        if (ss != se)
        {
            lazy[si*2 + 1]   = diff;//add
            lazy[si*2 + 2]   = diff;//add
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != -1)
    {
        tree[si] = (se-ss+1)*lazy[si];//add
        if (ss != se)
        {
            lazy[si*2+1] = lazy[si];//add
            lazy[si*2+2] = lazy[si];//add
        }
        lazy[si] = -1;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
int getSum(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(0, n-1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);

    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}
void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}
int main()
{
  int n,q;
  scanf("%d %d",&n,&q);
  int arr[n+1];
  for(int i=0; i<=n; i++)arr[i]=0;
  constructST(arr, n);
  while(q--)
  {
      int l,r,x;
      scanf("%d %d %d",&l,&r,&x);
      l--;
      r--;
      updateRange(n, l, r, x);
  }
   for(int i=0; i<n; i++)
   {
       printf("%d",getSum(n,i,i));
       if(i<n-1)printf(" ");
   }
   printf("\n");

    return 0;
}
