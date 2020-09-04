#include "audio.h"
#undef main
pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t audio_running= PTHREAD_MUTEX_INITIALIZER;


/*
 * How to play an wav file from C code.
 *
 * This is using a thread to play the sound - so that the main-code, can 
 * perform something useful - err like counting a number....
 *
 *  
 *
 */


int   play_audio(void)
{
    gchar          *audiofile;
    gchar	   *userconfdir;

    pthread_mutex_lock( &mtx );
    //printf(  "al_init\n" );
    //sleep(THREAD_SLEEP);
    if (!al_init()) {
    pthread_mutex_unlock(&mtx);
        return 1;
    }
    //printf(  "install_audio\n" );
    if (!al_install_audio()) {
    pthread_mutex_unlock(&mtx);
        return 2;
    }
    //sleep(THREAD_SLEEP);
    //printf(  "ac_codec\n" );
    if (!al_init_acodec_addon()) {
    pthread_mutex_unlock(&mtx);
        return 3;
    }
    //sleep(THREAD_SLEEP);
    //printf(  "reserve_samples\n" );
    if (!al_reserve_samples(1)) {
    pthread_mutex_unlock(&mtx);
        return 4;
    }
    //sleep(THREAD_SLEEP);
    userconfdir = get_user_conf_dir();
    audiofile = g_strconcat(userconfdir, G_DIR_SEPARATOR_S, "audio",
                          G_DIR_SEPARATOR_S, "arriving.wav", NULL);
    ALLEGRO_SAMPLE *idle_sound = al_load_sample(audiofile);
    ALLEGRO_SAMPLE_INSTANCE *sample_instance = al_create_sample_instance(idle_sound);
    g_free(audiofile);
     if (!idle_sound || !sample_instance) {
        printf("Setup error.\n");
        pthread_mutex_unlock(&mtx);
        return 5;
    }
    ALLEGRO_SAMPLE_ID sample_id;

    if (!al_play_sample(idle_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &sample_id)) {
        printf("Failed to play sample.\n");
    }
    if (!al_play_sample_instance(sample_instance)) {
        printf("Failed to play sample instance.\n");
    }
    al_rest(5.0);

    al_destroy_sample_instance(sample_instance);
    al_destroy_sample(idle_sound);
    //printf(  "Thread I have finished" );
    pthread_mutex_unlock(&mtx);
    return 1;
}



