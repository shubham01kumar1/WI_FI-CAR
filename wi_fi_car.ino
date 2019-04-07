#include <ESP8266WiFi.h>
String  ClientRequest;
IPAddress staticIP888_10(192,168,1,10);
IPAddress gateway888_10(192,168,1,1);
IPAddress subnet888_10(255,255,255,0);

WiFiServer server(80);

void setup()
{
  ClientRequest = "";
 

Serial.begin(9600);
pinMode(16, OUTPUT);
pinMode(5, OUTPUT);
pinMode(0, OUTPUT);
pinMode(2, OUTPUT);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("ssid_n","12345678");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  WiFi.config(staticIP888_10, gateway888_10, subnet888_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  server.begin();
}

void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    ClientRequest = (client.readStringUntil('\r'));
    ClientRequest.remove(0, 5);
    ClientRequest.remove(ClientRequest.length()-9,9);
    Serial.println(ClientRequest);
    if (ClientRequest == "on") {
      Serial.println("fgggft");
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(0,HIGH);
      digitalWrite(2,LOW);

    } else if (ClientRequest == "L") {
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
    } else if (ClientRequest == "R") {
      digitalWrite(0,HIGH);
      digitalWrite(2,LOW);
    } else if (ClientRequest == "B") {
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(0,LOW);
      digitalWrite(2,HIGH);
    }
     else {
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(0,LOW);
      digitalWrite(2,LOW);}
    client.flush();

}
