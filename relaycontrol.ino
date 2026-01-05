//global variables
//A1 - K1 Coil1, K2 Coil2
//A2 - K1 Coil2, K2 Coil1
//turn J2 on, apply relay coil supply betwween A2 and A1 to pull K1 and K2

//B1 - K3 coil1, K4 Coil2
//B2 - K3 coil2, K4 Coil1
//turn J3 on, apply coil voltage between B@ and B1 to close K3 and K4

//C1 - K5 coil1, K6 coil1
//C2- K5 coil2, K6 coil 2
//apply coil supply between c2 and ground to close k5 and k6

//A1 - SSTXN1
//B2 -CC1
//B1 - SBU1
//C2 - SSRXN2
//A2 - GND_A
//C1 - GND_A

const int relayJ2 = 2;
const int relayJ3 = 3;
const int relayJ4 = 4;

void setup(){
  pinMODE(relayJ2, OUTPUT);
  pinMODE(relayJ3, OUTPUT);
  pinMODE(relayJ4, OUTPUT);

  digitalWrite(relayJ2, LOW);
  digitalWrite(relayJ3, LOW);
  digitalWrite(relayJ4, LOW);

  Serial.begin(9600);
}

void loop() {
  //check if data is coming from the computer
  if (Serial.available() > 0) {
    char command = Serial.read(); //reads the key pressed

    if (command == '2') {
      digitalWrite(pinJ2, HIGH);
      Serial.println("Outlet J2: ON");
    } 
    else if (command == '3') {
      digitalWrite(pinJ3, HIGH);
      Serial.println("Outlet J3: ON");
    } 
    else if (command == '4') {
      digitalWrite(pinJ4, HIGH);
      Serial.println("Outlet J4: ON");
    } 
    else if (command == '0') {
      digitalWrite(pinJ2, LOW);
      digitalWrite(pinJ3, LOW);
      digitalWrite(pinJ4, LOW);
      Serial.println("All Outlets: OFF");
    }
  }
}
