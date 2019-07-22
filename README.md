# MidiSwitch
A MIDI-USB switch pedal for (almost) nothing

## Current version

**under design**

## Licensing

The design and source codes are provided freely under a closed licence. It makes you able to implement the whole project for your own usage but not to sell it.

If you want to use it in a commercial project please contact me at tristan.israel@tibsys.com.

## Cost

_Prices include VAT 20%_

| Part              | Unit (€) | Qty | Sub-total (€) |
|-------------------|----------|-----|---------------|
| *to be filled*    | --.00    | 1   | --.00         |
| ATmega 32u4       | 4.00     | 1   | 4.00          |
| USB cable (1)     | 2.60     | 1   | 2.60          |
| USB connector (2) | 1.70     | 1   | 1.70          |
| Small parts       | 0.50     | -   | 0.50          |
|-------------------|----------|-----|---------------|
| Total             | --.80    | 1   | --.80         |

(1): Bare USB cable
(2): USB Micro B connector

If you don't want to do it yourself, please contact me at tristan.israel@tibsys.com.

*Notes:*
- Enclosure: https://www.amazon.fr/Emily-Instruments-Musique-Aluminium-portatifs/dp/B07RLQDVHD/ref=sr_1_274?__mk_fr_FR=ÅMÅŽÕÑ&keywords=pédale+effet&qid=1563819405&s=gateway&sr=8-274
- Button: https://www.amazon.fr/Furphy-Commutateur-métallique-Pratique-Accessoires/dp/B07V65R28T/ref=sr_1_6?__mk_fr_FR=ÅMÅŽÕÑ&keywords=pédale+effet&qid=1563820040&s=gateway&sr=8-6
- Anti-slip pad

## Requirements

- provide MIDI-USB connectivity to a double switch pedal
- ensure compatibility with all DAWs and MIDI controllers

## Presentation

The project consists in a pedal equipped with 2 switches. The pedal uses a MIDI-USB connection to communicate with a PC or a tablet on which a DAW is installed. 

## Licenses and credits

- Arduino schemas made with [Fritzing](http://fritzing.org/).

# Do It Yourself

*to be done*

## Architecture

*to be done*

## Protocol

The pedal uses 2 different channels for the switches:
- channel 1 for the left button
- channel 2 for the right button

**Pedal -> DAW**

*to be done*

**DAW -> Pedal**

All messages are ignored.

## Mounting procedure

*to be done*