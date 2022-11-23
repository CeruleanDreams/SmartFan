//motor connections
int enA = 9; //DWM is being applied
int in1 = 4;
int in2 = 3;

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
  sensorValue = analogRead(A0);
  float voltage = sensorValue * 5.0;
  
  voltage /= 1024.0; 
  
  float temp = (voltage - 0.5) * 40 ; //Used to be * 100, but the STM32 seems to be operating at a higher voltage

  if ((temp > 20) && (temp < 25.00))
  {
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("--ON-- ");
    analogWrite(enA, 10);
   
  }
  else if ((temp => 25.00) && (temp < 30.00))
  {
   
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("--ON 2-- ");
   analogWrite(enA, 100);
  }

    else if ((temp => 30.00) && (temp < 37.00))
  {
   
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("--ON 2-- ");
   analogWrite(enA, 250);
  }
  
  else {

    delay (50);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);  
  }

  
  Serial.println(temp);
  delay(5);

}

/* void on(int s){// 0 <= s <256
  analogWrite(enA,s);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);  
  }

void off(){
  digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);  
  
  } */
