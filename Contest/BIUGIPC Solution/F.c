#include<stdio.h>

int main()
{
    int test_case,ii;
    scanf("%d",&test_case);
    // current date is: 8/12/2018
    for(ii = 1; ii <= test_case; ii++)
    {
        int day, month, year;
        int T, R, K;
        scanf("%d %d %d", &day, &month, &year);
        scanf("%d %d %d", &T, &R, &K);
        if(year>=2018)
        {
            if(month<8 && year==2018) printf("Case %d: Expired.\n",ii);
            else
            {
                if(day<=12 && month==8 && year==2018)printf("Case %d: Expired.\n",ii);
                else
                {
                    int need_points_to_drive = T - K;

                    if(need_points_to_drive < R)
                    {
                        printf("Case %d: Invalid.\n",ii);
                    }
                    else
                    {
                        int penalty = 10 * ((K *(K+1)) / 2); // through 1 to k, 1*10+2*10+....+10*k = 10*(1+2+...+k) = 10*(k*(k+2))/2
                        printf("Case %d: Valid.\n",ii);
                        printf("Total Penalty Money: %d$.\n",penalty);
                    }
                }
            }
        }
        else printf("Case %d: Expired.\n",ii);

    }
}
