# Arduino_PopCorn_CoffeeRoaster
This Projects enables you to control a popcorn machine with a Artisan, controlling the resistance with a Thermocouple sensor.

# Hardware Used

- **Thermocouple Type K and MAX6675 sensor:** Make sure that it can above 250 ºC. [Thermocouple and Sensor](https://es.aliexpress.com/item/1005006101886532.html?spm=a2g0o.productlist.main.1.7f7b6593lFmFU6&algo_pvid=fb36b5d2-0513-461f-ab79-961ad11463c5&algo_exp_id=fb36b5d2-0513-461f-ab79-961ad11463c5-0&pdp_npi=4%40dis%21MXN%2175.30%2125.27%21%21%2131.05%2110.42%21%40210307c317087049502276505e53ce%2112000035751129470%21sea%21MX%21828026433%21&curPageLogUid=w09l0CQAhUb5&utparam-url=scene%3Asearch%7Cquery_from%3A)
- **Arduino UNO Rev3:** You can get any version with or without WIFI and BT. [Arduino UNO W/WIFI](https://es.aliexpress.com/item/1005006027409358.html?spm=a2g0o.productlist.main.5.3b774ec0Rv4OoG&algo_pvid=48b35150-4982-479b-a4fe-2f47603f2b61&algo_exp_id=48b35150-4982-479b-a4fe-2f47603f2b61-2&pdp_npi=4%40dis%21MXN%21150.13%2174.98%21%21%218.61%214.30%21%40210318e817087051202674900e3ce6%2112000035384246917%21sea%21MX%21828026433%21&curPageLogUid=lcJXyIXoGC9q&utparam-url=scene%3Asearch%7Cquery_from%3A)
- **Solid State Relay:** You need the Realy in order to Swith On and Off the resistance of your Roaster. [SSR](https://es.aliexpress.com/item/1005005757882881.html?spm=a2g0o.productlist.main.3.1ae13a21LD6HRf&algo_pvid=4504d240-d414-410c-8992-c16f7af7ab56&algo_exp_id=4504d240-d414-410c-8992-c16f7af7ab56-1&pdp_npi=4%40dis%21MXN%2187.81%2154.90%21%21%2136.21%2122.64%21%402101f08717087052795921539e83a3%2112000034247715070%21sea%21MX%21828026433%21&curPageLogUid=pCRWooSj3TgD&utparam-url=scene%3Asearch%7Cquery_from%3A)
- **Mosfet:** Since we are going to use the PWM pins of the Arduino, the power may not be enogh to activate the SSR. [Mosfet](https://es.aliexpress.com/item/1005005701820316.html?spm=a2g0o.productlist.main.1.78426fceo3N5PK&algo_pvid=03032076-755e-4e1b-aeb0-8f3a7022c9ce&algo_exp_id=03032076-755e-4e1b-aeb0-8f3a7022c9ce-0&pdp_npi=4%40dis%21MXN%2149.40%2116.20%21%21%2120.37%216.68%21%402101c5a717087055315588034eb3df%2112000034141374504%21sea%21MX%21828026433%21&curPageLogUid=ZHkWjOagA6z8&utparam-url=scene%3Asearch%7Cquery_from%3A)
- **Arduino Connection Kit:** You can start doing your conections with an Arduino Kit. [Kit](https://es.aliexpress.com/item/1005005729997772.html?spm=a2g0o.productlist.main.3.583463dd2EVEtr&algo_pvid=dcd6f7e5-45ea-476f-a79a-090dff511478&algo_exp_id=dcd6f7e5-45ea-476f-a79a-090dff511478-1&pdp_npi=4%40dis%21MXN%21158.50%2151.99%21%21%2165.36%2121.44%21%402103247117087056247404653e7aa0%2112000034569395102%21sea%21MX%21828026433%21&curPageLogUid=R4eKExcVZFTO&utparam-url=scene%3Asearch%7Cquery_from%3A)

- **Soldering Kit:** You will need to solder some of the inputs of the Mosfet. [Solderin Kit](https://es.aliexpress.com/item/1005006534325782.html?spm=a2g0o.productlist.main.1.73bf86a73A1JNi&algo_pvid=95b9438a-c5e4-4e6a-95ac-c7db9266f2a7&algo_exp_id=95b9438a-c5e4-4e6a-95ac-c7db9266f2a7-0&pdp_npi=4%40dis%21MXN%21501.49%21175.59%21%21%2128.76%2110.07%21%402101e7a317087057339441815ea556%2112000037560090323%21sea%21MX%21828026433%21&curPageLogUid=)

# Modbus Communication with Artisan Roaster Software

This Arduino sketch enables communication between an Arduino board and Artisan Roaster Software using the Modbus protocol. The setup allows for temperature monitoring and control, typically used in coffee roasting applications. Below is a breakdown of the code functionality:

## Libraries Used
- **MAX6675**: Library for interfacing with MAX6675 thermocouple temperature sensor.
- **ModbusRtu**: Library for Modbus communication over serial ports.

## Global Variables
- **au16data**: An array holding data to be shared over the Modbus network. It contains 16 uint16_t elements. Data at specific indices are updated to reflect temperature readings and relay values.
- **thermoDO, thermoCS, thermoCLK**: Pins connected to the MAX6675 thermocouple sensor for data out, chip select, and clock, respectively.
- **thermocouple**: Object of class MAX6675 representing the thermocouple sensor.
- **relay**: Pin connected to a relay for control.

## Setup Function
- **Serial Communication**: Initializes serial communication at a baud rate of 9600 for debugging purposes.
- **Modbus Initialization**: Initializes the Modbus slave object with node ID 1 and RS-232 or USB-FTDI serial port configuration.
- **Pin Configuration**: Sets the relay pin as an output.

## Loop Function
- **Read Temperature**: Reads the temperature from the thermocouple sensor and updates the appropriate index in `au16data`.
- **Poll Modbus Registers**: Polls the Modbus registers to enable communication with the master device (Artisan Roaster Software).
- **Control Relay**: Uses pulse-width modulation (PWM) to control the relay based on the value received from the master device through Modbus.
- **Debugging Output**: Prints temperature readings and relay values for debugging purposes.
- **Delay**: Delays execution for 500 milliseconds.

## Note
- Ensure proper connections of the thermocouple sensor, relay, and Modbus communication lines for the code to function correctly.
- Modify the code as necessary to adapt to your specific hardware setup and communication requirements.

This sketch provides a foundation for integrating temperature monitoring and control functionalities with Artisan Roaster Software through Modbus communication.

