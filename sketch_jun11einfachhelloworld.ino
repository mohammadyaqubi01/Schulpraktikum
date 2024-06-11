#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "87654321";
const char* password = "Mohammad2420";

// Create an instance of the server
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Define the root endpoint
  server.on("/", []() {
    server.send(200, "text/html", "<h1>Hello World!</h1>");
  });

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}
