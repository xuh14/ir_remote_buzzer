#include <IRremote.h>
#include <TonePlayer.h>

TonePlayer tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L); // D9

unsigned int tone_C3 = 130;
unsigned int tone_D3 = 146;
unsigned int tone_E3 = 164;
unsigned int tone_F3 = 174;
unsigned int tone_G3 = 196;
unsigned int tone_A3 = 220;
unsigned int tone_B3 = 247;

const int RECV_PIN = 11;
const int BUZ_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int rec_result;

void setup() {
 Serial.begin(115200); 
 irrecv.enableIRIn();
 irrecv.blink13(true);
 pinMode(BUZ_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    switch(results.value){
          case 0xFF629D:
          Serial.println("up arrow");
          break;
          case 0xFF22DD:
          Serial.println("left arrow");
          break;
          case 0xFFC23D:
          Serial.println("right arrow");
          break ;               
          case 0xFFA857:
          Serial.println("down arrow");
          break ;
          case 0xFF30CF:
          Serial.println("1");
          tone1.tone(tone_C3);
          break ;
          case 0xFF18E7:
          Serial.println("2");
          tone1.tone(tone_D3);
          break ;
          case 0xFF7A85:
          Serial.println("3");
          tone1.tone(tone_E3);
          break ;
          case 0xFF10EF:
          Serial.println("4");
          tone1.tone(tone_F3);
          break ;
          case 0xFF38C7:
          Serial.println("5");
          tone1.tone(tone_G3);
          break ;
          case 0xFF5AA5:
          Serial.println("6");
          tone1.tone(tone_A3);
          break ;
          case 0xFF42BD:
          Serial.println("7");
          tone1.tone(tone_B3);
          break ;
          case 0xFF4AB5:
          Serial.println("8");
          break ;
          case 0xFF52AD:
          Serial.println("9");
          break;   
          case 0xFFFFFFFF:    
          Serial.println("cont.");         
          break;
          default: break;
        }
    irrecv.resume();
  } else {
    tone1.noTone();
  }
  delay(200);
}
