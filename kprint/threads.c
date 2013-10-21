#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>  // for threads
#include <linux/sched.h>  // for task_struct
#include <linux/time.h>   // for using jiffies  
#include <linux/timer.h>




static struct task_struct *thread1;

unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

int thread_fn(void* input) {
    unsigned long t2;
    unsigned long j0,j1;
    int delay = 60*HZ;

    j0 = jiffies; 
    j1 = j0 + delay; 

    int number = (int) input;


    printk(KERN_INFO "we are scheduled\n");
    while (time_before(jiffies, j1)) 
    {
	t2 = get_tsc();
	printk("TAOI:%d:ktime=%ld\n",number, t2);
	schedule(); // force to schedule
    }

    return 0;
}

int thread_init (void) {
    char  our_thread[4]="Tao";
    printk(KERN_INFO "in init\n");

    unsigned long t1;
    unsigned long t2;
    int i;
    int max;
    max = 20000;

    for (i = 0; i < max; i++)
    {
	t1 = get_tsc();
        printk("TAzz:printk=%ld\n", i);
	t2 = get_tsc();
        printk("TAOK:%d:printk=%ld\n", i,t2 - t1);
    }
    
    return 0;
}

void thread_cleanup(void) {
    

}
MODULE_LICENSE("GPL");    
module_init(thread_init);
module_exit(thread_cleanup);
