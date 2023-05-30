#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

char ctl_z = 0x1A;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // wait serial port initialization
  }

  mySerial.begin(9600);
  while (!mySerial) {
    // wait serial port initialization
  }

//  mySerial.println("AT");
//  delay(100);
//  
//  mySerial.println("AT+CMGF=1");
//  delay(1000); 
//  
//  mySerial.println("AT+CPIN=\"1234\"");
//  delay(1000);
//  
//  mySerial.println("AT+CMGS=\"+639127247880\"<CR>Sending text messages is easy.<Ctrl+z>");
//  delay(1000);

Serial.println("test only");
}

void loop() {

  mySerial.setTimeout(1000);
  
  if (mySerial.available()) {
    String received = mySerial.readStringUntil('\n');
    
    Serial.println(received);
  }
  
  if (Serial.available()) {
    String received2 = Serial.readStringUntil('\n');

    if (String(received2) == "send") {
      
      mySerial.print("AT+CMGS=\"");
      mySerial.print("9127247880");
      mySerial.print("\"\r");
      mySerial.print("test message only!\r\n" + ctl_z);
      delay(100);
      
      Serial.println("na send!");
    }
    else {
      mySerial.print(received2 + "\r\n");
      delay(100);
    }
  }
}
