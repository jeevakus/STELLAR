// defining pin numbers
int soundsensor = 3;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int colour[12][3] =
      {
        {255,0,0},    // red
        {255,128,0},  // orange
        {255,255,0},  // yellow
        {128,255,0},  // lime
        {0,255,0},    // green
        {0,255,128},  // lightgreen
        {0,255,255},  // turquoise
        {0,128,255},  // blue
        {0,0,255},    // darkblue
        {127,0,255},  // violet
        {255,0,255},  // pink
        {255,0,127},  // rose
      };

void setup() {
  // put your setup code here, to run once:
pinMode(soundsensor,INPUT);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
Serial.begin(9600); // Sets the BAUDRATE speed that information is transferred
}

void loop() {

int sensorvalue = digitalRead (soundsensor);
// if the sound intensity is higher than the threshold, which is set by myself
//then sensor would return this value as 1
if (sensorvalue >= 1)
  {
    int r = random(12);
    delay(20);
    setColour(colour[r][0],colour[r][1],colour[r][2]);
   
  }

else
  {
    setColour(0,0,0);
  }

}

void setColour(int red, int green, int blue) {
  
  digitalWrite(redPin,red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
  
}
