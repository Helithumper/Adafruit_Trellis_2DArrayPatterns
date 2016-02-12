#include <Wire.h>;

#include <Adafruit_Trellis.h>;




Adafruit_Trellis trellis = Adafruit_Trellis();


int board[4][4]= {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15}
};

void setup() {
  Serial.begin(9600);
  Serial.println("2dArray Demo");

  trellis.begin(0x70);


  //Trellis Test Pattern
  for (int i=0; i<16; i++) {
    trellis.setLED(i);
    trellis.writeDisplay();    
    delay(50);
  }
  for(int i=0; i<16; i++) {
    trellis.clrLED(i);
    trellis.writeDisplay();    
    delay(50);
  }

}




//Clears the Trellis Display
void clearPanel(){
  for(int i = 0 ;i < 16; i++){
    trellis.clrLED(i);
    trellis.writeDisplay();
  }
}

//Converts (i,j) coordinates to the 0-15 system that the trellis recognizes
void setPixel(int i, int j){
  trellis.setLED(4*i+j);
}

void pattern1(){
  clearPanel();
  for(int i = 0; i < 4; i ++){
    for(int j = 0; j < 4; j++){
      if(i==j){
        setPixel(i,j);
      }  
    }
  }
}

void pattern2(){
  clearPanel();
  for(int i = 0; i < 4; i ++){
    for(int j = 0; j < 4; j++){
      if(4-j-i==1){
        setPixel(i,j);
      }
    }
  }
}

void pattern3(){
  clearPanel();
  for(int i = 0; i < 4; i ++){
    for(int j = 0; j < 4; j++){
      if(j==0||j==2){
        setPixel(i,j);
      }
    }
  }
}

void pattern4(){
  clearPanel();
  for(int i = 0; i<4;i++){
    for(int j = 0; j < 4; j++){
      if(j==1||j==3){
        setPixel(i,j);
      }
    }
  }
}

void pattern5(){
  clearPanel();
  for(int i =0; i<4;i++){
    for(int j = 0; j < 4; j++){
      if(i==0||i==2){
        setPixel(i,j);
      }
    }
  }
}

void pattern6(){
  clearPanel();
  for(int i = 0 ; i < 4; i ++){
    for(int j = 0; j < 4; j++){
      if(i==1||i==3){
        setPixel(i,j);
      }
    }
  }
}

void loop() {
  //First Diagonal
  pattern1();
  delay(2000);
  //Second Diagonal
  pattern2();
  delay(2000);
  //First Horizontal
  pattern3();
  delay(2000);
  //Second Horizontal
  pattern4();
  delay(2000);
  //First Vertical
  pattern5();
  delay(2000);
  //Second Vertical
  pattern6();
  delay(2000);
}
