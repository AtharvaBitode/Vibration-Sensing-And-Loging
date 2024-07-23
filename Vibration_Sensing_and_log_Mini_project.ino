#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "OnePlus Nord 3 5G";
const char* password = "password11";

const int vibrationSensorPin = D2;  // Vibration sensor analog input pin
const int ledHighPin = D1;          // LED for high vibration
const int ledLowPin = D3;           // LED for low vibration

const char* host = "script.google.com";
const int httpsPort = 443;
unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {
  pinMode(vibrationSensorPin, INPUT);
  pinMode(ledHighPin, OUTPUT);
  pinMode(ledLowPin, OUTPUT);

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read analog vibration sensor data
  int vibrationValue = digitalRead(vibrationSensorPin);
  int measurement = vibration();
  Serial.print("Vibration Measurement: ");
  Serial.println(measurement);
  Serial.print("Vibration Measurement pin: ");
  Serial.println(vibrationValue);
  // Control LEDs based on vibration value
  if (vibrationValue > 512) {
    // High vibration detected
    digitalWrite(ledHighPin, HIGH);
    digitalWrite(ledLowPin, LOW);
  } else {
    // Low or no vibration
    digitalWrite(ledHighPin, LOW);
    digitalWrite(ledLowPin, HIGH);
  }


  // Create an HTTPS client
  WiFiClientSecure client;
  client.setInsecure();

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed");
    return;
  }
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;


    // Prepare the data to be sent
    String url = "/macros/s/AKfycbxOBOWHW-gi7zm4c2g4mjFZjAvtOeznLkXGaV0ueqk_WlseZm4pFoaFFJALHPygMQrp/exec?"
                 "vibrationValue="
                 + String(measurement);

    Serial.print("Sending request to: ");
    Serial.println(url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

    // Wait for the server's response

    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
    }
  }

  delay(100);  // Adjust delay as needed
}

long vibration() {
  long measurement = (vibrationSensorPin, HIGH); // Wait for the pin to get HIGH and return measurement
  return measurement;
}
