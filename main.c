#include <stdio.h>
#include <unistd.h>
#include "vlc/vlc.h"

void test( const struct libvlc_event_t *event, void *parm );

int main(int argc, char * arg[]){
	printf("main function\n");

	libvlc_instance_t * inst;  
	libvlc_media_player_t *mp;  
	libvlc_media_t *m;  
	libvlc_event_manager_t *eventManager;

	libvlc_time_t length;  
	int width;  
	int height;  
	int wait_time=5000;  

	inst = libvlc_new (0, NULL);  

	//m = libvlc_media_new_path (inst, "video/test.mp4");  
	m = libvlc_media_new_location(inst, "rtsp://192.168.0.201:6000/liv/ch01_0"); 
	eventManager = libvlc_media_event_manager (m); 
	libvlc_event_attach(eventManager, libvlc_MediaParsedChanged, test, NULL);
	
	/* Create a media player playing environement */  
	mp = libvlc_media_player_new_from_media (m);  

	/* No need to keep the media now */  
	libvlc_media_release (m);  

	// play the media_player  
	libvlc_media_player_play (mp);  

	//wait until the tracks are created  
	sleep (wait_time);  
	length = libvlc_media_player_get_length(mp);
	width = libvlc_video_get_width(mp);  
	height = libvlc_video_get_height(mp);  
	printf("Stream Duration: %ds\n",length/1000);  
	printf("Resolution: %d x %d\n",width,height);  
	//Let it play   
	sleep (length-wait_time);   

	// Stop playing  
	libvlc_media_player_stop (mp);  

	// Free the media_player  
	libvlc_media_player_release (mp);  

	libvlc_release (inst); 
	
	return 0;
}

void test( const struct libvlc_event_t *event, void *parm ){
	printf("---------------------------------\n");
	printf("÷¥––¡À\n");
}
