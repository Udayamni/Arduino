//Interfacing arduino with CPU fan, https://www.intel.com/content/dam/support/us/en/documents/intel-nuc/intel-4wire-pwm-fans-specs.pdf datasheet of fan.
//
int potVal;
int potPin = A2;
int fanVal;
const byte OC1A_PIN = 9;
const byte OC1B_PIN = 10;
const word PWM_FREQ_HZ = 25000; //Adjust this value to adjust the frequency
const word TCNT1_TOP = 16000000 / (2 * PWM_FREQ_HZ);
void setPwmDuty(byte duty) {
OCR1A = (word)(duty * TCNT1_TOP) / 100;
Serial.println(OCR1A);
}
void setup() {
  Serial.begin(9600);
pinMode(OC1A_PIN, OUTPUT);
// Clear Timer1 control and count registers
TCCR1A = 0;
TCCR1B = 0;
TCNT1 = 0;
TCCR1A |= (1 << COM1A1) | (1 << WGM11);
TCCR1B |= (1 << WGM13) | (1 << CS10);
ICR1 = TCNT1_TOP;
}
void loop() {
potVal = analogRead(potPin);
fanVal = map(potVal, 0, 1023, 0, 100);
setPwmDuty(fanVal);
}
