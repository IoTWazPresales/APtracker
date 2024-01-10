#ifndef LASTSEEN
#define LASTSEEN

#include <gpsdriver.h>

static int lastloclat;
static int lastloclng;

void lastSeenLoc() {

lastloclat= gps.location.lat();
lastloclng= gps.location.lng();

}

#endif 