#include <stdlib.h>
#include <pthread.h>
#include <glib.h>
#include <glib/gi18n.h>
#include <glib/gstdio.h>
#include <gtk/gtk.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#undef main
#define MAIN_SLEEP 2
#define THREAD_SLEEP 1
#define ALLEGRO_NO_MAGIC_MAIN
extern pthread_mutex_t mtx;
extern pthread_mutex_t  audio_running;
int   play_audio(void);
