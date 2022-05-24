// Changelog:
//  22.05.24 - added PM2008 data parsing & send to DB 
//  22.05.23 - added send DHT11 data to DB
//  22.05.22 - DB connection test

#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
#endif

#include <DHT.h> //DHT.h 라이브러리 추가
DHT dht(5, DHT11);
int humi = 0;
int temp = 0;

int small = 0;
int big = 0;

#include <HardwareSerial.h>
HardwareSerial mySerial(2); //3개의 시리얼 중 2번 채널을 사용

// network credentials
const char* ssid     = "yummy2.4";
const char* password = "kccikcci";

// Domain name and URL path or IP address with path
const char* serverName = "http://192.168.0.7/post-esp-data.php";

// Keep this API Key value to be compatible with the PHP code provided in the project page. 
// If you change the apiKeyValue value, the PHP file /post-esp-data.php also needs to have the same key 
String apiKeyValue = "tPmAT5Ab3j7F9";

String sensorName = "DHT11";
String sensorLocation = "Outside";


#define SEALEVELPRESSURE_HPA (1013.25)

// ================================================================
// ===                      INITIAL SETUP                       ===
// ================================================================

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

   mySerial.begin(115200, SERIAL_8N1, 12, 13); //추가로 사용할 시리얼. RX:12 / TX:13번 핀 사용
}

// ================================================================
// ===                     PARSING FUNCTION                     ===
// ================================================================

void parsing() {
    if(mySerial.available() > 0){

    char totalGot[50];
    char * totalGotArr[3];
    int index = 0, i = 0;
    char * ptr = NULL;
    
    while(mySerial.available())
    {
      totalGot[index++] = mySerial.read();
    }
    totalGot[index] = '\0';
    
    ptr = strtok(totalGot, "#");

    while (ptr !=NULL)
    {
      totalGotArr[i++] = ptr;
      ptr=strtok(NULL, " ");
    }
    small = atoi(totalGotArr[0]);
    big = atoi(totalGotArr[1]);    

//    Serial.println(small); //PM 2.5
//    Serial.println(big); //PM 10
//    Serial.print("\n");
//    delay(1000);
    }
}

// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================

void loop() {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    
    // Domain name with URL path or IP address with path
    http.begin(client, serverName);
    
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
      if(mySerial.available() > 0){
      //String command = mySerial.readStringUntil('\n'); //추가 시리얼의 값을 수신하여 String으로 저장
      Serial.parseFloat();
      String command = mySerial.readString();

    humi = dht.readHumidity();
    temp = dht.readTemperature();
    parsing();
    
    // Prepare HTTP POST request data
    String httpRequestData = "api_key=" + apiKeyValue 
                          + "&temp=" + String(temp) + "&humi=" + String(humi) + "&small=" + String(small) + "&big=" + String(big) + "";
   
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
     
 
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  //Send an HTTP POST request every 30 seconds
    delay(10000);  
  }
}
