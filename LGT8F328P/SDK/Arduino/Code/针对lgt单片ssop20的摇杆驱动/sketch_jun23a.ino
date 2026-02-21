#define DrvMISC_DisableSWD() do { MCUSR = 0xff; MCUSR = 0xff; } while(0)

void setup() {
  DrvMISC_DisableSWD();
  int btmp;
  btmp = PMX2 | (E6EN << 1) | C6EN;
  PMX2 = 0x80;
  PMX2 = btmp;

Serial.begin(115200);
Serial.println("*************************************");

analogReference(DEFAULT);

}
 int pc0read(){

int ADC;
  ADMUX = B11000000;
  ADCSRA |= (1 << ADEN);
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); 
  ADCSRA |= (1 << ADSC);
  while (!(ADCSRA & (1 << ADIF)));
  ADC =(ADCH << 8) | ADCL;
  ADCSRA |= (1 << ADIF);
  return ADC;
}
 int pc1read(){
  ADMUX = B11000001;
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); 
  ADCSRA |= (1 << ADSC);
  ADCSRA |= (1 << ADIF);
  return ADC;
}
 int pe3read(){
  ADMUX = B11000111;
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); 
  ADCSRA |= (1 << ADSC);
  while (!(ADCSRA & (1 << ADIF)));
  ADCSRA |= (1 << ADIF);
  return ADC;
}
  
void loop() {
 Serial.println("=====================================");
  Serial.println(pc1read());  
  Serial.println(pc0read());  
  Serial.println(pe3read());  
  Serial.println("=====================================");
  Serial.println(PMX2); 
   Serial.println(MCUSR); 
  
  // put your main code here, to run repeatedly:
  delay(1000); 

}
