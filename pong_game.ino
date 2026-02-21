#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//dimensions of the oled
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//define the pins
const int buttonUp = 3;
const int buttonDown = 2;

// paddle parameters
int paddleY = 22;
const int paddleWidth = 4;
const int paddleHeight = 20;

// ball parameters
int ballX = 64, ballY = 32;
int ballSpeedX = 2, ballSpeedY = 2;
const int ballSize = 4;

int score = 0;
int highScore = 0;

void setup() {
 Serial.begin(9600);
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
 display.clearDisplay();

  // start screen 
  display.setTextSize(2);              
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);            
  display.println("PONG GAME");
  display.display();                   
  delay(2000);
  
  // Set button pins with internal pull-up resistors
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
  // read buttons to move the paddle
  if (digitalRead(buttonUp) == LOW && paddleY > 0) {
    paddleY -= 3;
  }
  if (digitalRead(buttonDown) == LOW && paddleY < SCREEN_HEIGHT - paddleHeight) {
    paddleY += 3;
  }

  // update ball position
  ballX = ballX + ballSpeedX;
  ballY = ballY + ballSpeedY;
  
  // collision with top and bottom walls
  if (ballY <= 0 || ballY >= SCREEN_HEIGHT - ballSize) {
    ballSpeedY = -ballSpeedY;
  }

  // collision with the right wall
  if (ballX >= SCREEN_WIDTH - ballSize) {
    ballSpeedX = -ballSpeedX;
  }
  
  // collision with the paddle
  if (ballX <= paddleWidth) {
    if (ballY + ballSize >= paddleY && ballY <= paddleY + paddleHeight) {
      ballSpeedX = -ballSpeedX;
      score++;
      if(ballSpeedX > 0) ballSpeedX++; else ballSpeedX--;
    } else {
      //game over
      if (score > highScore) {
        highScore = score; // update highscore 
      }

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 5);
    display.println("GAME OVER");
      
    display.setTextSize(1);
    display.setCursor(10, 35);
    display.print("Your Score: ");
    display.println(score);
      
      display.setCursor(10, 48);
      display.print("Highscore:  ");
      display.println(highScore);
      
      display.display();
      delay(2500); //results for 2.5 seconds

      // restart Animation
      display.setCursor(10, 58);
      display.print("restarting...");
      display.display();
      delay(1000);

      // reset game state
      ballX = 64; 
      ballY = 32;
      ballSpeedX = 2;
      score = 0;
      paddleY = 22;

      return;
  }
}

  display.clearDisplay();
  
  // draw score
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(60, 0);
  display.print(score);

  // draw paddle
  display.fillRect(0, paddleY, paddleWidth, paddleHeight, SSD1306_WHITE);
  
  // draw ball
  display.fillRect(ballX, ballY, ballSize, ballSize, SSD1306_WHITE);
  
  display.display();
  delay(10);
  }

