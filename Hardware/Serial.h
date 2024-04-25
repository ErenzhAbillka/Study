#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetCompare2(uint16_t Compare);
void Servo_Down(float Angle);
void Servo_Up(float Angle);

#endif
