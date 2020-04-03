/*
  Laser Tower for the CAT - LA FABRIQUE DIY
  Pseudo-randomly moves a servo tower (on X and Y axis) and lights up a laser.
  x_servo is attached to pin 6 and moves in the X plan 
  y_servo is attached to pin 9 and moves in the Y plan 
  Laser is on pin 13

  HOW IT WORKS : 
  The program randomly choose a new position for the laser inside a square you can define below. 
  It checks the new position is different from the old one of at least "minimal_movement".
  It moves the tower to the new position and stays still for a time between min_freeze and max_freeze 
  (this aims to reproduce the behaviour of an insect landing somewhere for a bit and then flying off, 
  that's the variable you need to increase if your cat is fat).
  Ans starts the process over and over again. 
  
  Created 30 Sep 2016 by Lucas Berbesson
*/



void laser_cat() {
  movement_time = random(10,40);
  random_delay = random(min_freeze, max_freeze);
  x_new_position = random(min_x+minimal_movement, max_x-minimal_movement);
  y_new_position = random(min_y+minimal_movement, max_y-minimal_movement);
  
  if( (y_new_position > y_old_position) && (abs(y_new_position - y_old_position) < 5 )) {
    y_new_position = y_new_position + minimal_movement;
  }  else if ( (y_new_position < y_old_position) && (abs(y_new_position - y_old_position) < 5 )) {
    y_new_position = y_new_position - minimal_movement;
  }
  
  if( (x_new_position > x_old_position) && (abs(x_new_position - x_old_position) < 5 )) {
    x_new_position = x_new_position + minimal_movement;
  }  else if ( (x_new_position < x_old_position) && (abs(x_new_position - x_old_position) < 5 )) {
    x_new_position = x_new_position - minimal_movement;
  }
  
  x_speed = (x_new_position - x_old_position)/movement_time;
  y_speed = (y_new_position - y_old_position)/movement_time;  
  for (pos = 0; pos < movement_time; pos += 1) { 
      x_position = x_position + x_speed;
      y_position = y_position + y_speed;
      x_servo.write(x_position);  
      y_servo.write(y_position);                    
    delay(10); 
  }
  x_old_position = x_new_position;
  y_old_position = y_new_position;
  delay(random_delay);

}
