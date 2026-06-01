#ifndef WATCH_H
#define WATCH_H

class Watch{
public:
	char fSecondsChanged;
	unsigned char ucSeconds;
  char fMinutesChanged;   
  unsigned char ucMinutes;
	static void Update();

};

#endif
