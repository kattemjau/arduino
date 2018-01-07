String data="";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("schnigger");
  //Seriaial.write("snik");
  if(Serial.available() >0){
    data=Serial.read();
    Serial.println(data);  
  }else{
    Serial.println("no data");
  }
  
  delay(1000); 
}
