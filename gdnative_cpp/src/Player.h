#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <Input.hpp>
#include <Axe.h>

namespace godot {

    class Player: public Sprite {

        GODOT_CLASS(Player, Sprite)

    private:

        Vector2 extents;

    public : static void _register_methods();

        Player();
        ~ Player();

        void _init();
        void _ready();
        void _process(float delta);

        void die();
        void movement();
    };
}

#endif // PLAYER_H
