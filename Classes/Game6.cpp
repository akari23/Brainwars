#include "Game6.h"

Scene* Game6::scene()
{
	return Game6::create();
}
float Game6::benar = 0;
float Game6::salah = 0;

bool Game6::init()
{
	if (!Scene::init())
	{
		return false;
	}
	

	benar = 0;
	salah = 0;
	bg_menu->setAnchorPoint(Vec2(0, 0));
	bg_menu->setScale(1.f);
	this->addChild(bg_menu);
	btn_back->setAnchorPoint(Vec2(0, 1));
	btn_back->setPosition(Vec2(0, 1366));
	this->addChild(btn_back);
	btn_back->addClickEventListener(CC_CALLBACK_1(Game6::kembali, this));

	ui_play->setPosition(Vec2(384, 683));
	ui_play->setScale(1.f);
	this->addChild(ui_play);
	button_start->setScale(1.f);
	button_start->setPosition(Vec2(768 / 2, 400));
	button_start->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(button_start);
	auto label_start = Label::createWithTTF("START", "fonts/arial.ttf", 50);
	label_start->setPosition(Vec2(button_start->getContentSize().width / 2, button_start->getContentSize().height / 2));
	label_start->setScale(1.f);
	button_start->addChild(label_start);
	button_start->addClickEventListener(CC_CALLBACK_1(Game6::mulaiGame, this));

	//waktu//
	label_waktu->setPosition(Vec2(384, 1000));
	label_waktu->setScale(0.f);
	this->addChild(label_waktu);
	///////

	//soal game//
	soal_Gunting->setPosition(Vec2(768/2, 800));
	soal_Batu->setPosition(Vec2(768/2, 800));
	soal_Kertas->setPosition(Vec2(768/2, 800));

	soal_Gunting->setScale(0.f);
	soal_Batu->setScale(0.f);
	soal_Kertas->setScale(0.f);
	this->addChild(soal_Gunting);
	this->addChild(soal_Batu);
	this->addChild(soal_Kertas);
	/////////////

	//button jawab//

	jawab_Gunting->setPosition(Vec2(4.5, 300));
	jawab_Batu->setPosition(Vec2(259, 300));
	jawab_Kertas->setPosition(Vec2(513.5, 300));
	jawab_Gunting->setAnchorPoint(Vec2(0, 0));
	jawab_Batu->setAnchorPoint(Vec2(0, 0));
	jawab_Kertas->setAnchorPoint(Vec2(0, 0));
	
	jawab_Gunting->setScale(0.f);
	jawab_Batu->setScale(0.f);
	jawab_Kertas->setScale(0.f);
	
	this->addChild(jawab_Gunting);
	this->addChild(jawab_Batu);
	this->addChild(jawab_Kertas);
	

	////////////////
	jawab_Batu->addClickEventListener(CC_CALLBACK_1(Game6::btnBatu, this));
	jawab_Gunting->addClickEventListener(CC_CALLBACK_1(Game6::btnGunting, this));
	jawab_Kertas->addClickEventListener(CC_CALLBACK_1(Game6::btnKertas, this));
	return true;
}
void Game6::kembali(Ref* sender)
{

	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}
void Game6::mulaiGame(Ref* sender)
{
	HomeMenu::btn_sound();
	schedule(schedule_selector(Game6::penjadwalanWaktu), 0.0010f);
}
void Game6::penjadwalanWaktu(float dt)
{
	ui_play->setScale(0.f);
	label_waktu->setScale(1.f);
	button_start->setScale(0.f);
	jawab_Gunting->setScale(1.f);
	jawab_Batu->setScale(1.f);
	jawab_Kertas->setScale(1.f);
	

	//soal//
	if (mulai==0)
	{
		int soal_keluar = random(1, 3);
		log("%d", soal_keluar);
		if (soal_keluar == 1) // soal gunting
		{
			soal_Gunting->setScale(0.8f);
			soal_Batu->setScale(0.f);
			soal_Kertas->setScale(0.f);
			pilihan = 1;
		}
		else if (soal_keluar == 2) // soal batu
		{
			soal_Batu->setScale(0.8f);
			soal_Gunting->setScale(0.f);
			soal_Kertas->setScale(0.f);
			pilihan = 2;
		}
		else
		{
			soal_Kertas->setScale(0.8f);
			soal_Batu->setScale(0.f);
			soal_Gunting->setScale(0.f);
			pilihan = 3;
		}
		mulai = 1;
	}

	////////
	//waktu//
	nilai_waktu = __String::createWithFormat("%d", waktu)->getCString();
	label_waktu->setString(nilai_waktu);

	hitung--;
	if (hitung % 1000 == 0)
	{
		waktu--;
	}

	if (waktu == 0)
	{
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.5f), CallFunc::create([&]
		{

			Director::getInstance()->replaceScene(Score::scene());
		})));
	}
}

void Game6::btnBatu(Ref* sender)
{
	mulai = 0;

	if (pilihan == 1)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}

}

void Game6::btnGunting(Ref* sender)
{
	mulai = 0;

	if (pilihan == 3)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}

}

void Game6::btnKertas(Ref* sender)
{

	mulai = 0;

	if (pilihan == 2)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}
}

