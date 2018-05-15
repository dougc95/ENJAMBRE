//Author: Mateo Antonio Rengel Acebey
//Author: Mateo Antonio Rengel Acebey
//The current code provides the .cpp file of this new library.
/*It looks for an easier way to control micromotors, specially using 
the driver dual TB6612FNG */

#include "motor.h"//add motor.h library
#include "arduino.h"//add the basics functions of arduino like delay() for example

motor::motor(int pinPWMA, int pinPWMB, int pinAIN1, int pinAIN2,
		 int pinBIN1,int pinBIN2,int pinSTBY)
{
	//configure the type of the constructor's variables 	
	pinMode(pinPWMA,OUTPUT);
	pinMode(pinPWMB,OUTPUT);
	pinMode(pinAIN1,OUTPUT);
	pinMode(pinAIN2,OUTPUT);
	pinMode(pinBIN1,OUTPUT);
	pinMode(pinBIN2,OUTPUT);
	pinMode(pinSTBY,OUTPUT);
	//Make the internal variables take the value of the user's preferences
	_pinPWMA=pinPWMA;
	_pinPWMB=pinPWMB;
	_pinAIN1=pinAIN1;
	_pinAIN2=pinAIN2;
	_pinBIN1=pinBIN1;
	_pinBIN2=pinBIN2;
	_pinSTBY=pinSTBY;
}
void motor::enable()//It just turn on the driver. 
{
	digitalWrite(_pinSTBY, HIGH); //disable standby //habilitamos motores
}
//Function move needs the motor we want to move, the speed and direction that it will take
void motor::move(int motor, int speed, int direction)
{

	boolean inPin1 = LOW;
	boolean inPin2 = HIGH;

	if(direction == 1){
	inPin1 = HIGH;
	inPin2 = LOW;
	}

	if(motor == 1){
	digitalWrite(_pinAIN1, inPin1);
	digitalWrite(_pinAIN2, inPin2);
	analogWrite(_pinPWMA, speed);
	Serial.println(speed);
	}else{
	digitalWrite(_pinBIN1, inPin1);
	digitalWrite(_pinBIN2, inPin2);
	analogWrite(_pinPWMB, speed);
	Serial.println(speed);
	}	
}
void motor::stop()//disable the StandBy pin so the driver is turned off
{
	digitalWrite(_pinSTBY, LOW);
}