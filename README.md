# True-Random-Number-Generator-using-Avalanche-Noise

![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/a3ce5554-ba87-4b6a-b872-f7e090de5989)
. Methodology

Avalanche noise occurs in semiconductor devices, such as diodes or transistors, when they are operated in a reverse-biased state and experience a sudden and unpredictable increase in current due to the generation of electron-hole pairs within the device's depletion region.

Here we are using transistor 2N3904(NPN bipolar junction transistor) for the generation of avalanche noise because of factors such as, the breakdown voltage of 2N3904 at 10μA is
 
measured as 10.80V which is a crucial parameter as it signifies the voltage at which the avalanche effect occurs, leading to noise generation. At a current level of 10μA, the 2N3904 exhibits a noise amplitude of 400mVpp (millivolts peak-to-peak). A 2N3904 is the preferred choice for avalanche noise generation due to its combination of a high breakdown voltage and consistent noise performance. The higher breakdown voltage of the 2N3904 suggests that it can operate at a relatively higher voltage, making it robust for avalanche noise generation. A higher noise amplitude indicates that the 2N3904 can produce a more significant and discernible noise signal.

![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/03e97713-17ca-4969-9ef2-d5844c679181)

Fig. 1: Avalanche Noise Generator and Digital output generator

The circuit designed for generating true random numbers using avalanche noise in a reversed-biased p-n junction, primarily utilizing the 2N3904 transistor, can be divided into several distinct blocks, each serving a specific purpose in the noise generation and amplification process.

White Noise Generator: This is the initial stage of the circuit responsible for generating symmetrical, zero-average noise from the reverse-biased p-n junction of the 2N3904 transistor. It comprises two 2N3904 transistors, Q1 and Q2, along with resistor R1.Transistor Q1’s collector is not connected to any source, making Q1 to work as a diode in reverse bias. The key to achieving symmetrical noise is to bias the 2N3904 with a very low reverse current, approximately 50nA. The emitter current of Q2 (Ie2) is determined by R1, creating a base current (Ib2) that flows into the reverse-biased emitter-base junction of Q1. The result is a symmetrical noise voltage, with a small signal gain close to unity, served at the collector of Q2

Virtual Ground: Since the circuit operates with a single supply voltage, a virtual ground (labeled Vref) at Vcc/2 is required to bias subsequent op-amp stages. This virtual ground is created using a voltage divider consisting of equal resistors R9 and R10 of 100k ohm, followed by a unity-gain buffer realized with op-amp U2: A.
 
Buffer: Positioned between the noise generator and the amplifier, this buffer comprises half of the U1: A op-amp, resistor R2, and capacitor C1. It serves to prevent loading of the noise generator by the subsequent amplifier stage, ensuring minimal current draw from the noise source. Resistor R2 biases the amplifier around the virtual ground, and capacitor C1 removes any DC components from the signal.
![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/4d698ee6-55c1-42f3-994e-03b30f33df08)

Fig. 2: Vref Circuit

Amplifier: Following the buffer, the amplifier stage amplifies the noise signal. It employs the other half of op-amp U1: A, capacitors C2, and resistors R3, R4, and R5. The gain of this stage is set by the ratio of R5 to R3 and provides linear amplification of the noise signal. This amplification brings the initial noise signal from 250mVpp to approximately 1Vpp around the virtual ground.

![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/42825d88-23bd-428b-924b-775f73f68f6a)

Fig.3: Components of the TRANG circuit

Current Switch (Comparator): The final stage of the circuit is the current switch, which serves as a comparator. It determines whether the instantaneous noise voltage is positive or negative with respect to the virtual ground (Vref). This block comprises a constant current generator (D1, D2, Q5, R6, and R7) and a differential pair (Q3 and Q4) with resistive loads (R8 and R9). The constant current generator ensures a stable reference current (Ig) is available. The differential pair functions as a current switch, steering the constant current between R8 and RV1 based on the voltage at the base of Q3.
 
When the voltage exceeds a threshold, Q3 or Q4 turns off, creating a digital signal that represents the randomness of the noise signal.


3.1 Analysis

The noise characteristics of a circuit were investigated using ngspice simulations. The circuit design went through an initial conceptual phase followed by iterative refinement through simulation. Each node in the schematic diagram was labeled with progressive numbers for reference in the netlist. The simulations were conducted using ngspice, and the simulation output graphs can be seen in Fig. 4.

 ![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/e65954e5-89df-4959-9804-085f2e558799)
Fig. 4: Analog Noise output


![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/6c38f133-ca37-4927-b695-e2b557df6304)

Fig. 5: Digital Output (ngspice simulated)

In Fig.4 and Fig.5, time-domain signals were investigated, including v(8) representing the output noise of the amplifier and v(13) indicating the collector of Q3, associated with
 
digital signal processing. These simulations aimed to provide insights into the noise characteristics that the Avalanche noise generated is truly random in nature.

The Arduino code reads analog voltage levels from a connected analog pin. It does so by repeatedly reading the voltage and comparing it to a set threshold (0.06 V). When the voltage surpasses the threshold, it is considered a received "1," otherwise, it's treated as a "0." The code stores these received bits in an array. This process repeats for a fixed number of times as per our random digit requirement. The bits stored in the array are accessed in a loop and are multiplied with the 8421-weights format to get digital value. The 8421 can give random numbers from 0 to 15 decimal form.


Chi-Square test: Sequence generated: -

The Chi-Square test assesses the association or independence of two categorical variables. To use it, categorize and tabulate the data, calculate the Chi-Square statistic to quantify the difference between observed and expected data, and determine degrees of freedom. Find the critical value based on significance level. If the calculated statistic exceeds the critical value, reject the null hypothesis, indicating a significant relationship; otherwise, fail to reject it, suggesting no significant association. It's a valuable tool for various fields to analyze categorical data and make informed decisions.

Result and Discussion
![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/ae77e777-0974-4569-a222-11ffb6d7dcd9)

Fig. 6: True random number generated

The analog voltage levels read by the arduino are 0.08, 0.06, 0.06, 0.08. The code compares these values with the said threshold i.e.0.06, we get the sequence as 0, 1, 1
,0. Therefore by using the binary to decimal conversion by multiplying each bit by its weights i.e.8421, [ (8*1) + (4*1) + (2*1) + (1*0) ], we get 6 as our random number.
![image](https://github.com/prashant6869/True-Random-Number-Generator-using-Avalanche-Noise/assets/99020701/de6c42fc-e91a-418f-8b7a-26716083d77d)

Fig. 7: Output of Arduino on virtual terminal
 
Similarly, if the values are 0.08, 0.06, 0.08, 0.08 we get
the sequence 0, 1, 0, 0. Therefore the random number
generated is 4.


