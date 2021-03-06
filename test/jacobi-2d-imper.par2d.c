#include <omp.h>
#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))









int t1, t2, t3, t4, t5, t6;

register int lb, ub, lb1, ub1, lb2, ub2;
register int lbv, ubv;

omp_set_nested(1);
omp_set_num_threads(2);
/* Generated from PLUTO-produced CLooG file by CLooG v0.14.1 64 bits in 0.27s. */
if ((T >= 1) && (N >= 4)) {
    for (t1=-2; t1<=floord(5*T+2*N-7,32); t1++) {
        lb1=max(max(max(0,ceild(64*t1-2*N-83,160)),ceild(32*t1-3*T-N+4,32)),ceild(32*t1-T-N-26,64));
        ub1=min(min(min(floord(64*t1+3*N+115,160),floord(32*t1+N+58,64)),floord(8*t1+15,8)),floord(2*T+N-3,32));
        #pragma omp parallel for shared(t1,lb1,ub1) private(lb2,ub2,t2,t3,t4,t5,t6)
        for (t2=lb1; t2<=ub1; t2++) {
            lb2=max(max(max(max(ceild(32*t1-32*t2-T+1,32),0),ceild(32*t2-N-27,32)),ceild(64*t1-64*t2-29,96)),ceild(64*t1-96*t2-29,64));
            ub2=min(min(min(min(floord(32*t1-32*t2+31,32),floord(64*t1-96*t2+N+61,64)),floord(2*T+N-3,32)),floord(32*t2+N+27,32)),floord(64*t1-64*t2+N+61,96));
            #pragma omp parallel for shared(t1,t2,lb1,ub1,lb2,ub2) private(t3,t4,t5,t6)
            for (t3=lb2; t3<=ub2; t3++) {
                if ((t1 <= floord(64*t2+96*t3-N+1,64)) && (t2 <= t3) && (t3 >= ceild(N-1,32))) {
                    if ((-N+1)%2 == 0) {
                        for (t5=max(32*t3-N+4,32*t2); t5<=min(32*t3,32*t2+31); t5++) {
                            if ((-N+1)%2 == 0) {
                                a[-32*t3+t5+N-2][N-2]=b[-32*t3+t5+N-2][N-2]; ;
                            }
                        }
                    }
                }
                if ((t1 <= floord(96*t2+64*t3-N+1,64)) && (t2 >= max(ceild(N-1,32),ceild(32*t3+1,32)))) {
                    if ((-N+1)%2 == 0) {
                        for (t6=max(32*t2-N+4,32*t3); t6<=min(32*t2,32*t3+31); t6++) {
                            if ((-N+1)%2 == 0) {
                                a[N-2][-32*t2+t6+N-2]=b[N-2][-32*t2+t6+N-2]; ;
                            }
                        }
                    }
                }
                if (N == 4) {
                    for (t4=max(max(max(0,16*t2-1),16*t3-1),32*t1-32*t2-32*t3); t4<=min(min(min(T-1,32*t1-32*t2-32*t3+31),16*t3+14),16*t2+14); t4++) {
                        b[2][2]=0.2*(a[2][2]+a[2][2 -1]+a[2][1+2]+a[1+2][2]+a[2 -1][2]); ;
                        a[2][2]=b[2][2]; ;
                    }
                }
                for (t4=max(max(max(0,ceild(32*t2-N+2,2)),ceild(32*t3-N+2,2)),32*t1-32*t2-32*t3); t4<=min(min(min(min(min(16*t2-2,16*t3-2),floord(32*t3-N+32,2)),T-1),32*t1-32*t2-32*t3+31),floord(32*t2-N+32,2)); t4++) {
                    for (t5=32*t2; t5<=2*t4+N-2; t5++) {
                        for (t6=32*t3; t6<=2*t4+N-2; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                        a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                    }
                    for (t6=32*t3; t6<=2*t4+N-1; t6++) {
                        a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                    }
                }
                for (t4=max(max(max(16*t2-1,0),ceild(32*t3-N+2,2)),32*t1-32*t2-32*t3); t4<=min(min(min(16*t3-2,T-1),32*t1-32*t2-32*t3+31),floord(32*t2-N+32,2)); t4++) {
                    for (t6=32*t3; t6<=2*t4+N-2; t6++) {
                        b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                    }
                    for (t5=2*t4+3; t5<=2*t4+N-2; t5++) {
                        for (t6=32*t3; t6<=2*t4+N-2; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                        a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                    }
                    for (t6=32*t3; t6<=2*t4+N-1; t6++) {
                        a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                    }
                }
                for (t4=max(max(max(16*t3-1,0),ceild(32*t2-N+2,2)),32*t1-32*t2-32*t3); t4<=min(min(min(16*t2-2,floord(32*t3-N+32,2)),T-1),32*t1-32*t2-32*t3+31); t4++) {
                    for (t5=32*t2; t5<=2*t4+N-2; t5++) {
                        b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                        for (t6=2*t4+3; t6<=2*t4+N-2; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                        a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                    }
                    for (t6=2*t4+3; t6<=2*t4+N-1; t6++) {
                        a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                    }
                }
                for (t4=max(max(max(0,ceild(32*t3-N+2,2)),32*t1-32*t2-32*t3),ceild(32*t2-N+33,2)); t4<=min(min(min(T-1,32*t1-32*t2-32*t3+31),16*t2-2),floord(32*t3-N+32,2)); t4++) {
                    for (t5=32*t2; t5<=32*t2+31; t5++) {
                        for (t6=32*t3; t6<=2*t4+N-2; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                        a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                    }
                }
                for (t4=max(max(max(ceild(32*t3-N+33,2),32*t1-32*t2-32*t3),0),ceild(32*t2-N+2,2)); t4<=min(min(min(16*t3-2,T-1),32*t1-32*t2-32*t3+31),floord(32*t2-N+32,2)); t4++) {
                    for (t5=32*t2; t5<=2*t4+N-2; t5++) {
                        for (t6=32*t3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                    for (t6=32*t3; t6<=32*t3+31; t6++) {
                        a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                    }
                }
                if (N >= 5) {
                    for (t4=max(max(max(16*t2-1,16*t3-1),0),32*t1-32*t2-32*t3); t4<=min(min(min(floord(32*t3-N+32,2),T-1),32*t1-32*t2-32*t3+31),floord(32*t2-N+32,2)); t4++) {
                        for (t6=2*t4+2; t6<=2*t4+N-2; t6++) {
                            b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                        }
                        for (t5=2*t4+3; t5<=2*t4+N-2; t5++) {
                            b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                            for (t6=2*t4+3; t6<=2*t4+N-2; t6++) {
                                b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                                a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                            }
                            a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                        }
                        for (t6=2*t4+3; t6<=2*t4+N-1; t6++) {
                            a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                        }
                    }
                }
                for (t4=max(max(max(max(16*t2-1,0),ceild(32*t3-N+2,2)),32*t1-32*t2-32*t3),ceild(32*t2-N+33,2)); t4<=min(min(min(min(T-1,16*t3-2),16*t2+14),32*t1-32*t2-32*t3+31),floord(32*t3-N+32,2)); t4++) {
                    for (t6=32*t3; t6<=2*t4+N-2; t6++) {
                        b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                    }
                    for (t5=2*t4+3; t5<=32*t2+31; t5++) {
                        for (t6=32*t3; t6<=2*t4+N-2; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                        a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                    }
                }
                for (t4=max(max(max(max(ceild(32*t3-N+33,2),16*t3-1),0),ceild(32*t2-N+2,2)),32*t1-32*t2-32*t3); t4<=min(min(min(min(16*t2-2,T-1),32*t1-32*t2-32*t3+31),16*t3+14),floord(32*t2-N+32,2)); t4++) {
                    for (t5=32*t2; t5<=2*t4+N-2; t5++) {
                        b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                        for (t6=2*t4+3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                    for (t6=2*t4+3; t6<=32*t3+31; t6++) {
                        a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                    }
                }
                for (t4=max(max(max(0,32*t1-32*t2-32*t3),ceild(32*t3-N+33,2)),ceild(32*t2-N+33,2)); t4<=min(min(min(T-1,32*t1-32*t2-32*t3+31),16*t2-2),16*t3-2); t4++) {
                    for (t5=32*t2; t5<=32*t2+31; t5++) {
                        for (t6=32*t3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                }
                for (t4=max(max(max(0,32*t1-32*t2-32*t3),16*t3-1),ceild(32*t2-N+33,2)); t4<=min(min(min(T-1,32*t1-32*t2-32*t3+31),16*t2+14),floord(32*t3-N+32,2)); t4++) {
                    for (t6=2*t4+2; t6<=2*t4+N-2; t6++) {
                        b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                    }
                    for (t5=2*t4+3; t5<=32*t2+31; t5++) {
                        b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                        for (t6=2*t4+3; t6<=2*t4+N-2; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                        a[-2*t4+t5-1][N-2]=b[-2*t4+t5-1][N-2]; ;
                    }
                }
                for (t4=max(max(max(16*t2-1,0),ceild(32*t3-N+33,2)),32*t1-32*t2-32*t3); t4<=min(min(min(T-1,16*t3-2),32*t1-32*t2-32*t3+31),16*t2+14); t4++) {
                    for (t6=32*t3; t6<=32*t3+31; t6++) {
                        b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                    }
                    for (t5=2*t4+3; t5<=32*t2+31; t5++) {
                        for (t6=32*t3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                }
                for (t4=max(max(max(16*t2-1,ceild(32*t3-N+33,2)),0),32*t1-32*t2-32*t3); t4<=min(min(min(T-1,32*t1-32*t2-32*t3+31),16*t3+14),floord(32*t2-N+32,2)); t4++) {
                    for (t6=2*t4+2; t6<=32*t3+31; t6++) {
                        b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                    }
                    for (t5=2*t4+3; t5<=2*t4+N-2; t5++) {
                        b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                        for (t6=2*t4+3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                    for (t6=2*t4+3; t6<=32*t3+31; t6++) {
                        a[N-2][-2*t4+t6-1]=b[N-2][-2*t4+t6-1]; ;
                    }
                }
                for (t4=max(max(max(0,32*t1-32*t2-32*t3),16*t3-1),ceild(32*t2-N+33,2)); t4<=min(min(min(T-1,16*t3+14),32*t1-32*t2-32*t3+31),16*t2-2); t4++) {
                    for (t5=32*t2; t5<=32*t2+31; t5++) {
                        b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                        for (t6=2*t4+3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                }
                for (t4=max(max(max(max(max(16*t2-1,0),32*t1-32*t2-32*t3),ceild(32*t3-N+33,2)),16*t3-1),ceild(32*t2-N+33,2)); t4<=min(min(min(T-1,16*t3+14),32*t1-32*t2-32*t3+31),16*t2+14); t4++) {
                    for (t6=2*t4+2; t6<=32*t3+31; t6++) {
                        b[2][-2*t4+t6]=0.2*(a[2][-2*t4+t6]+a[2][-2*t4+t6-1]+a[2][1+-2*t4+t6]+a[1+2][-2*t4+t6]+a[2 -1][-2*t4+t6]); ;
                    }
                    for (t5=2*t4+3; t5<=32*t2+31; t5++) {
                        b[-2*t4+t5][2]=0.2*(a[-2*t4+t5][2]+a[-2*t4+t5][2 -1]+a[-2*t4+t5][1+2]+a[1+-2*t4+t5][2]+a[-2*t4+t5-1][2]); ;
                        for (t6=2*t4+3; t6<=32*t3+31; t6++) {
                            b[-2*t4+t5][-2*t4+t6]=0.2*(a[-2*t4+t5][-2*t4+t6]+a[-2*t4+t5][-2*t4+t6-1]+a[-2*t4+t5][1+-2*t4+t6]+a[1+-2*t4+t5][-2*t4+t6]+a[-2*t4+t5-1][-2*t4+t6]); ;
                            a[-2*t4+t5-1][-2*t4+t6-1]=b[-2*t4+t5-1][-2*t4+t6-1]; ;
                        }
                    }
                }
            }
        }
    }
}
/* End of CLooG code */

