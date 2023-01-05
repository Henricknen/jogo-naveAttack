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

byte nave[8]={B11000,B01100,B01110,B01111,B01111,B01110,B01100,B11000};
byte asteroide[8] = {B00000,B00100,B01110,B10111,B11101,B01110,B00100,B00000};
byte explosao[8] = {B10001,B10101,B01010,B10100,B00101,B01010,B10101,B10001};
byte energia[8] = {B01110,B11011,B10001,B10101,B10101,B10101,B10001,B11111};
byte tiro[8] = {B00000,B00000,B00000,B00111,B00111,B00000,B00000,B00000};

void setup() {
  pxnave = pynave = pyaste = pontos = pxenergia = pyenergia = pytiro = 0;		// fazendo a iniçiaização dos elementos
  pxtiro = -1;
  pxaste = 12;
  venergia = 100;
  lcd.createChar(1,nave);		// criando caracters dos elementos (nvae, tiro, asteroide etc)
  lcd.createChar(2, asteroide);
  lcd.createChar(3, explosao);
  lcd.createChar(4, energia);
  lcd.createChar(5, tiro);
  lcd.begin(16, 2);
  lcd.clear();
  game = false;		// o jogo iniciará em 'false' para não começar jogando
  vtiro = vpilha = false;
}

void loop(){
  if(game){
    venergia -= 0.25;
    lcd.clear();
    lcd.painel(13);		// redesenhando 'painel' após redesenha a tela
    if(digitalRead(btcima) == 1){
      pynave = 0;		// se 'btcima' for prwcionado a nav irá para linha de cima
    } else if(digitalRead(btbaixo) == 1){
      pynave = 1;		// ou para baixo se 'btbaixo' for precionado
    } else if(digitalRead(bttiro) == 1){
      pxtiro = 1;
      vtiro = true		// função sabe que foi disparado um tiro
      pytiro = pynave;		// o tiro recebe mesma posição da nave
    }
    pxaste -= 1;		// '-1' para o asteroide sempre andar para esquerda
    
    desenhaNave(pxnave, pynave);		// desenhando a nave
    desenhaAsteroide(pxaste, pyaste);		// desenhanhado o asteroide
    if(vtiro){
      desenha(pxtiro, pytiro);
      pxtiro += 1;		// deslocando tiro para direita
    }
    if(pxate < 0){
      pxaste = 12;		// asteroide volta para direita
      pyaste = random(0, 2);	// definido nova posição e sorteando com função 'random'
    }
    if(pxtiro > 16){		// quando o tiro sair da tela
      vtitro = false;	// é parado de ser processado
      pxtiro -= 1;
    }
    
    delay(vel);
  }else{
    tela(0);		//  o 'else' indica que o jogo não está rolando e chamará a função 'tela'
    if(digitalRead(bttiro) == 1){
      reset();
  	}
  }
  
}

void desenhaNave(int px, int py){
  lcd.setCursor(px,py);
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
void reset(){		// função 'reset' irá definir o jogo
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
void tela(int cond){// função de 'tela inicial, vitoria ou derrota'
  if(cond < 1){
    lcd.setCursor(3, 0);
  	lcd.print("NAVE ATTACK");
    lcd.print("Pressione tiro");		// para iniciar o jogo
  }else{    
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
}



