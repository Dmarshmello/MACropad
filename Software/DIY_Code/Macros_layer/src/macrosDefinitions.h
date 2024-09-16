#ifndef MACROS_DEFINITIONS_H
#define MACROS_DEFINITIONS_H

#include <HID-Project.h> // Include the required library

// ----------- BROWSER MACROS -----------

void openNewGoogleTab() {
    BootKeyboard.press(KEY_LEFT_CTRL);
    BootKeyboard.press('t');
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.print("https://www.google.com");
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void openMoodle() {
    BootKeyboard.press(KEY_LEFT_GUI);
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.print("Google Chrome");
    delay(200);
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.print("https://learning.monash.edu/my/");
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void closeTab() {
    BootKeyboard.press(KEY_LEFT_CTRL);
    BootKeyboard.press('w');
    delay(100);
    BootKeyboard.releaseAll();
}

void openTab() {
    BootKeyboard.press(KEY_LEFT_CTRL);
    BootKeyboard.press('t');
    delay(100);
    BootKeyboard.releaseAll();
}

void cntrlShiftT() {
    BootKeyboard.press(KEY_LEFT_CTRL);
    BootKeyboard.press(KEY_LEFT_SHIFT);
    BootKeyboard.press('t');
    delay(100);
    BootKeyboard.releaseAll();
}

// ----------- SYSTEM CONTROL MACROS -----------

void putComputerToSleep() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press('x');
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.press('u');
    delay(100);
    BootKeyboard.press('s');
    BootKeyboard.releaseAll();
}

void minimizeWindow() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press(KEY_DOWN_ARROW);
    delay(100);
    BootKeyboard.releaseAll();
}

void screenCapture() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press(KEY_LEFT_SHIFT);
    BootKeyboard.press('s');
    delay(100);
    BootKeyboard.releaseAll();
}

void volumeUp() {
    Consumer.write(MEDIA_VOLUME_UP);
}

void volumeDown() {
    Consumer.write(MEDIA_VOLUME_DOWN);
}

void mute() {
    Consumer.write(MEDIA_VOLUME_MUTE);
}

// ----------- APPLICATION LAUNCH MACROS -----------

void openSpotify() {
    BootKeyboard.press(KEY_LEFT_GUI);
    delay(100);
    BootKeyboard.releaseAll();
    delay(200);
    BootKeyboard.print("Spotify");
    delay(200);
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void openCalculator() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press('r');
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.print("calc");
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void cameraOnOff() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press('r');
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.print("camera");
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void openVScode() {
    BootKeyboard.press(KEY_LEFT_GUI);
    delay(100);
    BootKeyboard.releaseAll();
    delay(400);
    BootKeyboard.print("Visual Studio Code");
    delay(600);
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void openDiscord() {
    BootKeyboard.press(KEY_LEFT_GUI);
    delay(100);
    BootKeyboard.releaseAll();
    delay(400);
    BootKeyboard.print("Disco");
    delay(500);
    BootKeyboard.press(KEY_RETURN);
    delay(100);
    BootKeyboard.releaseAll();
}

// ----------- SYSTEM TOGGLE MACROS -----------

void micOnOff() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press(KEY_LEFT_ALT);
    BootKeyboard.press('k');
    delay(100);
    BootKeyboard.releaseAll();
}

void bluetooth() {
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press('a');
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);
    BootKeyboard.press(KEY_RIGHT);
    delay(100);
    BootKeyboard.releaseAll();
    BootKeyboard.press(KEY_RETURN);
    delay(100);
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press('a');
    BootKeyboard.releaseAll();
}

// ----------- MEDIA CONTROL MACROS -----------

// Next Song
void nextSong() {
    Consumer.write(MEDIA_NEXT);
}

// Previous Song
void previousSong() {
    Consumer.write(MEDIA_PREVIOUS);
}

// Play/Pause
void playPause() {
    Consumer.write(MEDIA_PLAY_PAUSE);
}

// Stop
void stop() {
    Consumer.write(MEDIA_STOP);
}

// Mute/Unmute
void muteUnmute() {
    Consumer.write(MEDIA_VOLUME_MUTE);
}

// Fast Forward
void fastForward() {
    Consumer.write(MEDIA_FAST_FORWARD);
}

// Rewind
void rewind() {
    Consumer.write(MEDIA_REWIND);
}


void openMonashSpecialConsiderationForm() {
    // Open a new tab
    BootKeyboard.press(KEY_LEFT_CTRL);
    BootKeyboard.press('t');
    delay(100);
    BootKeyboard.releaseAll();
    delay(500);

    // Navigate to the URL
    BootKeyboard.print("https://forms.monash.edu/special-consideration");
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.releaseAll();
}

void MAC() {
    BootKeyboard.print("I ");
    BootKeyboard.press(KEY_LEFT_GUI); 
    BootKeyboard.press('.');
    delay(400); 
    BootKeyboard.releaseAll();
    BootKeyboard.print("heart");
    delay(400);
    BootKeyboard.press(KEY_RETURN);
    BootKeyboard.press(KEY_ESC);
    delay(200);
    BootKeyboard.releaseAll();
    BootKeyboard.print(" MAC");
    BootKeyboard.releaseAll();
}

#endif
