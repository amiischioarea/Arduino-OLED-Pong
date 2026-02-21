# Arduino-OLED-Pong Game
A simple retro game built with Arduino Uno and an SSD1306 OLED Display. It features a highscore system and increasing difficulty.

# Project Overview
This project is a hardware-software implementation of the classic Pong game using the Arduino Uno platform. .

# Key Technical Features
~ real-time collision engine
~ adaptive difficulty
~ hardware efficiency

# Components Used 
For the hardware part I used:
  ~ Arduino Uno 
  ~ OLED Display 
  ~ Push Buttons 

# Game Description
This project is a hardware-based recreation of the iconic Pong game. It is designed to run as a single-player challenge where the player must prevent a moving ball from exiting the screen on the left side.

# Gameplay Mechanics:
The player controls a vertical paddle on the left side of the screen using two physical buttons. A ball moves across the screen, bouncing off the top, bottom, and right edges.
If the ball hits the paddle, it reverses direction and gains speed. If the ball misses the paddle and hits the left edge, the game ends. To keep the game challenging, the ball's velocity increases with every successful hit, requiring faster reaction times as the score climbs.
