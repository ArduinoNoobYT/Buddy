#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
MCUFRIEND_kbv tft;


#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define WHITE   0xFFFF

extern uint8_t happy[];
extern uint8_t idle[];
extern uint8_t surprised[];
extern uint8_t angry[];

String  question1 = "";  
String question2 = "";
String name = "";
String question3 = "";


int16_t ht = 16, top = 3, line, lines = 15, scroll;

void drawBitmap(int16_t x, int16_t y,
 const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {

  int16_t i, j, byteWidth = (w + 7) / 8;
  uint8_t byte;

  for(j=0; j<h; j++) {
    for(i=0; i<w; i++) {
      if(i & 7) byte <<= 1;
      else      byte   = pgm_read_byte(bitmap + j * byteWidth + i / 8);
      if(byte & 0x80) tft.drawPixel(x+i, y+j, color);
    }
  }
}

void setup() {


  
Serial.begin(9600);
//Buddys Intro 
tft.begin();
tft.setRotation(1);
 //intro
 tft.fillScreen(BLACK);
   tft.setCursor (120, 30);
  tft.setTextSize (3);
  tft.setTextColor(CYAN);
  tft.println("Buddy");
  tft.setCursor (60, 220);
  tft.setTextSize (2);
  tft.setTextColor(WHITE);
  tft.println("By -ArduinoNoobYT");
   drawBitmap(70, 60, idle, 195, 146,CYAN);
  delay(6500);
  Serial.println("Arduino Ready");
delay(1000);
//Name
Serial.println("Please type your name");
   tft.fillScreen(BLACK);
  drawBitmap(70, 55, idle, 195, 146,CYAN);
  delay(1000);

  while (Serial.available() == 0)
  { //Wait for user input

  }
  name= Serial.readString();

Serial.println("Type your question");
   while (Serial.available() == 0)
  { //Wait for user input

  }
  
  question1= Serial.readString();
  
   if (question1 == "Hello"){
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, happy, 195, 146,CYAN);
tft.setTextColor(CYAN);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("Why hello");
    tft.println("");
      tft.println(name);
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
   
  
 }
 
 else if (question1 == "Why do you hate humans")
  {
       
  tft.fillScreen(BLACK);
   drawBitmap(70, 55, angry, 195, 146,CYAN);
tft.setTextColor(RED);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("Cuz they suck");
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
    
       }

   else if (question1 == "Where did you come from")
  {
        
 tft.fillScreen(BLACK);
   drawBitmap(70, 55, surprised, 195, 146,CYAN);
tft.setTextColor(BLUE);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("????");
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);

  
 
  }





   Serial.println("Any other questions??");
//question2
  while (Serial.available() == 0)
  { //Wait for user input

  }

  question2 = Serial.readString();
   if (question2 == "Why do you hate humans")
  {
 
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, happy, 195, 146,CYAN);
tft.setTextColor(WHITE);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("IDK just hate them");
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
  
  }
   

   else if (question2 == "Hello")
  {
  
 tft.fillScreen(BLACK);
   drawBitmap(70, 55, happy, 195, 146,CYAN);
tft.setTextColor(BLUE);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("Hello");
   tft.println("");
   tft.println(name);
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
  
  }

   else if (question2 == "Where did you come from")
  {
    
     tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
tft.setTextColor(CYAN);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("A planet");
  delay(2000);
 
   
     
   
 
  }



//End of question2

 Serial.println("You got more questions??");
//question3
  while (Serial.available() == 0)
  { //Wait for user input

  }
   question3 = Serial.readString();


 if (question3 == "Why do you hate humans")
  {
 
 
      tft.fillScreen(BLACK);
   drawBitmap(70, 55, angry, 195, 146,CYAN);
tft.setTextColor(RED);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("Cuz they are dumb");
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
  
  }
   

   else if (question3 == "Hello")
  {
    
  
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, happy, 195, 146,CYAN);
tft.setTextColor(CYAN);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("Hi");
   tft.println("");
    tft.println(name);
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
   
  }

   else if (question3 == "Where did you come from")
  {
    
  tft.fillScreen(BLACK);
   drawBitmap(70, 55, surprised, 195, 146,CYAN);
tft.setTextColor(CYAN);
  tft.setCursor(0,0);
  tft.setTextSize(2);
  tft.println("space");
  delay(2000);
   tft.fillScreen(BLACK);
   drawBitmap(70, 55, idle, 195, 146,CYAN);
   
 
  }



//Not enough memory

}
 void loop(){
  
 }
     

  







  



  
