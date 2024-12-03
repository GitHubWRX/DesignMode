#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "../../common.h"

// DVD播放器
class DVDPlayer {
public:
    void on() { cout << "DVD Player is ON." << endl; }
    void play(string movie) { cout << "Playing movie: " << movie << endl; }
    void off() { cout << "DVD Player is OFF." << endl; }
};

// 音响
class Amplifier {
public:
    void on() { cout << "Amplifier is ON." << endl; }
    void setVolume(int level) { cout << "Volume set to " << level << endl; }
    void off() { cout << "Amplifier is OFF." << endl; }
};

// 投影仪
class Projector {
public:
    void on() { cout << "Projector is ON." << endl; }
    void setInput(string input) { cout << "Projector input set to: " << input << endl; }
    void off() { cout << "Projector is OFF." << endl; }
};

// 灯光
class Light {
public:
    void dim(int level) { cout << "Lights dimmed to " << level << "%" << endl; }
    void on() { cout << "Lights are ON." << endl; }
};

#endif