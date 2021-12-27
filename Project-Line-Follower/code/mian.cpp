#include <mega16a.h>
#include <delay.h>



#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | 
(0<<ADLAR))

unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;

delay_us(10);

ADCSRA|=(1<<ADSC);

while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}
void main(void)
{

 int S=0;


Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | 
(0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);

PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | 
(0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) 
| (0<<PORTA0);


Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | 
(0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);


PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | 
(0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | 
(0<<PORTB1) | (0<<PORTB0);


Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | 
(0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);

PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | 
(0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | 
(0<<PORTC1) | (0<<PORTC0);


Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | 
(1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);

PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | 
(0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | 
(0<<PORTD1) | (0<<PORTD0);


TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | 
(0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;





TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | 
(0<<COM1B0) | (0<<WGM11) | (1<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) 
| (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;


ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | 
(0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;


TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | 
(0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);


MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);


UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | 
(0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);


ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) 
| (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);


ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | 
(0<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0);
SFIOR=(0<<ADTS2) | (0<<ADTS1) | (0<<ADTS0);


SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | 
(0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);



TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | 
(0<<TWIE);
 PORTD.0=1;
 PORTD.1=0;
 PORTD.2=0;
 PORTD.3=1; 
 OCR1AL=0;
 OCR1BL=0;
while (1)
 {


 
 S=0;
 if(read_adc(6)>500)S+=1;
 if(read_adc(5)>500)S+=2; 
 if(read_adc(4)>500)S+=4;
 if(read_adc(3)>500)S+=8;
 if(read_adc(2)>600)S+=16;
 if(read_adc(0)>700)S+=32;
 if(read_adc(1)>500)S+=64;
 
 switch(S){
 case 0b0001000:
 PORTD.0=1;
 PORTD.1=0;
 PORTD.2=0;
 PORTD.3=1;
 OCR1AL=125;
 OCR1BL=125;
 break;
 case 0b0000100:
 PORTD.0=1;
 PORTD.1=0;

 PORTD.2=0;
 PORTD.3=1;
 OCR1AL=80;
 OCR1BL=125;
 break; 
 
 case 0b0000010:
 PORTD.0=1;
 PORTD.1=0;
 PORTD.2=0;
 PORTD.3=1; 
 OCR1AL=45;
 OCR1BL=125;
 break; 
 case 0b0000001:
 PORTD.0=1;
 PORTD.1=0;
 PORTD.2=1;
 PORTD.3=0;
 OCR1AL=125;
 OCR1BL=125;
 break; 
 
 
 
 case 0b0010000:
 PORTD.0=1;
 PORTD.1=0;
 PORTD.2=0;
 PORTD.3=1;
 OCR1AL=125;
 OCR1BL=80;
 break;
 
 case 0b0100000:
 PORTD.0=1;
 PORTD.1=0;

 PORTD.2=0;
 PORTD.3=1;
 OCR1AL=125;
 OCR1BL=45;
 break; 
 
 case 0b1000000:
 PORTD.0=0;
 PORTD.1=1;
 PORTD.2=0;
 PORTD.3=1;
 OCR1AL=125;
 OCR1BL=125;
 break;
 
 default :
 break;
 }
 }
}