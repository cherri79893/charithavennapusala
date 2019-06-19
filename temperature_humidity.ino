#include <DHT.h>
#include <DHT_U.h>

#include <ssl_client.h>
#include <WiFiClientSecure.h>

#include <Adafruit_Sensor.h>

#define DHTPIN 2
#define DHTTYPE    DHT11   

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal.h>
#include <ThingSpeak.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
 
const int rs = 13, en = 12, d4 = 14, d5 = 27, d6 = 26, d7 = 25;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const char* ssid     = "SmartBridge"; 
const char* password = "smartbridge@sb";

WiFiClient client;

unsigned long myChannelNumber = 804377; 
const char *myWriteAPIKey ="OSXMHARV02A3NZ9Y";

WiFiServer server(80);

void setup() {
  dht.begin();

  lcd.begin(16, 2);
  
  pinMode(4,OUTPUT);
  Serial.begin(115200);
  pinMode(34, INPUT);   
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi is connected");
    server.begin();
    Serial.println("Server started");
    Serial.println(WiFi.localIP());
    ThingSpeak.begin(client);
}
void loop() {
  float temperature = dht.readTemperature();
  
  float humidity = dht.readHumidity();
  
   Serial.print("Temperature ");
   Serial.print(temperature);
   delay(500);
   Serial.println("Humidity");
   Serial.print(humidity);
   delay(500);
   
    lcd.clear();
    lcd.print("Temperature ");
    lcd.print(temperature);
    lcd.setCursor(0,1);
    lcd.print("Humidity");
    lcd.print(humidity); 
    if(temperature>=30)
    {
    digitalWrite(4,HIGH);
    }
   else
   {
    digitalWrite(4,LOW);
    }
    WiFiClient client = server.available();
   
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  
    client.println("Refresh: 10"); 
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.print("<p style='text-align: center;'><span style='font-size: x-large;'><strong>Digital Temperature meter</strong></span></p>");
    client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>Temperature (*C)= ");
    client.println(temperature);
    client.print("<p style='text-align: center;'><span style='color: #0000ff;'><strong style='font-size: large;'>Humidity = ");
    client.println(humidity);
    client.print("</p>");
    client.println("</html>");
    delay(5000);
    static boolean data_state = false;
    ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
    delay(30000);
    ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
    delay(30000);
}
 
