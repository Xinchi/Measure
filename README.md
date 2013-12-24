Alert!!
Read before view or use!!

This project is the project from the UCSD 2013 Fall CSE 221 OS course.
So if you are taking or you are going to take CSE 221 OS in UCSD. 
Please DO NOT read any codes and documents here! It is a CHEAT!

Otherwise, these codes are published in GPLv2. Free to download and use :-)

By:
    Tao Cai (taocai@ucsd.edu)
    Xinchi Gu (xig015@ucsd.edu)

Good luck and enjoy :-D


Usage:

benchmark:

    nice python benchmark [test_prg] [argv] -n -20
    bash script is also provided

1.
tsc: tsc0.c and tsc3.c
    tsc0; O0
    tsc3; O3

loop: run.c
    run: O0

2.
function: c_function.c
    c_function: O0 (different # number of input)

3.
system_call: tgetpid, tgetppid, sgetpid, sgetppid
    tgetpid and tgetppid call glibc;
    sgetpid and tgetppid call syscall directly;

4.
fork: tfork.c
    tfork: create a process

kthread: thread.c

    make insert: to insert a module
    make remove: remove a module

    tail -0f /var/log/kern.log | grep TAO to capture the output of kernel log 
proceed_data: 
    use handle_kern_log.py to handle the kern log 

5.
context_switch: process.c
    tprocess: output the context_switch
proceed_data:
    handle_process_log.py: handle the context_switch of processes

context_switch_kernel: thread.c
    make insert: to insert a module
    make remove: remove a module

    tail -0f /var/log/kern.log | grep TAOI to capture the output of kernel log
proceed_data:
    use handle_kern_log_I.py to handle the kern log

kprint: thread.c
    make insert: to insert a module
    make remove: remove a module

    tail -0f /var/log/kern.log | grep TAOK to capture the output of kernel log 
proceed_data: 
    use handle_kern_log_K.py to handle the kern log 



    


    
    
