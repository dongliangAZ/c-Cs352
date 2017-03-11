import random
testcases = ['', 'AHKR HJUYT', 'ytgfrds kjhgfd tfjh', '33 444654', 'hfTY65aE POiuhgt654']
numbers = [3, 1000, 0, -7, -1000]
m=1
for i in range(len(numbers)):
	for j in range(len(testcases)):
		
		f=open('test'+str(m), 'w')
		m=m+1
		k=0
		if numbers[i] != 0:
			k = random.randint(0,2)
		f.write(str(numbers[i]+k)+' '+testcases[j]+'\n')
		f.close()
