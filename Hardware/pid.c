#include "stm32f10x.h"                  // Device header
#include "OPENMV.h"
#include "PID.H"

PID pid;


//void I_xianfu(int max);

//uint16_t VKp, VKi;
//float last_filt_velocity, filt_velocity, velocity_sum = 0;

void PID_Init()
{
	pid.X_Kp = 0.2;
	pid.X_Ki = 0.006;
	pid.X_Kd = 0;
	pid.X_err = 0;
	pid.X_err_sum = 0;
	pid.X_err_last = 0;
	
	pid.Y_Kp=0.2;
	pid.Y_Ki=0.004;
	pid.Y_Kd=0;
	pid.Y_err=0;
	pid.Y_err_sum=0;
	pid.Y_err_last=0;
}

int Servo_pid_x(int x)
{
	int out;
	
	pid.X_err = x - 127;
	pid.X_err_sum += pid.X_err;
	out = pid.X_Kp*(pid.X_err)
		+ pid.X_Ki*(pid.X_err_sum)
		+ pid.X_Kd*(pid.X_err - pid.X_err_last);
	pid.X_err_last = pid.X_err;
	
	return out;
}

int Servo_pid_y(int y)
{
	int out;
		
	pid.Y_err = y - 120;
	pid.Y_err_sum += pid.Y_err;
	out = pid.Y_Kp*(pid.Y_err)
		+ pid.Y_Ki*(pid.Y_err_sum)
		+ pid.Y_Kd*(pid.Y_err - pid.Y_err_last);
	pid.Y_err_last = pid.Y_err;
	
	return out;
}








///*PID调参(此为速度环)*/
///*KP:误差值 KI:误差累加值 KD:阻尼*/
//uint16_t Speed_PID_Value(uint16_t velocity)
//{	
//	float a = 0.3;														//滤波系数(算系数)
//	filt_velocity = a * velocity + (1 - a) * last_filt_velocity;		//一阶速度滤波
//	
//	velocity_sum += filt_velocity;										//速度的累加
//	I_xianfu(3000);														//限幅
//	
//	last_filt_velocity = filt_velocity;									//记录为上一次的速度
//	
//	return VKp * filt_velocity + VKi * velocity_sum;
//}

//void I_xianfu(int max)
//{
//	if(velocity_sum > max) velocity_sum = max;
//	if(velocity_sum < -max)	velocity_sum = max;
//}




