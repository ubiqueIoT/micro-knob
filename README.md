# Micro Knob

As it turns out [EC11 rotary encoders](https://amzn.to/3XUyDMp) fit nicely over a [Seeed XIAO](https://amzn.to/4bCtcoG) form factor module. This could prove to be useful as an extremely minimal macropad.

![IMG_2255](https://github.com/ubiqueIoT/micro-knob/assets/8181497/a57dd787-c7b7-494f-a67b-3adaee568df1)

### Notes on assembly

Some tabs need to be clipped off from the stock encoder as shown in the image below. It is okay if the metal housing of the encoder makes contact the shield of the XIAO module as both metal components should be connected to common ground by default.

Take care to not use too much solder when connecting the encoder pins. Excess solder may interfer with the case. 

![cut-diagram](https://github.com/ubiqueIoT/micro-knob/assets/8181497/4f2fc80c-3918-4185-997e-c5d8938018f9)

### Notes on software

The sample code provided moves the mouse around in varying sized steps. The step size is adjusted by turning the encoder, and the movement is toggled on and off with the encoder switch.

This example can easily be adapted for additional use cases such as scrolling, zooming, volume, etc.

The key is to configure the pins that connect to the encoder's common (GND) pins as digital output low so that switch and encoder work as usual.

```cpp
#define SW_GND 5
#define SW_PIN 3

#define ROT_B 10
#define ROT_GND 9
#define ROT_A 8

void setup() {
  pinMode(SW_GND, OUTPUT);
  pinMode(ROT_GND, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  pinMode(SW_PIN, INPUT_PULLUP);

  digitalWrite(ROT_GND, LOW);
  digitalWrite(SW_GND, LOW);
}
```

![microknob-wiring](https://github.com/ubiqueIoT/micro-knob/assets/8181497/931c4eb2-2892-4832-ba5a-f77bcdad81e2)

### Case details

A small 3D printable case is provided in the STLs folder. It is shown here below. The top section of the case might benifit from supports for the encoder nut cutout. The case is designed for use with [self tapping M2.5 screws](https://amzn.to/4cnJL8Z).

![CAD](https://github.com/ubiqueIoT/micro-knob/assets/8181497/074c6395-331a-4b22-bcc1-280e7dce159e)

### Full parts list

| Part  | Quantity |
| ------ | ---- |
| [EC11 Rotary Encoder](https://amzn.to/3XUyDMp)  | 1 |
| [Seeed XIAO](https://amzn.to/4bCtcoG)  | 1 |
| [Encoder Knob](https://amzn.to/4cu8ys3) | 1 |
| [Self Tapping M2.5 Screws](https://amzn.to/4cnJL8Z) | 4 |
