#ifndef ROTATEME_H
#define ROTATEME_H

#include <Godot.hpp>
#include <Sprite.hpp>

namespace godot {

    class RotateMe: public Sprite {

        GODOT_CLASS(RotateMe, Sprite)

    private : 
        float rotateSpeed;
        
    public : static void _register_methods();

        RotateMe();
        ~ RotateMe();

        void _init();
        void _process(float delta);

        void rotate();
    };
}

#endif // ROTATEME_H