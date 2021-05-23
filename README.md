# smart-refrigerator
Arduino based smart refrigerator.

![arduino circuit](https://user-images.githubusercontent.com/54089081/119261648-f8c56600-bbf5-11eb-907e-61886809ea6e.png)

# Description

We have created a smart refrigerator microcontroller using Arduino UNO. It is simulated on Tinkercad. It is designed like the mini fridges in hotels and is a prototype for water bottle units as of now. It detects the number of water bottles kept inside and displays the subsequent output to the user so that they know if it needs to be restocked or not. 

# Tech Stack

<h3><i>  Force Sensor  </i> </h3>
The force sensor or FSR (Force-sensitive) resistor is used because it changes the value of current passing through the sensor according to the pres vc sure on the sensor. Depending on the weight, the sensor’s resistance changes accordingly. Weight is directly proportional to the resistance of the sensor in the circuit. 

We have used FSR to detect the quantity of water bottles based on the presence of application of their weight. We have included these so that the user can view their inventory on the LCD without having to actually open the refrigerator and manually count.

When the sensor detects force/pressure on it, the value is incremented by one, determining the presence of one unit bottle. This is how we calculate the number of water bottles present.

<h3><i> PIR Sensor </i> </h3>
The Passive Infrared Motion sensor is used to detect the presence of the user in front of the refrigerator to regulate the powering of internal lights, which is depicted by an LED light in our tinkercad prototype.

Subsequently, if the fridge is empty, the lights remain switched off in order to conserve energy.

<h3><i> Temperature Sensor </i> </h3>
The Temperature Sensor LM35 series are precision integrated-circuit temperature devices with an output voltage linearly proportional to the Centigrade temperature. Depending on the temperature of the refrigerator, the cooling and ventilation system represented by an internal fan connected to a DC motor is induced. 

<h3><i> We also have a general RGB indicator for the temperature and the DC motor. </i> </h3>

If the temperature is too low, the RGB turns Blue, and the DC motor is reduced to ~1000 rpm.
For optimum temperature, the RGB is green and the DC motor runs at ~ 2000rpm-3000 rpm.
If the temperature has risen dramatically, and it is too hot, the RGB turns Red and the DC motor runs at ~4000-5000 rpm.


We have a potentiometer which is used to control the brightness of the LCD screen by varying the resistance.

# Project Link
https://www.tinkercad.com/things/g0oQyuGMDjZ-mpcaprojectv1/editel?sharecode=k8Cn1roxKejHFDiixsEgRVtS1JB290ZQjMeyRHvaPhk
