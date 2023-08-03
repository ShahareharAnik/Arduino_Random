 
 int i = 0 ; // microseconds
 int freq = 1000 ; // Hz
 int dutyCycle = 90 ; // in Percentage 

 int period = ( 1 / freq ) * 1000000 ;  // microsecond
 unsigned int onTime = ( dutyCycle * period ) / 100 ;
 unsigned int offTime = (100 - dutyCycle ) * period / 100 ;


void setup() {   
  pinMode(13, OUTPUT) ;
}

void loop() {                        
     
     digitalWrite(13, HIGH);
     delayMicroseconds( onTime ) ;
     digitalWrite(13, LOW);
     delayMicroseconds(offTime) ;
      

      /*
      analogWrite(13, 255) ;
      delay( 1000 ) ;
      analogWrite(13, 0) ;
      delay( 1000 ) ;
      
      digitalWrite(13, HIGH) ;
      delayMicroseconds( 70) ;
      digitalWrite(13, LOW) ;
      delayMicroseconds( 30 ) ;
       */
     
}

                    