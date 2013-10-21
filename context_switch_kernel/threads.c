#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>  // for threads
#include <linux/sched.h>  // for task_struct
#include <linux/time.h>   // for using jiffies  
#include <linux/timer.h>




static struct task_struct *thread1;
static struct task_struct *thread2;
static struct task_struct *thread3;
static struct task_struct *thread4;
static struct task_struct *thread5;
static struct task_struct *thread6;

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

    thread1 = kthread_create(thread_fn,(void*)1,our_thread);
    thread2 = kthread_create(thread_fn,(void*)2,our_thread);
    thread3 = kthread_create(thread_fn,(void*)3,our_thread);
    /*
    thread4 = kthread_create(thread_fn,(void*)4,our_thread);
    thread5 = kthread_create(thread_fn,(void*)5,our_thread);
    thread6 = kthread_create(thread_fn,(void*)6,our_thread);
    */
	//printk(KERN_INFO, "TAO:kthread_create_time=%ld\n", t2 - t1);
    
	//printk("TAO:%d:kthread_create_time=%ld\n", i,(t2 - t1));
    if((thread1))
    {
	printk(KERN_INFO "helloworld\n");
	wake_up_process(thread1);
    }

    if((thread2))
    {
	printk(KERN_INFO "helloworld\n");
	wake_up_process(thread2);
    }
    if((thread3))
    {
	printk(KERN_INFO "helloworld\n");
	wake_up_process(thread3);
    }
    /*
    if((thread4))
    {
	printk(KERN_INFO "helloworld\n");
	wake_up_process(thread4);
    }
    if((thread5))
    {
	printk(KERN_INFO "helloworld\n");
	wake_up_process(thread5);
    }
    if((thread6))
    {
	printk(KERN_INFO "helloworld\n");
	wake_up_process(thread6);
    }
    */
    return 0;
}

void thread_cleanup(void) {
    

}
MODULE_LICENSE("GPL");    
module_init(thread_init);
module_exit(thread_cleanup);
