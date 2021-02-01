The code is a simple client-server code in C programming. 
dataclient.c is client code which sends an array of size n, any number of times over to dataserver.c, the two programs run on two different machines
While the sending the data, netperf and iperf tools are used to measure different parameters of the two machines like throughput of the channel and the latency.

The plots included show results gotten from  machines with maximum throughput of 110 MB/s.

To run the dataclient.c, dataserver.c bash arrayclient.sh and arrayserver.sh
