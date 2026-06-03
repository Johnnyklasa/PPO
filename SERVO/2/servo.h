#ifndef SERVO_H
#define SERVO_H

enum ServoState {
   SERVO_CALLIB,
   IDDLE,
   IN_PROGRESS
};
enum DetectorState {
  ACTIVE,
  INACTIVE
};
class Servo{
	public:
	void Init();
	void Callib();
	void GoTo(unsigned int uiPosition);
	void Automate();
	private:
	enum DetectorState eReadDetector();
	void DetectorInit();
	enum ServoState eState;	
  unsigned int uiCurrentPosition;
  unsigned int uiDesiredPosition;
};


#endif

