#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "87654321";
const char* password = "Mohammad2420";

// Create an instance of the server
ESP8266WebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>ESP8266 Web Server</title>
  <script>
    function updateTime() {
      var now = new Date();
      var timeString = now.toLocaleTimeString('de-DE', { hour12: false });
      document.getElementById('time').innerHTML = timeString;
    }
    setInterval(updateTime, 1000);
  </script>
</head>
<body>
  <p>Current Time in Germany: <span id="time"></span></p>
  <script>
    updateTime(); // Initial call to display the time immediately
  </script>
</body>
</html>
)rawliteral";

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
    server.send(200, "text/html", index_html);
  });

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle client requests
  server.handleClient();
}
