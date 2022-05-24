#include <pm2008_i2c.h>
#include <SoftwareSerial.h>

SoftwareSerial A_Serial(5,6);

PM2008_I2C pm2008_i2c;

void setup() {
#ifdef PM2008N
  // wait for PM2008N to be changed to I2C mode
  delay(10000);
#endif
  pm2008_i2c.begin();
  Serial.begin(9600);
  A_Serial.begin(115200);
  
  pm2008_i2c.command();
  delay(1000);
}

void loop() {
  uint8_t ret = pm2008_i2c.read();
  if (ret == 0) {
//    Serial.print("PM 1.0 (GRIMM) : ");
//    Serial.println(pm2008_i2c.pm1p0_grimm);
    Serial.print("PM 2.5 (GRIMM) : ");
    Serial.println(pm2008_i2c.pm2p5_grimm);
    Serial.print("PM 10 (GRIMM) : ");
    Serial.println(pm2008_i2c.pm10_grimm);
//    Serial.print("PM 1.0 (TSI) : ");
//    Serial.println(pm2008_i2c.pm1p0_tsi);
//    Serial.print("PM 2.5 (TSI) : : ");
//    Serial.println(pm2008_i2c.pm2p5_tsi);
//    Serial.print("PM 10 (TSI) : : ");
//    Serial.println(pm2008_i2c.pm10_tsi);
//    Serial.print("Number of 0.3 um : ");
//    Serial.println(pm2008_i2c.number_of_0p3_um);
//    Serial.print("Number of 0.5 um : ");
//    Serial.println(pm2008_i2c.number_of_0p5_um);
//    Serial.print("Number of 1 um : ");
//    Serial.println(pm2008_i2c.number_of_1_um);
//    Serial.print("Number of 2.5 um : ");
//    Serial.println(pm2008_i2c.number_of_2p5_um);
//    Serial.print("Number of 5 um : ");
//    Serial.println(pm2008_i2c.number_of_5_um);
//    Serial.print("Number of 10 um : ");
//    Serial.println(pm2008_i2c.number_of_10_um);
    Serial.print("\n");

    
 
//    A_Serial.println(pm2008_i2c.pm1p0_grimm);
    A_Serial.print(pm2008_i2c.pm2p5_grimm);
    A_Serial.print("#");
    A_Serial.print(pm2008_i2c.pm10_grimm);
//    A_Serial.println(pm2008_i2c.pm1p0_tsi);
//    A_Serial.println(pm2008_i2c.pm2p5_tsi);
//    A_Serial.println(pm2008_i2c.pm10_tsi);
//    A_Serial.print(pm2008_i2c.number_of_0p3_um);
//    A_Serial.print(pm2008_i2c.number_of_0p5_um);
//    A_Serial.println(pm2008_i2c.number_of_1_um);
//    A_Serial.println(pm2008_i2c.number_of_2p5_um);
//    A_Serial.println(pm2008_i2c.number_of_5_um);
//    A_Serial.println(pm2008_i2c.number_of_10_um);
    A_Serial.print("\n");
  }
  delay(1000);
}
