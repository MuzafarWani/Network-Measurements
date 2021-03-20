import matplotlib.pyplot as plt

X, Y = [], []
for line in open('iperf_multiple_client.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[1])
 
plt.plot(X, Y,"-o")
X, Y = [], []
for line in open('netperf_multiple_client.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[1])
  
plt.plot(X, Y,"-o")

X, Y = [], []
for line in open('multiple_client_code_data.txt', 'r'):
  values = [float(s) for s in line.split()]
  X.append(values[0])
  Y.append(values[1])
  
plt.plot(X, Y,"-o")

plt.xlabel('Data Transfered(MB)') 
plt.ylabel('Bandwidith(MB/s)') 


plt.title("Bandwidth varaition measured with sends from multiple clients") 

plt.ylim(ymin=0)

plt.legend(["iperf", "netperf", "code measured"], loc ="lower right") 
plt.show()
