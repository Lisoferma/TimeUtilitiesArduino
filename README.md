# Time utilities for Arduino UNO
Device features:
- Stopwatch
- Timer
- Watch

# Device control
Press the E button to switch utilities.

- Stopwatch:
  - A - start / stop / reset
- Timer and Watch:
  - A - start / stop
  - B - set seconds
  - С - set minutes
  - D - set hours

# Circuit diagram
Circuit diagram of the device made in Proteus 8:

![TimeUtilitiesScheme](https://github.com/Lisoferma/TimeUtilitiesArduino/assets/115818156/5bbfe076-aa67-4e7f-b067-ca6dd79e4134)

# Running simulation in Proteus
## Compilation
Open the <code>source.ino</code> file in Arduino IDE.

Select Arduino UNO in the board selection menu.

Open the <kbd>Sketch</kbd> menu in the top panel > <kbd>Export Compiled Binary</kbd>.

The firmware file will be compiled to <code>source/build/source.ino.hex</code>.

## Simulation
Open the <code>TimeUtilitiesScheme.pdsprj</code> file in Proteus.

Double-click on the Arduino board.

Click the <kbd>Program File</kbd> button.

Select the file <code>source/build/source.ino.hex</code>.

Run the simulation.
