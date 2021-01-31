The code is a simple client-server code in C programming. 
dataclient.c is client code which sends an array of size n, t times over to dataserver.c, the two programs run on two different machines
While the sending is in progress netperf and iperf tools are used to measure different parameters of the two machines like throughput of the channel and the latency.

The figures included show results gotten from two machines with maximum throughput of 110 MB.

To run the dataclient.c, dataserver.c bash arrayclient.sh and arrayserver.sh
