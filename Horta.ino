//Giuliana Leon 
//Horta Inteligente

#include <DHT.h>
#include <DHT_U.h>
#define tipoSensor DHT22
#define sensorTH 5


DHT dht(sensorTH, tipoSensor);

char controleAPP = 0;

int leituraSensor;

void setup() {

  Serial.begin(9600);
  dht.begin();
  pinMode (A1, INPUT);     //Lê as informações do sensor
  pinMode (53, OUTPUT);    //Aciona o rele
  digitalWrite(53, LOW);
}

void loop() {

  controleAPP = Serial.read();

  //Serial.print("\n Umidade: ");
  Serial.print(dht.readHumidity());
  Serial.print(" %");
  Serial.print("|");
  
  //Serial.print("\n Temperatura: ");
  Serial.print(dht.readTemperature(), 0);
  Serial.print(" *C");
  Serial.print("|");

 leituraSensor = analogRead(A1);   //Le o sensor 
 
 //Serial.print("\n Umidade do Solo: ");
 Serial.print(leituraSensor);
 Serial.print("h");
 Serial.print("|");
 
  if (leituraSensor > 700){                 //Quando o solo estiver seco
    digitalWrite(53, LOW);       
    delay(15000);
  }

  if(leituraSensor < 500){                  //Quando estiver molhado
    digitalWrite(53, HIGH);
    delay(15000);
  }

  if(controleAPP == '1'){
    digitalWrite(53, LOW);          //Liga a bomba
    delay(10000);
  }
 
  if(controleAPP == '0'){
    digitalWrite(53, HIGH);          //Desliga a bomba
    delay(5000);
  }
}
