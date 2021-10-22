void setup() {
  Serial.begin(9600);
  Serial.println("Weekly class list");
  Serial.println("========================================");
}

void loop() {
  const int  Classes        = 2,
             id_no_min      = 1,
             id_no_max      = 8;
  int        Flag[Classes]     ;
  static int week           = 1;
  
  if(week != 18 + 1) {
  Serial.print("*** THE ");
  Serial.print(week);
  Serial.println(" WEEK(s) ***");
  for(int cla = 0, f = 0; cla < Classes; cla++, f = 0) {
     for(int i = id_no_min; i <= id_no_max; i++) {
        switch(week % 4) {
          case 0 :
            Flag[0] = 1; Flag[1] = 0;
      	    break;
          case 1 :
            Flag[0] = 0; Flag[1] = 1;
            break;
          case 2 :
            Flag[0] = 0; Flag[1] = 0;
            break;
          case 3 :
            Flag[0] = 1; Flag[1] = 1;
            break;
        }
        switch(cla) {
          case 0:
            if(Flag[0] == 0)       f = 0;
            else if(Flag[0] == 1)  f = 1;
            break;
          case 1:
            if(Flag[1] == 0)       f = 0;
            else if(Flag[1] == 1)  f = 1;
            break;
        }
        if(cla == 0 && i == 1)       Serial.println("\nMechanical Engineering");
        else if (cla != 0 && i == 1) Serial.println("\nDepartment of Chemical Materials");
        if(f == 0) {
          if(i % 2 == 0) {
            Serial.print("4A81200");
            Serial.println(i);
          }
        }
        else if(f == 1) 
          if(i % 2 != 0) {
          Serial.print("4A81200");
          Serial.println(i);
        }
      }
    }
  	Serial.println("========================================");
    delay(2000);
    if(week == 18) Serial.println("Has been completed!!\nSee you next time ^^ ~~");
  	week++;
  }
}