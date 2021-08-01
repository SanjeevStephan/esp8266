# Uploading the Sketch On ESP8266 
If you’re using an ESP8266 NodeMCU Kit, uploading the sketch is very simple, since it has built-in programmer. Plug your board to your computer. 
1. Make sure you have the right board selected:

<br/><img src="https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-select-board.png?w=669&quality=100&strip=all&ssl=1"/>
<br/>
2. You also need to select the Port:
<br/><img src="https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/07/Install-ESP8266-Board-add-on-in-Arduino-IDE-select-COM-port.png?w=584&quality=100&strip=all&ssl=1"/>
<br/>
3.Then, copy the code provided (<a href="https://github.com/RuiSantosdotme/Random-Nerd-Tutorials/raw/master/Projects/blink_led_esp8266.ino">Blink_led_esp8266.ino</a>:

```c++
  /*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

int pin = 2;  

void setup() {  
  // initialize GPIO 2 as an output.  <br/>
  pinMode(pin, OUTPUT); 
}  

// the loop function runs over and over again forever  <br/>
void loop() { \n
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
```



