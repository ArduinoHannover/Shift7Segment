#ifndef SHIFT7SEGMENT_H
#define SHIFT7SEGMENT_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define SegmentA 2
#define SegmentB 3
#define SegmentC 6
#define SegmentD 5
#define SegmentE 4
#define SegmentF 1
#define SegmentG 0
#define DOT 7

#define COMMON_ANODE true
#define COMMON_CATHODE false

class Shift7Segment {
	private:
	uint8_t
		Q0,
		Q1,
		Q2,
		Q3,
		Q4,
		Q5,
		Q6,
		Q7,
		*segmentPins[8] = {&Q7, &Q6, &Q5, &Q4, &Q3, &Q2, &Q1, &Q0},
		dataPin,
		clockPin,
		latchPin;
	boolean
		commonType;
	
	public:
		Shift7Segment(boolean type = COMMON_ANODE, uint8_t q0 = DOT, uint8_t q1 = SegmentC, uint8_t q2 = SegmentD, uint8_t q3 = SegmentE, uint8_t q4 = SegmentB, uint8_t q5 = SegmentA, uint8_t q6 = SegmentF, uint8_t q7 = DOT, uint8_t data = 6, uint8_t clock = 7, uint8_t latch = 8);
		~Shift7Segment();
		void
			shift(uint8_t bits, boolean order = MSBFIRST),
			show();
		uint8_t 
			to7Segment(char c, boolean dot = false);
};

#endif //SHIFT7SEGMENT_H
