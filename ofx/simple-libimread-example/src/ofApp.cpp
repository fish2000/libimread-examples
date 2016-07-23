
#include <algorithm>
#include <vector>
#include <libimread/ext/filesystem/path.h>

using ::filesystem::path;
using pathvec_t = std::vector<path>;

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    path basedir = "/Users/fish/Downloads";
    pathvec_t images = basedir.list("*.jpg", true); /// fullpaths
    std::transform(images.begin(), images.end(),
                   std::back_inserter(imagepaths),
                   [](path const& p) { return p.str(); });
    image.load(imagepaths[0].c_str());
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    image.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
