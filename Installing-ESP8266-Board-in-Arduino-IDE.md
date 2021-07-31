## Installing ESP8266 Board in Arduino IDE (Windows, Mac OS X, Linux) | <a href="https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/">go to source</a>
The ESP8266 community created an add-on for the Arduino IDE that allows you to program the ESP8266 using the Arduino IDE and its programming language

### Install ESP8266 Add-on in Arduino IDE
To install the ESP8266 board in your Arduino IDE, follow these next instructions:

1.In your Arduino IDE, go to <b> File> Preferences</b> <br/><br/>
<img src="https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-open-preferences.png?w=197&quality=100&strip=all&ssl=1"/>

2.Copy Below URL into the “Additional Boards Manager URLs” field as shown in the figure below. Then, click the “OK” button:  
        
    http://arduino.esp8266.com/stable/package_esp8266com_index.json 
  
 <img src="https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-enter-URL.png?w=722&quality=100&strip=all&ssl=1"/> 
 
 Note: if you already have the ESP32 boards URL, you can separate the URLs with a comma as follows:
 
     https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
     
3.Open the Boards Manager. Go to Tools > Board > Boards Manager… <br/><br/>

<img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-open-boards-manager.png?w=671&quality=100&strip=all&ssl=1"/>

4.Search for ESP8266 and press install button for the “<b>ESP8266 by ESP8266 Community</b>“: <br/>

<img src="https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-search-ESP8266.png?w=786&quality=100&strip=all&ssl=1"/>

That’s it. It should be installed after a few seconds.
