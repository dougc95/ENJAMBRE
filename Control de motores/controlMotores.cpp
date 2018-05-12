#include "controlMotores.h"//incluyo mi libreria
#include "arduino.h"//funciones basicas de arduino


controlMotores::controlMotores(int pinPWMA, int pinPWMB, int pinAIN1, int pinAIN2,
		 int pinBIN1,int pinBIN2,int pinSTBY)
{
	pinMode(pinPWMA,OUTPUT);
	pinMode(pinPWMB,OUTPUT);
	pinMode(pinAIN1,OUTPUT);
	pinMode(pinAIN2,OUTPUT);
	pinMode(pinBIN1,OUTPUT);
	pinMode(pinBIN2,OUTPUT);
	pinMode(pinSTBY,OUTPUT);
	_pinPWMA=pinPWMA;
	_pinPWMB=pinPWMB;
	_pinAIN1=pinAIN1;
	_pinAIN2=pinAIN2;
	_pinBIN1=pinBIN1;
	_pinBIN2=pinBIN2;
	_pinSTBY=pinSTBY;

	//pinMotorA[3]={pinPWMA, pinAIN2, pinAIN1};
	//pinMotorB[3]={pinPWMB, pinBIN2, pinBIN1};
	//_pinMotorA[3]=pinMotorA[3];
	//_pinMotorB[3]=pinMotorB[3];

	//_moveDirection{forward,backward}=moveDirection{forward,backward};
	//_turnDirection{clockwise,counterClockwise}=turnDirection{clockwise,counterClockwise};
	//_direction,_speed=direction,_speed;
	//_pinMotor[3]=pinMotor[3];

}
void controlMotores::move(int direction, int speed)
{
	if (direction == forward)
   {
      moveMotorForward(_pinMotorA, _speed);
      moveMotorForward(_pinMotorB, _speed);
   }
   else
   {
      moveMotorBackward(_pinMotorA, _speed);
      moveMotorBackward(_pinMotorB, _speed);
   }	
}
void controlMotores::turn(int direction, int speed)
{
   if (direction == forward)
   {
      moveMotorForward(_pinMotorA, _speed);
      moveMotorBackward(_pinMotorB, _speed);
      //moveMotorForward(pinMotorB, speed);
   }
   else
   {
      moveMotorBackward(_pinMotorA, _speed);
      moveMotorForward(_pinMotorB, _speed);
   }
}
void controlMotores::fullStop()
{
   disableMotors();
   stopMotor(_pinMotorA);
   stopMotor(_pinMotorB);
}
void controlMotores::moveMotorForward(const int pinMotor[3], int speed)
{
   digitalWrite(_pinMotor[1], HIGH);
   digitalWrite(_pinMotor[2], LOW);
 
   analogWrite(_pinMotor[0], _speed);
}
void controlMotores::moveMotorBackward(const int pinMotor[3], int speed)
{
   digitalWrite(_pinMotor[1], LOW);
   digitalWrite(_pinMotor[2], HIGH);
 
   analogWrite(_pinMotor[0], speed);
}
void controlMotores::stopMotor(const int pinMotor[3])
{
   digitalWrite(_pinMotor[1], LOW);
   digitalWrite(_pinMotor[2], LOW);
 
   analogWrite(_pinMotor[0], 0);
}
void controlMotores::enableMotors()
{
   digitalWrite(_pinSTBY, HIGH);
}
void controlMotores::disableMotors()
{
   digitalWrite(_pinSTBY, LOW);
}