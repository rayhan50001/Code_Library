// start from right
#define setbit(mask,i) mask|=(1<<i) // mask = 1010 i=2 then mask = 1110
#define unsetbit(mask,i) mask&!(1<<i) // mask = 1010 i=3 then mask = 0010
#define checkbit(mask,i) mask&(1<<i) // mask = 1010 i=3 then mask = 1000

