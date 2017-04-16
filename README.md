# Team9

DS18B20 is a more commonly used temperature sensor, using a single bus control, previously programmed with a single microcontroller in strict accordance with the timing control of a single bus. Now, the programe will be discussed how to control the Linux system DS18B20, experience in the Linux world, everything is the file.

## 1. Modify configuration file 
```
sudo vi /boot/config.txt
```
In the / boot / configure.txt file behind the following sentence, this sentence is the raspberry pie to add Device Tree device, dtoverlay = w1-gpio-pull that add a single bus device, gpioin = 4 default pin is 4, if the DS18B20 then To other pins need to modify this value, Pioneer 600 expansion board DS18B20 acquiescence received 4, so do not modify. (Note: the pin is BCM number)
```
dtoverlay=w1-gpio-pull，gpioin=4
```

## 2.Verify that the device is in effect
Restart raspberry pie is set to take effect, run lsmod command.
```
sudo modprobe w1_gpio
sudo modprobe w1_therm
```
## 3.Read temperature 
If there is no problem in / sys / bus / w1 / devices found in a 28-XXXX at the beginning of the folder, this is the DS18B20 ROM, each DS18B20 are the same, in this folder to read w1_slave file will return to the current temperature value.Operation as shown below:
```
cd  /sys/bus/w1/devices
cd 28-XXXX
cat w1_slave
```
Return to the data, the first line of the last YRS said CRC check is successful, the data is valid. The second line last t = xxx00 indicates that the current temperature is xx.x degrees Celsius.
