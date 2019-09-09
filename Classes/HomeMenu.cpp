#include "HomeMenu.h"

Scene* HomeMenu::scene()
{
	return HomeMenu::create();
}

bool HomeMenu::callBtnPlay = false;
int HomeMenu::pilih_game = 0;
int HomeMenu::setting = 0;

bool HomeMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	
	//bgm//
	if (HomeMenu::callBtnPlay == false)
	{
		bgm->playBackgroundMusic("aura_kingdom.mp3", true);

		bgm->setBackgroundMusicVolume(0.3f);
	}

	///////
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	float posX = (origin.x + visibleSize.width)/2;
	float posY = (origin.y + visibleSize.height) / 2;
	
	/////

	bg_menu->setPosition(Vec2(384, 683)); //background menu
	this->addChild(bg_menu);
	auto label = Label::createWithTTF("Menu", "fonts/arial.ttf", 50);
	label->setPosition(Vec2(250, 1300));
	this->addChild(label);

	auto logo_atas = Sprite::create("logoo.png"); //logo bagian pojok atas kiri
	logo_atas->setScale(0.2f);
	logo_atas->setPosition(Vec2(posX,1060));
	this->addChild(logo_atas);

	auto label_brain = Label::createWithTTF("BRAIN", "fonts/arial.ttf", 100); //label brain
	label_brain->setColor(Color3B::RED);
	label_brain->setAnchorPoint(Vec2(1, 1));
	label_brain->setPosition(Vec2(posX,940));
	this->addChild(label_brain);

	auto label_wars = Label::createWithTTF("WARS", "fonts/arial.ttf", 100); //label wars
	label_wars->setColor(Color3B::WHITE);
	label_wars->setAnchorPoint(Vec2(1,1));
	label_wars->setPosition(Vec2(posX+label_brain->getContentSize().width, 940));
	this->addChild(label_wars);
	////

	///button////
	
	tampungButton->setPosition(Vec2::ZERO);
	this->addChild(tampungButton);

	btn_play->setPosition(Vec2(posX, 760)); //button play
	auto label_play = Label::createWithTTF("PLAY GAME", "fonts/arial.ttf", 50);
	label_play->setPosition(Vec2(btn_play->getContentSize().width / 2, btn_play->getContentSize().height / 2));
	btn_play->addChild(label_play);
	tampungButton->addChild(btn_play);
	

	btn_profile->setPosition(Vec2(posX, 560)); //button profile
	auto label_profile = Label::createWithTTF("PROFILE", "fonts/arial.ttf", 50);
	label_profile->setPosition(Vec2(btn_profile->getContentSize().width / 2, btn_profile->getContentSize().height / 2));
	btn_profile->addChild(label_profile);
	tampungButton->addChild(btn_profile);
	
	//button profile ui//
	ui_profile->setPosition(Vec2(384, 440));
	ui_profile->setScale(0.f);
	this->addChild(ui_profile);
	close_profile->setPosition(Vec2(384, 140));
	close_profile->setScale(0.f);
	this->addChild(close_profile);
	auto profile_close_label = Label::createWithTTF("CLOSE", "fonts/arial.ttf", 50);
	profile_close_label->setPosition(Vec2(close_profile->getContentSize().width / 2, close_profile->getContentSize().height / 2));
	close_profile->addChild(profile_close_label);
	close_profile->addClickEventListener(CC_CALLBACK_1(HomeMenu::uiProfileClose, this));
	////////////////////


	btn_setting->setPosition(Vec2(posX,360)); //button setting
	auto label_setting = Label::createWithTTF("SETTING", "fonts/arial.ttf", 50);
	label_setting->setPosition(Vec2(btn_setting->getContentSize().width / 2, btn_setting->getContentSize().height / 2));
	btn_setting->addChild(label_setting);
	tampungButton->addChild(btn_setting);

	//button setting ui//
	bg_setting->setPosition(Vec2(384, 683));
	bg_setting->setScale(0.f);
	this->addChild(bg_setting);
	bgm_on->setPosition(Vec2(bg_setting->getContentSize().width / 2, 200));
	bgm_on->setScale(0.f);
	bgm_off->setPosition(Vec2(bg_setting->getContentSize().width / 2, 200));
	bgm_off->setScale(0.f);
	ui_setting_close->setPosition(Vec2(bg_setting->getContentSize().width - 330, btn_no->getContentSize().height - 20));
	auto label_setting_close = Label::createWithTTF("CLOSE", "fonts/arial.ttf", 50);
	label_setting_close->setPosition(Vec2(ui_setting_close->getContentSize().width / 2, ui_setting_close->getContentSize().height / 2));
	ui_setting_close->addChild(label_setting_close);
	bg_setting->addChild(bgm_on);
	bg_setting->addChild(bgm_off);
	bg_setting->addChild(ui_setting_close);
	ui_setting_close->addClickEventListener(CC_CALLBACK_1(HomeMenu::uiSettingClose, this));
	bgm_on->addClickEventListener(CC_CALLBACK_1(HomeMenu::buttonSettingOn, this));
	bgm_off->addClickEventListener(CC_CALLBACK_1(HomeMenu::buttonSettingOff, this));
	////////////////////

	//button exit//
	btn_exit->setPosition(Vec2(posX, 160)); 
	auto label_exit = Label::createWithTTF("EXIT", "fonts/arial.ttf", 50);
	label_exit->setPosition(Vec2(btn_exit->getContentSize().width / 2, btn_exit->getContentSize().height / 2));
	btn_exit->addChild(label_exit);
	tampungButton->addChild(btn_exit);
	////////////////

	//button exit ui//
	bg_exit->setPosition(Vec2(384, 683));
	bg_exit->setScale(0.f);
	btn_yes->setPosition(Vec2(200, 100));
	btn_yes->setScale(0.f);
	btn_no->setScale(0.f);
	btn_no->setPosition(Vec2(bg_exit->getContentSize().width - 200, 100));	
	this->addChild(bg_exit);
	bg_exit->addChild(btn_yes);
	bg_exit->addChild(btn_no);
	auto label_yes = Label::createWithTTF("YES", "fonts/arial.ttf", 50);
	label_yes->setPosition(Vec2(btn_yes->getContentSize().width / 2, btn_yes->getContentSize().height / 2));
	btn_yes->addChild(label_yes);
	auto label_no = Label::createWithTTF("NO", "fonts/arial.ttf", 50);
	label_no->setPosition(Vec2(btn_no->getContentSize().width / 2, btn_no->getContentSize().height / 2));
	btn_no->addChild(label_no);
	btn_yes->addClickEventListener(CC_CALLBACK_1(HomeMenu::buttonExitYes, this));
	btn_no->addClickEventListener(CC_CALLBACK_1(HomeMenu::buttonExitNo, this));
	//////////////////

	// UI PLAY GAME//
	auto label_game1 = Label::createWithTTF("OPERATIONS", "fonts/arial.ttf", 30);
	label_game1->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));
	auto label_game2 = Label::createWithTTF("CARD CALCULATION", "fonts/arial.ttf", 30);
	label_game2->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));
	auto label_game3 = Label::createWithTTF("SIMPLICITY", "fonts/arial.ttf", 30);
	label_game3->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));
	auto label_game4 = Label::createWithTTF("DRIVE GEAR", "fonts/arial.ttf", 30);
	label_game4->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));
	auto label_game5 = Label::createWithTTF("FLICKER MASTER", "fonts/arial.ttf", 30);
	label_game5->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));
	auto label_game6 = Label::createWithTTF("ROCK PAPER SCISSOR", "fonts/arial.ttf", 30);
	label_game6->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));

	pil_game1->setAnchorPoint(Vec2(0,0));
	pil_game1->setPosition(Vec2(30, 700));
	pil_game1->setScale(0.f);

	pil_game2->setAnchorPoint(Vec2(0, 0));
	pil_game2->setPosition(Vec2(400 , 700));
	pil_game2->setScale(0.f);

	pil_game3->setAnchorPoint(Vec2(0, 0));
	pil_game3->setPosition(Vec2(30, 500));
	pil_game3->setScale(0.f);

	pil_game4->setAnchorPoint(Vec2(0, 0));
	pil_game4->setPosition(Vec2(400, 500));
	pil_game4->setScale(0.f);

	pil_game5->setAnchorPoint(Vec2(0, 0));
	pil_game5->setPosition(Vec2(30, 300));
	pil_game5->setScale(0.f);

	pil_game6->setAnchorPoint(Vec2(0, 0));
	pil_game6->setPosition(Vec2(400, 300));
	pil_game6->setScale(0.f);

	close_play->setAnchorPoint(Vec2(0.5, 0));
	close_play->setPosition(Vec2(768/2, 100));
	close_play->setScale(0.f);
	auto close_play_label = Label::createWithTTF("CLOSE", "fonts/arial.ttf", 30);
	close_play_label->setPosition(Vec2(pil_game1->getContentSize().width / 2, pil_game1->getContentSize().height / 2));


	this->addChild(pil_game1);
	this->addChild(pil_game2);
	this->addChild(pil_game3);
	this->addChild(pil_game4);
	this->addChild(pil_game5);
	this->addChild(pil_game6);
	this->addChild(close_play);

	pil_game1->addChild(label_game1);
	pil_game2->addChild(label_game2);
	pil_game3->addChild(label_game3);
	pil_game4->addChild(label_game4);
	pil_game5->addChild(label_game5);
	pil_game6->addChild(label_game6);

	close_play->addChild(close_play_label);

	pil_game1->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGame1, this));
	pil_game2->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGame2, this));
	pil_game3->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGame3, this));
	pil_game4->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGame4, this));
	pil_game5->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGame5, this));
	pil_game6->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGame6, this));
	close_play->addClickEventListener(CC_CALLBACK_1(HomeMenu::menuGameClose, this));
	////////////////
	if (callBtnPlay == true)
	{
		buttonPlay(this);
	}
	return true;
}
	

void HomeMenu::buttonPlay(Ref* sender)
{
	btn_sound();
	buttonMenu_hilang();
	pil_game1->setScale(1.f);
	pil_game2->setScale(1.f);
	pil_game3->setScale(1.f);
	pil_game4->setScale(1.f);
	pil_game5->setScale(1.f);
	pil_game6->setScale(1.f);
	close_play->setScale(1.f);

}
void HomeMenu::menuGame1(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), CallFunc::create([&]
	{
		
		Director::getInstance()->replaceScene(Game1::scene());
	})));
	pilih_game = 1;

}


void HomeMenu::menuGame2(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(Game2::scene());
	})));
	pilih_game = 2;
}
void HomeMenu::menuGame3(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(Game3::scene());
	})));
	pilih_game = 3;
}
void HomeMenu::menuGame4(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(Game4::scene());
	})));
	pilih_game = 4;
}
void HomeMenu::menuGame5(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(Game5::scene());
	})));
	pilih_game = 5;
}
void HomeMenu::menuGame6(Ref* sender)
{
	btn_sound();
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(Game6::scene());
	})));
	pilih_game = 6;
}
void HomeMenu::menuGameClose(Ref* sender)
{
	btn_sound();
	pil_game1->setScale(0.f);
	pil_game2->setScale(0.f);
	pil_game3->setScale(0.f);
	pil_game4->setScale(0.f);
	pil_game5->setScale(0.f);
	pil_game6->setScale(0.f);
	close_play->setScale(0.f);
	buttonMenu_tampil();
}
void HomeMenu::buttonProfile(Ref* sender)
{
	btn_sound();
	buttonMenu_hilang();
	ui_profile->setScale(1.f);
	close_profile->setScale(1.f);

}
void HomeMenu::uiProfileClose(Ref* sender)
{
	ui_profile->setScale(0.f);
	close_profile->setScale(0.f);
	btn_sound();
	buttonMenu_tampil();
}
void HomeMenu::buttonSetting(Ref* sender)
{
	btn_sound();
	buttonMenu_hilang();
	ui_setting_close->setScale(0.6f);
	bg_setting->setScale(1.f);
	if (setting == 0)
	{
		bgm_on->setScale(1.f);
		bgm_off->setScale(0.f);
	}
		
	else if (setting == 1)
	{
		bgm_off->setScale(1.f);
		bgm_on->setScale(0.f);
	}
		
}
void HomeMenu::buttonExit(Ref* sender)
{
	
	btn_sound();
	buttonMenu_hilang();
	bg_exit->setScale(1.f);
	btn_yes->setScale(0.5f);
	btn_no->setScale(0.5f);
	
	
}

void HomeMenu::buttonExitYes(Ref* sender)
{
	btn_sound();
	Director::getInstance()->end();
}
void HomeMenu::buttonExitNo(Ref* sender)
{
	btn_sound();
	buttonMenu_tampil();
	bg_exit->setScale(0.f);
	btn_yes->setScale(0.f);
	btn_yes->setScale(0.f);
}

void HomeMenu::buttonSettingOn(Ref* sender)
{
	btn_sound();
	bgm_off->setScale(1.f);
	bgm_on->setScale(0.f);
	bgm->setBackgroundMusicVolume(0.f);
	setting = 1;
}

void HomeMenu::buttonSettingOff(Ref* sender)
{
	btn_sound();
	setting = 0;
	bgm_off->setScale(0.f);
	bgm_on->setScale(1.f);
	bgm->setBackgroundMusicVolume(0.3f);
}
void HomeMenu::uiSettingClose(Ref* sender)
{
	btn_sound();
	bg_setting->setScale(0.f);
	bgm_off->setScale(0.f);
	bgm_on->setScale(0.f);
	ui_setting_close->setScale(0.f);
	buttonMenu_tampil();
}
void HomeMenu::buttonMenu_hilang()
{
	btn_exit->setScale(0.f);
	btn_play->setScale(0.f);
	btn_profile->setScale(0.f);
	btn_setting->setScale(0.f);
	
}
void HomeMenu::buttonMenu_tampil()
{
	btn_exit->setScale(1.f);
	btn_play->setScale(1.f);
	btn_profile->setScale(1.f);
	btn_setting->setScale(1.f);
}
 void HomeMenu::btn_sound()
{
	SimpleAudioEngine* sfx = SimpleAudioEngine::getInstance();
	sfx->playEffect("button.mp3", false, 1.0f, 1.0f, 1.0f);
}
 void HomeMenu::btn_wrong()
 {
	 SimpleAudioEngine* wrong = SimpleAudioEngine::getInstance();
	 wrong->playEffect("wrong.mp3", false, 1.0f, 1.0f, 1.0f);
	 Device::vibrate(0.4f);
 }


