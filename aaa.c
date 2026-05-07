#include <SchooMyUtilities.h>
SchooMyUtilities scmUtils = SchooMyUtilities();

float _sbeGetBrightness(int pinNumber, int res, float vol) {
  pinMode(pinNumber, INPUT);
  float cds_ad = analogRead(pinNumber);
  float cds_v = cds_ad * vol / res;
  float v_res = vol - cds_v;
  if (v_res < 0.01) {
    v_res = 0.01;
  }
  return 10000 * cds_v / v_res / 1000;
}

void setup() {
  Serial.begin(9600);
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);
}

void loop() {
  if ((_sbeGetBrightness(A5, 1023, 5) < 100)) {
    digitalWrite(15, LOW);
  }
}
