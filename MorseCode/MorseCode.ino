int led = 3; 
int buzz = 4;

String str; //ovde cemo cuvati unos sa tastature preko serijal monitora
int dotLen = 100; //duzina trajanja tacke u ms
int dashLen = dotLen * 3; //duzina trajanja crte u ms
int elemPause = dotLen; //duzina pauze izmedju crte-tacke
int Spaces = dotLen * 3; //duzina pauze izmedju slova
int wordPause = dotLen * 7; //duzina pauze izmedju reci
char empty = ' '; //definisemo prazan karakter

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
}

void loop()
{
  Serial.println("Unesite string za prevodjenje na Morzeovu azbuku: ");
  while (Serial.available() == 0) {} //cekaj na unos, pa predji na slefecu liniju
  str = Serial.readString(); // sacuvaj unos u promenjivoj str
  for (int i = 0; i <= str.length() - 1; i++) {
    if (str[i] != empty); {
      Serial.print("\n---"); //preskoci red pa ispisi ---
      Serial.print(str[i]); //ispisi  slovo koje se prevodi
      Serial.println("---"); // ispisi ---
      char tmpChar = str[i]; //sacuvaj trenutni karakter u promenjivu tmpChar
      tmpChar = toLowerCase(tmpChar); //ukoliko je karakter veliko slovo konvertuje se u malo, radi dalje realizacije programa
      GetChar(tmpChar); // pozicavmo GetChar
    }
  }
  LightsOff(1000);
  Serial.println("\nZavrseno prevodjenje.\n");
}
// Tacka
void MorseDot()
{
  digitalWrite(led, HIGH);  	
  Serial.println("Tacka");
  digitalWrite(buzz, HIGH);
  delay(dotLen);
}

// Crta
void MorseDash()
{
  digitalWrite(led, HIGH);  	
  Serial.println("Crta");
  digitalWrite(buzz, HIGH);
  delay(dashLen); 
}

// Gasenje
void LightsOff(int delayTime)
{
  digitalWrite(led, LOW);    	
  digitalWrite(buzz, LOW);       	   	
  delay(delayTime);            
}

// *** Konverzija karaktera u morzeovu azbuku *** //
void GetChar(char tmpChar)
{
  // Proslijedjeni karakter iz seriala, saljemo u metodu GetChar, koja dalje uporedjuje proslijedjeno slovo sa svim case-ovima i ukoliko se poklopi ispisuje odgovarajuce tacke-crte
  switch (tmpChar) {
    case 'a':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'b':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'c':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'd':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'e':
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'f':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'g':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'h':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'i':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'j':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'k':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'l':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'm':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'n':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'o':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'p':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 'q':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'r':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 's':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    case 't':
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'u':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'v':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'w':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'x':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'y':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    case 'z':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
      case '1':
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
      case '2':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
      case '3':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
      case '4':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
      case '5':
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
      case '6':
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
      case '7':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
      case '8':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
      case '9':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
      case '0':
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    default:
      LightsOff(Spaces);
      Serial.println("Bato, nesto se pokvarilo :)");
  }
}

/* Cesto koriscene skracenice u morzeovoj azbuci: 
AA	sve posle (koristi se nakon znaka pitanja kao zahtev za ponavljanje)
AB	sve pre (slično)
ARRL	Američki radio-amaterski savez
ABT	oko, u smislu približno
ADS	adresa
AGN	ponovo
ANT	antena
BN	sve između
BK	pauza - Break (da se pauzira prenošenje poruke, reći)
BUG	Poluautomatski mehanički taster
C	da
CBA	adresa u imeniku
CFM	potvrda
CLG	Zove
CQ	poziv svim stanicama
CQD	stari poziv u pomoć
CS	pozivni znak
CUL	vidimo se kasnije
CUZ	jer
CW	telegrafija Continuous wave
CX	Uslovi
DE	od
DSW	doviđenja (ruski: Dosvidanja)
DX	razdaljina (često se koristi da označi veze sa udaljenim mestima)
ES	i
FB	Dobar posao (analogno sa "OK")
FCC	Savezna komisija za komunikacije (SAD)
FER	za
FM	od
FREQ	frekvencija
GA	Dobar dan ili samo napred (zavisno od konteksta)
GE	dobro veče
GM	dobro jutro
GND	Uzemljenje
GUD	dobro
HIHI	smeh
HR	ovde
HV	imati
LID	loš operater
MILS	mili-amperi
NIL	ništa
NR	broj
OB	staro momče - Old boy
OC	stari prijatelju - Old chap
OM	stari - Old man (svakom muškom operateru se govori OM)
OO	Zvanični posmatrač
OP	Operator
OT	starina - Old timer
OTC	Klub veterana
OOTC	Klub staraca Old old timers club
PSE	molim
PWR	Snaga
QCWA	Četvrt veka bežične asocijacije Quarter Century Wireless Association
R	I oznaka decimalne tačke (zavisi od konteksta. Potiče od reči "Roger")
RCVR	prijemnik
RIG	Radio uređaj
RPT	ponovi ili raport (zavisno od konteksta)
RPRT	raport
RST	ocena signala u 3 broja (razumljivost, snaga, ton) Signal report format (Readability-Signal Strength-Tone)
RTTY	Radioteleprinter
RX	prijemnikReceive
SAE	lično adresirana koverta
SASE	lično adresirana, štampana koverta
SED	rekao
SEZ	Kaže
SIG	signal
SIGS	signali
SKED	Raspored
SN	uskoro
SMS	kratka poruka Short message service
SOS	međunarodni poziv u pomoć
SRI	izvini
STN	stanica
TEMP	temperatura
TMW	sutra
TNX	hvala
TU	hvala ti
TX	predajnik Transmit, transmiter
U	ti
UR	tvoj ili ti si (zavisno od konteksta)
URS	tvoj
VY	veoma
W	vati
WDS	reči
WKD	radio
WL	Will
WUD	bih
WX	vreme, meteorološki Weather
XMTR	primopredajnik
XYL	supruga
YL	mlada dama (koristi se za sve žene radio-amatere)
73	puno pozdrava
88	ljubav i poljupci */
