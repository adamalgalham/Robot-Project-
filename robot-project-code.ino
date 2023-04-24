#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create a servo driver object for PCA9685 PWM controller
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the servo channels for each joint
#define BASE_CHANNEL 0
#define SHOULDER_CHANNEL 1
#define ELBOW_CHANNEL 2 
#define WRIST_CHANNEL 3
#define GRIPPER_CHANNEL 4

// Define the initial angle for each joint
int baseAngle = 120;
int shoulderAngle = 120;
int elbowAngle = 120;
int wristAngle = 90;
int gripperAngle = 90;

void setup() {
  // Initialize the servo driver
  pwm.begin();
  pwm.setPWMFreq(50); // Set the PWM frequency to 50 Hz

  // Set the initial position for each servo
  setServoPosition(BASE_CHANNEL, baseAngle);
  setServoPosition(SHOULDER_CHANNEL, shoulderAngle);
  setServoPosition(ELBOW_CHANNEL, elbowAngle);
  setServoPosition(WRIST_CHANNEL, wristAngle);
  setServoPosition(GRIPPER_CHANNEL, gripperAngle);
}

void loop() {
  // Move the robot arm in a pre-defined sequence

  // Move the base joint to 45 degrees
  setServoPosition(BASE_CHANNEL, 90);
  delay(1000);

  // Move the shoulder joint to 135 degrees
  setServoPosition(SHOULDER_CHANNEL, 70);
  delay(1000);

  // Move the elbow joint to 45 degrees
  setServoPosition(ELBOW_CHANNEL, -2);
  delay(1000);

  // Move the wrist joint to 135 degrees
  setServoPosition(WRIST_CHANNEL, 150);
  delay(1000);

  // Open the gripper
  setServoPosition(GRIPPER_CHANNEL, 30);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 150);
  delay(1000);

  // Open the gripper
  setServoPosition(GRIPPER_CHANNEL, 90);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);
  
  setServoPosition(BASE_CHANNEL, 120);
  delay(1000);

  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 150);
  delay(1000);
  
  setServoPosition(GRIPPER_CHANNEL, 30);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);

  setServoPosition(WRIST_CHANNEL, 150);
  delay(1000);  
  
  setServoPosition(GRIPPER_CHANNEL, 90);
  delay(1000);  
  
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);
  
  setServoPosition(BASE_CHANNEL, 60);
  delay(1000);
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 150);
  delay(1000);
  
  setServoPosition(GRIPPER_CHANNEL, 30);
  delay(1000);
  
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);

  setServoPosition(WRIST_CHANNEL, 150);
  delay(1000);  
  
  setServoPosition(GRIPPER_CHANNEL, 90);
  delay(1000);  
  
  setServoPosition(WRIST_CHANNEL, 90);
  delay(1000);
  // Close the gripper
  //setServoPosition(GRIPPER_CHANNEL, 90);
  //delay(1000);
  
  
 
}

// Function to set the position of a servo on a specified channel
void setServoPosition(int channel, int angle) {
  int pwmValue = map(angle, 0, 180, 102, 512); // Map the angle to a PWM value between 102 and 512
  pwm.setPWM(channel, 0, pwmValue); // Set the PWM value for the specified channel
}