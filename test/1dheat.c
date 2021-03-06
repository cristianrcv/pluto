/*
1dheat.c -- a simple 1D finite difference heat equation stencil calculation
designed to benchmark Cluster OpenMP and pluto
by Tim Douglas (tdouglas@haverford.edu) -- Summer 2008

compile with:
[i|g]cc -Wall -O2 1dheat.c -o 1dheat

the following MD5 code works, but gives different hashes every time for the same
input. wonky. so I've hacked a simple sum, but that's not rigorous...


#include <openssl/md5.h>

unsigned char hash[MD5_DIGEST_LENGTH];

MD5((unsigned char *)A, N * (sizeof(double) / sizeof(char)), hash);

printf("\nMD5 sum: ");
for (i = 0; i < MD5_DIGEST_LENGTH; i++)
	printf("%02x", hash[i]);
*/

#if defined SHOW_ORDER
#include <string.h>
#endif
#include <math.h>   /* for sqrt */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

/* T is number of timesteps
N is size of array, in doubles --
i.e., size 1 = 64 bits = 8 bytes.
size 1024 = 1024 * 64 bits = 1024 * 8 bytes = 8 KB

hence, for our experiments:
  6 KB =   6 *  1024    B =      6144 B ->      6144/8 =       768 doubles
  8 KB =   8 *  1024    B =      8192 B ->      8192/8 =      1024 doubles
 10 KB =  10 *  1024    B =     10240 B ->     10240/8 =      1280 doubles
.75 MB = .75 * (1024^2) B =    786432 B ->    786432/8 =     98304 doubles
  1 MB =   1 * (1024^2) B =   1048576 B ->   1048576/8 =    131072 doubles
  2 MB =   2 * (1024^2) B =   2097152 B ->   2097152/8 =    262144 doubles
 .5 GB =  .5 * (1024^3) B = 536870912 B -> 536870912/8 =  67108864 doubles
.75 GB = .75 * (1024^3) B = 805306368 B -> 805306368/8 = 100663296 doubles */

/* get N and T definitions from decls.h, generated by par_runner.py */
#ifdef HAVE_DECLS
#include "decls.h"
#else
#define N 786432L
#define T 200L
#endif


#ifdef PERFCTR
#include "papiStdEventDefs.h"
#include <papi.h>
#include "papi_defs.h"
#endif


double A[N], new[N];

double cur_time(void) {
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);
    return tv.tv_sec + tv.tv_usec*1.0e-6;
}

int main(int argc, char *argv[]) {
    double run_time, mflops, total = 0, sum_err_sqr = 0;
    char chtotal = 0;
    long int i, t;
    long long n_fp_ops = 0;
    int ops_per_iter = 3; // constant
    int cores;

    if (argc != 2) {
        fprintf(stderr, "usage: %s numcores\n", argv[0]);
        exit(-1);
    }

    cores = atoi(argv[1]);

#ifndef DEBUG
    printf("%2d\t%7.2f\t%7.2f\t%7.2f\t", cores, N/1024.0/cores, N/1024.0, T/1024.0);
#else
    printf("Using array size %ld and %ld timesteps.\n", N, T);
    printf("Filling array randomly...");
#endif

#if defined SHOW_ORDER || defined PERFCTR
    printf("\n");
#endif

    /* seed it with a constant so we can check/compare the results */
    srand(42);
    for (i = 0; i < N; i++)
        A[i] = rand() % 700;

#ifdef DEBUG
    printf("done.\nCalculating...");
#endif

    fflush(stdout);
    run_time = cur_time();

#ifdef PERFCTR
    PERF_INIT;
#endif

    /* pluto start (T,N) */
    for (t = 0; t < T; t++) {
        for (i = 1; i < N-1; i++) {
            new[i] = (A[i-1] + A[i] + A[i+1]) * (1.0/3);
            /* n_fp_ops = n_fp_ops + 3; /*  just a check */

            /* debug[t][i] = new[i]; /* USE THIS ONLY FOR SHOWING THE EXECUTION ORDER */

            /* new[i] = (A[i-1] + A[i] + A[i] + A[i+1]) * (1.0/4); */
            /* n_fp_ops = n_fp_ops + 4; /*  just a check */

        }
        for (i = 0; i < N; i++) {
            A[i] = new[i];
        }
    }
    /* pluto end */

#ifdef PERFCTR
    PERF_EXIT;
    printf("counted %lld FP ops, expected %lld\t", n_fp_ops, ((long long)ops_per_iter)*(N-2)*T);
#endif
    run_time = cur_time() - run_time;
    mflops = (((double) ops_per_iter*(N-2)*T) / run_time) / 1000000L;

#ifndef DEBUG
    printf("%7.2f\t%7.2f\t%7.2f  \t", run_time, mflops, mflops / cores);
#else
    printf("done.\nTime elapsed: %fs\n", run_time);
    printf("MFLOPS: %f\n", ((((double)ops_per_iter*(N-2)*T) / run_time) / 1000000L));
#endif

    for (i = 0; i < N; i++)
        total += A[i];
    printf("sum(A) = %7.2f\t", total);
    for (i = 0; i < N; i++)
        sum_err_sqr += (A[i] - (total/N))*(A[i] - (total/N));
    printf("rms(A) = %7.2f\t", sqrt(sum_err_sqr));
    for (i = 0; i < N*sizeof(A[0]); i++)
        chtotal += ((char *)A)[i];
    printf("sum(rep(A)) = %d\n", chtotal);

    return 0;
}

