#include <LiquidCrystal.h>		// fazendo incue da biblioteca 'LiquidCrystal'

#define btcima 8		// definições
#define btbaixo 9
#define bttiro 10

LiquidCrystal lcd(7,6,5,4,3,2);

int vel = 100;
int pxnave, pynave, pxaste, pyaste, pxenergia, pyenergia, pxtiro, pytiro;
bool game, vtiro, vpilha;
int pontos;
double venergia;

byte nave[8] = {B11000,B01100,B01110,B01111,B01111,B01110,B01100,B11000};
byte asteroide[8] = {B00000,B00100,B01110,B10111,B11101,B01110,B00100,B00000};
byte explosao[8] = {B10001,B10101,B01010,B10100,B00101,B01010,B10101,B10001};
byte energia[8] = {B01110,B11011,B10001,B10101,B10101,B10101,B10001,B11111};
byte tiro[8] = {B00000,B00000,B00000,B00111,B00111,B00000,B00000,B00000};

void setup() {
  pxnave = pynave = pyaste = pontos = pxenergia = pyenergia = pytiro = 0;		// fazendo a iniçiaização dos elementos
  pxtiro = -1;
  pxaste = 12;
  venergia = 100;
  lcd.createChar(1, nave);		// criando caracters dos elementos (nvae, tiro, asteroide etc)
  lcd.createChar(2, asteroide);
  lcd.createChar(3, explosao);
  lcd.createChar(4, energia);
  lcd.createChar(5, tiro);
  lcd.begin(16, 2);
  lcd.clear();
  game = true;
  vtiro = vpilha = false;
}

void loop(){
  
}

void desenhaNave(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(1); 
}

void desenhaAsteroide(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(2);
}
void desenhaEnergia(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(4);
}
void desenhaTiro(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(5);
}
void desenhaExplosaoNave(int px, int py){
  lcd.clear();
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}
void desenhaExplosaoAsteroide(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}
void reset(){
  pontos = 0;
  venergia = 100;
  game=true;
}
void painel(int px){
  lcd.setCursor(px, 0);
  lcd.print(pontos);
  lcd.setCursor(px, 1);
  lcd.print(venergia);
}
void tela(int cond){// função de 'vitoria' ou 'derrota'
  char txt[6] = {(cond > 0 ? "GANHOU" : "PERDEU")};
  lcd.setCursor(9, 0);
  lcd.print("pts:");
  lcd.setCursor(13, 0);
  lcd.print(pontos);
  lcd.setCursor(1, 0);
  lcd.print(txt);
  lcd.setCursor(0, 1);
  lcd.print("Pressione tiro");
}



