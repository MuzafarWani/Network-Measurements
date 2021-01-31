import matplotlib.pyplot as plt

X, Y = [], []
for line in open('iperf_single_client.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[1])
 
plt.plot(X, Y)
X, Y = [], []
for line in open('netperf_single_client.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[1])
  
plt.plot(X, Y)  

plt.xlabel('Data Transfered(MB)') 
plt.ylabel('Bandwidith(MB/s)') 


plt.title("Bandwidth varaition measured with sends from one client") 

plt.ylim(ymin=0)

plt.legend(["iperf", "netperf"], loc ="lower right") 
plt.show()
