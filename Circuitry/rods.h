#ifndef __rods_h_INCLUDED__
#define __rods_h_INCLUDED__
class rods {
public:
	void initialize(int pin);
	int read();
	rods(const uint8_t);
private:
	uint8_t rodPin;
	int sensorVal;
	int outputVal;
};
#endif // !__rods_h_INCLUDED__