#include "menu.h"


play* play_init()
{
	//지역 변수 초기화
	play* PL = new play[1]; //동적 할당
	

	//------------------ bgm variable -----------------------------
	InitAudioDevice();
	PL->music = LoadMusicStream("resources/bgm.mp3");
	PL->music2 = LoadMusicStream("resources/bgm2.mp3");
	PlayMusicStream(PL->music);
	PlayMusicStream(PL->music2);
	//---------------------------------------------------------

	//----------------- image variable --------------------------------
	PL->image = LoadImage("resources/window.png");
	PL->texture = LoadTextureFromImage(PL->image);
	UnloadImage(PL->image);
	PL->image = LoadImageFromTexture(PL->texture);
	UnloadTexture(PL->texture);
	PL->texture = LoadTextureFromImage(PL->image);
	UnloadImage(PL->image);

	 PL->image_music = LoadImage("resources/music.png");
	PL->texture_music = LoadTextureFromImage(PL->image_music);
	UnloadImage(PL->image_music);
	PL->image_music = LoadImageFromTexture(PL->texture_music);
	UnloadTexture(PL->texture_music);
	PL->texture_music = LoadTextureFromImage(PL->image_music);
	UnloadImage(PL->image_music);

	 PL->image_mute = LoadImage("resources/music_mute.png");
	 PL->texture_mute = LoadTextureFromImage(PL->image_mute);
	UnloadImage(PL->image_mute);
	PL->image_mute = LoadImageFromTexture(PL->texture_mute);
	UnloadTexture(PL->texture_mute);
	PL->texture_mute = LoadTextureFromImage(PL->image_mute);
	UnloadImage(PL->image_mute);

	PL->image_object = LoadImage("resources/brick.png");
	PL->texture_object = LoadTextureFromImage(PL->image_object);
	UnloadImage(PL->image_object);
	PL->image_object = LoadImageFromTexture(PL->texture_object);
	UnloadTexture(PL->texture_object);
	PL->texture_object = LoadTextureFromImage(PL->image_object);
	UnloadImage(PL->image_object);

	PL->image_target = LoadImage("resources/dog.png");
	PL->texture_target = LoadTextureFromImage(PL->image_target);
	UnloadImage(PL->image_target);
	PL->image_target = LoadImageFromTexture(PL->texture_target);
	UnloadTexture(PL->texture_target);
	PL->texture_target = LoadTextureFromImage(PL->image_target);
	UnloadImage(PL->image_target);

	return PL;
	
}

//-----------------------------------------------------------------
//bgm
void music_control(play* PL)
{
	if (PL->play_or_mute == 1) {
		StopMusicStream(PL->music);
		StopMusicStream(PL->music2);
	}
	else if (PL->music_number == 0) {
		UpdateMusicStream(PL->music);
		PlayMusicStream(PL->music);
	}
	else {
		UpdateMusicStream(PL->music2);
		PlayMusicStream(PL->music2);
	}

}