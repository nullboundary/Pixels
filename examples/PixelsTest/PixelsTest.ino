//#include <Pixels_PPI16.h>
//#include <Pixels_Antialiasing.h>  // optional (a removal does not impact fonts antialiasing)
//#include <Pixels_HX8352.h>

//Pixels pxs(240, 400);

#include <Pixels_Antialiasing.h>
#include <Pixels_SPIsw.h>
#include <Pixels_ILI9341.h>

Pixels pxs(240, 320);

extern prog_uchar Eurostile13a[494] PROGMEM;
extern prog_uchar Verdana8[637] PROGMEM;

#define TFT_CLK D5
#define TFT_MOSI D7
#define TFT_DC D4
#define TFT_CS D1
#define TFT_RST D2


	void setup() {
		pxs.init();
    pxs.setSpiPins(TFT_CLK,TFT_MOSI,TFT_CS,TFT_RST,TFT_DC);
		int delayCounter = 0;
		long start = millis();
		int orientation = pxs.getOrientation();
		
		pxs.setBackground(0,0,0);
		pxs.setColor(255,255,255);
		
		
		pxs.clear();
		pxs.setFont(Eurostile13a);
		String str1 = "Pixels Test";
		int widthX = pxs.getTextWidth(str1);
		pxs.print((pxs.getWidth() - widthX)/2, 45, str1);
		
		delay(2000);
		delayCounter += 2;
		
		pxs.setFont(Verdana8);
		
		String str2 = "antialiasing is off";
		int width = pxs.getTextWidth(str2);
		pxs.print((pxs.getWidth() - width)/2, 65, str2);
		
		delay(2000);
		if ( pxs.canScroll() ) {
			if (  pxs.getWidth() > pxs.getHeight()) {
				int scroll = (pxs.getWidth() + width)/2;
				if ( scroll < 200 ) {
					scroll = (pxs.getWidth() + width)/2;
					pxs.scroll(scroll, SCROLL_SMOOTH | SCROLL_CLEAN);
					pxs.scroll(-scroll, 0);
				} else {
					pxs.setFont(Eurostile13a);
					pxs.cleanText((pxs.getWidth() - widthX)/2, 45, str1);
					pxs.setFont(Verdana8);
					pxs.cleanText((pxs.getWidth() - width)/2, 65, str2);
				}
			} else {
				pxs.scroll(90, SCROLL_SMOOTH | SCROLL_CLEAN);
				pxs.scroll(-90, 0);
			}	
			delay(1000);
			delayCounter += 1;
		} else {
			pxs.setColor(0,0,0);
			pxs.fillRectangle((pxs.getWidth() - widthX)/2, 45, widthX, 40);
		}
		
		int xoffset = (pxs.getWidth() - 152)/2;
		int yoffset = (pxs.getHeight() - 101)/2;
		
		fillRectangles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		fillRoundRectangles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		
		fillCircles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		fillOvals(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		xoffset += 3;
		yoffset += 3;
		
		drawRectangles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		drawRoundRectangles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		drawCircles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		drawOvals(xoffset, yoffset);
		
		xoffset -= 3;
		yoffset -= 3;
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		int i = 0;
		pxs.setColor(175, 230, 135);
		for ( ; i < pxs.getWidth()+30; i+=10 ) {
			pxs.drawLine(i+8, 0, i-20, pxs.getHeight()-1);
		}
		pxs.setColor(101, 147, 156);
		for ( i = 0; i < pxs.getHeight()+40; i+=20 ) {
			pxs.drawLine(0, i+5, pxs.getWidth()-1, i-40);
		}
		
		delay(2000);
		delayCounter += 2;
		pxs.clear();
		
		pxs.setColor(255, 255, 255);
		String str3 = "antialiasing is on";
		width = pxs.getTextWidth(str3);
		pxs.print((pxs.getWidth() - width)/2, 55, str3);
		delay(2000);
		delayCounter += 2;
		pxs.cleanText((pxs.getWidth() - width)/2, 55, str3);
		
		pxs.enableAntialiasing(true);
		
		pxs.setColor(175, 230, 135);
		for ( i = 0; i < pxs.getWidth()+30; i+=10 ) {
			pxs.drawLine(i+8, 0, i-20, pxs.getHeight()-1);
		}
		pxs.setColor(101, 147, 156);
		for ( i = 0; i < pxs.getHeight()+40; i+=20 ) {
			pxs.drawLine(0, i+5, pxs.getWidth()-1, i-40);
		}
		
		delay(3000);
		delayCounter += 3;
		pxs.clear();
		
		fillRoundRectangles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		fillCircles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		fillOvals(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		xoffset += 3;
		yoffset += 3;
			
		drawRoundRectangles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		drawCircles(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		drawOvals(xoffset, yoffset);
		
		delay(2000);
		delayCounter += 2;
		
		clean();
		
		pxs.setColor(255, 255, 255);
		String str4 = "axis control with";
		String str5 = "setOrientation()";
		width = pxs.getTextWidth(str4);
		pxs.print((pxs.getWidth() - width)/2, 35, str4);
		pxs.print((pxs.getWidth() - width)/2, 50, str5);
			
		delay(2000);
		delayCounter += 2;
		
		pxs.cleanText((pxs.getWidth() - width)/2, 35, str4);
		pxs.cleanText((pxs.getWidth() - width)/2, 50, str5);
		
		pxs.setOrientation(LANDSCAPE);
		cross(10, 10);
		cross(100, 10);
		pxs.print(22, 18, "LANDSCAPE");
		delay(2000);
		delayCounter += 2;
		clean2();
		
		pxs.setOrientation(PORTRAIT);
		cross(10, 10);
		cross(100, 10);
		pxs.print(22, 18, "PORTRAIT");
		delay(2000);
		delayCounter += 2;
		clean2();
		
		pxs.setOrientation(LANDSCAPE_FLIP);
		cross(10, 10);
		cross(100, 10);
		pxs.print(22, 18, "LANDSCAPE_FLIP");
		delay(2000);
		delayCounter += 2;
		clean2();
		
		pxs.setOrientation(PORTRAIT_FLIP);
		cross(10, 10);
		cross(100, 10);
		pxs.print(22, 18, "PORTRAIT_FLIP");
		delay(2000);
		delayCounter += 2;
		clean2();
		
		//if (pxs.getWidth() > pxs.getHeight()) {
		//	pxs.setOrientation(LANDSCAPE);	
		//} else {
		//	pxs.setOrientation(PORTRAIT);
		//}
		
		pxs.enableAntialiasing(false);
		
		
		pxs.setOrientation(PORTRAIT);
		
		int devWidth = pxs.getWidth() < pxs.getHeight() ? pxs.getWidth() : pxs.getHeight();
		
		String str6 = "relative origin";
		width = pxs.getTextWidth(str6);
		pxs.print((devWidth - width)/2, 35, str6);
		
		pxs.setOriginRelative();
		
		delay(2000);
		delayCounter += 2;
		pxs.cleanText((devWidth - width)/2, 35, str6);
		
		cross(10, 10);
		cross(100, 10);
		delay(1000);
		delayCounter += 1;
		pxs.print(5, 19, "scroll: 80");
		delay(1000);
		delayCounter += 1;
		pxs.scroll(80, SCROLL_SMOOTH);
		delay(1000);
		delayCounter += 1;
		pxs.print(5, 31, "line: y=0");
		delay(1000);
		delayCounter += 1;
		pxs.setColor(255, 0, 0);
		pxs.drawLine(0, 0, pxs.getWidth(), 0);
		pxs.setColor(255, 255, 255);
		delay(1000);
		delayCounter += 1;
		cross(10, 50);
		cross(100, 50);
		delay(3000);
		delayCounter += 3;
		
		pxs.scroll(-80, SCROLL_SMOOTH | SCROLL_CLEAN);
		
		String str7 = "absolute origin";
		width = pxs.getTextWidth(str7);
		pxs.print((devWidth - width)/2, 35, str7);
		
		delay(2000);
		delayCounter += 2;
		
		pxs.cleanText((devWidth - width)/2, 35, str7);
		
		cross(10, 10);
		cross(100, 10);
		delay(1000);
		delayCounter += 1;
		pxs.print(5, 19, "scroll: 80");
		delay(1000);
		delayCounter += 1;
		pxs.scroll(80, SCROLL_SMOOTH);
		delay(1000);
		delayCounter += 1;
		pxs.print(5, 31, "line: y=0");
		delay(1000);
		delayCounter += 1;
		
		pxs.setOriginAbsolute();
		
		pxs.setColor(255, 0, 0);
		pxs.drawLine(0, 0, pxs.getWidth(), 0);
		pxs.setColor(255, 255, 255);
		delay(2000);
		delayCounter += 2;
		
		cross(10, 50);
		cross(100, 50);
		
		delay(3000);
		delayCounter += 3;
		pxs.scroll(60, SCROLL_SMOOTH | SCROLL_CLEAN);
		pxs.scroll(-140, SCROLL_SMOOTH | SCROLL_CLEAN);
		
		pxs.setOrientation(orientation);
		
		long end = millis();
		long elapsed = end - start;    
		long effective = elapsed - (long)delayCounter * (long)1000;
		#ifdef PIXELMEISTER
		pxs.print(20, 20, "Total: " + elapsed + "ms");
		pxs.print(20, 35, "Effective: " + effective + "ms");
		#else
		pxs.print(20, 20, "Total: " + String(elapsed) + "ms");
		pxs.print(20, 35, "Effective: " + String(effective) + "ms");
		#endif
		
		
		
		#ifdef PIXELMEISTER
		// dump to STDOUT font usage statistics to help in 
		// a generation of size-optimized fonts
		pxs.fontStatistics(); 
		#endif
	}

	void loop() {

	}

	void cross( int x, int y ) {
		pxs.drawLine( x-5, y, x+5, y );
		pxs.drawLine( x, y-5, x, y+5 );
		
	#ifdef PIXELMEISTER
		pxs.print(x+12, y-5, "(" + x + "," + y + ")");
	#else
		pxs.print(x+12, y-5, "(" + String(x) + "," + String(y) + ")");
	#endif	
		
	}
	
	void clean() {
		pxs.setColor(0,0,0);
		pxs.fillRectangle((pxs.getWidth() - 152)/2, (pxs.getHeight() - 101)/2, 154, 104);
	}
	
	void clean2() {
		pxs.setColor(0,0,0);
		pxs.fillRectangle(0, 0, 160, 35);
		pxs.setColor(255,255,255);
	}
	
	void fillRectangles(int xoffset, int yoffset) {
		pxs.setColor(101, 147, 156);
		pxs.fillRectangle(xoffset, yoffset, 50, 50);
		pxs.setColor(151, 219, 232);
		pxs.fillRectangle(xoffset+51, yoffset, 50, 50);
		pxs.setColor(156, 128, 101);
		pxs.fillRectangle(xoffset+102, yoffset, 50, 50);
		pxs.setColor(232, 178, 151);
		pxs.fillRectangle(xoffset, yoffset+51, 50, 50);
		pxs.setColor(99, 99, 99);
		pxs.fillRectangle(xoffset+51, yoffset+51, 50, 50);
		pxs.setColor(156, 156, 156);
		pxs.fillRectangle(xoffset+102, yoffset+51, 50, 50);
	}
	
	void fillRoundRectangles(int xoffset, int yoffset) {
		pxs.setColor(101, 147, 156);
		pxs.fillRoundRectangle(xoffset, yoffset, 50, 50, 12);
		pxs.setColor(151, 219, 232);
		pxs.fillRoundRectangle(xoffset+51, yoffset, 50, 50, 12);
		pxs.setColor(156, 128, 101);
		pxs.fillRoundRectangle(xoffset+102, yoffset, 50, 50, 12);
		pxs.setColor(232, 178, 151);
		pxs.fillRoundRectangle(xoffset, yoffset+51, 50, 50, 12);
		pxs.setColor(99, 99, 99);
		pxs.fillRoundRectangle(xoffset+51, yoffset+51, 50, 50, 12);
		pxs.setColor(156, 156, 156);
		pxs.fillRoundRectangle(xoffset+102, yoffset+51, 50, 50, 12);
	}
	
	void fillCircles(int xoffset, int yoffset) { 
		pxs.setColor(101, 147, 156);
		pxs.fillOval(xoffset, yoffset, 50, 50);
		pxs.setColor(151, 219, 232);
		pxs.fillOval(xoffset+51, yoffset, 50, 50);
		pxs.setColor(156, 128, 101);
		pxs.fillOval(xoffset+102, yoffset, 50, 50);
		pxs.setColor(232, 178, 151);
		pxs.fillOval(xoffset, yoffset+50, 50, 50);
		pxs.setColor(99, 99, 99);
		pxs.fillOval(xoffset+51, yoffset+51, 50, 50);
		pxs.setColor(156, 156, 156);
		pxs.fillOval(xoffset+102, yoffset+51, 50, 50);
	}
	
	void fillOvals(int xoffset, int yoffset) { 
		pxs.setColor(101, 147, 156);
		pxs.fillOval(xoffset+5, yoffset, 40, 50);
		pxs.setColor(151, 219, 232);
		pxs.fillOval(xoffset+50, yoffset+5, 50, 40);
		pxs.setColor(156, 128, 101);
		pxs.fillOval(xoffset+105, yoffset, 40, 50);
		pxs.setColor(232, 178, 151);
		pxs.fillOval(xoffset, yoffset+55, 50, 40);
		pxs.setColor(99, 99, 99);
		pxs.fillOval(xoffset+55, yoffset+50, 40, 50);
		pxs.setColor(156, 156, 156);
		pxs.fillOval(xoffset+100, yoffset+55, 50, 40);
	}
	
	void drawRectangles(int xoffset, int yoffset) {
		pxs.setColor(101, 147, 156);
		pxs.drawRectangle(xoffset, yoffset, 45, 45);
		pxs.setColor(151, 219, 232);
		pxs.drawRectangle(xoffset+50, yoffset, 45, 45);
		pxs.setColor(156, 128, 101);
		pxs.drawRectangle(xoffset+100, yoffset, 45, 45);
		pxs.setColor(232, 178, 151);
		pxs.drawRectangle(xoffset, yoffset+50, 45, 45);
		pxs.setColor(99, 99, 99);
		pxs.drawRectangle(xoffset+50, yoffset+50, 45, 45);
		pxs.setColor(156, 156, 156);
		pxs.drawRectangle(xoffset+100, yoffset+50, 45, 45);
	}
	
	void drawRoundRectangles(int xoffset, int yoffset) {
		pxs.setColor(101, 147, 156);
		pxs.drawRoundRectangle(xoffset, yoffset, 45, 45, 12);
		pxs.setColor(151, 219, 232);
		pxs.drawRoundRectangle(xoffset+50, yoffset, 45, 45, 12);
		pxs.setColor(156, 128, 101);
		pxs.drawRoundRectangle(xoffset+100, yoffset, 45, 45, 12);
		pxs.setColor(232, 178, 151);
		pxs.drawRoundRectangle(xoffset, yoffset+50, 45, 45, 12);
		pxs.setColor(99, 99, 99);
		pxs.drawRoundRectangle(xoffset+50, yoffset+50, 45, 45, 12);
		pxs.setColor(156, 156, 156);
		pxs.drawRoundRectangle(xoffset+100, yoffset+50, 45, 45, 12);
	}
	
	void drawCircles(int xoffset, int yoffset) { 
		pxs.setColor(101, 147, 156);
		pxs.drawOval(xoffset, yoffset, 45, 45);
		pxs.setColor(151, 219, 232);
		pxs.drawOval(xoffset+50, yoffset, 45, 45);
		pxs.setColor(156, 128, 101);
		pxs.drawOval(xoffset+100, yoffset, 45, 45);
		pxs.setColor(232, 178, 151);
		pxs.drawOval(xoffset, yoffset+50, 45, 45);
		pxs.setColor(99, 99, 99);
		pxs.drawOval(xoffset+50, yoffset+50, 45, 45);
		pxs.setColor(156, 156, 156);
		pxs.drawOval(xoffset+100, yoffset+50, 45, 45);
	}
	
	void drawOvals(int xoffset, int yoffset) { 
		pxs.setColor(101, 147, 156);
		pxs.drawOval(xoffset+5, yoffset, 40, 50);
		pxs.setColor(151, 219, 232);
		pxs.drawOval(xoffset+50, yoffset+5, 50, 40);
		pxs.setColor(156, 128, 101);
		pxs.drawOval(xoffset+105, yoffset, 40, 50);
		pxs.setColor(232, 178, 151);
		pxs.drawOval(xoffset, yoffset+55, 50, 40);
		pxs.setColor(99, 99, 99);
		pxs.drawOval(xoffset+55, yoffset+50, 40, 50);
		pxs.setColor(156, 156, 156);
		pxs.drawOval(xoffset+100, yoffset+55, 50, 40);
	}
	
	// int[] Eurostile13a = { //:Java
	prog_uchar Eurostile13a[494] PROGMEM = { //:Wiring
	0x5A,0x46,0x02,0x0F,0x0F,0x00,0x54,0x00,0x34,0x09,0x80,0x01,0x01,0x03,0x30,0x4B,0x81,0x2F,0x4B,0x81,
	0x2F,0x4B,0x81,0x2E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x8E,0x20,0x2B,0x2B,0x2B,
	0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x2B,0x81,0x2F,0x4B,0x81,0x2F,0x4B,0x81,0x2F,0x4B,0x00,0x20,0x00,
	0x08,0x05,0x05,0x00,0x05,0x00,0x74,0x00,0x3D,0x06,0x80,0x02,0x00,0x43,0x08,0x31,0x48,0x26,0x04,0x04,
	0x00,0x03,0x04,0x04,0x04,0x04,0x04,0x10,0x2E,0x41,0x37,0x2C,0x2C,0x05,0x22,0x2C,0x2C,0x2C,0x2C,0x2B,
	0x1A,0x0A,0x44,0x08,0x31,0x45,0x3E,0x02,0x3C,0x43,0x08,0x31,0x43,0x3E,0x2C,0x1B,0x0E,0x44,0x22,0x38,
	0x43,0x3C,0x0A,0x1A,0x34,0x41,0x00,0x65,0x00,0x52,0x09,0x00,0x05,0x00,0x41,0x39,0x16,0x07,0x01,0x07,
	0x13,0x35,0x42,0x15,0x0F,0x31,0x38,0x33,0x14,0x0E,0x41,0x3F,0x01,0x2D,0x43,0x34,0x81,0x3D,0x3A,0x81,
	0x2C,0x36,0x36,0x36,0x31,0x81,0x37,0x36,0x81,0x07,0x08,0x08,0x08,0x08,0x08,0x35,0x3A,0x81,0x34,0x46,
	0x3E,0x00,0x2F,0x43,0x3B,0x19,0x39,0x41,0x0F,0x16,0x3D,0x42,0x24,0x00,0x3C,0x41,0x33,0x0D,0x01,0x05,
	0x03,0x05,0x25,0x44,0x3F,0x39,0x3C,0x43,0x00,0x73,0x00,0x4C,0x09,0x00,0x05,0x01,0x41,0x26,0x0A,0x03,
	0x01,0x08,0x1D,0x3E,0x3A,0x00,0x1F,0x37,0x39,0x33,0x04,0x24,0x33,0x81,0x36,0x43,0x2A,0x2D,0x3B,0x00,
	0x1D,0x3B,0x3F,0x44,0x26,0x08,0x81,0x00,0x05,0x1C,0x3A,0x43,0x3D,0x3A,0x32,0x0B,0x20,0x32,0x11,0x3F,
	0x43,0x1D,0x0E,0x34,0x81,0x2B,0x42,0x3C,0x0B,0x13,0x41,0x1D,0x03,0x04,0x05,0x00,0x0C,0x34,0x42,0x3F,
	0x3B,0x39,0x3D,0x42,0x00,0x50,0x00,0x54,0x0B,0x01,0x01,0x00,0x09,0x84,0x00,0x06,0x13,0x36,0x41,0x09,
	0x1B,0x36,0x36,0x36,0x36,0x30,0x10,0x11,0x41,0x09,0x20,0x45,0x2D,0x00,0x3F,0x09,0x20,0x45,0x33,0x81,
	0x3A,0x09,0x20,0x45,0x34,0x81,0x38,0x09,0x20,0x45,0x2C,0x00,0x3E,0x09,0x1B,0x35,0x35,0x35,0x32,0x2A,
	0x0B,0x10,0x41,0x09,0x85,0x03,0x12,0x36,0x41,0x09,0x1E,0x3C,0x3C,0x3C,0x3D,0x44,0x09,0x20,0x48,0x09,
	0x20,0x48,0x09,0x20,0x48,0x09,0x20,0x48,0x00,0x6C,0x00,0x22,0x03,0x01,0x01,0x00,0x05,0x2C,0x05,0x2C,
	0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,
	0x05,0x2C,0x00,0x78,0x00,0x39,0x07,0x80,0x05,0x01,0x25,0x3E,0x45,0x38,0x11,0x0C,0x09,0x30,0x43,0x26,
	0x03,0x11,0x3C,0x1E,0x02,0x19,0x34,0x11,0x05,0x28,0x43,0x36,0x06,0x81,0x0A,0x3A,0x43,0x2F,0x0B,0x0B,
	0x22,0x04,0x11,0x37,0x41,0x18,0x02,0x21,0x3E,0x41,0x39,0x14,0x02,0x22,0x17,0x36,0x45,0x2A,0x05,0x00,
	0x69,0x00,0x1F,0x03,0x01,0x01,0x00,0x05,0x2C,0x29,0x38,0x44,0x0C,0x2E,0x05,0x2C,0x05,0x2C,0x05,0x2C,
	0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x05,0x2C,0x00,0x00,0x00,0x00,};
	// antialiased
	// array size:   492
	// glyph height: 28
	// baseline:     15
	// range:         PTeilstx
	/* usage:
		pxs.setFont(Eurostile13a);
		pxs.print(x, y, "...");
	*/
	
	// int[] Verdana8 = { //:Java
	prog_uchar Verdana8[637] PROGMEM = { //:Wiring
	0x5A,0x46,0x01,0x0C,0x0C,0x00,0x20,0x00,0x08,0x04,0x04,0x00,0x04,0x00,0x28,0x00,0x0D,0x05,0x01,0x01,
	0x01,0xD6,0xB6,0xDB,0xB7,0x7F,0x00,0x29,0x00,0x0D,0x05,0x01,0x01,0x01,0x76,0xED,0xB6,0xB5,0xFF,0x00,
	0x2C,0x00,0x09,0x04,0x01,0x08,0x01,0xA9,0x00,0x33,0x00,0x0D,0x07,0x01,0x02,0x01,0x8B,0xBD,0x9F,0x79,
	0xD1,0x00,0x32,0x00,0x0D,0x07,0x01,0x02,0x01,0x8B,0xBD,0xDD,0xDC,0xE0,0x00,0x31,0x00,0x0D,0x07,0x01,
	0x02,0x01,0xD8,0xF7,0xBD,0xEF,0x60,0x00,0x30,0x00,0x0D,0x07,0x01,0x02,0x01,0x8B,0x9C,0xE7,0x39,0xD1,
	0x00,0x37,0x00,0x0D,0x07,0x01,0x02,0x01,0x07,0xBB,0xDD,0xEE,0xF7,0x00,0x36,0x00,0x0D,0x07,0x01,0x02,
	0x01,0xCD,0xDE,0x17,0x39,0xD1,0x00,0x35,0x00,0x0D,0x07,0x01,0x02,0x01,0x03,0xDE,0x1F,0x79,0xD1,0x00,
	0x34,0x00,0x0E,0x07,0x00,0x02,0x01,0xF7,0x9D,0x6D,0x74,0x0F,0x7D,0x00,0x3A,0x00,0x09,0x05,0x02,0x04,
	0x02,0x33,0x00,0x39,0x00,0x0D,0x07,0x01,0x02,0x01,0x8B,0x9C,0xE8,0x7B,0xB3,0x00,0x38,0x00,0x0D,0x07,
	0x01,0x02,0x01,0x8B,0x9D,0x17,0x39,0xD1,0x00,0x3D,0x00,0x0B,0x09,0x01,0x05,0x01,0x01,0xFC,0x07,0x00,
	0x44,0x00,0x0F,0x09,0x01,0x02,0x01,0x06,0xF5,0xF3,0xE7,0xCF,0x9E,0x83,0x00,0x45,0x00,0x0D,0x07,0x01,
	0x02,0x01,0x03,0xDE,0x07,0xBD,0xE0,0x00,0x46,0x00,0x0D,0x06,0x01,0x02,0x00,0x03,0xDE,0x17,0xBD,0xEF,
	0x00,0x41,0x00,0x0E,0x08,0x01,0x02,0x01,0xCF,0x3B,0x6D,0xB4,0x07,0x9E,0x00,0x43,0x00,0x0F,0x09,0x01,
	0x02,0x01,0xC3,0x79,0xFB,0xF7,0xEF,0xEF,0x61,0x00,0x4C,0x00,0x0D,0x06,0x01,0x02,0x00,0x7B,0xDE,0xF7,
	0xBD,0xE0,0x00,0x4E,0x00,0x0E,0x08,0x01,0x02,0x01,0x38,0xE5,0x96,0x69,0xA7,0x1C,0x00,0x4F,0x00,0x0F,
	0x09,0x01,0x02,0x01,0xC7,0x75,0xF3,0xE7,0xCF,0xAE,0xE3,0x00,0x49,0x00,0x0B,0x05,0x01,0x02,0x01,0x16,
	0xDB,0x68,0x00,0x54,0x00,0x0F,0x07,0x00,0x02,0x00,0x01,0xDF,0xBF,0x7E,0xFD,0xFB,0xF7,0x00,0x50,0x00,
	0x0D,0x07,0x01,0x02,0x01,0x0B,0x9C,0xE0,0xBD,0xEF,0x00,0x53,0x00,0x0E,0x08,0x01,0x02,0x01,0x85,0xE7,
	0xE7,0xE7,0xE7,0xA1,0x00,0x52,0x00,0x0E,0x08,0x01,0x02,0x01,0x0D,0xD7,0x5D,0x0D,0xB7,0x5E,0x00,0x5F,
	0x00,0x09,0x07,0x00,0x0B,0x00,0x01,0x00,0x66,0x00,0x0D,0x04,0x00,0x01,0x00,0xCB,0xB0,0xBB,0xBB,0xBF,
	0x00,0x67,0x00,0x0D,0x07,0x01,0x04,0x01,0x83,0x9C,0xE7,0x43,0xD1,0x00,0x65,0x00,0x0C,0x07,0x01,0x04,
	0x01,0x8B,0x80,0xF7,0x47,0x00,0x62,0x00,0x0E,0x07,0x01,0x01,0x01,0x7B,0xDE,0x17,0x39,0xCE,0x0F,0x00,
	0x63,0x00,0x0C,0x06,0x01,0x04,0x00,0x8B,0x9E,0xF7,0x47,0x00,0x61,0x00,0x0C,0x07,0x01,0x04,0x01,0x8F,
	0xA0,0xE7,0x43,0x00,0x6E,0x00,0x0C,0x07,0x01,0x04,0x01,0x0B,0x9C,0xE7,0x3B,0x00,0x6F,0x00,0x0C,0x07,
	0x01,0x04,0x01,0x8B,0x9C,0xE7,0x47,0x00,0x6C,0x00,0x0A,0x03,0x01,0x01,0x01,0x00,0x7F,0x00,0x6D,0x00,
	0x0F,0x0B,0x01,0x04,0x01,0x00,0xBB,0x9D,0xCE,0xE7,0x73,0xBB,0x00,0x68,0x00,0x0E,0x07,0x01,0x01,0x01,
	0x7B,0xDE,0x17,0x39,0xCE,0x77,0x00,0x69,0x00,0x0A,0x03,0x01,0x01,0x01,0x60,0x7F,0x00,0x77,0x00,0x0E,
	0x09,0x01,0x04,0x01,0x6C,0xD9,0x52,0xAB,0xB7,0x7F,0x00,0x76,0x00,0x0C,0x07,0x01,0x04,0x01,0x73,0xAB,
	0x5D,0xEF,0x00,0x75,0x00,0x0C,0x07,0x01,0x04,0x01,0x73,0x9C,0xE7,0x43,0x00,0x74,0x00,0x0C,0x04,0x00,
	0x02,0x00,0xBB,0x0B,0xBB,0xBC,0x00,0x73,0x00,0x0B,0x06,0x01,0x04,0x01,0x87,0x3C,0xE1,0x00,0x72,0x00,
	0x0B,0x05,0x01,0x04,0x00,0x43,0x77,0x77,0x00,0x79,0x00,0x0D,0x07,0x01,0x04,0x01,0x75,0x6B,0x5D,0xEF,
	0x77,0x00,0x78,0x00,0x0C,0x07,0x01,0x04,0x01,0x75,0x77,0xBA,0xBB,0x00,0x00,0x00,0x00,};
	// array size:   635
	// glyph height: 22
	// baseline:     12
	// range:        (), 0-9 :=ACDEFILNOPRST_abcefghilmnorstuvwxy
	/* usage:
		pxs.setFont(Verdana8);
		pxs.print(x, y, "...");
	*/

