
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#define TRIGGER 5
#define ECHO    4
const char *ssid = "House Flooding Early Detection" ;
char *ssid_client = "" , *pass = "";
const char *password = "alaa&abrar";
String ID = "1" ; 
const int httpPort = 80;
const char* host = "www.alaaandabrar.co.nf";
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<!DOCTYPE html>\
  <html><body><center><font color=\"#B10789\">\
  <h1>Welcome to House Flooding Early Detection Settings Configuration</h1>\
  <form action=\"Thankyou\">\
  <br>Name of your Wifi:<br><input type=\"text\" name=\"Wifi\">\
  <br><br>Enter Password:<br><input type=\"text\" name=\"pass\">\
  <br><br><input type=\"submit\" value=\"Submit\">\
  </center></form></body></html>");
}

void handelthank() {
  char tmp[10001] ;
  String a = server.arg("Wifi") ;
  String b = server.arg("pass");
  a+=" "; 
  b+=" ";
  a.toCharArray(ssid_client, a.length());
  b.toCharArray(pass, b.length());  
  sprintf(tmp , "<!DOCTYPE html>\
  <html><body><center><h1><font color=\"green\"> Thank you =D</h1>\
  <p><font color=\"BLACK\"> Your Wifi Network is : %s </p>\
  <p> Your Password is : %s  </p>\
  <p><font color=\"red\">If you didn't fill the information correctly or you have any errors <a href=\"/\" >Try Again</a></p>\
  </center></body></html>" , ssid_client , pass ) ; 
  server.send(200, "text/html", tmp);   
}
void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: " );
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/Thankyou", handelthank);
  server.begin();
  Serial.println("HTTP server started");
  Serial.begin (9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}
int stat=0; 
void loop() {
  if(!stat){ 
    memset(ssid_client,0,sizeof(ssid_client));
    memset(pass,0,sizeof(pass));
    server.handleClient();
    Serial.print("Connecting to ");
    Serial.println(ssid_client);
    if (strlen(ssid_client) != 0 ) {
      WiFi.begin(ssid_client, pass);
      for (int i=0; i < 10; i++) 
        if (WiFi.status() != WL_CONNECTED) {
          delay(500);Serial.print(".");
        }else 
        break;
      delay(1000);
      if(WiFi.status() == WL_CONNECTED ) { 
        Serial.println("WiFi connected");
        stat = 1 ; 
      }}}else { 
        //Serial.println("WiFi connected =D");
        server.stop();
        delay(5000);
   
        WiFiClient client;
        
        client.connect(host, httpPort);
        //int dist =random(1000); 
        double  duration, dist;
        digitalWrite(TRIGGER, LOW);  
        delayMicroseconds(2); 
        digitalWrite(TRIGGER, HIGH);
        delayMicroseconds(10); 
        digitalWrite(TRIGGER, LOW);
        duration = pulseIn(ECHO, HIGH);
        dist = (duration/2) / 29.1;
        delay(500);
        
        Serial.println(dist);
        String url = "/b.php?Dist=";
        url +=String(dist);
        url += "&ID=";
        url +=ID; 
        Serial.print("Requesting URL: ");
        Serial.println(url);
        // This will send the request to the server
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
        int timeout = millis() + 5000;
        while (client.available() == 0) {
         if (timeout - millis() < 0) {
           Serial.println(">>> Client Timeout !");
           client.stop();
           return;
            }
         }
       // Read all the lines of the reply from server and print them to Serial
       while(client.available()){
       String line = client.readStringUntil('\r');
        Serial.print(line);
        
       }
  
      Serial.println();
     
      Serial.println("closing connection");
      
         
      }
        
}
   
   
 
