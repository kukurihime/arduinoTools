#include "CServoMotor.h"

CServoMotor srv1 = CServoMotor( 3, 490.0, 256, 0.0013, 0.00001, 0.0, 80.0, -80.0);

void setup() {
  // put your setup code here, to run once:
  srv1.moveToInitialAngle();
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  double angle = 0.0;
  
  for( i = 0; i < 50; i++ ){
    angle = angle - 1.0;
    srv1.setTargetAngle( angle );
    srv1.moveToTargetAngle();
    delay(25);
  }

  delay(1000);
  
  for( i = 0; i < 100; i++ ){
    angle = angle + 1.0;
    srv1.setTargetAngle( angle );
    srv1.moveToTargetAngle();
    delay(25);
  }

  delay(1000);
  
  for( i = 0; i < 50; i++ ){
    angle = angle - 1.0;
    srv1.setTargetAngle( angle );
    srv1.moveToTargetAngle();
    delay(25);
  }
  
}
