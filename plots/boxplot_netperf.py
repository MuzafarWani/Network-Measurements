import matplotlib.pyplot as plt 
import numpy as np 
  
  
# Creating dataset 
np.random.seed(10)  
  
data_1 = np.random.normal(130, 30, 200) 
data_2 = np.random.normal(107, 23, 200)  
data = [data_1, data_2] 
  
fig = plt.figure(figsize =(10, 7)) 
ax = fig.add_subplot(111) 
  
# Creating axes instance 
#ax = fig.add_axes([0, 0, 1, 1]) 

ax.set_xticklabels(['Data Transfered(MB)', 'netperf values(MB/s)']) 
  
# Creating plot 
bp = plt.boxplot(data) 

plt.title("Bandwidth varaition with netperf") 
 
plt.ylim(ymin=0) 
# show plot 
plt.show() 
