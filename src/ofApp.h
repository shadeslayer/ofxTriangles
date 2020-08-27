// SPDX-License-Identifier:  GPL-2.0-or-later
/*
 * Copyright (C) 2020 Rohan Garg <rohan@garg.io>
 */

#pragma once

#include "ofMain.h"
#include "triangle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

	private:
		const int m_numTriangles = 100;
		vector<Triangle *> m_Triangles;
};
