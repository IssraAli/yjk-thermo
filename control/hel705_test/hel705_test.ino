#include <math.h>
#include <stdio.h>
#include <time.h>

const int topPin = A0;
const int bottomPin = A1;
const int vccc = A2;

// setting instrument parameters
const double r0 = 1000;
const double A = 3.8101E-3;//= alpha + (alpha * delta)/100;
unsigned long start_time = millis();


double resistance_to_temp(double r, double r0, double A){
    // based on linear model from hel705 manual, calculates temperature as a function of thermistor resistance r
    return ((r/r0)-1)/A;
}

double wheatstone(double r1, double r2, double vo, double vcc){
    double num = vcc*r2 - vo*(r1 + r2);
    double denom = vcc*r1 + vo*(r1 + r2);
    return r1 * (num/denom);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  Serial.print("\nstart\n");
  analogReference(EXTERNAL); // running with vcc coming out of a current divider at 4.26V
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(topPin) - analogRead(bottomPin);
  //double vcc = analogRead(vccc);
  double V_out = (val/1024.0) * 4.21; //running with vcc coming out of a current divider at 4.26V
  double R_T = wheatstone(4.7e3, 1e3, V_out, 5.0);
  double temp = resistance_to_temp(R_T, r0, A);
  unsigned long current = millis() - start_time;

  //Serial.print("V_out: ");
  Serial.print(V_out, 3);
  Serial.print("\t");
  Serial.print(R_T);
  Serial.print("\t");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print(current);
  Serial.print("\n");
  

  // Serial.plot("V_out: ");
  // Serial.plot(V_out);
  // Serial.plot(", R_T: ");
  // Serial.plot(R_T);
  // Serial.plot(", temp: ");
  //Serial.plot("\n");

}
