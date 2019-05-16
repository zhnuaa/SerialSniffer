void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //display port
  //Serial1 and Serial2 should have the same speedrate
  Serial1.begin(9600); //input port from computer
  Serial2.begin(9600); //output port to board
}

void loop() {
  // put your main code here, to run repeatedly:
//  byte cmd[19];
//  int index=0;
  //recieve data from input port
  while(Serial1.available()>0){
    byte data=Serial1.read(); //read data from computer
    Serial.write(data); //send data to display port
    Serial2.write(data); //send data to board
//    cmd[index]=data;
//    index++;
    delay(10);
  }
//  if(index>0){
//    for(int i=0;i<19;i++){
//      Serial1.write(cmd[i]);
//    }
  }
  //recieve data from board
  while(Serial2.available()>0){
    byte data=Serial2.read(); //read data from board
    Serial.write(data); //send data to display port
    Serial1.write(data);  //send data to computer port
    delay(10);
  }
}
