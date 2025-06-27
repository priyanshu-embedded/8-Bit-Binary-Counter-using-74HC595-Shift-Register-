const  short int dataPin=4;
const   short int storagePin=3;
const   short int clockPin=5;
const  short int switchpin=2;
 short int switchval;
unsigned long previous_time=0;
short int read_time=200;//time to  read the value  from  the serial monitor to increase readability
void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(storagePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(switchpin),bit_increament,FALLING);//handle the task at the button press
  pinMode(switchpin, INPUT_PULLUP);//enable buit-in pull_up resistor
  Serial.begin(9600);//start serial communication
  
}volatile byte bin=0b00000000; //initialize the 8 bit binary value from 0
 

void loop() {
  // put your main code here, to run repeatedly:
  //to overcome race condition in isr and loop 
byte safeCopy;
noInterrupts(); // disable interrupts temporarily
safeCopy = bin;
interrupts();
digitalWrite(storagePin, LOW);
shiftOut(dataPin,clockPin,LSBFIRST,safeCopy);
digitalWrite(storagePin, HIGH);
Serial.print("Binary value: ");
Serial.println(safeCopy,BIN);
delay(read_time);

}
void bit_increament(){
  if(millis()-previous_time>=200UL){
   bin++;
  previous_time=millis();}
  
}
