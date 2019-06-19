#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
 
#include <ThingSpeak.h>  
  
const char* ssid = "dharani@123";  
const char* password = "friendsforever";  
WiFiClient client;  
unsigned long myChannelNumber = 804377;  
const char * myWriteAPIKey = "OSXMHARV02A3NZ9Y";  

void setup()  
{  
  Serial.begin(115200);  
    
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
}  
void loop()   
{  
  static boolean data_state = false;  
  for (int i=0;i<=10;i++)
    {
        
    int temperature = i;
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
   
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1. 
   ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);  
  
  delay(30000); // ThingSpeak will only accept updates every 15 seconds.  
} 
}
