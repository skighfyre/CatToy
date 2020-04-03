#include <SoftwareSerial.h>
#include <Servo.h>

/* YOU CAN CUSTOM THESE VARIABLES IF YOU WANT TO ALTER THE TOWER BEHAVIOUR */

// X servo angle will stay in [min_x, max_x] range
// Y servo angle will stay in [min_y, max_y] range
// to be ajsuted to the size of your living room

float min_x = 100;
float max_x = 130;
float min_y = 1;
float max_y = 110;
int min_freeze = 500;
int max_freeze = 1000;
float minimal_movement = 2;

/* YOU SHOULD NOT HAVE TO MODIFY THE CODE BELOW THIS LINE */

// finding center of square for starting point
int random_delay;
float x_position = min_x + (max_x - min_x)/2;
float y_position = min_y + (max_y - min_y)/2; 
float x_old_position = x_position;
float y_old_position = y_position;
float x_new_position;
float y_new_position;
float x_speed;
float y_speed;
int movement_time;

// Instantiating two servos
Servo x_servo;  
Servo y_servo;
int pos = 0;
int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
   Serial.begin(9600);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  pinMode(2, INPUT);
  y_servo.attach(6);  // attaches the y servo on pin 6 to the servo object
  x_servo.attach(9);  // attaches the x servo on pin 9 to the servo object
  pinMode (13, OUTPUT);
  digitalWrite (13, HIGH);  // switch on  the laser
  
  //Place the servos in the center at the beginning 
  y_servo.write(y_position); 
  x_servo.write(x_position);     

}

void loop() {
  unsigned int mode = bluetooth.read();
  Serial.println(mode);
  if (mode == 0){
  laser_cat();
  }
  if (mode == 256){
  laser_cat2();
  }
}
