//Asignación de puertos del arduino.
int MotorBanda = 2;       //motor de la banda
int MotorCaja = 8;       //motor de la banda
int infra = 7;          //receptor infrarrojo
//variables globales
int valor = 0;          //almacenamiento y lectura del infrarrojo
char a;                //almcenamiento y lectura puerto serial

void setup() {
    //iniciamos el puerto serial
    Serial.begin(9600);
    //declarmaos entradas y salidas
    pinMode(MotorBanda, OUTPUT);
    pinMode(MotorCaja, OUTPUT);
    pinMode(infra, INPUT);

}

void loop() {

    valor = digitalRead(infra);
    if (Serial.available() > 0) {
        a = Serial.read();
        switch (a) {
        case 'c':
            digitalWrite(MotorBanda, 1);

            break;
        case '0':
            digitalWrite(MotorBanda, 0);
            digitalWrite(MotorCaja, 1);
            delay(250);
            digitalWrite(MotorCaja, 0);
            break;
        }

    }
    if (valor == 0) {
        digitalWrite(MotorBanda, 0);
        a = 'c';
    }if (valor == 1 && a == 'c') {
        digitalWrite(MotorBanda, 1);
    }
}
