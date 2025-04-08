//
// SMFDEasy_AYA071 Lchicaスケッチ
// Copyright(C)'2025 Ayanosuke(Maison de DCC)
//
// PB0,PB1,PB4 をanalogWrite()で光るか確認→光りますね。昔直接レジスタ叩いたのはなんだったんだろう
//
// AYA071-2
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//
//--------------------------------------------------------------------------------

#include  <arduino.h>
//Task Schedule
unsigned long gPreviousL5 = 0;

#define ON 1
#define OFF 0

#define PIN_AUX1 0      // Atiny85 PB0(5pin)O7 analogwrite head light
#define PIN_AUX2 1      // Atiny85 PB1(6pin)O6 analogwrite tail light
#define PIN_AUX3 3      // Atint85 PB3(2pin)O3             sign light
#define PIN_AUX4 4      // Atiny85 PB4(3pin)O2 analogwrite room light

void setup() {
  pinMode(PIN_AUX1, OUTPUT);
  digitalWrite(PIN_AUX1, OFF);
  pinMode(PIN_AUX2, OUTPUT);
  digitalWrite(PIN_AUX2, OFF);
  pinMode(PIN_AUX3, OUTPUT);
  digitalWrite(PIN_AUX3, OFF);
  pinMode(PIN_AUX4, OUTPUT);
  digitalWrite(PIN_AUX4, OFF);
}

void loop() {
  if ( (millis() - gPreviousL5) >= 500) {
    led();
    gPreviousL5 = millis();
  }
}

void led(){
  static char state = 0;

  switch(state){
    case 0:
            digitalWrite(PIN_AUX1,ON);
            digitalWrite(PIN_AUX2,OFF);
            digitalWrite(PIN_AUX3,OFF);
            digitalWrite(PIN_AUX4,OFF);
            state = 1;
            break;
    case 1:
            digitalWrite(PIN_AUX1,OFF);
            digitalWrite(PIN_AUX2,ON);
            digitalWrite(PIN_AUX3,OFF);
            digitalWrite(PIN_AUX4,OFF);
            state = 2;
            break;
    case 2:
            digitalWrite(PIN_AUX1,OFF);
            digitalWrite(PIN_AUX2,OFF);
            digitalWrite(PIN_AUX3,ON);
            digitalWrite(PIN_AUX4,OFF);          
            state = 3;
            break;
    case 3:
            digitalWrite(PIN_AUX1,OFF);
            digitalWrite(PIN_AUX2,OFF);
            digitalWrite(PIN_AUX3,OFF);
            digitalWrite(PIN_AUX4,ON);          
            state = 0;
            break;  
    default:
            break;

  }
}
