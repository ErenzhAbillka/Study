#ifndef __PID_H
#define __PID_H

typedef struct 
{
	float X_Kp;
	float X_Ki;
	float X_Kd;
	float X_err;
	float X_err_sum;
	float X_err_last;	
	
	float Y_Kp;
	float Y_Ki;
	float Y_Kd;
	float Y_err;
	float Y_err_sum;
	float Y_err_last;	
}PID;

void PID_Init(void);
int Servo_pid_x(int x);
int Servo_pid_y(int y);

extern PID pid;
extern int offset_x;
extern int offset_y;

#endif
