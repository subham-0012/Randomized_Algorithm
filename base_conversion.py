num=int(input())
count=0
for i in range(2,num+1):
    result=""
    temp=num
    while(temp>0):
        result+=str(temp%i)
        temp=int(temp/i)
    if(result[0]=='0'):
        count+=1
print(count)