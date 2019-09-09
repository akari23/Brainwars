#include "Game1.h"

Scene* Game1::scene()
{
	return Game1::create();
}
float Game1::benar = 0;
float Game1::salah = 0;
bool freeze = false;


bool Game1::init()
{
	if (!Scene::init())
	{
		return false;
	}
	benar = 0;
	salah = 0;
	bg_menu->setAnchorPoint(Vec2(0,0));
	bg_menu->setScale(1.f);
	this->addChild(bg_menu);
	btn_back->setAnchorPoint(Vec2(0, 1));
	btn_back->setPosition(Vec2(0, 1366));
	this->addChild(btn_back);
	btn_back->addClickEventListener(CC_CALLBACK_1(Game1::kembali, this));
	
	
	ui_play->setPosition(Vec2(384, 683));
	ui_play->setScale(1.f);
	this -> addChild(ui_play);
	button_start->setScale(1.f);
	button_start->setPosition(Vec2(768/2 , 400));
	button_start->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(button_start);
	auto label_start = Label::createWithTTF("START","fonts/arial.ttf",50);
	label_start->setPosition(Vec2(button_start->getContentSize().width / 2, button_start->getContentSize().height / 2));
	label_start->setScale(1.f);
	button_start->addChild(label_start);
	button_start->addClickEventListener(CC_CALLBACK_1(Game1::mulaiGame, this));
	
	label_samadengan->setPosition(Vec2(460, 800));
	garis->setPosition(Vec2(260, 800));
	label_waktu->setPosition(Vec2(384, 1000));
	label_soal1->setPosition(Vec2(160, 800));
	label_soal2->setPosition(Vec2(360, 800));
	label_hasil->setPosition(Vec2(560, 800));
	label_samadengan->setScale(0.f);
	garis->setScale(0.f);
	label_waktu->setScale(0.f);
	label_soal1->setScale(0.f);
	label_soal2->setScale(0.f);
	label_hasil->setScale(0.f);
	this->addChild(garis);
	this->addChild(label_samadengan);
	this->addChild(label_waktu);
	this->addChild(label_soal2);
	this->addChild(label_soal1);
	this->addChild(label_hasil);


	//button game//
	btnTambah->setPosition(Vec2(200, 600));
	btnKurang->setPosition(Vec2(500, 600));
	btnKali->setPosition(Vec2(200, 300));
	btnBagi->setPosition(Vec2(500, 300));

	btnTambah->setScale(0.f);
	btnKurang->setScale(0.f);
	btnKali->setScale(0.f);
	btnBagi->setScale(0.f);
	this->addChild(btnTambah);
	this->addChild(btnKurang);
	this->addChild(btnKali);
	this->addChild(btnBagi);
	//////////////


	btnTambah->addClickEventListener(CC_CALLBACK_1(Game1::btnTambahAction, this));
	btnKurang->addClickEventListener(CC_CALLBACK_1(Game1::btnKurangAction, this));
	btnKali->addClickEventListener(CC_CALLBACK_1(Game1::btnKaliAction, this));
	btnBagi->addClickEventListener(CC_CALLBACK_1(Game1::btnBagiAction, this));
	return true;
}

void Game1::penjadwalanWaktu(float dt)
{
	ui_play->setScale(0.f);
	label_waktu->setScale(1.f);
	button_start->setScale(0.f);
	label_soal1->setScale(1.f);
	label_soal2->setScale(1.f);
	label_hasil->setScale(1.f);
	btnTambah->setScale(1.f);
	btnKurang->setScale(1.f);
	btnKali->setScale(1.f);
	btnBagi->setScale(1.f);
	garis->setScale(1.f);
	label_samadengan->setScale(1.f);

	log("bebar = %.2f", benar);
	log("salah = %.2f", salah);
	
	if (mulai == 0)
	{
		operation = random(1, 4);
		int nilai1 = random(1, 10);
		int nilai2 = random(1, 10);
		log("%d", operation);

		if (operation == 1)
		{
			hasil_string = __String::createWithFormat("%d", nilai1 + nilai2)->getCString();
		}
		else if (operation == 2)
		{
			hasil_string = __String::createWithFormat("%d", nilai1 - nilai2)->getCString();
		}
		else if (operation == 3)
		{
			hasil_string = __String::createWithFormat("%d", nilai1 * nilai2)->getCString();
		}
		else if (operation == 4)
		{
			while (nilai1%nilai2 != 0)
			{
				nilai1 = random(1, 10);
				nilai2 = random(1, 10);
			}
			hasil_string = __String::createWithFormat("%d", nilai1 / nilai2)->getCString();
		}
		mulai = 1;

		const char* soal1 = __String::createWithFormat("%d", nilai1)->getCString();
		const char* soal2 = __String::createWithFormat("%d", nilai2)->getCString();

		
		label_soal1->setString(soal1);
		label_soal2->setString(soal2);
		label_hasil->setString(hasil_string);
	}
	const char* waktu_angka = __String::createWithFormat("%d", waktu)->getCString();
	label_waktu->setString(waktu_angka);
	
	
	

	
	hitung--;
	log("%d", hitung);
	if (hitung%1000 == 0)
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
	
	freeze = false;
	
}

void Game1::kembali(Ref* sender)
{
	
	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}

void Game1::mulaiGame(Ref* sender)
{
	HomeMenu::btn_sound();
	schedule(schedule_selector(Game1::penjadwalanWaktu), 0.0010f);
}

void Game1::btnTambahAction(Ref* sender)
{
	
	if (operation == 1)
	{
		HomeMenu::btn_sound();
	 mulai = 0;
	 benar += 1;
	 if (freeze) return;
	 freeze = true; //kalau true di klik lagi gak bakal masuk sini
	}
	else
	{
		HomeMenu::btn_wrong();
		 mulai = 1;
		 salah += 1;
		
	}
}
void Game1::btnKurangAction(Ref* sender)
{
	
	if (operation == 2)
	{
		HomeMenu::btn_sound();
		benar += 1;
		mulai = 0;
		if (freeze) return;
		freeze = true; //kalau true di klik lagi gak bakal masuk sini
	}
	else
	{
		HomeMenu::btn_wrong();
		 mulai = 1;
		 salah += 1;
		
	}
}
void Game1::btnKaliAction(Ref* sender)
{
	
	if (operation == 3)
	{
		HomeMenu::btn_sound();
		benar += 1;
		mulai = 0;
		if (freeze) return;
		freeze = true; //kalau true di klik lagi gak bakal masuk sini
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
		mulai = 1;
		
	}
}
void Game1::btnBagiAction(Ref* sender)
{
	
	if (operation == 4)
	{
		HomeMenu::btn_sound();
		benar += 1;
		mulai = 0;
		if (freeze) return;
		freeze = true; //kalau true di klik lagi gak bakal masuk sini
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
		mulai = 1;

	}
}