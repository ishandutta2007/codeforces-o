x=int(input())
lcopy=[]
l=list(map(int,input().split()))
lcopy+=l
lcopy.remove(max(lcopy))
l.remove(min(l))
minns=max(lcopy)-min(lcopy)
minns=min(minns,max(l)-min(l))
print(minns)