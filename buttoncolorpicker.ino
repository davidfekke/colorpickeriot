// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

//#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();

int red, green, blue;
bool up = true;

void myHandler(const char *event, const char *data)
{
    char* dataToParse = (char*)data;
    int ipos = 0;
    int intArray[3];
    // Get the first token from the string
    char *tok = strtok(dataToParse, ",");
    // Keep going until we run out of tokens
    while (tok) {
        // Don't overflow your target array
        if (ipos < 3) {
            // Convert to integer and store it
            intArray[ipos++] = atoi(tok);
        }
        tok = strtok(NULL, ",");
    }
    
    red = intArray[0];
    green = intArray[1];
    blue = intArray[2];
  //b.allLedsOn(red,green,blue);
}

void setup() {
    Particle.subscribe("pushcolor", myHandler, MY_DEVICES);
    red = 0; 
    green = 0;
    blue = 0;
    b.begin();
}

void loop() {
    b.allLedsOn(red,green,blue);
    delay(1000);
}