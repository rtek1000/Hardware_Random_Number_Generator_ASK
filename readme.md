## Seed generator for random function using generic hardware.

The RF 433 receiver captures any noise in its reception range, we can use these pulses to generate a random number.

(Just seeding the random function using the ADC read value without a signal generated by dedicated hardware may not be enough to produce a random initial value)

- Software
- - Read times between rising and falling edges
- - Perform simple average
- - Seed random value

- Hardware:
- - 1- RF 433 recetor ASK (OOK)
- - 1- Analog input
- - 1- Resistor 10k (between receiver output and analog input)

![img](https://raw.githubusercontent.com/rtek1000/Hardware_Random_Number_Generator_ASK/main/rf433-92mhz-xtal.jpg)

>Receiver module that receives On-off keyed (OOK) modulation signal and demodulated to digital signal for the next decoder stage. Local oscillator is made of PLL structure. The result is excellent performance in a simple to use, with a very low external component count.
Source: https://manualzz.com/doc/30833578/rfrm4302-rxn3s-rf-receiver-module-ask--ook---315-433.92mhz


## Serial Monitor output using this method:

- 06:07:55.480 -> random: 67
- 06:08:03.250 -> random: 44
- 06:08:09.750 -> random: 82
- 06:08:15.777 -> random: 67
- 06:08:21.647 -> random: 97
- 06:08:27.750 -> random: 67
- 06:08:35.715 -> random: 35

## Serial Monitor output without using this method:
- 06:13:51.300 -> random: 7
- 06:13:55.114 -> random: 7
- 06:13:59.659 -> random: 7
- 06:14:03.539 -> random: 7
- 06:14:07.154 -> random: 7
- 06:14:11.001 -> random: 7

## Schematic:

![img](https://raw.githubusercontent.com/rtek1000/Hardware_Random_Number_Generator_ASK/main/RF433_COLOR.png)

## References:

- https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/

- https://en.wikipedia.org/wiki/Hardware_random_number_generator


## Licence:
   
#### Hardware:

Released under CERN OHL 1.2: https://ohwr.org/cernohl

#### Software:

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
