#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <Godot.hpp>
#include <Node2D.hpp>
#include <SceneTree.hpp>

namespace godot {

    class UIManager: public Node2D {

        GODOT_CLASS(UIManager, Node2D)

    private:
        String scenePath;
        float secondsPassed;

    public : static void _register_methods();

        UIManager();
        ~ UIManager();

        void _init();
        void changescene();
    };
}

#endif // UIMANAGER_H