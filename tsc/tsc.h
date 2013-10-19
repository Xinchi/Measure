/* V 0.1
 * tao comment:
 *  .h for TSC init and log
 *  lib for testing, so that we can use it in any where
 *  please implement functions in tsc.c
 *  Write a makefile to make .a and .so
 *  Write a makefile to install lib with the name tsc
 */

//change it if nessary
inline long long get_tsc(void);
inline long long diff_tsc(long long t1, long long t2); //return the diff

//tsc overhead
long long tsc_overhead;
int test_tsc_overhead(); // set tsc_overhead


//record functions
register long long timestamp1;
register long long timestamp2;

inline int record_begin(void); // timestamp1 = get_tsc() return 0; 
inline int record_end(void);   // timestamp2 = get_tsc() return 0;
long long get_result(); // return timestamp2 - timestamp1 - overhead of tsc;
