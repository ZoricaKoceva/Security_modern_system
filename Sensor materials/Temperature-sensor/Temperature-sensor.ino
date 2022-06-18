#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11//#define DHTTYPE DHT21
                     //#define DHTTYPE DHT22
                     
DHT dht(DHTPIN, DHTTYPE);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <GSM.h>

#define PINNUMBER ""

GSM gsmAccess;
GSM_SMS sms;

void setup() {
 dht.begin();// inicijalizacija na senzorot
 lcd.backlight();// vkluchuvanje na lcd 
 lcd.init();// initialize lcd
//   // inicijalizacija na seriska komunikacija i chekanje za porta 
//  Serial.begin(9600);
//  Serial.println("SMS prakjach na poraki");
}

void loop() {
   lcd.clear();
   lcd.setCursor(0,0); //postavuvanje na pochetok
   lcd.print("Vlazhnost=");
   lcd.print((float)dht.readHumidity());//pechatenje na vlazhnosta
   lcd.print("%");
   lcd.setCursor(0,1);//postavuvanje za pechatenje podole
   lcd.print("Temperatura=");
   lcd.print((float)dht.readTemperature());//print the temperature
   lcd.print("Celsius");
//   int vremeMomentalno = millis();
//   int temperatura = lcd.read();
//   delay(2000);
//   lcd.clear();
//
//   if (millis() - vremeMomentalno >= 15000 and temperatura > 50);{ // ako za vreme od 15 sekundi trae, postoi golema toplina i ne se izgasne, itna pomosh
//    
//      char pozharnaBroj[3] = "193";  // telefonski broj za da se prati porakata na pozharnata
//      Serial.println(remoteNum);
//    
//      // sms tekst
//      Serial.print("ITNA sodrzhina na porakata: ");
//      char tekstPoraka[200]="ITNO-pozhar na adresa... ";
//      Serial.println("ISPRAKJANJE");
//      Serial.println();
//      Serial.println("Poraka za pomosh:");
//      Serial.println(txtMsg);
//    
//      // isprakjanje na poraka
//      sms.beginSMS(pozharnaBroj);
//      sms.print(tekstPoraka);
//      sms.endSMS();
//      Serial.println("\nZAVRSHENO!\n");
//   }
}
