 # include <stdio.h>

  float   f       = 10.66;
  int     myVar   = 10;
  int*    PmyVar;
  float*  Pf ;
  float   sample [10] ;
  float*  Psample  ;


  void setup() {
  Serial.begin(9600);
  PmyVar = &myVar;  //  *PmyVar   = 15;
  Pf = &f ;         //  *Pf       = 13.00 ;
   Psample = &sample [10] ;

  for (int i=0; i<10 ; ++i) {sample [i] = 100+i;} 
  Serial.println("Initialization completed ..");
 }

 void loop() {
  /*
  Serial.print("Value of int myVar by passing value -> "); Serial.println(myVar);
  Serial.print("Value of int myVar by passing pointer -> "); Serial.println(*PmyVar);
  Serial.print("Address of int myVar -> "); Serial.println((unsigned long)&myVar);
  Serial.print("Size of int myVar -> "); Serial.println(sizeof(myVar));
  Serial.print("Value of float f by passing value -> "); Serial.println(f);
  Serial.print("Value of float f by passing pointer -> "); Serial.println(*Pf);
  Serial.print("Address of float f -> "); Serial.println((unsigned long)&f);
  Serial.print("Size of float f -> "); Serial.println(sizeof(f));
  Serial.println();
  */
  Serial.println("Printing Starts ..");

  for (int i=0; i<10 ; ++i) {
    Serial.print(" Sample No  "); Serial.print(i) ;
    Serial.print(" ,Sample value passing value  "); Serial.print(":") ; Serial.println(sample[i]);
    Serial.print(" Sample value passing pointer : "); Serial.println( Psample [i] );
    Serial.print(" Address of sample "); Serial.print(":") ; Serial.print((unsigned long)&sample[i]);
        
  }
  Serial.print(" Total Size of float sample : "); Serial.println(sizeof(sample));

  Serial.println(" Nullification  : ");
  for (int i=0; i<10 ; ++i) {

    ( Psample  [i] ) = NULL;
    Serial.println();
    Serial.print(" Sample No : "); Serial.print(i) ;
    Serial.print(" Sample value by passing Refference "); Serial.print(":") ; Serial.print(*sample +i); ////
   // Serial.print("Sample value passing pointer -> "); Serial.println(*PmyVar);
   // Serial.print(" Address of sample : "); Serial.println((unsigned long)&sample[i]);
    if ( sample [i] != NULL ) Serial.println(" Not Nulled ");
   // Serial.print(" Size of float sample -> "); Serial.println(sizeof(sample));
    }
    Serial.print(" Total Size of float sample Array : "); Serial.println(sizeof(sample));
  

  while(1){} // Infinite loop to halt program
 }