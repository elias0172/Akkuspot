# Akkuspot
Battery operated wireless DMX RGBW Soptlight
I used common components and a custom made PCB for DMX handling and LED control.

![20240328_144935](https://github.com/elias0172/Akkuspot/assets/84908851/2a4d4d6e-1c12-4cf1-a4de-67b6e9b81d23)

## Construction

The Enclosure was made in Fusion 360 and mainly build around the batteries (8x18650).
I continued to use the original case from the spotlight for my new build.
Maybe there will be major changes in enclosure designin a further revision.
The batteries are orientated at the middle support bar. 
To provide an easy way to replace defective cells I used battery holders for all eight cells.
The whole enclosure is designed to be mounted glueless. Except cell mounting where you will need 2K Glue.
Glue the distance plate to the battery holders before glueing them into position in the case.
For easy screw-together I used -as always- Ruthex M3 thread inserts.
The PCB is screwed in from behind.
The parts were printed from black PLA. A bad decision as I noticed while using them in direct radiation of sun.

![CAD-Files](https://github.com/elias0172/Akkuspot/assets/84908851/c9378011-d33e-4701-a8a9-fd13c083b486)
![20240328_143911](https://github.com/elias0172/Akkuspot/assets/84908851/6b2c7c91-7aa0-411a-8187-8901049224c6)

## Electrical
As a power source I used a pack of 8 of US18650NC Li-Ion Batteries. Each can store up to 10,7Wh. The whole pack contains ~ 86Wh.
The configuration is 4S2P what means that pack runs at 14,8V and 5,8Ah.
I included an common 4S 3,7V BMS which is primary used as under / over voltage and short circuit detection. For over current sensing there is a simple fuse.
I added later an equalizer circuit due to the cell-voltage drift that resulted in noticeable less usable capacity.
The battery pack is charged with a dedicated CC/CV charger for Li-Ion packs (16,8V / 2A) over the DC-Jack in the front.
For fast and easy recognition of the left capacity I added an voltage based gauge at the side of the light.
Later this gauge should be replaced by a software solution in the display. Hardware preparations therefor are already done.
The only two things I recycled from the original spot are 1. Enclosure incl. lenses, 2. LED-Board . At the LED-board there have to be done some modifications to fit my led driving circuit. 
To get as close as possible to my battery voltage range I decided to drive all three LEDs of every single color in series.
In a second revision I will try to figure out the sweet spot between luminous intensity and power consumption to further increase runtime.

![20240328_144854](https://github.com/elias0172/Akkuspot/assets/84908851/4e659c1c-5833-4a09-8c5c-20ea7c006bfa)

The LEDs are driven by a constant current circuit based on PT4115. For communication between Arduino Nano and the DMX-Universe the MAX485 transceiver is used.
To show all necessary settings and values I used an 0,96" monochrome I²C OLED display. It's always important to save energy, especially at battery powered applications. For this and for optical reasons I decided to switch the display and the battery gauge off after a short period. As a side effect this will prevent the OLED from burning in. There are also modes in which the wireless DMX Unit is not used. It is also switched off in this modes.
Schematic is provided as a jpeg file in the branch.
Unfortunately its not possible to use the USB-Port to programm the Arduino because Serial0 (used for prog) is also used for DMX communication with MAX485. I have to use the isp port for uploading code. Using a microcontroller with at least two serial ports or native usb upload support is crucial for the next revision.  
There are slight differences between the physically used pcb and the 3D Pictures shown here. As always rev0 contains some mistakes... xD 

Firmware was written with Arduino.

<img width="892" alt="Screenshot 2024-03-28 145619" src="https://github.com/elias0172/Akkuspot/assets/84908851/83097eb2-2042-469e-ad99-cc93a3599d48">

<img width="727" alt="Screenshot 2024-03-28 145632" src="https://github.com/elias0172/Akkuspot/assets/84908851/a52291a3-39a8-4fb7-85ec-22e7734e019c">
