#define Xaxis_pin A0
#define Yaxis_pin A1
#define Sw_pin 6
#define UP 3
#define RIGHT 4
#define DOWN 2
#define LEFT 5
#define X_ANALOG A0
#define Y_ANALOG A1
#define BUZZER_PIN 6

int x_value = 0;
int y_value = 0;
int z_value = 0;

void pinModesForJoystick() {
  pinMode(Xaxis_pin, INPUT);
  pinMode(Yaxis_pin, INPUT);
  pinMode(Sw_pin, INPUT_PULLUP);
  pinMode(X_ANALOG, INPUT);
  pinMode(Y_ANALOG, INPUT);
}

void pinModesForMoves() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void movesStartOff() {
  digitalWrite(LEFT, LOW);
  digitalWrite(RIGHT, LOW);
  digitalWrite(UP, LOW);
  digitalWrite(DOWN, LOW);
}

void xyzValues() {
  x_value = analogRead(X_ANALOG);
  y_value = analogRead(Y_ANALOG);
  z_value = digitalRead(Sw_pin);
}

void xValues() {
  Serial.print("X-axis: ");
  Serial.print(x_value);
  Serial.print(" : ");
}

void yValues() {
  Serial.print("Y-axis: ");
  Serial.print(y_value);
  Serial.print(" : ");
}

void zValues() {
  Serial.print("Button (z_value): ");
  Serial.println(z_value);
}

void setup() {
  pinModesForJoystick();
  Serial.begin(9600);
  pinModesForMoves();
}

void loop() {
  movesStartOff();
  xyzValues();
  xValues();
  yValues();
  zValues();
  delay(100);

  if (x_value < 50) {
    digitalWrite(LEFT, HIGH);
  }
  else if (x_value > 973) {
    digitalWrite(RIGHT, HIGH);
  }

  if (y_value < 50) {
    digitalWrite(UP, HIGH);
  }
  else if (y_value > 973) {
    digitalWrite(DOWN, HIGH);
  }

  if (z_value == LOW) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}
