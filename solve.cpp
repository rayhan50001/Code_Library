//Prime Number
#import <Foundation/Foundation.h>

int main ()
{
  int n=11;
  int f=0,i,j;
  for(i=1; i<=n; i++)
  {
      if(n%i==0)f++;
  }
  if(f==2)NSLog(@"It's Prime Number");
  else NSLog(@"It's Not Prime Number");

   return 0;
}
// gcd

#import <Foundation/Foundation.h>
@interface number_theory:NSObject
{
    int aa;
    int bb;
}
-(void) print_gcd;
-(void) print_lcm;
-(void) seta:int a setb: int b;
-(int) geta;
-(int) getb;
@end
@implementation number_theory
-(void) print_gcd()
{

}
-(void) print_lcm()
{

}
-(void) seta: int a setb: int b
{
    aa=a;
    bb=b;
}

int main ()
{
  NSAutoreleasePool *pool = [[NSAutoreleasePool allco] init];
  number_theory *gcd = [[number_theory alloc] init];
  [gcd seta:2 setb:3];
  NSLog(@"Gcd Of %i and %i is: ",[gcd geta],[gcd getb]);
   number_theory *lcm = [[number_theory alloc] init];
  [lcm seta:5 setb:20];


   return 0;
}
