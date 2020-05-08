#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// WiFi Parameters
const char* ssid = "Jax-2.4";
const char* password = "Swimstrong";

//Arduino pin that strip is connected to.
#define PIN 0

//How many neoPixels needed:
#define NUMPIXELS 30

// How many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Blink Rate
int blinkRate = 1000;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  //Initialize neoPixel Library
  pixels.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("https://api.nasa.gov/insight_weather/?api_key=xoBye15bYCpmZs687PsofXehlwdrLZNeryDJt1ky&feedtype=json&ver=1.0");
    int httpCode = http.GET();
    //Check the returning code
    if (httpCode > 0) {
      // Get the request response payload
      String json = http.getString();


      // Parsing
      const size_t capacity = 5 * JSON_ARRAY_SIZE(7) + JSON_ARRAY_SIZE(8) + 4 * JSON_ARRAY_SIZE(18) + 24 * JSON_ARRAY_SIZE(24) + 32 * JSON_OBJECT_SIZE(2) + 29 * JSON_OBJECT_SIZE(4) + 112 * JSON_OBJECT_SIZE(5) + 7 * JSON_OBJECT_SIZE(7) + JSON_OBJECT_SIZE(9) + JSON_OBJECT_SIZE(10) + 7 * JSON_OBJECT_SIZE(16) + 10230;
      DynamicJsonDocument doc(capacity);

      deserializeJson(doc, json);


      JsonObject a513 = doc["513"];

      JsonObject a513_AT = a513["AT"];
      float a513_AT_av = a513_AT["av"]; // -57.605
      long a513_AT_ct = a513_AT["ct"]; // 177554
      float a513_AT_mn = a513_AT["mn"]; // -93.043
      float a513_AT_mx = a513_AT["mx"]; // -1.54

      const char* a513_First_UTC = a513["First_UTC"]; // "2020-05-03T05:40:25Z"

      JsonObject a513_HWS = a513["HWS"];
      float a513_HWS_av = a513_HWS["av"]; // 4.541
      long a513_HWS_ct = a513_HWS["ct"]; // 80350
      float a513_HWS_mn = a513_HWS["mn"]; // 0.18
      float a513_HWS_mx = a513_HWS["mx"]; // 16.049

      const char* a513_Last_UTC = a513["Last_UTC"]; // "2020-05-04T06:20:00Z"


      if (a513_AT_mx < -5) {
        // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(0 , 0, 255));
          pixels.show();
          delay(20);
        }
        // This sends the updated pixel color to the hardware.
        //pixels.show(); // nothing happens until this is called

        // pause for a moment
        delay(blinkRate);

        // turn off:
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
          pixels.show();
          delay(20);
        }
        //pixels.show(); // This sends the updated pixel color to the hardware.
        // pause for a moment
        delay(blinkRate);
      }

      if (a513_AT_mx >= -5 && a513_AT_mx < -3) {
        // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(150 , 0, 255));
          pixels.show();
          delay(20);
        }
        // This sends the updated pixel color to the hardware.
        //pixels.show(); // nothing happens until this is called

        // pause for a moment
        delay(blinkRate);

        // turn off:
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
          pixels.show();
          delay(20);
        }
        //pixels.show(); // This sends the updated pixel color to the hardware.
        // pause for a moment
        delay(blinkRate);
      }


      if (a513_AT_mx >= -3 && a513_AT_mx < 0) {
        // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(255 , 150, 0));
          pixels.show();
          delay(20);
        }
        // This sends the updated pixel color to the hardware.
        //pixels.show(); // nothing happens until this is called

        // pause for a moment
        delay(blinkRate);

        // turn off:
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
          pixels.show();
          delay(20);
        }
        //pixels.show(); // This sends the updated pixel color to the hardware.
        // pause for a moment
        delay(blinkRate);
      }


      if (a513_AT_mx >= 0) {
        // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(255 , 0, 0));
          pixels.show();
          delay(20);
        }
        // This sends the updated pixel color to the hardware.
        //pixels.show(); // nothing happens until this is called

        // pause for a moment
        delay(blinkRate);

        // turn off:
        for (int i = 0; i < NUMPIXELS; i++) {
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
          pixels.show();
          delay(20);
        }
        //pixels.show(); // This sends the updated pixel color to the hardware.
        // pause for a moment
        delay(blinkRate);
      }
    }
  }
}
