// ini adalah variabel yang dipakai dalam program
//adc untuk data kg dari hx711
//b untuk fungsi kontrol angka
//modku adalah variabel untuk menyimpan angka satuan
int adc,b,modku;

//ini adalah program untuk mengkontrol isd dengan relay untu pemilihan angka
void suaraangka(int angka);
void puluh();
void kilogram();
void ratus();

void sepuluh();
void belas();
void sebelas();
//ini adalah program untuk mengkontrol permulaan pengucapan dua fungsi memiliki beda variabel saja
void play();
void play2();

#include <HX711.h> // ini adalah library dari hx711 disimpan /arduino/libraries/HX711
HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library
void setup() {
  pinMode(3,OUTPUT);                    //deklarasi untuk pin 3 sebagai output
  digitalWrite(3,HIGH);                 //dibuat automatic high karena Memakai logika NC dengan supply sehingga bila berlogika low maka akan mentrigger suara
  for (int i=7;i<=10;i++){              //deklarasi untuk pin pemilihan suara
  pinMode(i,OUTPUT);}                   
  digitalWrite(7,LOW);                  //dibuat automatic low karena Logika NC dengan supply isd pin sehingga bila berlogika HIGH akan memutus koneksi dari pin ke supply
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
}
void loop() {
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 1);
  scale.power_down();			        // mematikan fungsi adc
  delay(5000);
  scale.power_up();

  if (adc<10){    //control statement untuk angka di 1-9; 
  suaraangka(adc);
  play();
  kilogram();
  play2();
}else if(adc==10){  // control statement untuk angka 10
  suaraangka(adc);
  play();
  kilogram();
  play2();}
else if(adc==11){  // control statement untuk angka 11
  sebelas();
  play();
  kilogram();
  play2();
}else if (adc<=19){ // control statement untuk angka 12-19
  modku=adc%10;
  suaraangka(adc);
  play();
  belas();
  play();
  kilogram();
  play2();}
  else if(adc<=99)// control statement untuk angka 20-99
{if(adc%10==0){// control statement untuk angka yang habis dibagi sepuluh
  modku=adc%10;
  suaraangka(modku);
  play();
  puluh();
  play();
  kilogram();
  play2();
}

else{// control statement untuk angka yang memiliki satuan
 modku=adc/10;
  suaraangka(modku);
  play();
  puluh();
  play();
  modku=adc%10;
  suaraangka(modku);
  play();
  kilogram();
  play2();}
}  
}
void play(){    //void untuk pengucapan yang sebentar
digitalWrite(3,LOW);
delay(100);
digitalWrite(3,HIGH);
delay(900);
}

void play2(){    // void angka untuk pengucapa yang lama yaitu kilo  gram
digitalWrite(3,LOW);
delay(500);
digitalWrite(3,HIGH);
delay(1500);
}
//fungsi control isd pemilihan angka
void suaraangka(int angka){
if (b==0){ delay(1500);}
if (b==1){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);}
if (b==2){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);}
if (b==3){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);}
if (b==4){
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);}
if (b==5){
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);}
if (b==6){
  digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
}
if (b==7){
  digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
}
if (b==8){
  digitalWrite(7,LOW);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
}
if (b==9){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
}}//fungsi kontrol isd untu puluh
void puluh(){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
}//fungsi kontrol isd untuk belas
void belas(){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
}
//fungsi kontrol isd untuk sebelas
void sebelas(){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
}
//fungsi kontrol isd untuk ratus
void ratus(){
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);}
//fungsi kontrol isd untuk kilogram
void kilogram(){
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);}
//fungsi kontrol isd untuk sepuluh
void sepuluh(){
digitalWrite(7,HIGH);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
}
