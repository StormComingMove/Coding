'''
n = 4 (input)
*
**
***
****

'''

x = int(input())
for line in range(1, x+1): 					# line -> traverse from 1 to x
	for star in range(0, line): 			# star ->traverse from 0 to line-1, because line needs line no. of stars
		print("*", end ='')
	print() 								# after each line we need eol(end of line)
