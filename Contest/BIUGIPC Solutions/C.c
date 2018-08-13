#include<stdio.h>
#define ll long long
int main()
{
        ll A, B, C, D;
        ll n;
        scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
        scanf("%lld",& n);
        ll price[5];
        price[0] = A;
        price[1] = B;
        price[2] = C;
        price[3] = D;
        int i;
        if(n == 1)
        {
            price[0] *= 4;//0.25*4 = 1 Litter
            price[1] *= 2;//0.5*2 = 1 Litter
            ll min = 99999999999999999;
            for (i = 0; i < 3; i++)
            {
                if(min > price[i])
                {
                    min = price[i];
                }
            }
            printf("%lld\n", min);
        }
        else
        {
            price[0] *= 8;// 0.25*8= 2 litter
            price[1] *= 4;// 0.5*4 = 2 litter
            price[2] *= 2;// 1*2 = 2 litter

            ll min = 999999999999999;
            for(i = 0; i < 4; i++)
            {
                if(min > price[i])
                {
                    min = price[i];
                }
            }
            if(n % 2 == 0)
            {
                printf("%lld\n", (n / 2) * min);
            }
            else
            {
                ll min_new = 999999999999999;
                for (i = 0; i < 3; i++)
                {
                    if(min_new > price[i])
                    {
                        min_new = price[i];
                    }
                }
                printf("%lld\n", ((n / 2) * min) + (min_new / 2));
            }
        }
}



