#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

byte deger = -1;

void setup() {
  Serial.begin(115200);
  pinMode(25,OUTPUT); //kırmızı
  pinMode(26,OUTPUT); //sarı
  pinMode(27,OUTPUT); //yeşil
  SerialBT.begin("LED_KONTROL"); 
  Serial.println("Bluetooth'u eslestir");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    
    deger=SerialBT.read();
    delay(20);

    if (deger == 1) {
      digitalWrite(25, HIGH);
      Serial.println("KIRMIZI LED YANDI");
    } else if (deger == 2) {
      digitalWrite(25, LOW);
      Serial.println("KIRMIZI LED SÖNDÜ");
    } else if (deger == 3) {
      digitalWrite(26, HIGH);
      Serial.println("SARI LED YANDI");
    } else if (deger == 4) {
      digitalWrite(26, LOW);
      Serial.println("SARI LED SÖNDÜ");
    } else if (deger == 5) {
      digitalWrite(27, HIGH);
      Serial.println("YEŞİL LED YANDI");
    } else if (deger == 6) {
      digitalWrite(27, LOW);
      Serial.println("YEŞİL LED SÖNDÜ");
    }
    Serial.write(deger);
  }
  delay(20);
}