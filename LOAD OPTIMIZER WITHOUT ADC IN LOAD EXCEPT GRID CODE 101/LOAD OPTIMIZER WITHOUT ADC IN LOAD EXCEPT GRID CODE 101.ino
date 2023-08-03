// serial scans lines, if found loaded transfers it in Inverter Grid 
// as long as inverter is under load, if inverter is overloaded line is left in utility Grid
// lines are interfaced with microcontroller without ADC, 2 AC signal is sampled at and interval of 3 ms
// Grids are interfaced with ADC
// if absolute value of difference of two samples is greater than a threshold, then scan of lines starts    

void setup() {
Serial.begin(9600);

  // Microcontroller pin setting 
        //Analog input of Load circuit, utility grid and inverter Grid
  pinMode(A0, INPUT);  // set A0 as input of load circuit N
  pinMode(A1, INPUT);  // set A1 as input of Load of Utility Grid
  pinMode(A2, INPUT);  // set A2 as input of Load of inverter Grid
  pinMode(A3, INPUT);   // command input for single loop of operation

        // PinMode for Load Circuit relay switching (on/off)
  pinMode(5, OUTPUT);   // set pin 5 as output (LSB for channel selection)
  pinMode(6, OUTPUT);   // set pin 6 as output (MSB for channel selection)
  pinMode(7, OUTPUT);   // set pin 7 as output (ESB for channel selection)
//Set Initial Values (for load circuit switching  Pins)

    digitalWrite(5, LOW);   // multiplexer input of master reset pin
    digitalWrite(6, LOW);       // multiplexer Write enable (WR) Pin 
    digitalWrite(7, LOW);       // multiplexer input signal (D) Pin

      // Digital Output for channel Selection 
      pinMode(11, OUTPUT);  // set pin 11 as output
      pinMode(12, OUTPUT);  // set pin 12 as output
      pinMode(13, OUTPUT);  // set pin 13 as output

          //Set Initial Values (for Channel Selector Pins)
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
     }
     ///////

    int cycle=0; 
    void loop ()  { 
      //delay (3000);
      Serial.println ();
      Serial.print (" Cycle = "); Serial.print (cycle);
      float IV = analogRead (A1)*(5.0/1023.0);
if (IV> 4.50) {
              Serial.print (" Inverter Load = "); Serial.print (IV);
              Serial.print (",  Inverter overloaded, Switching skipped ");
              return (0);
              }
                if  (IV < 4.50){
                //delay(1000);
                bool relay_state [8];
                //Serial.println ();  
                for (int num = 0; num < 8; num++) { 
                  Serial.println (); 
                digitalWrite (11, num & 0x01); digitalWrite(12, (num & 0x02) >> 1); digitalWrite(13, (num & 0x04) >> 2);
                 delay(2000);
                Serial.print ("          line= "); Serial.print (num);
                float LV1 = analogRead(A0)*(5.0/1023.0); delay (3); float LV2 = analogRead(A0)*(5.0/1023.0);
                Serial.print (",  Line Differential = "); Serial.print (abs (LV1-LV2));
                // Serial.print (",  Utility Voltage = ");Serial.print (analogRead(A2)*(5.0/1023.0));
                IV = analogRead (A1)*(5.0/1023.0);
                Serial.print (",  Inverter Voltage = "); Serial.print (IV);
 if (abs (LV1-LV2) < 0.02 ) {
                digitalWrite(6, HIGH); delay (100); digitalWrite(7, LOW); delay (100); digitalWrite(6, LOW);
                Serial.print (",     Circuit unloaded--Switching skipped  ");
                                      }
          
 if (abs (LV1-LV2) >= 0.02 && IV<4.45 ) { 
                digitalWrite (7, HIGH); delay (100); digitalWrite (6, HIGH); delay (100); 
                digitalWrite (6, LOW); delay (100); digitalWrite (7, LOW); 
                Serial.print ("      Inv in Capacity, Circuit loaded, Transferred to INV Grid ");
                                        
                LV1 = analogRead(A0)*(5.0/1023.0); delay (3);  LV2 = analogRead(A0)*(5.0/1023.0);
 
                                   
                                    } 
                                    }
           cycle++;
  }
    }   
   

