#include "Shift7Segment.h"

Shift7Segment::Shift7Segment(uint8_t q0, uint8_t q1, uint8_t q2, uint8_t q3, uint8_t q4, uint8_t q5, uint8_t q6, uint8_t q7, uint8_t data, uint8_t clock, uint8_t latch) : Q0(q0), Q1(q1), Q2(q2), Q3(q3), Q4(q4), Q5(q5), Q6(q6), Q7(q7), dataPin(data), clockPin(clock), latchPin(latch) {
	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	digitalWrite(latchPin, LOW);
	digitalWrite(clockPin, LOW);
}
Shift7Segment::~Shift7Segment() {
	
}
void Shift7Segment::show() {
	digitalWrite(latchPin, HIGH);
	digitalWrite(latchPin, LOW);
}
void Shift7Segment::shift(uint8_t bits, boolean order) {
	for (int i = order?0:7; order?(i < 8):(i >= 0); order?i++:i--) {
		digitalWrite(dataPin, (bits >> *segmentPins[i]) & 1);
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);
	}
}

uint8_t Shift7Segment::to7Segment(char character, boolean dot) {
	uint8_t bits;
	if (character >= 'A' && character <= 'Z') {
		character -= 'A' - 'a';
	}
	if (character >= '0' && character <= '9') {
		character -= '0';
	}
	/*
	Pattern:
	 555
	6   4
	6   4
	 777
	3   5
	3   1
	 222  0
	 
	-> 0b01234567;
	*/
	switch (character) {
	case 0:
		bits = 0b01111110;break;
	case 1:
		bits = 0b01001000;break;
	case 2:
	case 'z':
		bits = 0b00111101;break;
	case 3:
		bits = 0b01101101;break;
	case 4:
		bits = 0b01001011;break;
	case 5:
	case 's':
		bits = 0b01100111;break;
	case 6:
		bits = 0b01110111;break;
	case 7:
		bits = 0b01001100;break;
	case 8:
		bits = 0b01111111;break;
	case 9:
		bits = 0b01101111;break;
	case 'a':
		bits = 0b01011111;break;
	case 'b':
		bits = 0b01110011;break;
	case 'c':
		bits = 0b00110001;break;
	case 'd':
		bits = 0b01111001;break;
	case 'e':
		bits = 0b00110111;break;
	case 'f':
		bits = 0b00010111;break;
	case 'g':
		bits = 0b01110110;break;
	case 'h':
		bits = 0b01010011;break;
	case 'i':
	case '|':
		bits = 0b00010010;break;
	case 'j':
		bits = 0b01111100;break;
	case 'k':
		bits = 0b01010111;break;
	case 'l':
		bits = 0b00110010;break;
	case 'm':
		bits = 0b01011110;break;
	case 'n':
		bits = 0b01010001;break;
	case 'o':
		bits = 0b01110001;break;
	case 'p':
		bits = 0b00011111;break;
	case 'q':
		bits = 0b01001111;break;
	case 'r':
		bits = 0b00010001;break;
	case 't':
		bits = 0b00110011;break;
	case 'u':
	case 'v':
		bits = 0b01110000;break;
	case 'w':
		bits = 0b01111010;break;
	case 'x':
		bits = 0b01011011;break;
	case 'y':
		bits = 0b01001011;break;
	case ' ':
		bits = 0;break;
	case '.':
		bits = 0b10000000;break;
	case '-':
		bits = 0b00000001;break;
	case '_':
		bits = 0b00100000;break;
	case '=':
		bits = 0b00100001;break;
	case '/':
		bits = 0b00011001;break;
	case '\\':
		bits = 0b01000011;break;
	case '(':
	case '[':
		bits = 0b00110110;break;
	case ')':
	case ']':
		bits = 0b01101100;break;
	case '"':
		bits = 0b00001010;break;
	case '\'':
		bits = 0b00000010;break;
	case '´':
		bits = 0b00000110;break;
	case '`':
		bits = 0b00001100;break;
	case '!':
		bits = 0b10001000;break;
	case '^':
		bits = 0b00001110;break;
	case '~':
		bits = 0b00001111;break;
	case ',':
		bits = 0b01000000;break;
	case '@':
		bits = 0b01111101;break;
	case '?':
		bits = 0b10001100;break;
	default:
		bits = 0b00100101;break;
	}
	bits |= dot << 7;
	return bits;
}
