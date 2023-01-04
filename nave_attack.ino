#include <LiquidCrystal.h>		// fazendo include da bibioteca 'LiquidCrystal'

#define btcima 8		// 'definição' dos botões
#define btbaixo 9
#define bttiro 10

LiquidCrystal.lcd(7, 6, 5, 4, 3, 2);	// objeto do tipo 'LiquidCrystal'

int vel = 100;		// variável de veloçidade
int pxnave, pynave, pxaste, pyaste, pxenergia, pyenergia, pxtiro, pytiro;		// variável de posição dos elementos do jogo
bool game, vtiro, vpilha;		// variáveis boleana que recebe 'true', 'false' ou '0' e '1'
int pontos;
double venergia;

byte nave[8]={ B11000, B01100, B01110, B01111, B01111, B01110, B01100, B11000};
byte asteroide[8]={ B00000, B00100, B01110, B10111, B11101, B01110, B00100, B00000};
byte explosao[8]={B10001,B10101,B01010,B10100,B00101,B01010,B10101,B10001};
byte energia[8]={B01110,B11011,B10001,B10101,B10101,B10101,B10001,B11111};
byte tiro[8]={B00000,B00000,B11110,B01111,B11110,B00000,B00000,B00000};

void setup(){
  pxnave = pynave = pontos = pyaste = pxenergia = pyenergia  = pytiro = 0;
  pxtiro = -1;		// '-1' indica que o tiro está la mas so que estará fora da tela
  pxaste = 12;			// o asteroide iniçiará na posição 12
  energia = 100;			// iniçiará cheia
  
  lcd.createChar(1, nave);		// criação do caracteres do jogo
  lcd.createChar(2, asteroide);
  lcd.createChar(3, explosao);
  lcd.createChar(4, energia);
  lcd.createChar(5, tiro);
  lcd.begin(16, 2);		// iniçializando o tamaho do display
  lcd.clear();
  game = true;		// 'true' indica que o game está em funcionamento
  vtiro = vpilha = false;		// inidia que o jogo iniçiara sem tiro ou pilha na tela
}

void loop(){
  }