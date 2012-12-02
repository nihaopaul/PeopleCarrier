int m1speed = 5;
int m1dir = 7;

int m2speed = 6;
int m2dir = 8;

int x = A4;
int y = A5;
int button = A3;
int power = A2;
int gnd = A1;

void setup() {
  pinMode(m1speed, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(m2speed, OUTPUT);
  pinMode(m2dir, OUTPUT);
  
  pinMode(gnd, OUTPUT);
  pinMode(power, OUTPUT);
  digitalWrite(power, HIGH);
  digitalWrite(gnd, LOW);
  
  pinMode(button, INPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  //

}

void loop() {

   digitalWrite(m1dir, HIGH);
   digitalWrite(m2dir, HIGH);
   analogWrite(m1speed, 255);
   analogWrite(m2speed, 255);
   
}

