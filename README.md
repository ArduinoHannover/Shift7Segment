# Arduino-Shift7Segment
Control 7 Segment Displays easily with Shiftregisters like '595s

## Usage:
Constructor defaults to an easy wiring from the shift registers to the 7 segment display:
```
          76G54
Q0 -> •   |||||
Q1 -> C    AAA
Q2 -> D   F   B
Q3 -> E   F   B
Q4 -> B    GGG
Q5 -> A   E   C
Q6 -> F   E   C
Q7 -> G    DDD•
          |||||
          32G10
```
The default pins are data on D6, clock (SHCP) on D7 and latch (STCP) on D8. You can easily change these settings, by feeding the constructor with as many parameters as you wish to change:
```cpp
Shift7Segment mySegment = Shift7Segment(commonPinType, Q0, ..., Q7, dataPin, clockPin, latchPin);
```
commonPinType can be either `COMMON_ANODE` (default) or `COMMON_CATHODE`.
After creating a `Shift7Segment` you can access the following functions:

`mySegment.shift(uint8_t bits, [boolean order = MSBFIRST])` shift the provided bits out in the order {A, B, ... G, Dot}. Defaults to MSBFirst, but can be inverted on the fly with setting order to `LSBFIRST`.

`mySegment.to7Segment(char c, [boolean dot = false])` converts the given char to an bitpattern. You can turn the dot explicitly on, if passing `true` as second parameter which has no effect on characters like `.?!`. See list below for displayable chars.

`mySegment.show()` toggles latch high and low. Alternatively toggle it manually, so you can ignore `latchPin`.

Characters are limited:
  * `a-z` may be displayed in lower or uppercase (e.g. T is not displayable, but t; B would interfere with 8, so b is the better solution)
  * `z` and `s` map to `2` and `5`
  * `u` and `v` are the same character
  * `m` is an uppercase `N` (more like Pi `∏`)
  * `W` is an uppercase `U`, while `U` maps to lowercase `u`
  * `°` is accessible via `~` as tilde is not displayable and the degree symbol not in ASCII range
  * `()` are the same brackets as `[]`
  * Supported special chars `` /\|[]"'´`_-!?^,.@°``
  * Not displayable characters are displayed as three horizontal bars `≡`.
  * `k` looks a bit wierd (better to display as `H`?)
  
Tip: easily dim your segments using the OE-Pin of the registers and setting up an `analogWrite()`. Note that 1024 will be off and 0 will be on. Otherwise just connect the OE-Pin to GND and MR to VCC. You can chain as many registers you like by connecting `Q7S` to `DS` of the next register; just call the `shift()`-command as often as many registers you have connected.
