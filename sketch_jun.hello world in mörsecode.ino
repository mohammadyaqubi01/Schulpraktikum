const int ledPin = 2;  // LED an GPIO2, oft die eingebaute LED auf ESP8266

// Morse-Code Definitionen
const int dotDuration = 200;  // Dauer eines Punktes in Millisekunden
const int dashDuration = dotDuration * 3;  // Dauer eines Strichs
const int intraCharGap = dotDuration;  // Pause zwischen Punkten/Strichen eines Zeichens
const int interCharGap = dotDuration * 3;  // Pause zwischen Zeichen
const int interWordGap = dotDuration * 7;  // Pause zwischen Wörtern

// Morse-Code-Tabelle
const char* morseCodeTable[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};
 
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Sicherstellen, dass die LED zunächst aus ist
}

void loop() {
  const char* message = "HELLO WORLD";
  for (int i = 0; message[i] != '\0'; i++) {
    if (message[i] == ' ') {
      delay(interWordGap);  // Wortzwischenraum
    } else {
      sendMorseCode(message[i]);
      delay(interCharGap);  // Zeichenzwischenraum
    }
  }
  delay(5000);  // Pause zwischen Nachrichten
}

void sendMorseCode(char c) {
  if (c >= 'A' && c <= 'Z') {
    const char* morse = morseCodeTable[c - 'A'];
    while (*morse) {
      if (*morse == '.') {
        digitalWrite(ledPin, HIGH);
        delay(dotDuration);
        digitalWrite(ledPin, LOW);
      } else if (*morse == '-') {
        digitalWrite(ledPin, HIGH);
        delay(dashDuration);
        digitalWrite(ledPin, LOW);
      }
      morse++;
      delay(intraCharGap);  // Pause zwischen Punkten/Strichen
    }
  }
}
