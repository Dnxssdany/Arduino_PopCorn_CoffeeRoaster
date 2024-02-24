#include <max6675.h>
#include <ModbusRtu.h>

// data array for modbus network sharing
uint16_t au16data[16] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, UINT16_MAX, 0 };

/**
 *  Modbus object declaration
 *  u8id : node id = 0 for master, = 1..247 for slave
 *  u8serno : serial port (use 0 for Serial)
 *  u8txenpin : 0 for RS-232 and USB-FTDI 
 *               or any pin number > 1 for RS-485
 */

Modbus slave(1,0,0); // this is slave @1 and RS-232 or USB-FTDI

int thermoDO = 10;
int thermoCS = 11;
int thermoCLK = 12;

int thermoDO_2 = 7;
int thermoCS_2 = 8;
int thermoCLK_2 = 9;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

MAX6675 thermocouple_2(thermoCLK_2, thermoCS_2, thermoDO_2);

int relay = 13;  
  
void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  while (!Serial) {}  // Wait for serial port to connect
  slave.begin( 19200); // 19200 baud, 8-bits, even, 1-bit stop
  // use Arduino pins 
  pinMode(relay, OUTPUT);
  delay(500); 
}

void loop() {
   //write current thermocouple value
   float temperature = thermocouple.readCelsius();
   au16data[2] = ((uint16_t) (temperature * 100));

   float temperature_2 = thermocouple_2.readCelsius();
   au16data[3] = ((uint16_t) (temperature_2 * 100));

   //poll modbus registers
   uint8_t result = slave.poll( au16data, 16 );
   if (result != 0) {
     Serial.print("Modbus error: ");
     Serial.println(result);
   }

   //write relay value using pwm
   analogWrite(relay, (au16data[4]/100.0)*255);

   // Debugging: Print temperature and relay value
   Serial.print("Temperature 1: ");
   Serial.print(temperature);
   Serial.print(" °C, Relay value: ");
   Serial.println(au16data[4]);
   Serial.print("Temperature 2: ");
   Serial.print(temperature_2);
   Serial.println(" °C");
   delay(500);
}