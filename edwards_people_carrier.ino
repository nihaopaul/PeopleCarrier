int m1speed = 5;
int m1dir = 7;

int m2speed = 6;
int m2dir = 8;

int x = A4;
int y = A5;
int button = A3;
int power = A2;
int gnd = A1;

boolean go = LOW;

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
  Serial.begin(9600);
  analogWrite(m1speed, 0);
  analogWrite(m2speed, 0);
}

void loop() {
  Serial.println(go);
  if (digitalRead(button)) {
    if (go == HIGH) {
      go = LOW;
          analogWrite(m2speed, 0);
              analogWrite(m1speed, 0);

    } 
    else {
      go = HIGH;
    }
                  delay(500);
  } 
  if (go == HIGH) {
    drive();
  }

}
void drive() {

  int spd = map(analogRead(y), 0, 1024, -255, 255);
  int dir = map(analogRead(x), 0, 1024, -255, 255);

  Serial.print("speed: \t");
  Serial.print(spd);
  Serial.print("\tdir: \t");
  Serial.println(dir);
  m1(cap(spd+dir));
  m2(cap(spd-dir));

}
int cap(int number) {
  if (number > 255) {
    return 255;
  } 
  if (number < -255) {
    return -255;
  }
  return number;
}
void m1(int number) {
  if (number <0) {
    digitalWrite(m1dir, LOW);
    analogWrite(m1speed, -number);
  } 
  else if (number > 0) {
    digitalWrite(m1dir, HIGH);
    analogWrite(m1speed, number);
  } 
  else {
    //stop!
    digitalWrite(m1dir, LOW);
    analogWrite(m1speed, 0);
  }
}

void m2(int number) {
  if (number <0) {
    digitalWrite(m2dir, LOW);
    analogWrite(m2speed, -number);

  } 
  else if (number > 0) {
    digitalWrite(m2dir, HIGH);
    analogWrite(m2speed, number);
  } 
  else {
    //stop!
    digitalWrite(m2dir, LOW);
    analogWrite(m2speed, 0);
  }
}







