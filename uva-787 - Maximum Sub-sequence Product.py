from sys import stdin
for line in stdin:
        lll=line.split()
        arr = [int(x) for x in lll]
        n=len(arr)-1                       
        max_ending_here=1;
        min_ending_here=1;
        max_so_far=1
        for i in range(n):
            if(arr[i]>0):
                max_ending_here=max_ending_here*arr[i]
                min_ending_here=min(min_ending_here*arr[i],1)
            elif(arr[i]==0):
                max_ending_here=1
                max_ending_here=1
            else:
                tmp=max_ending_here
                max_ending_here=max(min_ending_here*arr[i],1)
                min_ending_here=tmp*arr[i]
            if(max_so_far<max_ending_here):
                max_so_far=max_ending_here
        mx=-9999999999
        if(max_so_far==1):
            f=0
            for i in range(n):
                if(arr[i]==max_so_far):
                    f=1
                    break
                else:
                      mx=max(mx,arr[i])
            if(f==0):
                max_so_far=mx
        print(max_so_far)
            
