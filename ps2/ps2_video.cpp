#include <port.h>

#include <gs_psm.h>
#include <graph.h>
#include <audsrv.h>

#include <settings.h>
#include <video.h>
#include <init.h>

#include <apu.h>
#include <snes9x.h>
#include <gfx.h>

int last_width = 0;
int last_height = 0;

void S9xInitGFX(void)
{

	video_packets_init();

	video_init_framebuffer(512,512);

	video_init_texbuffer(512,478,GS_PSM_16S,0);

	GFX.Screen = (uint16*)memalign(128,2*512*478);
	GFX.Pitch = 1024;

	//video_enable_vsync_handler();
}

void S9xDeinitGFX(void)
{

	last_width = 0;
	last_height = 0;

	video_packets_free();

	free(GFX.Screen);

	//video_disable_vsync_handler();

}

bool8 S9xContinueUpdate (int width, int height)
{

	return 1;

}

// texture buffer is 512x478
// use the width/height of part of the texture

bool8 S9xDeinitUpdate (int width, int height)
{

	settings_t settings = settings_get();

	int mode = settings.display.mode;

	if ((width != last_width) || (height != last_height))
	{

		// hardcoded mode
		if (height > 256)
		{
			if (mode == GRAPH_MODE_NTSC || mode == GRAPH_MODE_PAL)
			{
				video_init_screen(0,0,width,height,1,mode);
			}
		}
		else
		{
			video_init_screen(0,0,width,height,0,mode);
		}

		video_init_draw_env(width,height);

		last_width = width;
		last_height = height;

		video_send_packet(512,478,(void*)GFX.Screen,NULL);
		video_draw_packet(width,height,GS_PSM_16S,0);
	}

	video_send_texture();
	video_draw_texture();

	//video_sync_flip();
	video_sync_wait();

	return 1;
}
