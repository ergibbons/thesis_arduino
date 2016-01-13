int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
int val; // the mapped value from the force sensor
int objNumber; // the number of the object that was recognized

void setup(void) {
  
  Serial.begin(9600);   
}
// object 1 415-425, after mapping: 399-385
// object 2 470-505, after mapping 319-269
void loop(void) {

  fsrReading = analogRead(fsrPin);  
  val = map(fsrReading, 0, 690, 1000, 0);
  objNumber = numberOfObject(val);

  Serial.println(objNumber);
  
  delay(300); // how long it waits before reading again   
}

int numberOfObject(int val) {
  if (val > 100 && val <= 400) {
    return 1;
  } else if (val > 400 && val <= 800) {
    return 2;
  } else if (val > 800) {
    return 3;
  }
  return 0;
}

