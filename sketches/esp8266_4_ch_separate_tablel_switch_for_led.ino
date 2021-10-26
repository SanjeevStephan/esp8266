#include <dummy.h>

/*********
  Sanjeev stephan
  Complete project details at http://randomnerdtutorials.com 
NODE MCU ESP8266
------------------
LED      = GPIO D4
RELAY 1  = GPIO D5
RELAY 2  = GPIO D6
RELAY 3  = GPIO D7
RELAY 4  = GPIO D8

*********/

// Load Wi-Fi library
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid     = "SmartHome";
const char* password = "smarthome123";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output8State = "off";
String output7State = "off";
String output6State = "off";
String output5State = "off";
String ledState = "off";

// Assign output variables to GPIO pins
const int output8 = D8;
const int output7 = D7;
const int output6 = D6;
const int output5 = D5;
const int led = D4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output8,OUTPUT);
  pinMode(output7,OUTPUT);
  pinMode(output6, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(led,OUTPUT);
  
  // Set outputs to LOW
  digitalWrite(output8, HIGH);
  digitalWrite(output7, HIGH);
  digitalWrite(output6, HIGH);
  digitalWrite(output5, HIGH);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(led, HIGH);
    delay(400);
    Serial.print(".");
    digitalWrite(led, LOW);  
    delay(400);  
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients
 // digitalWrite(led, LOW);                // Light up LED to show that it is CONNECTED_2_WIFI
  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off

            
              if (header.indexOf("GET /8/on") >= 0) {
              Serial.println("GPIO D8 ON");
              Serial.println("RELAY 4 ON");              
              output8State = "on";
              digitalWrite(output8, LOW);
            } else if (header.indexOf("GET /8/off") >= 0) {
              Serial.println("GPIO D8 OFF");
              Serial.println("RELAY 4 OFF");                      
              output8State = "off";
              digitalWrite(output8, HIGH);
            } else if (header.indexOf("GET /7/on") >= 0) {
              Serial.println("GPIO D7 ON");
              Serial.println("RELAY 3 ON");                      
              output7State = "on";
              digitalWrite(output7, LOW);
            } else if (header.indexOf("GET /7/off") >= 0) {
              Serial.println("GPIO D7 OFF");
              Serial.println("RELAY 3 OFF");                      
              output7State = "off";
              digitalWrite(output7, HIGH);
            } else if (header.indexOf("GET /6/on") >= 0) {
              Serial.println("GPIO D6 ON");
              Serial.println("RELAY 2 ON");                      
              output6State = "on";
              digitalWrite(output6, LOW);
            } else if (header.indexOf("GET /6/off") >= 0) {
              Serial.println("GPIO D6 OFF");
              Serial.println("RELAY 2 OFF");                      
              output6State = "off";
              digitalWrite(output6, HIGH);
            } else if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO D5 ON");
              Serial.println("RELAY 1 ON");                      
              output5State = "on";
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO D5 OFF");
              Serial.println("RELAY 1 OFF");                      
              output5State = "off";
              digitalWrite(output5, HIGH);
            } else if (header.indexOf("GET /led/on") >= 0) {
              Serial.println("GPIO D4 ON");
              Serial.println("LED ON");                      
              ledState = "on";
              digitalWrite(led, LOW);
            } else if (header.indexOf("GET /led/off") >= 0) {
              Serial.println("GPIO D4 OFF");
              Serial.println("LED OFF");                      
              ledState = "off";
              digitalWrite(led, HIGH);
            }
            
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println("a {text-decoration: none; font-size: 30px;color: white;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP8266 Web Server</h1>");

    

           // table headings
          client.println("<center><table border=\"2\"><th>Switch</th><th>RELAY</th><th>GPIO</th><th>STATE</th>");
          //----------------- first row opening -----------------
          client.println("<tr>");
           // If the output5State is off, it displays the ON button  
          if (output5State=="off") {
              client.println(" <td><a href=\"/5/on\"><button class=\"button button2\">OFF</button></a></td>");    
           } else {
              client.println("<td><a href=\"/5/off\"><button class=\"button \">ON</button></a></td>");
            }                    
          // Display current state, and ON/OFF buttons for GPIO 5  
          client.println("<td> Relay Ch 1</td>");
          client.println("<td>GPIO D5 </td>");                  
          client.println("<td> " + output5State + "</td>");
          client.println("</tr>");
          //----------------- first row closing -----------------          


          //----------------- second row opening -----------------
          client.println("<tr>");
           // If the output5State is off, it displays the ON button  
          if (output6State=="off") {
              client.println(" <td><a href=\"/6/on\"><button class=\"button button2\">OFF</button></a></td>");    
           } else {
              client.println("<td><a href=\"/6/off\"><button class=\"button \">ON</button></a></td>");
            }                    
          // Display current state, and ON/OFF buttons for GPIO 6  
          client.println("<td> Relay Ch 2</td>");
          client.println("<td>GPIO D6 </td>");                  
          client.println("<td> " + output6State + "</td>");
          client.println("</tr>");
          //----------------- second row closing -----------------        

         //----------------- third row opening -----------------
          client.println("<tr>");
           // If the output7State is off, it displays the ON button  
          if (output7State=="off") {
              client.println(" <td><a href=\"/7/on\"><button class=\"button button2\">OFF</button></a></td>");    
           } else {
              client.println("<td><a href=\"/7/off\"><button class=\"button \">ON</button></a></td>");
            }                    
          // Display current state, and ON/OFF buttons for GPIO 7  
          client.println("<td> Relay Ch 3</td>");
          client.println("<td>GPIO D7 </td>");                  
          client.println("<td> " + output7State + "</td>");
          client.println("</tr>");
          //----------------- third row closing ----------------- 

           //----------------- fourth row opening -----------------
          client.println("<tr>");
           // If the output8State is off, it displays the ON button  
          if (output8State=="off") {
              client.println(" <td><a href=\"/8/on\"><button class=\"button button2\">OFF</button></a></td>");    
           } else {
              client.println("<td><a href=\"/8/off\"><button class=\"button \">ON</button></a></td>");
            }                    
          // Display current state, and ON/OFF buttons for GPIO 8  
          client.println("<td> Relay Ch 4</td>");
          client.println("<td>GPIO D8 </td>");                  
          client.println("<td> " + output8State + "</td>");
          client.println("</tr>");
          //----------------- fourth row closing ----------------- 


          //----------------- fifth row opening -----------------
          client.println("<tr>");
           // If the output5State is off, it displays the ON button  
          if (ledState=="off") {
              client.println(" <td><a href=\"/led/on\"><button class=\"button button2\">OFF</button></a></td>");    
           } else {
              client.println("<td><a href=\"/led/off\"><button class=\"button \">ON</button></a></td>");
            }                    
          // Display current state, and ON/OFF buttons for GPIO 4  
          client.println("<td> LED</td>");
          client.println("<td>GPIO D4 </td>");                  
          client.println("<td> " + ledState + "</td>");
          client.println("</tr>");
          //----------------- fifth row closing -----------------          



          
            
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
