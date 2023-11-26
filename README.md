# yjk-thermo
Variable temperature stage for use in an x-ray diffractometer at the Young-June Kim lab for Quantum Materials. Uses a thermoelectric cooler. 

<img src=https://github.com/IssraAli/yjk-thermo/blob/main/control/photos/frosty.png>

# Current status:

- [x] Circuit and Arduino script to read data from hel705 thermistor
- [x] Power circuit for TE cooling block
- [x] First cooling block test: Achieved around ~ 260 K (goal: 250 K)
- [x] Plotting from serial in python 
- [ ] Create LTI model for cooling
- [ ] Implement PI temperature controller in Arduino (or other microcontroller)

# Issues:
- [ ] ADC resolution - heavy quanitzation (~ 2.5 K) in temperature output from Arduino: only two decimal places in accuracy from Arduino UNO analog out
- [ ] Would be nice to monitor voltage and current at source, TE block


