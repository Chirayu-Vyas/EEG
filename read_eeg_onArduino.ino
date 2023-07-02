#define samplingRate 240

int EEG_data;
int counter;

void setup(){
  counter = 0;
  Serial.begin(9600); //start up our serial communication
}

void loop(){
  delay(1000/samplingRate);
  //EEG_data = analogRead(0);
  EEG_data = 412 + counter%200;
  //Incoming data comes in between 0 and 1023, but to easily send data via serial port
  //(with a single byte), it needs to be between 0 and 255. Scale it down for this.
  EEG_data = EEG_data / 4;
  Serial.write(EEG_data);
  counter++;
}
