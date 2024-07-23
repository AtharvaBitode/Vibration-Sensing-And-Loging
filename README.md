# Vibration-Sensing-And-Loging
This project aims to sense and log vibration data using sensors and a microcontroller. The collected data can be used for various applications, such as machinery maintenance, structural health monitoring, and environmental sensing.

# Hardware Requirement
  - Vibration Sensor (SW-420)
  - Microcontroller  (ESP8266)
  - Breadboard / Jumper Wires

# Software Requirement
  - Arduino IDE: It is used to program the ESP8266 microcontroller.
  - Google Sheets: To upload the collected data from the sensor.

# Installation and Setup

** Connect the vibration sensor to the microcontroller:
  - Connect the sensor's VCC to the microcontroller's 3.3V.
  - Connect the sensor's GND to the microcontroller's GND.
  - Connect the sensor's output pins to the digital input pins of the microcontroller.
** Install the required libraries in the Arduino IDE:
  - Open the Arduino IDE.
  - Go to Sketch > Include Library > Manage Libraries.
  - Search for and install the'ESP8266' libraries. 
  - Then select the board as 'NodeMCU 0.9'.
  - Write the required code and upload it on the ESP8266.
**  Google Sheets:
  - Create a google sheets and then write the required app script so the data collected can be uploaded on the sheet.
  - Give the url of the sheet in the code which is been uploaded on the ESP8266.
