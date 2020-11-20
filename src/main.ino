const unsigned int LED = 13;
const int FADE_AMOUNT = 5;
int currentBrightness = 0;
bool ascending = true;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // if (currentBrightness >= 255) {
  //   ascending = false;
  // } else if (currentBrightness <= 0) {
  //   ascending = true;
  // }
  
  // if (ascending) {
  //   currentBrightness += FADE_AMOUNT;
  // } else {
  //   currentBrightness -= FADE_AMOUNT;
  // }
  // analogWrite(LED, currentBrightness);
  // delay(50);
}