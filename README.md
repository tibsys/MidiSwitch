# MidiSwitch
A MIDI-USB switch pedal for (almost) nothing

## Current version

**under design**

## Licensing

The design and source codes are provided freely under a closed licence. It makes you able to implement the whole project for your own usage but not to sell it.

If you want to use it in a commercial project please contact me at tristan@alefbet.net

## Cost

_Prices include VAT 20%_

| Part              | Unit (€) | Qty | Sub-total (€) |
|-------------------|----------|-----|---------------|
| Aluminium enclos. | 7.00     | 1   | 7.00          |
| Switch            | 1.13     | 1   | 1.13          |
| Selector 16       | 2.32     | 1   | 2.32          |
| Selector 10       | 2.59     | 1   | 2.59          |
| Button for select | 1.00     | 2   | 2.00          |
| ATmega 32u4       | 4.00     | 1   | 4.00          |
| USB cable (1)     | 2.60     | 1   | 2.60          |
| USB connector (2) | 1.70     | 1   | 1.70          |
| Small parts       | 0.50     | -   | 0.50          |
|-------------------|----------|-----|---------------|
| Total             |          |     | 21.84         |

(1): Bare USB cable
(2): USB Micro B connector

If you don't want to do it yourself, please contact me at tristan@alefbet.net.

*Notes:*
- Enclosure: https://www.amazon.fr/Emily-Instruments-Musique-Aluminium-portatifs/dp/B07RLQDVHD/ref=sr_1_274?__mk_fr_FR=ÅMÅŽÕÑ&keywords=pédale+effet&qid=1563819405&s=gateway&sr=8-274
- Button: https://www.amazon.fr/Furphy-Commutateur-métallique-Pratique-Accessoires/dp/B07V65R28T/ref=sr_1_6?__mk_fr_FR=ÅMÅŽÕÑ&keywords=pédale+effet&qid=1563820040&s=gateway&sr=8-6
- Selector 16 positions: https://fr.rs-online.com/web/p/commutateurs-rotatifs/1251882/
- Selector 10 positions: https://fr.rs-online.com/web/p/commutateurs-rotatifs/1251880/
- Button for selectors: https://www.audiophonics.fr/fr/boutons-volume-6mm/bouton-aluminium-axe-crante-10x15mm-o6mm-argent-p-12989.html
- Anti-slip pad

## Requirements

- provide MIDI-USB connectivity to a double switch pedal
- ensure compatibility with all DAWs and MIDI controllers

## Presentation

The project consists in a pedal equipped with 1 switch and 2 selectors:
- The switch is used as an on/off MIDI control change. 
- The first selector (16 positions) offers MIDI channel selection (1-16).
- The second selector offers MIDI control change (CC) number selection (see below)

MIDI control change numbers
| Dec| Hex | Function | 
|----|-----|----------|
| 16 | 10  | General purpose controller 1 | 
| 17 | 11  | General purpose controller 2 | 

The pedal uses a MIDI-USB connection to communicate with a PC or a tablet on which a DAW is installed. 

## Licenses and credits

- Arduino schemas made with [Fritzing](http://fritzing.org/).

# Do It Yourself

*to be done*

## Architecture

*to be done*

## Protocol

The pedal uses 2 different CC for the switches:
- channel 1 CC 0x10 (16) for the left button
- channel 1 CC 0x11 (17) for the right button

**Pedal -> DAW**

*to be done*

**DAW -> Pedal**

All messages are ignored.

## Mounting procedure

*to be done*

## Useful links

When the board is bricked: https://eldontronics.wordpress.com/2019/06/16/arduino-pro-micro-clone-port-not-detected/