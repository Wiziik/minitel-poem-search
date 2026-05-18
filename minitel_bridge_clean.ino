/**
 * Minitel <-> Mac Clean Bridge
 * 
 * A simple, high-performance bridge for the Arduino Mega.
 * Features:
 * - 1200 Baud 7E1 for Minitel compatibility
 * - Internal Pull-up on Pin 19 (RX1) to support Minitel's open-collector TX
 * - Low-latency bidirectional passthrough
 * 
 * Wiring:
 *   DIN 1 (Rx) -> Pin 18 (TX1)
 *   DIN 3 (Tx) -> Pin 19 (RX1)
 *   DIN 2 (GND)-> GND
 */

void setup() {
  Serial.begin(9600);
  Serial1.begin(1200, SERIAL_7E1);
  pinMode(19, INPUT_PULLUP);
  delay(500);
  Serial1.write(0x0C);           // clear screen
  Serial1.print("3615 TV STORE...");
}


void loop() {
  if (Serial.available() > 0) Serial1.write(Serial.read());
  if (Serial1.available() > 0) Serial.write(Serial1.read());

}
