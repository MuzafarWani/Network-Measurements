The code is a simple client-server code in C programming. 
dataclient.c is client code which sends an array of size n, any number of times over to dataserver.c, the two programs run on two different machines
While the sending the data, netperf and iperf tools are used to measure different parameters of the two machines like throughput of the channel and the latency.

The plots included show results gotten from  machines with maximum throughput of 110 MB/s.

To run the dataclient.c, dataserver.c bash  csewsxxclient.sh and server.sh

The folder plot has four plots.

The graphs have the below details:
1. Single_clients_graph.png

This has the two curves one for iperf and one for netperf. The x-axis represents the data measured by the code that is being transferred between client and server code. the y-axis is the measure of the bandwidth on the server side by iperf and netperf. This graph basically shows the variation in the bandwidth between the two nodes when a certain amount of data is being transferred between them.

2. Multiple_clients_graph,png

This one represents the variation of bandwidth on one server while sending data to that server from multiple clients. The x-axis represents the total data sent from three clients to one server and the y-axis represents the variation in the bandwidth on the server side.  The effect of having multiple clients and using the same client to send many times is almost same

3.Boxplot_iperf.png,Boxplot_netperf.png

This one shows the variation as shown in the above two graphs using boxplot. I calculated the median,standard deviation for the data sent between machines and also for the bandwidth measured  and used the boxplot to plot the both. That is what the two boxes on the x-axis are showing.


