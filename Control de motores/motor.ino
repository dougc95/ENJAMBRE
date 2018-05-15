//Author: Mateo Antonio Rengel Acebey
//The current code provides the example file for the motor.h library
/*It looks for an easier way to control micromotors, specially using 
the driver dual TB6612FNG */


/*
FUNCTIONS AVAILABLE
  
  enable(); This function just enable de Standby Pin so you can introduce voltage to the motors
You have to put it before the move() function. 
  
  move(int motor,int speed,int direction); This one asks you for which motor to move, the speed and
the direction it will take
  
  stop(); It just turn off the Standby pin so the motors are no available until you use the 
enable(); function again. 


RANGES OF SPEED:  MIN=0    MAX=255
DIRECTION:  1 = to move ahead     2 = to move back
MOTOR       1 for the first motor     2 for the second one 
*/
//Enjoy the library
#include <motor.h>
//motor 1 connected between A01 and A02
//motor 2 connected between B01 and B02

int STBY = 9; //standby

//Motor A
int PWMA = 6; //Speed control
int AIN1 = 8; //Direction
int AIN2 = 7; //Direction

//Motor B
int PWMB = 10; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction
//Declaration of mymotor that takes the required values
motor mymotor(PWMA, PWMB, AIN1, AIN2,BIN1,BIN2,STBY);
void setup()
{
  mymotor.enable();
  /*We don't need nothing else here because all the functions that we use in this example
  are decleared in the library*/  
}
void loop(){
  
  mymotor.move(1,250,1);
  delay(1000);
  mymotor.move(1,0,1);
  mymotor.move(2,250,1);
  delay(1000);
  mymotor.move(2,0,1);

  mymotor.stop();
  /*after this last line both of the motors will stop unless yo use the enable(); function in the 
  first part of the void loop()*/
}
