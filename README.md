# Arduino_PopCorn_CoffeeRoaster
This Projects enables you to control a popcorn machine with a Artisan, controlling the resistance with a Thermocouple sensor.

# Hardware Used

- **Thermocouple:** Make sure that it can above 250 ºC. [Example](https://es.aliexpress.com/item/1005006101886532.html?spm=a2g0o.productlist.main.1.7f7b6593lFmFU6&algo_pvid=fb36b5d2-0513-461f-ab79-961ad11463c5&algo_exp_id=fb36b5d2-0513-461f-ab79-961ad11463c5-0&pdp_npi=4%40dis%21MXN%2175.30%2125.27%21%21%2131.05%2110.42%21%40210307c317087049502276505e53ce%2112000035751129470%21sea%21MX%21828026433%21&curPageLogUid=w09l0CQAhUb5&utparam-url=scene%3Asearch%7Cquery_from%3A)
- ** 

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

