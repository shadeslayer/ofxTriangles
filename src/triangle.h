// SPDX-License-Identifier:  GPL-2.0-or-later
/*
 * Copyright (C) 2020 Rohan Garg <rohan@garg.io>
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ofMain.h"

enum TriangleDirection {
        Up = 0,
        Down,
        Right,
        Left,
        Undefined
};

class Triangle {
        public:
                Triangle(TriangleDirection direction);
                void update();
                void draw();
                void setHeight(int height);
                void setHead(ofPoint head);
                void setDirection(TriangleDirection direction);
        private:
                ofPoint m_left;
                ofPoint m_right;
                ofPoint m_head;
                ofColor m_color;
                TriangleDirection m_direction = TriangleDirection::Undefined;
                int m_height;
};

#endif // TRIANGLE_H
