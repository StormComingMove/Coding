x  = 3
y = 10
for i in range(x,y):
    if(i==0 or i==1):
        print("not prime")
    elif i>1:
        for num in range(2,i):
            if(i%num== 0):
                break
	    else:
            print(i)