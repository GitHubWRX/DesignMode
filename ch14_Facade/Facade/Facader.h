#ifndef FACADER_H
#define FACADER_H

#include "Components.h"

class HomeTheaterFacade {
private:
    DVDPlayer* dvdPlayer;
    Amplifier* amplifier;
    Projector* projector;
    Light* light;

public:
    HomeTheaterFacade(DVDPlayer* dvd, Amplifier* amp, Projector* proj, Light* light)
        : dvdPlayer(dvd), amplifier(amp), projector(proj), light(light) {}

    void watchMovie(string movie) {
        cout << "Preparing to watch a movie..." << endl;
        light->dim(20);
        projector->on();
        projector->setInput("DVD");
        amplifier->on();
        amplifier->setVolume(10);
        dvdPlayer->on();
        dvdPlayer->play(movie);
        cout << "Enjoy your movie!" << endl;
    }

    void endMovie() {
        cout << "Shutting down the home theater..." << endl;
        dvdPlayer->off();
        amplifier->off();
        projector->off();
        light->on();
    }
};

#endif