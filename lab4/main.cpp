#include <graphics.h>           
#include <process.h>           

#define XMAX 640               
#define YMAX 480                
#define MAXCOUNT 2500             

void GraphInit();
void GraphClose();

int main() {
	
	GraphInit();

	int driver, mode;
	int x, y, count;                    
	float xscale, yscale;        
	float left, top;             
	float xside, yside;         
	float zx, zy;                
	float cx, cy;                
	float tempx;                 

	// Sorry for hardcode, but this parametrs is optimal
	left = -2.0;                
	top = 1.25;                  
	xside = 2.5;                 
	yside = -2.5;               
	xscale = xside / XMAX;       
	yscale = yside / YMAX;
	rectangle(0, 0, XMAX+1, YMAX+1);  

	for(y = 1; y <= YMAX; y++) {
		for(x = 1; x <= XMAX; x++) {
			cx = x * xscale + left;    
		 	cy = y * yscale + top;
		 	zx = zy = 0;           
	 		count = 0;             
			while(zx*zx + zy*zy < 4 && count < MAXCOUNT) {
		    		tempx = zx*zx - zy*zy + cx;  	// z = z*z + c
	    			zy = 2 * zx*zy + cy;
            			zx = tempx;
		    		count++;            
		    	}
	 		putpixel(x, y, count); 

			if( kbhit() )
		    		exit(0); 
		 }
	} 

	GraphClose();
}


void GraphInit() {
	int g_driver = DETECT, g_mode, ErrorCode;
	initgraph(&g_driver, &g_mode, "");
	ErrorCode = graphresult();
	if (ErrorCode != grOk) {
		cout << " graphics error! " << grapherrormsg(ErrorCode) << endl;
		cout << " press any key to start! " << endl;
		exit(1);
	}
}

void GraphClose() {
	system("PAUSE");
	closegraph();
}
