#include <TVout.h>
//#include <fontALL.h>

TVout TV;

int x;
int y;

int x_inc = 1;
int y_inc = 1;

int score = 50;

int u = 0;
int l = 0;
int inc = 1;

  int sensorPin1 = A0;    // select the input pin for the potentiometer
  int sensorPin2 = A1;
  int r_in = 0;
  int l_in = 0;
  int paddle = 10;
  int l_paddle =10;
  
int counter = 0;

void setup() {

  TV.begin(NTSC,136,104);
  //TV.select_font(font8x8);
  randomSeed(analogRead(3));
 
  TV.clear_screen();
  TV.draw_rect(0,0,135,103,WHITE);

   x = random(5,130);
   y = random(5,20);
  
}

void loop() {

      TV.draw_rect(0,0,135,103,WHITE);
      TV.draw_circle(x,y,4,WHITE,WHITE);
      TV.delay(1);   
      
       r_in = (analogRead(sensorPin1) - analogRead(sensorPin2));
       //r_in = analogRead(sensorPin1);
       //l_in = analogRead(sensorPin2);

       if (r_in > l_in) {
        paddle+=2;
       }

       if (r_in < l_in) {
        paddle-=2;
       }

        
       if (paddle >= 118) {
        paddle = 118;
      }
      if (paddle <= 1) {
        paddle = 1;
      }
   
      if (r_in != l_in) {
        TV.draw_rect(l_paddle,99,16,2,BLACK,BLACK);
        //TV.delay(5);
        TV.draw_rect(paddle,99,16,2,WHITE,WHITE);
        l_in = r_in;
        l_paddle = paddle;
        
       }
       
       TV.draw_circle(x,y,4,BLACK, BLACK); 
       x+=x_inc;
       y+=y_inc;

        if (x == 132 ) {
          x_inc = -1;
       }
        if (x == 4 ) {
        x_inc = 1;
       }
        
        if (y == 4 ) {
        y_inc = 1;
       }

      if (y == 96 ) {
        
        
        l = paddle;
        u = paddle+22;

       if ( x>=l &&  x<=u ) { 
       y_inc = -1;   
     } 
     else {

      TV.delay(2000);
      TV.clear_screen();
      TV.draw_rect(0,0,135,103,WHITE);

           x = random(5,130);
           y = random(5,20);
     
       } 
    
      }     
}
