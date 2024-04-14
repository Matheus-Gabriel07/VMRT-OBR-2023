#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class button {
private:
    byte debounce;
    unsigned long nextRead;
    bool _hasEstade;

    void init() {
        pinMode(pin, INPUT_PULLUP);
    }

public:
    byte pin;
    bool estado;

    button(byte _pin, byte _debounce = 10) {
        this->pin = _pin;
        this->debounce = _debounce;
        this->init();
    }

    bool read() {
        if (millis() > nextRead && digitalRead(pin) != estado) {
            estado = !estado;
            _hasEstade = true;
            nextRead = millis() + debounce;
        }
        return estado;
    }

    bool hasEstade() {
        read();
        if (_hasEstade) {
            _hasEstade = true;
            return true;
        }
        return false;
    }

    bool pressed() {  //Se esta precionado
        read();
        return !estado;
    }

    bool released() {  //Se esta solto
        read();
        return estado;
    }

    bool risingEdge() {  //Indica se houve uma borda de subida
        return !read() && hasEstade();
    }

    bool fallingEdge() {  //Indica se houve uma borda de descida
        return read() && hasEstade();
    }

    void waitForPress(void (*doWhileWait)() = ([]() -> void {})) {  //Espera o botão ser pressionado enquando executa uma ação
        while (!pressed()) {
            doWhileWait();
        }
    }


    void waitForRealease(void (*doWhileWait)() = ([]() -> void {})) {  //Espera o botão ser solto enquando executa uma ação
        while (!released()) {
            doWhileWait();
        }
    }

    void waitForPressAndRealease(void (*doBeforePress)() = ([]() -> void {}), void (*doBeforeRealease)() = ([]() -> void {})) {  //Espera o botão ser pressionado enquanto executa uma ação e depois espera ser solto executando outra ação (lambda)
        while (!pressed()) {
            doBeforePress();
        }
        while (!released()) {
            doBeforeRealease();
        }
    }
};

#endif