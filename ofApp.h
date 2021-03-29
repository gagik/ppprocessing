#include "Sketch.h"
#include "antlr4-runtime.h"
#include "libs/ProcessingLexer.h"
#include "libs/ProcessingParser.h"
#include "ImageVisitor.h"
#include <sys/stat.h>

using namespace antlr4;
using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		Sketch* sketch;
		ImageVisitor visitor;
		bool shouldSwitch;
		time_t mTime;
		int strokeColor;

	private:
		void updateFile();
};
