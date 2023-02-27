#include<SPI.h>
#include<Ethernet.h>
#include<Modbus.h>
#include<ModbusIP.h>
const int COIL  = 10;
const int COIL1 = 11;
const int COIL2 = 12;
const int HOLDING_REGISTER  = 12;
const int HOLDING_REGISTER1 = 13;
const int HOLDING_REGISTER2 = 14;
const int HOLDING_REGISTER3 = 15;
const int ledPin  = 2;
const int ledPin3 = 3;
const int ledPin5 = 5;
const int analogPin  = A0;
const int analogPin1 = A1;
const int analogPin2 = A2;
const int analogPin3 = A3;
ModbusIP mb;
void setup() {
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  byte ip[] = { 192, 168, 1 ,3 };
  mb.config(mac, ip);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  mb.addCoil(COIL);
  mb.addCoil(COIL1);
  mb.addCoil(COIL2);
  mb.addHreg(HOLDING_REGISTER);
  mb.addHreg(HOLDING_REGISTER1);
  mb.addHreg(HOLDING_REGISTER2);
  mb.addHreg(HOLDING_REGISTER3);
}

void loop() {
  mb.task();
  digitalWrite(ledPin, mb.Coil(COIL));
  digitalWrite(ledPin3, mb.Coil(COIL1));
  digitalWrite(ledPin5, mb.Coil(COIL2));
  mb.Hreg(HOLDING_REGISTER, analogRead(A0));
  mb.Hreg(HOLDING_REGISTER1, analogRead(A1));
  mb.Hreg(HOLDING_REGISTER2, analogRead(A2));
  mb.Hreg(HOLDING_REGISTER3, analogRead(A3));
}
