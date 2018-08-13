#include<stdio.h>
#define ll long long
int main()
{
    int test_case,ii;
    scanf("%d",&test_case);
    for(ii = 1; ii <= test_case; ii++)
    {
        long long ohi,naim,billah;

        scanf("%lld %lld %lld",&ohi, &naim, &billah);

        ll ohi_cake_piece  = ohi*3;
        ll naim_cake_piece = naim*3;
        ll average_piece   = ( ohi_cake_piece + naim_cake_piece ) / 3;

        if(naim_cake_piece < average_piece)
        {
            ll naim_need    = average_piece - naim_cake_piece;
            naim_cake_piece = naim_cake_piece + naim_need;
            ohi_cake_piece  = ohi_cake_piece - naim_need;
        }
        else if(ohi_cake_piece < average_piece)
        {
            ll ohi_need     = average_piece - ohi_cake_piece;
            ohi_cake_piece  = ohi_cake_piece + ohi_need;
            naim_cake_piece = naim_cake_piece - ohi_need;
        }
        ll billah_pay_to_ohi    = ohi_cake_piece - average_piece;
        ll billah_pay_to_naim   = naim_cake_piece - average_piece;
        ll billah_leftover_taka = billah - ( billah_pay_to_ohi + billah_pay_to_naim );
        printf("Case %d: %lld %lld %lld\n", ii, billah_pay_to_ohi, billah_pay_to_naim, billah_leftover_taka);
    }
}
