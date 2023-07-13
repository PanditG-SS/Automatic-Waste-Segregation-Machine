#include <Servo.h>

int ir_sensor = 5;   //For Detecting if waste has been put
int hydro_sensor = A0; // For detecting moisture levels in garbage
int mag_sensor = 2;   // For detecting if waste is magnetic

int motor_pin = 6;
int val = 0;
int mag = LOW;
int hyd = 0;

int state = 0;
int new_s = 0;

int is_mag=0;

Servo servo;


void setup() {
Serial.begin(9600);

pinMode(ir_sensor, INPUT); // initialize sensor as an input
pinMode(hydro_sensor, INPUT);
pinMode(mag_sensor, INPUT);
servo.attach(motor_pin);
servo.write(0);
}

void loop(){
  Serial.println();

val = digitalRead(ir_sensor); // read sensor value

if (val == LOW) { // check if the sensor is HIGH
  delay(5000);
  is_mag = digitalRead(mag_sensor);
  Serial.print("Magnetic:");
  Serial.print(is_mag);
  Serial.println();

  if (is_mag == LOW){
    val = 110;
    servo.write(val);                  // sets the servo position according to the scaled value
    Serial.print(val);

    delay(300);

    delay(2000);

    delay(300);

    state=2;

  }

  else{
    delay(5000);
    hyd = analogRead(A0);
    Serial.print("Hydro:");
    Serial.print(hyd);
    Serial.println();
    if (hyd<500){
      val=50;
      servo.write(val);
      Serial.print(val);


    delay(2000);
    delay(300);
      
      state=1;
    }
    else{
      val = 0;
      servo.write(val);
      Serial.print(val);
      

    delay(300);

    delay(2000);


      state=0;    
    }
  }
}
}
