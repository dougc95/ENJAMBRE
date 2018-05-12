//Author: Mateo Antonio Rengel Acebey
// This library has been done starting from other code that can be found at the url: 
//https://www.luisllamas.es/arduino-motor-dc-tb6612fng/
//this code looks for a better and easier way to control motors, specially using the driver 
//
#ifndef controlMotores_h
#define controlMotores_h//define la clase
#include "arduino.h"//anexa las funciones basicas de arduino como delay()

class controlMotores
{
	private://variable interna del programa
		int _pinPWMA,_pinPWMB,_pinAIN1,_pinAIN2,_pinBIN1,_pinBIN2,_pinSTBY;//configuracion de pines
		enum _moveDirection{forward,backward};
		enum _turnDirection{clockwise,counterClockwise};
		int _direction,_speed;
		int _pinMotor[3];
		int _pinMotorA[3]={_pinPWMA, _pinAIN2, _pinAIN1};
		int _pinMotorB[3]={_pinPWMB, _pinBIN1, _pinBIN2 };
	public://funciones que puede ver el usuario
	//Constructor toma las variables que se usaran una vez conectada la tarjeta al driver
		controlMotores(int pinPWMA, int pinPWMB, int pinAIN1, int pinAIN2,
		 int pinBIN1,int pinBIN2,int pinSTBY);

		void move(int direction, int speed);
		void turn(int direction, int speed);
		void fullStop();
		void moveMotorForward(const int pinMotor[3], int speed);
		void moveMotorBackward(const int pinMotor[3], int speed);
		void stopMotor(const int pinMotor[3]);
		void enableMotors();
		void disableMotors();
};
#endif