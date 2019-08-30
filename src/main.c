
#include <stdio.h>
#include <math.h>

#include "ww.h"

#include "green.h"

int main( int argc, char * argv[] ) {
	
	init_green();
	
	ww_sprite_t * green2 = ww_clone_sprite(green);
	
	float angle = 0;
	float angle2 = 0;
	int circle_center_x = 300;
	int circle_center_y = 300;
	int radius = 200;
	int degree = 0;
	
	if(ww_window_create(argc, argv, "Pixarray", 1024, 576)) {
		printf("Closing..\n");
		return 1;
	}
	
	while(!ww_window_received_quit_event()) {
		ww_window_update_events();
		
		angle = degree * 3.14159 / 180;
		//~ printf("angle: %f\n", angle);
		green->pad_x = circle_center_x + radius * cos(angle);
		green->pad_y = circle_center_y + radius * sin(angle);
		
		angle2 = angle + 3.14159;
		if(angle2 > (3.14159 * 2)){
			angle2 = angle2 - (3.14159 * 2);
		}
		printf("angle2: %f\n", angle2);
		green2->pad_x = circle_center_x + radius * cos(angle2);
		green2->pad_y = circle_center_y + radius * sin(angle2);
		
		
		degree = degree + 1;
		if(degree == 360){
			degree = 0;
		}
		
		ww_draw_sprite(green);
		ww_draw_sprite(green2);
		
		ww_window_update_buffer();
		
	}
	
	ww_free_sprite(green);
	ww_free_sprite(green2);
	
	ww_window_destroy();
	return 0;
}
