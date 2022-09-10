/*
Ardunio program to control relay board of JEEP AUX

  Shitty SPOD
*/
int i;
int val=0;         // variable to receive data from the serial port
int condition;
int ledpin[]={5,5,6,6,9,9,10,10,11,11};         /*array LED connected to pin (11 10 9 6)
                                                  all odd arrays are for LOW  
                                                  all even arrays are for HIGH
                                                  */
int PWRpin1 =12;
int PWRpin2 =13;


void setup()
{
  for(i=2;i<10;i++)
    pinMode(ledpin[i], OUTPUT);                  // pin 2>>10 (on-board LED) as OUTPUT
  
  pinMode(PWRpin1,OUTPUT);
  pinMode(PWRpin2,OUTPUT);
    digitalWrite(PWRpin1,HIGH);
    digitalWrite(PWRpin2,HIGH);
  
  Serial.begin(9600);                          // start serial communication at 115200bps
}

void loop(){
  if ( Serial.available()>0){                   // if data is available to read
       val = Serial.parseInt();                 //set val to the int value of serial monitor
    }
    if ((val%2)==1){                             //if the serial input is an odd number then sets condition to LOW
      condition=0;
    }
    else{                                        //if the serial input value is an even number then sets condition to HIGH
      condition=1;
  }
   _relayswitch(ledpin[val],condition);      //calls the function that changes the state of the relay
}


/* ------------------------------------Future---------------------------------------------
 * 
 * 
 * 
 * 
 *Still need to add the ability to take inputs from the PI CAR Computer 
 *  IDEAS for UART of I2C protocal? maybe.
 *
 *
 *
 ----------------------------------------------------------------------------------------- */



//------------------------Functions--------------------------------------
/* function takes inputs (pin, (On or OFF) and sets output as such*/
void _relayswitch(int ledpin,int condition){
    if (condition==1){
      digitalWrite(ledpin, HIGH);
    }
    else if (condition == 0){
      digitalWrite(ledpin, LOW);
    }
    else{
      //do nothing
    }
  }




 
