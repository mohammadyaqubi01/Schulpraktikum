#include <ESP8266WiFi.h>
#include <time.h>

WiFiClient espClient;
const char* wifi_ssid = "87654321";
const char* wifi_password = "Mohammad2420";
char time_value[20];

void setup() {
    Serial.begin(115200);
    WiFi.begin(wifi_ssid, wifi_password);

    // Aktuelle Uhrzeit über den Zeit-Server ermitteln
    configTime(2 * 3600, 0, "0.de.pool.ntp.org", "ptbtime1.ptb.de");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    delay(1000);
}

void loop() {
    time_t now = time(nullptr);
    String time = String(ctime(&now));
    time.trim();
    time.substring(0, 19).toCharArray(time_value, 20);

    Serial.print("Uhrzeit: ");
    Serial.println(time_value);
    delay(5000);
}
