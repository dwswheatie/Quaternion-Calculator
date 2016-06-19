#include <math.h>

typedef struct {
		double q0;
		double q1;
		double q2;
		double q3;
} quat;

quat quat_conj(quat a);
quat quat_mult(quat a, quat b);
double quat_norm(quat a);
quat quat_inv(quat a);
quat rotVec(quat a, quat b);

/*Calculates the conjugate of a quaternion*/
quat quat_conj(quat a){
	quat r;
	r.q0 = a.q0;
	r.q1 = -a.q1;
	r.q2 = -a.q2;
	r.q3 = -a.q3;
	return r;
}
/*Mulktiply 2 quaternions by each other*/
quat quat_mult(quat a, quat b){
	quat r;
	r.q0 = a.q0*b.q0 - a.q1*b.q1 - a.q2*b.q2 - a.q3*b.q3;
	r.q1 = a.q0*b.q1 + a.q1*b.q0 - a.q2*b.q3 + a.q3*b.q2;
	r.q2 = a.q0*b.q2 + a.q1*b.q3 + a.q2*b.q0 - a.q3*b.q1;
	r.q3 = a.q0*b.q3 - a.q1*b.q2 + a.q2*b.q1 + a.q3*b.q0;
	return r;
}
/*Calculates the norm of a quaternion*/
double quat_norm(quat a){
	double r;
	r = sqrt(pow(a.q0,2)+pow(a.q1,2)+pow(a.q2,2)+pow(a.q3,2));
	return r;
}
/*Calculates the inverse of a quaternion*/
quat quat_inv(quat a){
	quat r;
	r = quat_conj(a);
	r.q0 = r.q0/quat_norm(a);
	r.q1 = r.q1/quat_norm(a);
	r.q2 = r.q2/quat_norm(a);
	r.q3 = r.q3/quat_norm(a);
	return r;
}
/*Rotate a vector about a quaternion*/
quat rotVec(quat a, quat b){
	quat u, r;
	b.q0 = 0;
	u.q0 = a.q0/quat_norm(a);
	u.q1 = a.q1/quat_norm(a);
	u.q2 = a.q2/quat_norm(a);
	u.q3 = a.q3/quat_norm(a);
	r = quat_mult(quat_mult(u,b), quat_inv(a));
	return r;
}