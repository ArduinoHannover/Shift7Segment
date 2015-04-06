/*
 * Default Wiring of 7 Segments to '595s:
 *           76G54
 * Q0 -> •   |||||
 * Q1 -> C    AAA
 * Q2 -> D   F   B
 * Q3 -> E   F   B
 * Q4 -> B    GGG
 * Q5 -> A   E   C
 * Q6 -> F   E   C
 * Q7 -> G    DDD•
 *           |||||
 *           32G10
 *
 * Default Wiring of '595s to Arduino:
 * Data:  D6
 * Clock: D7
 * Latch: D8
 */
Shift7Segment segment = Shift7Segment();

void setup() {
}

void loop() {
  //Show all characters from space on (has some non-displayable chars)
  for (char c = ' '; c < 'a'; c++) {
    segment.begin();
    segment.shift(segment.to7Segment(c));
    segment.show();
    delay(500);
  }
}
