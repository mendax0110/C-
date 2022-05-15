#define BAUD 9600
#define DELAY_TIME 100

const char* STUDYOS = "STUDY - OS";

void setup() {
    Serial.begin(BAUD);
}

void loop() {
    Serial.println(STUDYOS);
    delay(DELAY_TIME);
}
