# IoT-enabled-Automatic-Access-Control-System-with-COVID-detection
## Description

This is a new state of the Art concept of a complete automated doorway system which functions on the basis of the inputs fed into the microncontroller like Body temperature and SpO2 level. if the intended 
parameters are in the optimum level then only the doorway can be accessed otherwise not.
Microncontroller user: - Arduino UNO R3
Sensors used: - MLX90614 - IR based Industry graded temperature sensor, MAX30102 - pulse oximeter sensor
Programming Language - Arduino interfaced C++ 
IDE: - Arduino IDE version 1.8.16

## Getting Started

### Dependencies

* Works on OLED display Library, MLX90614 IR temperature sensor library

### Installing

* All the libraries mentioned

## Help

* Clock error might occur when using multiple I2C sensor. In this case master slave confuguration is used. 
* To resolve that error, wire.setfrequency(10000) command can be used. This command enhances the pulsetting frequency of both the sensors and thus sync occuers

## Authors

Main author - Abhirup Bhattacharyya

## Version History

* 1.0

## License

This project is licensed under the Abhirup Bhattacharyya
