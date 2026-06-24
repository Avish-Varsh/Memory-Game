# Memory game 

## Project Status

🚧 In Development

## Current version
v0.2.0 - Hardware Prototype

## Goal: 
To create a fully functional Simon style Memory game complete with an enclosure, increasing difficulty and sound feedback.

## Gameplay Overview:
At startup, a random sequence of LEDs is displayed. The player must replicate the sequence using the corresponding colored buttons. Each successful round increases the difficulty by extending the sequence length and increasing the playback speed. If the player enters an incorrect sequence at any point, the game ends.

## Components Used:
|Name|Quantity|
|----|--------|
|Buttons|3(Each of different color, must correspond to LED colors)|
|LEDs|3(Each of different color)|
|Resistors 220 Ω|3|
|Arduino Uno|1|
|Piezo Buzzer|1|
|Jumper wires|As per requirement|

## Planned Features:
- Simon says style memory game
- Sound feedback
- Random sequence generation
- Progressive difficulty scaling
- Custom enclosure

# Progress Roadmap:

## Phase 1: Planning

* [x] Define project concept
* [x] Select components
* [x] Create GitHub repository
* [x] Create initial project structure
* [x] Draft wiring schematic

## Phase 2: Core Hardware

* [x] Connect LEDs and verify operation
* [x] Connect buttons and verify input
* [x] Connect buzzer and verify sound output
* [x] Build and test complete circuit

## Phase 3: Core Game Logic

* [ ] Generate random sequences
* [ ] Display sequence to player
* [ ] Read player input
* [ ] Validate player input
* [ ] Implement win/lose conditions
* [ ] Add score tracking

## Phase 4: Difficulty System

* [ ] Increase sequence length each level
* [ ] Increase playback speed as levels progress
* [ ] Balance game difficulty

## Phase 5: Audio Feedback

* [ ] Add unique tones for each button
* [ ] Add correct input feedback
* [ ] Add incorrect input feedback
* [ ] Add startup melody

## Phase 6: Enclosure Design 

* [ ] Create initial enclosure concept
* [ ] Design button layout
* [ ] Design LED placement
* [ ] Create enclosure v1
* [ ] Refine enclosure based on testing
* [ ] Finalize enclosure design

## Phase 7: Testing & Optimization

* [ ] Test all game functions
* [ ] Fix identified bugs
* [ ] Improve code organization
* [ ] Perform final hardware verification

## Phase 8: Documentation

* [ ] Create final schematic
* [ ] Add circuit images
* [ ] Add project photos
* [ ] Document challenges faced
* [ ] Document lessons learned
* [ ] Complete README

## Challenges Faced:
> To be updated during development

## Lessons Learned:
> To be updated during development

## Phase 9: Future Improvements:
* [ ] Add EEPROM to save important user data such as high scores
* [ ] Add LCD for live feedback
* [ ] Create custom Win/Lose screens for the LCD
* [ ] Add a LED matrix to increase difficulty as sequences can come from a bigger space and in a harder to remember pattern
* [ ] Make it chargeable by adding a battery charging module
* [ ] Multiple Game play modes
* [ ] Use ESP32 instead of Arduino to link the game to an online leaderboard

## Images

### Hardware Prototype v1

![Hardware Prototype](images/hardware_v1.jpg)
