void laser_cat2()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo <1256) {
      int servo1 = realservo;
      servo1 = map(servo1, 1256, 1000, 30, 150);
      y_servo.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if (realservo >= 2000 && realservo <2200) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000,2200, 30, 150);
      x_servo.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }

//   if (realservo >= 0 && realservo < 3)  {
//      digitalWrite(led, LOW);
//    }

//   if (realservo >=255 && realservo < 259) {
//      digitalWrite(led,HIGH);
//    }
   
  }
/*
    if (realservo >= 3000 && realservo <3200) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 ON");
      delay(10);
    }
*/
  
}
