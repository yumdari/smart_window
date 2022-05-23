#include <DHT.h> //DHT.h 라이브러리 추가

#define DHTDELAY 200

unsigned long curTimeMs = 0;

DHT dht(5, DHT11);
void setup() {
    Serial.begin(115200);
    curTimeMs = millis();
}

void loop() {
    //delay(200);
    if (curTimeMs + DHTDELAY < millis()) {

        int tem = dht.readTemperature();
        int hum = dht.readHumidity();
        Serial.print("Temperature :");
        Serial.print(tem);
        Serial.print("C ");
        Serial.print("Humidity : ");
        Serial.print(hum);
        Serial.println("% "); //온도와 동일

        curTimeMs = millis();
    }
}
