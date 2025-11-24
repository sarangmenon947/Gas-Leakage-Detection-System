#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "A's M14";       
const char* password = "rdgj45yu"; 

const int smokeSensorPin = A0; 
const int buzzerPin = D1;      
const int ledRed = D2;
const int ledYellow = D3;
const int ledGreen = D4;

int noGasLeakage = 0;
int moderateGasLeakage = 50;
int highGasLeakage = 75;

ESP8266WebServer server(80);   

void setup() {
  Serial.begin(115200);

  digitalWrite(ledGreen, HIGH);
  
  pinMode(smokeSensorPin, INPUT);  
  pinMode(buzzerPin, OUTPUT);      
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  int gasLeakageLevel;

  gasLeakageLevel = analogRead(smokeSensorPin);
  
  if (gasLeakageLevel == noGasLeakage) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(buzzerPin, LOW);
  } else if (gasLeakageLevel >= highGasLeakage) {
    digitalWrite(ledYellow, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else if (gasLeakageLevel >= highGasLeakage) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  server.handleClient();
}

void handleRoot() {
  String html = "<html><title>ESP8266 Gas Leakage Detection System</title><body>";

  html += "<h1>Gas Leakage Detection System</h1>";

  html += "<button>Red LED</button>";
  html += "<button>Green LED</button>";
  html += "<button>Yellow LED</button>";
  html += "</body></html>";


  server.send(200, "text/html");
}
