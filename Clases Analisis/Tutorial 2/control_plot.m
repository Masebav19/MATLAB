[num,den]=ss2tf(linsys1.A,linsys1.B,linsys1.C,linsys1.D);
TF = tf (num,den)
step(TF)