#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    // wait serial port initialization
  }

  mySerial.begin(9600);
  while (!mySerial)
  {
    // wait serial port initialization
  }

  Serial.println("test only");
}

void loop()
{

  mySerial.setTimeout(1000);

  if (mySerial.available())
  {
    String received = mySerial.readStringUntil('\n');

    Serial.println(received);
  }

  if (Serial.available())
  {
    String received2 = Serial.readStringUntil('\n');

    if (String(received2) == "send")
    {
      mySerial.println("AT+CMGF=1");                   // Sets the GSM Module in Text Mode
      delay(1000);                                     // Delay of 1000 milli seconds or 1 second
      mySerial.println("AT+CMGS=\"+639159524049\"\r"); // Replace x with mobile number
      delay(1000);
      mySerial.println("I am SMS from GSM Module"); // The SMS text you want to send
      delay(100);
      mySerial.println((char)26); // ASCII code of CTRL+Z
      delay(1000);
    }
    else
    {
      mySerial.print(received2 + "\r\n");
      delay(100);
    }
  }
}
