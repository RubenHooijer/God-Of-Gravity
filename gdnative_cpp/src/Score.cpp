#include "Score.h"

using namespace godot;

void Score::_register_methods() {
    register_method("_process", &Score::_process);
    register_method("stopCounting", &Score::stopCounting);

}

Score::Score() : secondsPassed(0)
{
}

Score::~Score() {
    // add your cleanup here
}

void Score::_init() {

}

void Score::_process(float delta){
    secondsPassed += delta;
    int intSeconds = static_cast<int>(secondsPassed);
    int minutes = intSeconds/60;
    int seconds = intSeconds % 60;

    String minutesText = minutes < 10 ? "0" + get_string(minutes) : get_string(minutes);
    String secondsText = seconds < 10 ? "0" + get_string(seconds) : get_string(seconds);

    set_text("0:" + minutesText + ":" + secondsText);
}

//Solution from Nathan Nieuwenhuizen (I didn't remember the better solution)
String Score::get_string(int value){
    
    return String(Vector2(0, (real_t)value)).right(3);
}

void Score::stopCounting(){
    set_process(false);
}
