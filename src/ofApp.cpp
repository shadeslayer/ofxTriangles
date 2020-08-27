// SPDX-License-Identifier:  GPL-2.0-or-later
/*
 * Copyright (C) 2020 Rohan Garg <rohan@garg.io>
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        ofSetLogLevel(OF_LOG_VERBOSE);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);

        ofSetVerticalSync(true);
        ofBackground(0);
        ofPoint bottomHead, topHead;
        bottomHead.x = ofGetWidth() / 2;
        bottomHead.y = ofGetHeight();
        topHead.x = bottomHead.x;
        topHead.y = 0;

        Triangle *tmp;
        for (int i = 0; i < m_numTriangles / 2; i++) {
                if (i%2 == 0) {
                        tmp = new Triangle(TriangleDirection::Up);
                        tmp->setHead(bottomHead);
                        bottomHead.y += 100;
                } else {
                        tmp = new Triangle(TriangleDirection::Down);
                        tmp->setHead(topHead);
                        topHead.y -= 100;
                }
                tmp->setHeight(300);
                m_Triangles.push_back(tmp);
        }
}

//--------------------------------------------------------------
void ofApp::update(){
        for(Triangle *tmp : m_Triangles) {
                tmp->update();
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
        for(Triangle *tmp : m_Triangles){
                tmp->draw();
        }
}

void ofApp::exit() {
        for (Triangle *tmp : m_Triangles){
                delete tmp;
        }
}