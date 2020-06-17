#ifndef SCORE_H
#define SCORE_H

#include <Godot.hpp>
#include <RichTextLabel.hpp>

namespace godot {

    class Score: public RichTextLabel {

        GODOT_CLASS(Score, RichTextLabel)

    private:
        float secondsPassed;

    public : static void _register_methods();

        Score();
        ~ Score();

        void _init();
        void _process(float delta);

        String get_string(int);
        void stopCounting();
    };
}

#endif // SCORE_H