//motor connections
int enA = 9; //PWM is set to pin 9
int in1 = 4; //input 1 is set to pin 4
int in2 = 3; //input 2 is set to pin 3

int DC_MOTOR_PWM_RATE = 0; 
int sensorValue;
double temp;

void setup() 
{
  Serial.begin(9600);  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  pinMode(A0,INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  
  sensorValue = analogRead(A0); //tmp 36 reads resistance
  float voltage = sensorValue * 3000;  
  voltage /= 1024.0; 
  float temp = voltage; // ^ Formula used to transform input voltage into temperature in Celsius
  
 // float temp = (voltage - 0.5) * 40 ; // Used to be (x100), but the STM32 seems to be operating at a higher voltage compared to the Arduino UNO

  if ((temp > 20) && (temp < 25.00)) //lowest setting to allow for the fan's operation
  {
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("--ON-- ");
    analogWrite(enA, 10);
   
  }
  else if ((temp > 25.00) && (temp < 30.00)) //middle setting
  {
   
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("--ON 2-- ");
   analogWrite(enA, 100);
  }

    else if ((temp > 30.00) && (temp < 37.00)) //once it reaches body temperature, the fan shuts down
  {
   
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("--ON 3-- ");
   analogWrite(enA, 250); //analogWrite: using PWM to change the output and thus reduce the fan's RPM
  }
  
  else {
    delay (100); //small delay in case of sudden temperature spikes or glitches
    digitalWrite(in1, HIGH); //fan spins in one direction only
    digitalWrite(in2, LOW);  //switching the direction makes the fan halt
  }

  
  Serial.println(temp);
  delay(5);

}
