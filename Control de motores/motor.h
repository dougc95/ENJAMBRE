//Author: Mateo Antonio Rengel Acebey
//The current code provides the header of this new library.
/*It looks for an easier way to control micromotors, specially using 
the driver dual TB6612FNG */

#ifndef motor_h 
#define motor_h//define the class
#include "arduino.h"//add the basics functions of arduino like delay() for example


class motor
{
	private://variables available just for this class. 
		int _pinPWMA,_pinPWMB,_pinAIN1,_pinAIN2,_pinBIN1,_pinBIN2,_pinSTBY;//configuracion de pines
	public://functions that the user can manipulate.
	//constructor takes the values of the declared variables 
		motor(int pinPWMA, int pinPWMB, int pinAIN1, int pinAIN2,
		 int pinBIN1,int pinBIN2,int pinSTBY);
	//declaration of functions of the library
		void move(int motor, int speed,int direction);
		void enable();
		void stop();
};
#endif