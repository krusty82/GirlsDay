// Text vom Handy ans Display senden

// WLAN Einstellungen

const char *ssid = "Girlsday";
const char *password = "12345678";


#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// OLED-Display Parameter
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// I2C-Pin Definitionen
#define OLED_SCL 12
#define OLED_SDA 14

const unsigned char Girlsday [] PROGMEM = {
	// 'Girlsday2, 128x64px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xf3, 0xff, 0xfe, 0x1f, 0xff, 0x88, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xfc, 0xff, 0xe1, 0xff, 0xfe, 0x1f, 0xff, 0x98, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xc0, 0x1f, 0xc1, 0xff, 0xfe, 0x9f, 0xff, 0x38, 0x3f, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x80, 0x0f, 0xc1, 0xff, 0xff, 0x9f, 0xfb, 0x78, 0x3f, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x1f, 0xc7, 0xe3, 0xff, 0xff, 0x9f, 0xdb, 0xf8, 0x3f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xfe, 0x7f, 0xe3, 0xff, 0xfe, 0x1d, 0x8f, 0xdb, 0xf8, 0x3f, 0xf0, 0x7f, 0x03, 0xff, 0xff, 0xff, 
	0xfc, 0xff, 0xf3, 0xff, 0xbf, 0xff, 0x8f, 0xdb, 0xf8, 0x3f, 0xf8, 0x3c, 0x71, 0xe0, 0x3f, 0x87, 
	0xf9, 0xff, 0xff, 0xfe, 0xfd, 0x87, 0x8f, 0x8f, 0xf8, 0x3f, 0xf8, 0x38, 0x98, 0xe0, 0x3f, 0x87, 
	0xf9, 0xff, 0xff, 0xfa, 0x81, 0x03, 0x8f, 0xad, 0x78, 0x3f, 0xf8, 0x39, 0x94, 0x78, 0x7f, 0x87, 
	0xf3, 0xff, 0xff, 0xc2, 0xc0, 0x0b, 0x8e, 0x69, 0x78, 0x3f, 0xfc, 0x10, 0x94, 0x78, 0x7f, 0x07, 
	0xf3, 0xff, 0xff, 0xc2, 0xe0, 0xcb, 0xce, 0x82, 0xf8, 0x3f, 0xfc, 0x10, 0x74, 0x78, 0x7f, 0x0f, 
	0xf3, 0xff, 0xff, 0xc2, 0xe0, 0xfb, 0xcf, 0x03, 0xf8, 0x3f, 0xfc, 0x13, 0x94, 0x70, 0x7f, 0x0f, 
	0xe3, 0xc0, 0x03, 0x82, 0xe1, 0xfb, 0xcf, 0x10, 0xf8, 0x3f, 0xfc, 0x15, 0x14, 0x70, 0x7f, 0x0f, 
	0xe3, 0xc0, 0x03, 0x82, 0xe1, 0xff, 0xcf, 0x10, 0xf8, 0x3f, 0xfc, 0x1e, 0x14, 0x70, 0xfe, 0x0f, 
	0xe3, 0xc0, 0x03, 0x86, 0xe1, 0xff, 0xcf, 0x0f, 0xf8, 0x3f, 0xfc, 0x1a, 0x15, 0xf0, 0xfe, 0x0f, 
	0xf3, 0xff, 0xe7, 0x86, 0xe1, 0xff, 0xcf, 0x87, 0xf8, 0x3f, 0xfc, 0x37, 0x15, 0x70, 0xfe, 0x1f, 
	0xf3, 0xff, 0xe7, 0x86, 0xe1, 0xf7, 0xce, 0xc2, 0xf8, 0x3f, 0xf8, 0x35, 0xd7, 0x60, 0xfe, 0x1f, 
	0xf1, 0xff, 0xcf, 0x86, 0xe1, 0xf7, 0xce, 0x63, 0xf8, 0x3f, 0xf8, 0x30, 0x0e, 0x20, 0xfe, 0x1f, 
	0xf8, 0xff, 0x9f, 0x86, 0xe1, 0xf7, 0xcf, 0xf0, 0xf8, 0x3f, 0xf0, 0x7c, 0x00, 0x60, 0xfc, 0x1f, 
	0xf8, 0x7e, 0x3f, 0x86, 0xe1, 0xf7, 0xce, 0x01, 0xf8, 0x3f, 0xf0, 0xff, 0xc1, 0xe0, 0xf8, 0x1f, 
	0xfc, 0x00, 0x7f, 0x86, 0xe1, 0xf7, 0xc3, 0x01, 0xf8, 0x3f, 0xc1, 0xff, 0xff, 0xe0, 0x00, 0x1f, 
	0xff, 0x01, 0xff, 0x06, 0xe1, 0xfe, 0x01, 0x81, 0xf8, 0x3e, 0x03, 0xff, 0xff, 0xe0, 0x04, 0x3f, 
	0xff, 0xff, 0xff, 0x06, 0xc0, 0x3e, 0x03, 0xe7, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x0c, 0x3f, 
	0xff, 0xff, 0xff, 0xfe, 0xdf, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7c, 0x3f, 
	0xff, 0xff, 0xff, 0xfe, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xfc, 0x3f, 
	0xff, 0xff, 0xff, 0xfe, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xf8, 0x3f, 
	0xff, 0xff, 0xff, 0xfe, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xf8, 0x7f, 
	0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0xe0, 0x7f, 
	0xff, 0xff, 0x80, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 
	0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xff, 0x84, 0x4a, 0x10, 0x40, 0x00, 0x38, 0x18, 0x00, 0x34, 0x00, 0x00, 0x38, 0x1f, 0xff, 
	0xff, 0xff, 0x86, 0x40, 0x10, 0x40, 0x00, 0x08, 0x10, 0x00, 0x24, 0x08, 0x00, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0x86, 0xce, 0x77, 0x73, 0xbc, 0x19, 0x54, 0xa7, 0x6c, 0x99, 0xde, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0x86, 0xa2, 0x94, 0x42, 0xa5, 0x91, 0x5c, 0xa5, 0x24, 0x88, 0xd2, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0x8d, 0xaa, 0x94, 0x5a, 0x24, 0x21, 0x5c, 0xa5, 0x24, 0x49, 0x5c, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0x89, 0x2e, 0x77, 0x53, 0xa4, 0x39, 0xd6, 0xe5, 0x26, 0xcd, 0xdc, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// DS18B20 Temperatur-Sensor
#define ONE_WIRE_BUS 4 // GPIO4 = D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float currentTemperature = 0.0;


AsyncWebServer server(80);

String replaceGermanUmlauts(String text) {
  text.replace("ä", "ae");
  text.replace("ö", "oe");
  text.replace("ü", "ue");
  text.replace("Ä", "Ae");
  text.replace("Ö", "Oe");
  text.replace("Ü", "Ue");
  text.replace("ß", "ss");
  text.replace("ẞ", "ss");
  return text;
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Text an OLED senden</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
      display: flex;
      align-items: center;
      justify-content: center;
      height: 100vh;
      background-color: #f4f4f9;
    }
    .container {
      background-color: white;
      padding: 20px;
      box-shadow: 0 4px 8px rgba(0,0,0,0.1);
      border-radius: 10px;
      text-align: center;
      max-width: 400px;
      width: 80%;
    }
    .container h1 {
      font-size: 1.5em;
      margin-bottom: 10px;
      color: #333;
    }
    .container p {
      margin: 10px 0;
      font-size: 1.1em;
      color: #444;
    }
    .container textarea {
      width: 90%;
      height: 125px;
      padding: 10px;
      font-size: 1.5em;
      border-radius: 5px;
      border: 1px solid #ddd;
      resize: vertical;
    }
    .container button {
      margin-top: 20px;
      padding: 10px 20px;
      font-size: 1em;
      color: white;
      background-color: #5cb85c;
      border: none;
      border-radius: 5px;
      cursor: pointer;
      transition: background-color 0.3s;
    }
    .container button:hover {
      background-color: #4cae4c;
    }
  </style>
  <script>
    function fetchTemperature() {
      fetch('/temperature')
        .then(response => response.text())
        .then(temp => {
          document.getElementById('tempDisplay').innerText = temp;
        })
        .catch(error => {
          document.getElementById('tempDisplay').innerText = 'Fehler';
          console.error('Temperatur-Fehler:', error);
        });
    }

    window.onload = function() {
      //fetchTemperature(); // beim Laden

      setInterval(fetchTemperature, 5000); // alle 5 Sekunden

      document.getElementById('sendBtn').onclick = function() {
        const text = document.getElementById('textInput').value;
        fetch('/upload', {
          method: 'POST',
          headers: {'Content-Type': 'application/x-www-form-urlencoded'},
          body: 'text=' + encodeURIComponent(text)
        })
        .then(response => {
          if (!response.ok) throw new Error('Netzwerk-Antwort war nicht okay');
          return response.text();
        })
        .then(data => alert(data))
        .catch(error => alert('Fetch-Fehler: ' + error.message));
      };

      document.getElementById('clearBtn').onclick = function () {
        document.getElementById('textInput').value = "";
      };
    };
  </script>
</head>
<body>
  <div class="container">
    <h1>Text an das OLED-Display senden:</h1>
    <p><strong>Aktuelle Temperatur:</strong> <span id="tempDisplay">lade...</span> &deg;C</p>
    <textarea id="textInput" placeholder="Gib hier deinen Text ein"></textarea>
    <button id="sendBtn">An OLED senden</button>
    <button id="clearBtn" class="clear-btn">Text l&ouml;schen</button>
  </div>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  Wire.begin(OLED_SDA, OLED_SCL);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.drawBitmap(0, 0, Girlsday, 128, 128, WHITE);
  display.display();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  sensors.begin();
  Serial.println("DS18B20 Sensor gestartet.");

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Access Point IP: ");
  Serial.println(myIP);

  //display.clearDisplay();
  display.setCursor(0, 0);
  display.print("WLAN: ");
  display.println(ssid);
  display.print("IP: ");
  display.println(myIP);
  display.display();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  server.on("/upload", HTTP_POST, [](AsyncWebServerRequest *request) {
    if (request->hasParam("text", true)) {
      String text = replaceGermanUmlauts(request->getParam("text", true)->value());
      Serial.print("Empfangener Text: ");
      Serial.println(text);

      display.fillRect(0, 16, SCREEN_WIDTH, SCREEN_HEIGHT - 16, SSD1306_BLACK);
      int16_t x = 0, y = 16;
      display.setTextSize(1);

      for (size_t i = 0; i < text.length(); i++) {
        if (x > SCREEN_WIDTH - 6 || text[i] == '\n') {
          x = 0;
          y += 8;
        }
        if (y > SCREEN_HEIGHT - 8) break;
        display.setCursor(x, y);
        if (text[i] != '\n') {
          display.write(text[i]);
          x += 6;
        }
      }
      // display.display();
      request->send(200, "text/plain", "Text empfangen und angezeigt");
    } else {
      request->send(400, "text/plain", "Kein Text empfangen");
    }
  });

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(currentTemperature, 1));
  });

  server.begin();
  Serial.println("Webserver gestartet.");
}

void loop() {
  static unsigned long lastTempRead = 0;
  static int lastClientCount = -1;
  int currentClientCount = WiFi.softAPgetStationNum();
  sensors.requestTemperatures();
  currentTemperature = sensors.getTempCByIndex(0);

  if (currentClientCount != lastClientCount) {
    display.fillRect(0, 0, SCREEN_WIDTH, 16, SSD1306_BLACK);
    display.setCursor(0, 0);
    display.print("WLAN: ");
    display.println(ssid);

    if (currentClientCount > 0) {
      display.print("C ");
      display.print("IP: ");
      display.println(WiFi.softAPIP());
    } else {
      display.print("IP: ");
      display.println(WiFi.softAPIP());
    }
    display.display();
    lastClientCount = currentClientCount;
  }

  if (millis() - lastTempRead > 5000) {
    sensors.requestTemperatures();
    currentTemperature = sensors.getTempCByIndex(0);
    Serial.print("Temp: ");
    Serial.println(currentTemperature);

    display.fillRect(92, 0, SCREEN_WIDTH-80, 8, SSD1306_BLACK);
    display.setCursor(92, 0);
    display.print("T:");
    display.println(currentTemperature, 1);
    display.display();

    lastTempRead = millis();
  }

  delay(1000);
  display.display();
  yield();
}

