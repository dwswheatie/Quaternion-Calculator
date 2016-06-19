#include <stdio.h>
#include <quaternion.h>

int main(){
	char menuSelect;
	while (menuSelect != 'q'){
		printf("Select an option below: \n");
		printf("'m' to multiply 2 quaternions\n");
		printf("'r' to rotate a vector by a quaternion\n");
		printf("'n' to calculate the norm of a quaternion\n");
		printf("'c' to calculate the conjugate of a quaternion\n");
		printf("'q' to quit the program\n\n");
		scanf("%s", &menuSelect);
		if(menuSelect == 'm'){
			quat a,b,r;
			printf("Enter first quaternion components, beginning ");
			printf("with the scalar,\nand separating each part by a comma\n");
			scanf("%lf,%lf,%lf,%lf",&(a.q0),&(a.q1),&(a.q2),&(a.q3));
			printf("\nEnter the second quaternion components separating\n");
			printf("each component by a comma\n");
			scanf("%lf, %lf, %lf, %lf", &(b.q0),&(b.q1),&(b.q2),&(b.q3));
			r = quat_mult(a,b);
			printf("\nProduct = %.2f + %.2fi + %.2fj + %.2fk\n\n", r.q0, r.q1, r.q2, r.q3);
		}
		else if (menuSelect == 'r'){
			quat a,b,r;
			printf("Enter the quaternion, scalar first, separating\n");
			printf("each component by a comma:\n");
			scanf("%lf, %lf, %lf, %lf", &(a.q0),&(a.q1),&(a.q2),&(a.q3));
			printf("Enter the vector, separating components by commas:\n");
			scanf("%lf, %lf, %lf", &(b.q1),&(b.q2),&(b.q3));
			r = rotVec(a,b);
			printf("New vector:\n");
			printf("[%.2f  %.2f  %.2f]\n\n", r.q1,r.q2,r.q3);
		}
		else if(menuSelect == 'n'){
			quat a;
			printf("Enter the quaternion, scalar first, separating\n");
			printf("each component by a comma:\n");
			scanf("%lf, %lf, %lf, %lf", &(a.q0),&(a.q1),&(a.q2),&(a.q3));
			double r = quat_norm(a);
			printf("\nNorm = %.2f\n\n", r);
		}
		else if(menuSelect == 'c'){
			quat a,r;
			printf("Enter the quaternion, scalar first, separating\n");
			printf("each component by a comma:\n");
			scanf("%lf,%lf,%lf,%lf",&(a.q0),&(a.q1),&(a.q2),&(a.q3));
			r = quat_conj(a);
			printf("Conjugate:\n");
			printf("%.2f + %.2fi + %.2fj + %.2fk\n\n", r.q0,r.q1,r.q2,r.q3);
		}
		else if(menuSelect == 'q'){
			break;
		}
		else{
			printf("Enter a valid selection\n\n");
		}
	}
	return 0;
}
