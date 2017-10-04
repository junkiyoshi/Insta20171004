#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(1);

	this->size = 20;
	bool flg = true;
	for (float y = -ofGetHeight() / 2 - size; y < ofGetHeight() / 2 + size; y += this->size + this->size / 2) {
		for (float x = -ofGetWidth() / 2 - size; x < ofGetWidth() / 2 + size; x += this->size * sqrt(3)) {
			ofVec3f location;
			if (flg) {
				location = ofVec3f(x, y, 0);
			} else {
				location = ofVec3f(ofVec3f(x + (this->size * sqrt(3) / 2), y, 0));
			}

			this->particles.push_back(new Particle(location, this->size, ofColor(255)));
		}
		flg = !flg;
	}
}


//--------------------------------------------------------------
void ofApp::update(){
	ofVec3f mouse_point = ofVec3f(ofGetMouseX() - ofGetWidth() / 2, ofGetHeight() / 2 - ofGetMouseY(), 0);

	for (Particle* p : this->particles) {
		float distance = mouse_point.distance(p->get_location());

		if (distance < 100) {
			p->seek_r(mouse_point);
		}
		else {
			p->seek(p->get_start_location());
		}

		p->update();	
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	for (Particle* p : this->particles) { 
		p->draw();
	}
	
	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
