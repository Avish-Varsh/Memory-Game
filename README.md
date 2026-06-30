# Simon-style Retro Memory Game 

# Project Status

🚧 **Active Development** (Beta)

## Current version

**Version: v0.5.0 (Beta)**

_Latest update: Audio feedback_

Current features:
- Fully playable game loop
- Random sequence generation
- Player input validation
- Progressive difficulty
- Win/Loss sequences 
- Unique audio feedback on player input
- Startup melody 

## Overview

This project is a Simon-style memory game built using an Arduino Uno. The player must memorize and repeat an increasingly long sequence of colored LEDs using the corresponding push buttons.

The project focuses on embedded systems programming, finite state machines, input validation, timing control and modular code design. It is being developed incrementally, with each version introducing new gameplay mechanics and hardware features. Development is being tracked using Git for versioning to document project progression.


## Gameplay Overview:
At startup, a random sequence of LEDs is displayed. The player must replicate the sequence using the corresponding colored buttons. Each successful round increases the difficulty by extending the sequence length and increasing the playback speed. If the player enters an incorrect sequence at any point, the game ends and they must restart the game.


## Components Used:
|Name|Quantity|
|----|--------|
|LEDs|3 (One of each color)|
|Push Buttons|3 (One for each LED color)|
|Resistors 220 Ω|3|
|Arduino Uno|1|
|Piezo Buzzer|1|
|Potentiometer|1|
|Jumper wires|As per requirement|

## Planned Features:
- Custom enclosure
- Custom PCB 

# Progress Roadmap:

## Section 1: Planning

* [x] Define project concept
* [x] Select components
* [x] Create GitHub repository
* [x] Create initial project structure
* [x] Draft wiring schematic

## Section 2: Core Hardware

* [x] Connect LEDs and verify operation
* [x] Connect buttons and verify input
* [x] Connect buzzer and verify sound output
* [x] Build and test complete circuit

## Section 3: Core Game Logic

* [x] Generate random sequences
* [x] Display sequence to player
* [x] Read player input
* [x] Validate player input
* [x] Implement win/lose conditions
* [x] Add score tracking
* [x] Add correct game progression

## Section 4: Difficulty System

* [x] Increase sequence length each level
* [x] Add potentiometer to control LED blink speed
* [x] Balance game difficulty

## Section 5: Audio Feedback

* [x] Add unique tones for each button
* [x] Add correct input feedback
* [x] Add loss melody
* [x] Add startup melody
* [x] Add win melody

## Section 6: Enclosure Design 

* [ ] Create initial enclosure concept
* [ ] Design button layout
* [ ] Design LED placement
* [ ] Create custom PCB
* [ ] Create enclosure v1
* [ ] Refine enclosure based on testing
* [ ] Finalize enclosure design

## Section 7: Testing & Optimization

* [ ] Test all game functions
* [ ] Fix identified bugs
* [ ] Improve code organization
* [ ] Perform final hardware verification

## Section 8: Documentation

* [ ] Create final schematic
* [ ] Add circuit images
* [ ] Add project photos
* [ ] Document challenges faced
* [ ] Document lessons learned
* [ ] Complete README

## Challenges Faced

- Designing a reliable input validation system while preventing accidental multiple button presses.
- Debugging state transition issues that caused the game logic to become inconsistent.
- Resolving timing conflicts between LED animations and player input.
- Preventing invalid variable values caused by unintended state changes.
- Structuring the code into reusable functions to improve maintainability.

> Additional challenges will be documented as development continues.

## Skills Learned

- Finite State Machine (FSM) design
- Edge detection for button input
- Software debouncing techniques
- Modular programming using custom functions
- Enum-based state management
- Switch-case driven program flow
- Random sequence generation
- Timing management using millis()
- Debugging embedded software
- Hardware/software integration

> Additional skills will be documented as development continues.

## Section 9: Future Improvements
* [ ] Add EEPROM to save important user data such as high scores
* [ ] Add LCD for live feedback
* [ ] Create custom win/loss screens for the LCD
* [ ] Add an LED matrix to increase difficulty as sequences can come from a bigger space and in a harder to remember pattern
* [ ] Add a charging feature to improve portability
* [ ] Multiple gameplay modes
* [ ] Use ESP32 instead of Arduino to link the game to an online leaderboard

## Images

### Hardware Prototype v1

![Hardware Prototype v1](images/hardware_v1.jpg)

### Hardware Prototype v2

![Hardware Prototype v2](images/hardware_v2.jpg)

## Version History

### v0.5.0
- Added unique audio feedback for each button
- Added startup melody
- Added win melody
- Added loss melody
- Integrated audio feedback into gameplay

### v0.4.0
- Playable beta release
- Added input validation
- Added win/lose sequences
- Improved game progression

### v0.3.0
- Added score tracking
- Added progressive difficulty using random sequences that increase in length after each successful round 
- Added a potentiometer to control LED speed

### v0.2.0
- Initial hardware prototype and schematic

### v0.1.0
- Initial planning