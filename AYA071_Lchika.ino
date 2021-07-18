//
// SMFDEasy_AYA071 Lchicaスケッチ
// Copyright(C)'2020 Ayanosuke(Maison de DCC)
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

#define O2 4            // Atiny85 PB4(3pin) analog
#define O3 3            // Atiny85 PB3(2pin) digital
#define O6 1            // Atint85 PB1(6pin) analog
#define O7 0            // Atiny85 PB0(5pin) analog


void setup() {
  pinMode(O2, OUTPUT);   // 出力に設定
  pinMode(O3, OUTPUT);   // 出力に設定
  pinMode(O6, OUTPUT);   // 出力に設定
  pinMode(O7, OUTPUT);   // 出力に設定
}

void loop() {
  if ( (millis() - gPreviousL5) >= 100) {
    led();
    gPreviousL5 = millis();
  }
}

void led(){
  static char state = 0;

  switch(state){
    case 0:
            digitalWrite(O2, HIGH);
            digitalWrite(O3, LOW);
            digitalWrite(O6, LOW);                 
            digitalWrite(O7, LOW);
            state = 1;
            break;
    case 1:
            digitalWrite(O2, LOW);
            digitalWrite(O3, HIGH);
            digitalWrite(O6, LOW);                 
            digitalWrite(O7, LOW);
            state = 2;
            break;
    case 2:
            digitalWrite(O2, LOW);
            digitalWrite(O3, LOW);
            digitalWrite(O6, HIGH);                 
            digitalWrite(O7, LOW);
            state = 3;
            break;
    case 3:
            digitalWrite(O2, LOW);
            digitalWrite(O3, LOW);
            digitalWrite(O6, LOW);                 
            digitalWrite(O7, HIGH);
            state = 0;
            break;
    default:
            break;

  }
}
