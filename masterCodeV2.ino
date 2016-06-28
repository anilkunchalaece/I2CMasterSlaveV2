#include<Wire.h>

#define slaveA 8
#define slaveB 9
#define slaveC 10

#define byteLength 2

boolean chRead = false;
char ch;


void setup() {
  Wire.begin();//Address is Optional For Master
  Serial.begin(9600);
  Serial.println("Please enter --> a to read the data from Slave 1 ");
  Serial.println("Pleae enter -->  b to read the data from slave 2 ");
  Serial.println("Please enter --> c to read the data from slave 3");
  
}

void loop() {
  if(Serial.available()){
     ch = Serial.read();
    chRead = true;
  }

  if(chRead){
    switch(ch){
      case 'a':
      requestSlaveA();
      break;

      case 'b':
      requestSlaveB();
      break;

      case 'c':
      requestSlaveC();
      break;

      default:
      Serial.println("Please check the Command");
      
    }
    chRead = false;
  }

}

void requestSlaveA(){
  if(Wire.requestFrom(slaveA,byteLength)){
    Serial.print("Data from Slave A is --> \t");
    Serial.println(getData());
  }else{
    Serial.println("Something Wrong with Slave A");
  }
}


void requestSlaveB(){
  if(Wire.requestFrom(slaveB,byteLength)){
    Serial.print("Data from the Slave B is --> \t");
    Serial.println(getData());
  }else{
    Serial.println("Something Wrong with Slave B");
  }
}

void requestSlaveC(){
  if(Wire.requestFrom(slaveC,byteLength)){
    Serial.print("Data from the Slave C is --> \t");
    Serial.println(getData());
  }else{
    Serial.println("Something wrong with Slave C");
  }
}


int getData(){
  int receivedValue  = Wire.read() << 8;
    receivedValue |= Wire.read();
    return receivedValue;
 }

