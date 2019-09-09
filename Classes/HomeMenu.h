#ifndef __HOME_MENU_H__
#define __HOME_MENU_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
#include "Game4.h"
#include "Game5.h"
#include "Game6.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class HomeMenu : public Scene
{
private:

public:

	static bool callBtnPlay;

	//bgm/&sfx/
	SimpleAudioEngine* bgm = SimpleAudioEngine::getInstance();
	SimpleAudioEngine* sfx = SimpleAudioEngine::getInstance();
	//static void btn_sound();
	//////////

	void buttonMenu_hilang(); // menghilangkan button di ui menu
	void buttonMenu_tampil(); // menampilkan button di ui menu
	void buttonPlay(Ref* sender); // action button play
	void buttonProfile(Ref* sender); //action button profile
	void buttonSetting(Ref* sender); //action button setting
	void buttonExit(Ref* sender); //action button exit
	void buttonExitYes(Ref* sender); //action button ui exit(yes)
	void buttonExitNo(Ref* sender);  //action button ui exit(no)
	void buttonSettingOn(Ref* sender); //action button ui setting bgm(on) 
	void buttonSettingOff(Ref* sender);//action button ui setting bgm(off)
	void uiSettingClose(Ref* sender);//action untuk mengclose ui setting
	void uiProfileClose(Ref* sender);//action untuk mengclose ui profile

	// method action pilih game //
	void menuGame1(Ref* sender);
	void menuGame2(Ref* sender);
	void menuGame3(Ref* sender);
	void menuGame4(Ref* sender);
	void menuGame5(Ref* sender);
	void menuGame6(Ref* sender);
	void menuGameClose(Ref* sender);
	////////////////////////////
	
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(HomeMenu);

	int count = 0;
	float volume = 1;
	static int setting;
	//menu tampung button////
	Menu* tampungButton = Menu::create();
	//////////////////////// 
	MenuItemImage* btn_play = MenuItemImage::create("btn_awal.jpg", "btn_tekan.jpg", CC_CALLBACK_1(HomeMenu::buttonPlay, this));
	MenuItemImage* btn_profile= MenuItemImage::create("btn_awal.jpg", "btn_tekan.jpg", CC_CALLBACK_1(HomeMenu::buttonProfile, this));
	MenuItemImage* btn_setting = MenuItemImage::create("btn_awal.jpg", "btn_tekan.jpg", CC_CALLBACK_1(HomeMenu::buttonSetting, this));
	MenuItemImage* btn_exit = MenuItemImage::create("btn_awal.jpg", "btn_tekan.jpg", CC_CALLBACK_1(HomeMenu::buttonExit, this));
	Sprite* bg_exit = Sprite::create("ui_exit.jpg");	
	Button* btn_yes = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");//pilihan yes di button ui exit
	Button* btn_no = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");//pilihan no di button ui exit
	Sprite* bg_setting = Sprite::create("ui_setting.jpg");//background ui setting
	Button* ui_setting_close = Button::create("btn_awal.jpg","btn_tekan.jpg","btn_awal.jpg");//close ui setting
	Button* bgm_on = Button::create("bgm_on.jpg", "bgm_on.jpg", "bgm_on.jpg");
	Button* bgm_off = Button::create("bgm_off.jpg", "bgm_off.jpg", "bgm_off.jpg");
	Sprite* ui_profile = Sprite::create("ui_profile.png");
	Button* close_profile = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");

	//button game//
	Button* pil_game1 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* pil_game2 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* pil_game3 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* pil_game4 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* pil_game5 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* pil_game6 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* close_play = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	//////////////////

	Sprite* bg_menu = Sprite::create("bg_menu.jpg");
	
	
	static void btn_sound();
	static void btn_wrong();

	static int pilih_game;
};






#endif