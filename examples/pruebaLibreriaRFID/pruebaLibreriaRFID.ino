/**
* PruebaLibreriaRFID.ino  (Test of RFID Library)
*
* Read a card using an mfrc522 reader connected to SPI interface
* and display its serial number on the console
*
* Pin layout should be as follows:
* Signal     Pin              Pin               Pin
*            Arduino Uno      Arduino Mega      MFRC522 board
* ------------------------------------------------------------
* Reset      9                5                 RST
* SPI SS     10               53                SDA
* SPI MOSI   11               51                MOSI
* SPI MISO   12               50                MISO
* SPI SCK    13               52                SCK
*
*/

#include <SPI.h>
#include <RFID.h>

RFID rfid(10,5); 

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init();
  
}

void loop()
{
    if (rfid.isCard()) {
      
          Serial.println("IS CARD");
          
          if (rfid.readCardSerial()) {
            
                        Serial.println(" ");
                        Serial.println("El numero de serie de la tarjeta es  : ");
			Serial.print(rfid.serNum[0],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[1],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[2],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[3],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[4],DEC);
                        Serial.println(" ");
                       
            
          }
          
    }
    
    rfid.halt();
}
