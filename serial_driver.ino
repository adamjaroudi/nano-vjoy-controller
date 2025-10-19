#define B_PIN 2
#define Y_PIN 7
#define X_PIN 4
#define A_PIN 3
#define UP_PIN 9
#define DOWN_PIN 12
#define LEFT_PIN 11
#define RIGHT_PIN 8
#define L_BUTTON 6
#define R_BUTTON 5
#define SW_JOYSTICK1 10
#define SW_JOYSTICK2 13
#define X_JOYSTICK A1
#define Y_JOYSTICK A2
#define X_JOYSTICK2 A3
#define Y_JOYSTICK2 A4

void setup() {
    pinMode(B_PIN, INPUT_PULLUP);
    pinMode(Y_PIN, INPUT_PULLUP);
    pinMode(A_PIN, INPUT_PULLUP);
    pinMode(X_PIN, INPUT_PULLUP);
    pinMode(UP_PIN, INPUT_PULLUP);
    pinMode(RIGHT_PIN, INPUT_PULLUP);
    pinMode(LEFT_PIN, INPUT_PULLUP);
    pinMode(L_BUTTON, INPUT_PULLUP);
    pinMode(R_BUTTON, INPUT_PULLUP);
    pinMode(DOWN_PIN, INPUT_PULLUP);
    pinMode(SW_JOYSTICK1, INPUT_PULLUP);
    pinMode(SW_JOYSTICK2, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop() {
    int x = analogRead(X_JOYSTICK);
    int y = analogRead(Y_JOYSTICK);
    int x2 = analogRead(X_JOYSTICK2);
    int y2 = analogRead(Y_JOYSTICK2);

    String buttonStates = "";
    buttonStates += String(digitalRead(A_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(B_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(X_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(Y_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(L_BUTTON) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(R_BUTTON) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(UP_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(DOWN_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(LEFT_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(RIGHT_PIN) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(SW_JOYSTICK2) == LOW ? "1" : "0") + ";";
    buttonStates += String(digitalRead(SW_JOYSTICK2) == LOW ? "1" : "0") + ";";
    buttonStates += String(x) + ";";
    buttonStates += String(y);
    /*buttonStates += String(x2) + ";";
    buttonStates += String(y2);*/

    Serial.println(buttonStates);
    delay(50);
}
