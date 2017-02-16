#include "robo_hardware.h"
#include <math.h>
//#include "/usr/share/arduino/libraries/Servo/Servo.h"
//#include <Servo.h>
//nesse arquivo e onde as funcoes devem ser implementadas
//todas as funcoes relacionadas ao arduino devem estar nessa classe

#define RODA_ESQUERDA 5
#define SENTIDO_HORARIO_RODA_ESQUERDA 7
#define SENTIDO_ANTIHORARIO_RODA_ESQUERDA 8

#define RODA_DIREITA 6
#define SENTIDO_HORARIO_RODA_DIREITA 4
#define SENTIDO_ANTIHORARIO_RODA_DIRETA 9

#define SERVO 10
#define BOTAO 13

Servo servo;


void tensao(float valor_por_cento,int pino){
  float k = 255/100;
  float valor_ate_255 = valor_por_cento * k;
  analogWrite(pino, abs(valor_ate_255)); 
}

robo_hardware::robo_hardware(){
  
}

void robo_hardware::configurar(){
  
  Serial.begin(9600);
  
  servo.attach(SERVO);
  
  pinMode(2, OUTPUT);  
  digitalWrite(2, HIGH);
  
  pinMode(3, OUTPUT);  
  digitalWrite(3, HIGH);
  
  pinMode(4, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);

  pinMode(BOTAO, INPUT);
}

boolean robo_hardware::lerSensorFimDeCurso(){
  return digitalRead(BOTAO); 
}

float robo_hardware::lerSensorDeLinha(int sensor){
  return analogRead(sensor);
}

void robo_hardware::lerXbee(){
  
}

void robo_hardware::acionarMotores(float motor1, float motor2){
  if( motor1 < 0 ){
       //7 faz lado motor A1 B1 andar no sentido horario e o 8 andar no sentido antihorario
       digitalWrite(SENTIDO_HORARIO_RODA_ESQUERDA, HIGH);
       digitalWrite(SENTIDO_ANTIHORARIO_RODA_ESQUERDA, LOW);
    }else{
      digitalWrite(SENTIDO_ANTIHORARIO_RODA_ESQUERDA, HIGH);
      digitalWrite(SENTIDO_HORARIO_RODA_ESQUERDA, LOW);
      
    }
    tensao(motor1,RODA_ESQUERDA);
  
  
    if(motor2 < 0){
      //4 faz lado motor A2 B2 andar no sentido horario e o 9 andar no sentido antihorario
       digitalWrite(SENTIDO_ANTIHORARIO_RODA_DIRETA, HIGH);
       digitalWrite(SENTIDO_HORARIO_RODA_DIREITA, LOW);    
    }else{
       digitalWrite(SENTIDO_HORARIO_RODA_DIREITA, HIGH);
       digitalWrite(SENTIDO_ANTIHORARIO_RODA_DIRETA, LOW);
    }
    tensao(motor2, RODA_DIREITA);
}

void robo_hardware::acionarServo(float angulo){
  servo.write(angulo);
}

void robo_hardware::addLog(float dado){
}
