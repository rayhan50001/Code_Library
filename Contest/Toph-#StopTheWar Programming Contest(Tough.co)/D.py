import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def fast_power(base, power,MOD):
    result = 1
    while power > 0:
        if power % 2 == 1:
            result = (result * base) % MOD
        power = power / 2
        base = (base * base) % MOD
    return result
inputArr = []

def Out(x):
    sys.stdout.write(str(x) + '\n')

def In():
    return sys.stdin.readline().strip()

def inputGrab():
    for line in sys.stdin:
        inputArr.extend(map(str, line.strip().split()))

def main():
    while(1):
        n,m,p=input().split();
        n=int(n)
        m=int(m)
        p=int(p)
        if(n==0 and m==0 and p==0):
            break
        ans=fast_power(n, m, p)
        if(ans<0):
            ans+=p
        print(ans)
    
    
if __name__ == '__main__':
    main()
