#include <NTPClient.h>
// change next line to use with another board/shield
#include <SPI.h>
#include <WiFiNINA.h>
//#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>

const char *ssid     = "TECHNICOLOR";
const char *password = "212142984";

WiFiUDP ntpUDP;

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
//NTPClient timeClient(ntpUDP, "id.pool.ntp.org", 3600, 60000);
NTPClient timeClient(ntpUDP, "id.pool.ntp.org",25200,60000);


void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());

  delay(1000);
}
