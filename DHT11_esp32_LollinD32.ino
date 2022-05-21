#include<DHT.h> //DHT.h 라이브러리 추가
DHT dht(13, DHT11);
void setup(){
  Serial.begin(115200);
 }
  
 void loop(){ 
  delay(200);
  int tem = dht.readTemperature();
  int hum = dht.readHumidity();
  Serial.print("Temperature :");
  Serial.print(tem);
  Serial.print("C ");
  Serial.print("Humidity : ");
  Serial.print(hum);
  Serial.println("% "); //온도와 동일
 }
