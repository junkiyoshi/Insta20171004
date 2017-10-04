#include "Particle.h"

Particle::Particle() : Particle(ofVec3f(0, 0, 0), 10, ofColor(255)) {

}

Particle::Particle(ofVec3f location, float size, ofColor body_color) {
	this->location = location;
	this->start_location = location;
	this->velocity = ofVec3f();
	this->acceleration = ofVec3f();
	
	this->size = size;

	this->radius = radius;
	this->max_force = 1;
	this->max_speed = 18;
	this->radius = 5;
}

Particle::~Particle() {

}

void Particle::apply_force(ofVec3f force)
{
	this->acceleration += force;
}

void Particle::seek(ofVec3f target)
{
	ofVec3f desired = target - this->location;
	float distance = desired.length();
	desired.normalize();
	if (distance < this->radius)
	{
		if (distance < 1) {
			this->location = this->start_location;
			return;
		} else {
			distance *= ofMap(distance, 0, this->radius, 0, this->max_speed);
		}
	} else {
		distance *= max_speed;
	}

	ofVec3f steer = desired - this->velocity;
	steer.limit(this->max_force);
	apply_force(steer);
}

void Particle::seek_r(ofVec3f target)
{
	ofVec3f desired = target - this->location;
	desired.normalize();
	desired *= this->max_speed;
	ofVec3f steer = desired - this->velocity;
	steer.limit(this->max_force);
	steer *= -1;
	apply_force(steer);
}

void Particle::update() {
	this->velocity += this->acceleration;
	this->velocity.limit(this->max_speed);
	this->location += this->velocity;
	this->acceleration *= 0;
	this->velocity *= 0.98;
}

void Particle::draw() {
	ofPushMatrix();
	ofTranslate(this->location);

	ofFill();
	ofSetColor(255);
	ofBeginShape();
	float x, y;
	for (int i = 0; i < 360; i += 60) {
		x = this->size * cos(DEG_TO_RAD * (i + 90));
		y = this->size * sin(DEG_TO_RAD * (i + 90));
		ofVertex(x, y, 0);
	}
	ofEndShape(true);

	ofNoFill();
	ofSetColor(0);
	ofBeginShape();
	for (int i = 0; i < 360; i += 60) {
		x = this->size * cos(DEG_TO_RAD * (i + 90));
		y = this->size * sin(DEG_TO_RAD * (i + 90));
		ofVertex(x, y, 0);
	}
	ofEndShape(true);

	ofPopMatrix();
}

ofVec3f Particle::get_location() { return this->location; }
ofVec3f Particle::get_start_location() { return this->start_location; }