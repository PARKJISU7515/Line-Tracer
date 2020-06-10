//E1, E2, M1, M2 = 3,4,5,6
//적외선 센서 핀 = 8,9,10,11
//스위치 = 12
// 속도 0 - 120 : 전진 ( 최고속도 0 ) 
// 속도 120-240 : 후진 ( 최고속도 240 )
bool state = true; 
void setup() { 
  int i;
  for(i=3;i<7;i++) pinMode(i, OUTPUT);
  pinMode(12, INPUT);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
  digitalWrite(6, HIGH);//왼쪽 바퀴 방향 HIGH 뒤   로 , LOW 앞으로 
  for(i=8; i<12; i++) pinMode(i, INPUT);
  
}
   
void loop() {                                                                                                                                                                                                                                                      
 
  if((digitalRead(12)==LOW) && state ){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    state =!state;
    delay(500);
  }
  else if((digitalRead(12)==LOW) && !state)
  {
    digitalWrite(3, LOW);
    digitalWrite(4,LOW);
        state =!state;
        delay(500);
  }
    if( digitalRead(8)==HIGH&&digitalRead(9)==HIGH&&digitalRead(10)==HIGH&&digitalRead(11)==HIGH){
       digitalWrite(5, HIGH); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
       digitalWrite(6, LOW); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
      straight();
    }
    else if(digitalRead(8)==HIGH&&digitalRead(9)==LOW&&digitalRead(10)==HIGH&&digitalRead(11)==HIGH){ 
      digitalWrite(5, HIGH); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, HIGH); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
      left();
    }
    else if(digitalRead(8)==LOW&&digitalRead(9)==HIGH&&digitalRead(10)==HIGH&&digitalRead(11)==HIGH){
      digitalWrite(5, HIGH); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, HIGH); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
      
      hleft();
    }
    else if(digitalRead(8)==LOW&&digitalRead(9)==LOW&&digitalRead(10)==HIGH&&digitalRead(11)==HIGH){ //왼쪽 턴 직각
      digitalWrite(5, HIGH); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, HIGH); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
       analogWrite(4, 200);
      analogWrite(3, 100);
     /*hhleft();*/
    }
    else if(digitalRead(8)==HIGH&&digitalRead(9)==HIGH&&digitalRead(10)==LOW&&digitalRead(11)==HIGH){ 
      //왼쪽 앞으로 오른쪽 뒤로 
      digitalWrite(5, LOW); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, LOW); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
      right();
    }
    else if(digitalRead(8)==HIGH&&digitalRead(9)==HIGH&&digitalRead(10)==HIGH&&digitalRead(11)==LOW){
      digitalWrite(5, LOW); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, LOW); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
      hright();
    }
    else if(digitalRead(8)==HIGH&&digitalRead(9)==HIGH&&digitalRead(10)==LOW&&digitalRead(11)==LOW){ //오른쪽턴 
      digitalWrite(5, LOW); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, LOW); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
      //hhright();
      analogWrite(4, 10);
      analogWrite(3, 250);
      //바꿈
    }
    else if(digitalRead(8)==LOW&&digitalRead(9)==LOW&&digitalRead(10)==LOW&&digitalRead(11)==LOW){ // 아예 턴 
      digitalWrite(5, HIGH); //오른쪽 바퀴 방향 LOW 뒤로 , HIGH 앞으로
      digitalWrite(6, HIGH); //왼쪽 바퀴 방향 HIGH 뒤로 , LOW 앞으로 
     analogWrite(4, 255);
      analogWrite(3, 255);
      delay(610);
    }
   // else if( digitalRead(8)==HIGH && digitalRead(11)==LOW) {
    //  turn();
  //}
  
 
//else if(sw ==0){
//    rstop();
//}
}
 
 void straight(){
  analogWrite(3, 120);
  analogWrite(4, 120);
  
 }
 
 void left(){
  analogWrite(4, 90);
  analogWrite(3, 60);
 }
 
 void hleft(){
  analogWrite(4, 200);
  analogWrite(3, 20);
 }
 
 void hhleft(){
  analogWrite(4, 255);
  analogWrite(3, 0);
 }
 
 void right(){
  analogWrite(4, 50);  
  analogWrite(3, 80);
 }
 
 void hright(){
  analogWrite(4, 20);
  analogWrite(3, 200);
 }
 
 void hhright(){
  analogWrite(4, 0);
  analogWrite(3, 255);
 }
 void rstop(){
  analogWrite(3, 0);
  analogWrite(4, 0);
 }

