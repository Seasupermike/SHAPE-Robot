//input pins
# define Line_Track_Left A0
# define Line_Track_Middle A1
# define Line_Track_Right A2
# define Flame_Dectector A5
//output pins
# define IN1 7
# define IN2 8
# define IN3 9
# define IN4 11
# define STBY 3
# define ENA 5
# define ENB 6


void setup() {
  // put your setup code here, to run once:

pinMode(Line_Track_Left, INPUT);
pinMode(Line_Track_Middle, INPUT);
pinMode(Line_Track_Right, INPUT);
pinMode(Flame_Dectector, INPUT);
//setting our variables to either input and output
Serial.begin(9600);
//Now we set up our output pins
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(STBY, OUTPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
//digitalWrite(ENA, HIGH);
//digitalWrite(ENB, HIGH);
}
//Now to save time when writing our code to move, we can use functions
void foward() {
    digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 50);
  analogWrite(ENB, 50);
  digitalWrite(STBY, HIGH);
}
//Function to move backward
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 50);
  analogWrite(ENB, 50);
  digitalWrite(STBY, HIGH);
}
//Function to stop
void motion_stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(STBY, LOW);
}
//Function to turn left
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 50);
  analogWrite(ENB, 50);
  digitalWrite(STBY, HIGH);
}
//Function to turn right
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 50);
  analogWrite(ENB, 50);
  digitalWrite(STBY, HIGH);
}

int Min = 1000;
int Max = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println((String)analogRead(Line_Track_Left) + " " + (String)analogRead(Line_Track_Middle) + " " + (String)analogRead(Line_Track_Right));
  //Code to slow down:
  //analogWrite(ENA, 50);
  //analogWrite(ENB, 50);

  //Code to move foward
  foward();

  delay(2000);

  //Code to stop
  motion_stop();

  delay(2000);

  //Code to move backward
  backward();

  delay(2000);

  //Code to stop
  motion_stop();

  delay(2000);

  //Code to turn left
  left();

  delay(2000);

  //Code to stop
  motion_stop();

  delay(2000);

    //Code to turn right
  right();

  delay(2000);

  //Code to stop
  motion_stop();

  delay(2000);

  
  Serial.println(
    String(analogRead(Line_Track_Left)) + " " +
    String(analogRead(Line_Track_Middle)) + " " +
    String(analogRead(Line_Track_Right))
  );
}
