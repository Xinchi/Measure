#include "pcap.h"
#include <stdio.h>
#include "sr_protocol.h"

/* prototype of the packet handler */

int main(int argc, char **argv)
{
    char errbuff[256];
    if (argc < 2)
    {
	printf("usage: pcapfile [filename]");
	return 0;
    }
    pcap_t * handler = pcap_open_offline(argv[1], errbuff);
    struct pcap_pkthdr *header;
    const u_char *packet;
    struct timeval t1, t2;
    unsigned long long interval;

    sr_tcp_hdr_t* tcphdr;
    long port_old;
    port_old = 0;
    long port1;
    long port2;
    long port;
    int offset = 1024;
    struct timeval timestamp[100];
    long syn[100];
    long fin[100];
    long count[100] = {0};
    int i;
    while (pcap_next_ex(handler, &header, &packet) >= 0)
    {
	sr_ip_hdr_t* iphdr;
	sr_icmp_hdr_t* icmphdr;
	iphdr = (sr_ip_hdr_t*)(packet + sizeof(sr_ethernet_hdr_t));

	if (iphdr->ip_p == ip_protocol_tcp)
	{
	    //if (iphdr->ip_src == 171354304) // dst == 192.168.54.10
	    //if (iphdr->ip_src == 37136576) // dst == 192.168.54.10
	    {
		tcphdr = (sr_tcp_hdr_t*) (packet + 
			sizeof(sr_ethernet_hdr_t) +
			sizeof(sr_ip_hdr_t));
		port1 = ntohs(tcphdr->dst_port);
		port2 = ntohs(tcphdr->src_port);
		port = port1 > port2 ? port2 : port1;

		port = port - offset;

		count[port]++;
		if (count[port] == 1)
		{
		    timestamp[port] = header->ts;
		}

		if (count[port] == 3)
		{
		    t1 = timestamp[port];
		    t2 = header->ts;
		    //first 3 syn
		    interval = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
		    syn[port] = interval;
		    timestamp[port] = header->ts;
		}

		if (count[port] == 7)
		{
		    t1 = timestamp[port];
		    t2 = header->ts;
		    //first 3 syn
		    interval = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
		    fin[port] = interval;
		}
		//interval = header->ts.tv_sec * 1000000 + header->ts.tv_usec;
		//printf("TCP,%lu,%llu,%u\n",count,interval, ntohs(tcphdr->window_size));
	    }
	}
    }    

    printf("syn\n");
    for (i = 0; i < 100; i++)
    {
	printf("syn,%d, %llu\n", i, syn[i]);
    }
    printf("syn\n");
    for (i = 0; i < 100; i++)
    {
	printf("fin,%d, %llu\n", i, fin[i]);
    }
    return 0;
}

