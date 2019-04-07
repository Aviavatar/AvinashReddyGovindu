#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "speedy-nodemcu.firebaseio.com"
#define FIREBASE_AUTH "yymxIQPbnInvnvLS0fc1tkA9UzPZuSbmTZGTlqv5"
#define WIFI_SSID "Aviavatar"
#define WIFI_PASSWORD "qwertyui"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
    for(int i=1; i<=10; i++) {
        String phdata = Serial.readStringUntil(':');
        Serial.println(phdata);
        if(phdata != ""){
            String ph = Serial.readStringUntil('$');
           
            Serial.println(ph);
            float phvalue=ph.toFloat();
             Serial.println();
            Serial.println("PH Value");
            Serial.println(phvalue);
             Firebase.setFloat("pH value",phvalue);
            Firebase.setString("details",phdata);
                   }
    }
}
