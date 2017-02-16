#include <Servo.h>
#include "robo_hardware.h"


int media_direita = 850;
int media_esquerda =  850;


robo_hardware robo;
int luz_direita = 0;
int luz_esquerda = 0;


void setup() {
  robo.configurar();
  //Serial.begin(9600);
}

void loop(){
  
  //Serial.println();  
//  Serial.println(luz_esquerda);
//  delay(1000);
  
  luz_direita = robo.lerSensorDeLinha(A1);
  luz_esquerda = robo.lerSensorDeLinha(A0);
  if(luz_esquerda > media_esquerda && luz_direita > media_direita){
    robo.acionarMotores(0,0);
  
  }else if(luz_esquerda < media_esquerda && luz_direita < media_direita ){
    robo.acionarMotores(25,25);
    
  
  } //else if(luz_esquerda > media_esquerda && luz_direita < media_direita ){
    
  //  robo.acionarMotores(0,0);
  
  //}
  else if(luz_esquerda > media_esquerda && luz_direita < media_direita ){
    robo.acionarMotores(-25,35); 
  }
  else if (luz_esquerda < media_esquerda && luz_direita < media_direita){
    robo.acionarMotores(25,25);
  }
  else if (luz_esquerda < media_esquerda && luz_direita > media_direita){
    robo.acionarMotores(35,-25);
  }
  else if ( luz_esquerda > media_esquerda && luz_direita > media_direita){
    robo.acionarMotores (0,0);
  }  
    
    
}
