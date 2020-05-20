#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
	for (int x = -300; x <= 300; x += 50) {

		for (int y = -300; y <= 300; y += 50) {

			auto distance = 600 - glm::length(glm::vec2(x, y));

			auto noise_value = glm::vec3(
				ofNoise(noise_seed.x, distance * 0.001 + ofGetFrameNum() * 0.008),
				ofNoise(noise_seed.y, distance * 0.001 + ofGetFrameNum() * 0.008),
				ofNoise(noise_seed.z, distance * 0.001 + ofGetFrameNum() * 0.008));

			ofPushMatrix();
			ofTranslate(x, y, 0);

			ofRotateZ(ofMap(noise_value.z, 0, 1, -180, 180));
			ofRotateY(ofMap(noise_value.y, 0, 1, -180, 180));
			ofRotateX(ofMap(noise_value.x, 0, 1, -180, 180));

			ofFill();
			ofSetColor(39);
			ofDrawBox(24);

			ofNoFill();
			ofSetColor(239);
			ofDrawBox(25);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}