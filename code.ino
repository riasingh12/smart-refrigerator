/* This is the Arduino code for a model of a Smart refrigerator
It constitutes of four Force sensors, a PIR sensor, 
a Temperature sensor, a LCD 16x2 display , a DC motor,
a potentiometer, one LED light, and one RGB LED light.

The PIR sensor is used to detect wheter the fridge has been opened
or not, and if it detects any motion, it switches on the LED
in the fridge. If the fridge is empty, the LED is switched off
irrespective of whether the PIR detects any motion. The force sensors 
act as pressure sensors and gives us an inventory of how many items 
are present in the fridge.
The DC motor is connected to an internal fan which is used for 
ventilation and to remove heat from the inside, and the speed is 
based on the temperature. The LCD display displays the temperature 
and the number of items present in the fridge at all times detected 
by the temperature and force sensors respectively. The RGB LED 
light shines either red, green or blue depending on the temperature
inside the fridge. (RED - extreme, GREEN - optimum, BLUE - very low).
The potentiometer controls the brightness of the LCD screen
by varying the resistance.

*/

#include <LiquidCrystal.h>
//Initialise all the digital and analog pin values
LiquidCrystal lcd(13, 7, 11, 10, 9, 8);
int fridgeSensor[4]={A0,A1,A2,A3};//analog pins
float fridgeForceValue[4]={0,0,0,0};

int LED = 12;//Digital pin 12 for door LED

//Digital Pin 2,3,4 for temp optimization
int LEDR = 2;
int LEDB = 3;
int LEDG = 4;

int PIR = 6;//Digital pIN 6
int FAN = 5;//Digital Pin 5

int speed = 0;
int sensor = 0;
int temp = 0;

void setup() 
{
  lcd.begin(16, 2);  //Initializes the interface for the LCD screen
  pinMode(LED, OUTPUT); // Setting the pin for the LED
  // Setting the pins for the RGB LED
  pinMode(LEDR, OUTPUT); 
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(PIR, INPUT);// Setting the pin for the PIR sensor
  pinMode(A5, INPUT);//Setting the pin for the temperature sensor
  pinMode(FAN, OUTPUT);// Setting the pin for the DC motor
  // Setting the pins for the Force sensors
  pinMode(fridgeSensor[0],INPUT); 
  pinMode(fridgeSensor[1],INPUT);
  pinMode(fridgeSensor[2],INPUT);
  pinMode(fridgeSensor[3],INPUT);
  lcd.print("TEMP: ");
}

void loop()
{
  int count = 0;
  for(int i=0; i<4; i++)//to read input from the four Force sensors
  {
    fridgeForceValue[i]=analogRead(fridgeSensor[i]);
    //if sensor is squeezed, force value is >0 and  item count incremented
    if(fridgeForceValue[i]>0)
    {
      	count++;
    }
  }
  
  if(count>0)	//if fridge empty, do not turn LED lights on
  	{
    sensor = digitalRead(PIR); //reading PIR sensor value
    if(sensor==HIGH) //if motion detected, fridge lights on
      digitalWrite(LED, HIGH);
    else
      digitalWrite(LED, LOW);
    }
  
  
  	temp = analogRead(A5); //reading temperature sensor value
 	//To map the input from the temperature sensor to the appropriate temperature values
  	temp=map(temp, 20, 358, -40, 125); 
  	if(temp>30)
    {
		//red LED for high temperature
      	digitalWrite(LEDR, HIGH);//Red indicator on
 	  	digitalWrite(LEDB, LOW);
  	  	digitalWrite(LEDG, LOW);
      	analogWrite(5, 150); //fan speed slightly high
  	}
  	else if(temp<12)
    {
  		//blue LED for low temperature
        digitalWrite(LEDR, LOW);
        digitalWrite(LEDB, HIGH);//Blue indicator on
   	 	digitalWrite(LEDG, LOW);
      	analogWrite(5, 50); //fan speed low
  	}
  	else 
    {
      //green LED for optimum temperature
   	 	digitalWrite(LEDR, LOW);
   	 	digitalWrite(LEDB, LOW);
      	digitalWrite(LEDG, HIGH);//Green indicator on 
      	analogWrite(5, 100); //fan speed optimal
    }
    if(temp > 90 )
    {
      	analogWrite(5, 255); //fan speed very high
    }
    else if(temp > 60 )
    {
      	analogWrite(5, 200); //fan speed reasonably high
    }
    // print temp detected in the temperature sensor
  	String output = String(temp)+ String((char)178) + "C ";
  	lcd.setCursor(10,0);
    lcd.print(output); 
  	lcd.setCursor(0,1); //set cursor to line 2
  	//print number of items inside the fridge
  	lcd.print("No of items: "); 
  	lcd.setCursor(13,1);
    lcd.print(count); 
  	delay(10); //delay after which loop() function is executed again.
}