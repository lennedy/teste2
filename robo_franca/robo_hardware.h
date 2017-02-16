//nesse arquivo as funcoes devem ser somente declaradas
#ifndef ROBO_HARDWARE_H
#define ROBO_HARDWARE_H

#define RH_MAX_TAMANHO_LOG

#include <Arduino.h>
#include <Servo.h>

class robo_hardware{
float Log[RH_MAX_TAMANHO_LOG];
int logSize;
  
public:
	robo_hardware();
        void configurar();
        boolean lerSensorFimDeCurso();
        float lerSensorDeLinha(int sensor);
        void lerXbee();
        void acionarMotores(float motor1, float motor2);
        void acionarServo(float angulo);
        void addLog(float dado);

};

#endif
