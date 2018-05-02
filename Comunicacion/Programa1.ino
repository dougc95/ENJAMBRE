/*Programa para colocar en el arduino con el xbee receptor*/

/*
 ----------------------------------------------- 
  Escritura serial inalámbrica - XBee
 -----------------------------------------------
 
  Consiste en escribir por la pantalla del computador (consola serial) 
   una letra predeterminada, la primera vez que se escriba esta 
   un LED se enciende, si se vuelve a escribir por segunda vez 
   el LED se apaga, además el modulo XBee (E) ubicado en el computador
   esta recibiendo en tiempo real el incremento de un contador ubicado en
   el modulo XBee (R). Esta comuniación serial se establece de manera
   inalámbrica por medio de dos modulos XBee
 
*/
 
//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int led = 13;           //Pin donde se encuentra el LED, salida
char leer;              //Variable donde se almacena la letra 
boolean prendido=false; //Estado LED la primera vez, apagado
int contador = 0;       //Variable del contador
 
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  Serial.begin(9600);    //Inicia comunicación serial
  pinMode(led, OUTPUT);  //Configurar el LED como una salida
}
 
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{           //  cuando este energizado el Arduino 
 
 
 contador++;               //Incrementa el contador en una unidad  
 Serial.println(contador); //Imprime por consola el valor del contador
 delay(100);               //Retardo
 
 
  //Guardar en una variable el valor de la consola serial
  leer=Serial.read();
 
  // Si es la letra 'a' y ademas el LED esta apagado
  if ( (leer=='a') && (prendido==false) )
  {
  ///Esta parte puede ser editada para encender un motor o para activar cualquier actuador
  
      digitalWrite(led,HIGH);  // Enciende el LED
      prendido=true;           // Actualiza el estado del LED 
  }
  // Si es la letra 'a' y ademas el LED esta encendido
  else if ( (leer=='a') && (prendido==true) )
   {
    ///Esta parte puede ser editada para apagar el motor o para desactivar otro tipo de actuadores
      digitalWrite(led,LOW);   // Apaga el LED 
      prendido=false;          // Actualiza el estado del LED 
  }  
 
}
 
//Fin programa
