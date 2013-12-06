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
    unsigned long count = 0;

    sr_tcp_hdr_t* tcphdr;
    while (pcap_next_ex(handler, &header, &packet) >= 0)
    {
	sr_ip_hdr_t* iphdr;
	sr_icmp_hdr_t* icmphdr;
	iphdr = (sr_ip_hdr_t*)(packet + sizeof(sr_ethernet_hdr_t));

	if (iphdr->ip_p == ip_protocol_icmp)
	{
	    icmphdr = (sr_icmp_hdr_t*)
		      (packet + sizeof(sr_ethernet_hdr_t) + sizeof(sr_ip_hdr_t));
	    //printf("%d\n", icmphdr->icmp_type);
	    if (icmphdr->icmp_type == icmp_request)
	    {
		t1 = header->ts;
	    }
	    if (icmphdr->icmp_type == icmp_reply)
	    {
		t2 = header->ts;
		//printf("request:%lu,%lu\n", t1.tv_sec, t1.tv_usec);
		//printf("reply:%lu,%lu\n", t2.tv_sec, t2.tv_usec);
		interval = (t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec);
		
		//printf("ICMP,%lu,%f\n", count ,interval * 1.0 / 1000);
		printf("ICMP,%d,%llu\n", count ,interval);
	    }
	}
	if (iphdr->ip_p == ip_protocol_tcp)
	{
	    if (iphdr->ip_src == 171354304) // dst == 192.168.54.10
	    //if (iphdr->ip_src == 37136576) // dst == 192.168.54.10
	    {
		tcphdr = (sr_tcp_hdr_t*) (packet + 
			sizeof(sr_ethernet_hdr_t) +
			sizeof(sr_ip_hdr_t));
		interval = header->ts.tv_sec * 1000000 + header->ts.tv_usec;
		printf("TCP,%lu,%llu,%u\n",count,interval, ntohs(tcphdr->window_size));
	    }
	}
	count++;
    }    
    return 0;
}

