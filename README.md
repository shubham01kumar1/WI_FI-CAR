# WI_FI-CAR

A user can control the car by using  a mobile app, through that app he can control it's movement with help of video that is streaming in that app.
it is implemented with the help of node-MCU,a camera or mobile phone that can act as camera in robo-car, another mobile that will run it's app through that we will control it and a battery to give power to motor driver and node-mcu
At first we have to make connection to Wi-Fi Robo-car and Andriod App.
robo-car can be connected by entering network's ssid and it's password in wi-fi-car.ino file then dumping it into node-mcu, it will generate a static ip,through this ip we can connect app by entering ip and video can be stream in app by entering the address or ip on which video is streaming.
This app uses web api to connect to streaming video.
