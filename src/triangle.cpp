// SPDX-License-Identifier:  GPL-2.0-or-later
/*
 * Copyright (C) 2020 Rohan Garg <rohan@garg.io>
 */

#include "triangle.h"


//------------------------------------------------------------------
Triangle::Triangle(TriangleDirection direction){
        m_direction = direction;
        m_left.x = 0;
        m_right.x = ofGetWidth();
        m_color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 100);

        switch(m_direction) {
                case TriangleDirection::Up:
                        m_right.y = m_left.y = ofGetHeight();
                        break;
                case TriangleDirection::Down:
                        m_right.y = m_left.y = 0;
                        break;
                case TriangleDirection::Undefined:
                default:
                        ofLog() << "Invalid direction";
                        break;

        }
        m_color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 100);
}

void Triangle::update()
{
        switch (m_direction) {
                case TriangleDirection::Up:
                        m_head.y -= 1;
                        m_left.y -= 1;
                        m_right.y -= 1;
                        break;
                case TriangleDirection::Down:
                        m_head.y += 1;
                        m_left.y += 1;
                        m_right.y += 1;
                        break;
                default:
                        ofLog() << "Invalid direction";
                        assert(0);
        }
}

//------------------------------------------------------------------
void Triangle::draw() {
        ofSetColor(m_color);
        ofDrawTriangle(m_left, m_head, m_right);
}

void Triangle::setHeight(int height)
{
        m_height = height;
        switch (m_direction) {
                case TriangleDirection::Up:
                        m_right.y += m_height + m_head.y;
                        break;
                case TriangleDirection::Down:
                        m_right.y -= m_height - m_head.y;
                        break;
                case TriangleDirection::Undefined:
                default:
                        ofLog() << "Invalid direction";
                        assert(false);
        }
        m_left.y = m_right.y;
}

void Triangle::setHead(ofPoint head)
{
        m_head = head;
}

void Triangle::setDirection(TriangleDirection direction)
{
        m_direction = direction;
}