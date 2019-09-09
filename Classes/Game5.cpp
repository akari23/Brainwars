#include "Game5.h"

Scene* Game5::scene()
{
	return Game5::create();
}
float Game5::benar = 0;
float Game5::salah = 0;

bool Game5::init()
{
	if (!Scene::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	benar = 0;
	salah = 0;
	bg_menu->setAnchorPoint(Vec2(0, 0));
	bg_menu->setScale(1.f);
	this->addChild(bg_menu);
	btn_back->setAnchorPoint(Vec2(0, 1));
	btn_back->setPosition(Vec2(0, 1366));
	this->addChild(btn_back);
	btn_back->addClickEventListener(CC_CALLBACK_1(Game5::kembali, this));

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
	button_start->addClickEventListener(CC_CALLBACK_1(Game5::mulaiGame, this));

	//waktu//
	label_waktu->setPosition(Vec2(384, 1000));
	label_waktu->setScale(0.f);
	this->addChild(label_waktu);
	///////

	//soal game//
	SoalBiruAtas->setPosition(Vec2(768 / 2, 800));
	SoalBiruBawah->setPosition(Vec2(768 / 2, 800));
	SoalBiruKanan->setPosition(Vec2(768 / 2, 800));
	SoalBiruKiri->setPosition(Vec2(768 / 2, 800));
	SoalPinkAtas->setPosition(Vec2(768 / 2, 800));
	SoalPinkBawah->setPosition(Vec2(768 / 2, 800));
	SoalPinkKanan->setPosition(Vec2(768 / 2, 800));
	SoalPinkKiri->setPosition(Vec2(768 / 2, 800));

	SoalBiruAtas->setScale(0.f);
	SoalBiruBawah->setScale(0.f);
	SoalBiruKanan->setScale(0.f);
	SoalBiruKiri->setScale(0.f);
	SoalPinkAtas->setScale(0.f);
	SoalPinkBawah->setScale(0.f);
	SoalPinkKanan->setScale(0.f);
	SoalPinkKiri->setScale(0.f);

	this->addChild(SoalBiruAtas);
	this->addChild(SoalBiruBawah);
	this->addChild(SoalBiruKanan);
	this->addChild(SoalBiruKiri);
	this->addChild(SoalPinkAtas);
	this->addChild(SoalPinkBawah);
	this->addChild(SoalPinkKanan);
	this->addChild(SoalPinkKiri);
	/////////////

	//touch event//
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(Game5::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Game5::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Game5::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	isTouchDown = false;

	initialTouchPos[0] = 0;
	initialTouchPos[1] = 0;
	///////////////

	return true;
}
void Game5::kembali(Ref* sender)
{

	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}
void Game5::mulaiGame(Ref* sender)
{
	HomeMenu::btn_sound();
	schedule(schedule_selector(Game5::penjadwalanWaktu), 0.0010f);
}
void Game5::penjadwalanWaktu(float dt)
{
	ui_play->setScale(0.f);
	label_waktu->setScale(1.f);
	button_start->setScale(0.f);


	if (mulai == 0)
	{
		int soal_keluar = random(1, 8);
		if (soal_keluar == 1)//biru atas
		{
			SoalBiruAtas->setScale(1.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 1;
		}
		else if (soal_keluar == 2)//biru bawah
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(1.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 2;
		}
		else if (soal_keluar == 3)//biru kanan
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(1.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 3;
		}
		else if (soal_keluar == 4)//biru kiri
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(1.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 4;
		}
		else if (soal_keluar == 5)//pink atas
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(1.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 2;
		}
		else if (soal_keluar == 6)//pink bawah
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(1.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 1;
		}
		else if (soal_keluar == 7)//pink kanan
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(1.f);
			SoalPinkKiri->setScale(0.f);
			pilihan = 4;
		}
		else if (soal_keluar == 2)//pink kiri
		{
			SoalBiruAtas->setScale(0.f);
			SoalBiruBawah->setScale(0.f);
			SoalBiruKanan->setScale(0.f);
			SoalBiruKiri->setScale(0.f);
			SoalPinkAtas->setScale(0.f);
			SoalPinkBawah->setScale(0.f);
			SoalPinkKanan->setScale(0.f);
			SoalPinkKiri->setScale(1.f);
			pilihan = 3;
		}
		mulai = 1;
	}

	//fungsi swipe//
	if (true == isTouchDown)
	{
		if (initialTouchPos[0] - currentTouchPos[0] > visibleSize.width * 0.05)
		{
			CCLOG("SWIPED LEFT");
			
			if (pilihan == 4)
			{
				HomeMenu::btn_sound();
				benar += 1;
				mulai = 0;
			}
			else
			{
				salah += 1;
				HomeMenu::btn_wrong();
			}
			
			isTouchDown = false;
		}
		else if (initialTouchPos[0] - currentTouchPos[0] < -visibleSize.width * 0.05)
		{
			CCLOG("SWIPED RIGHT");
			
			if (pilihan == 3)
			{
				HomeMenu::btn_sound();
				benar += 1;
				mulai = 0;
			}
			else
			{
				HomeMenu::btn_wrong();
				salah += 1;
			}

			isTouchDown = false;
		}
		else if (initialTouchPos[1] - currentTouchPos[1] > visibleSize.width * 0.05)
		{
			CCLOG("SWIPED DOWN");
			
			if (pilihan == 2)
			{
				HomeMenu::btn_sound();
				benar += 1;
				mulai = 0;
			}
			else
			{
				HomeMenu::btn_wrong();
				salah += 1;
			}

			isTouchDown = false;
		}
		else if (initialTouchPos[1] - currentTouchPos[1] < -visibleSize.width * 0.05)
		{
			CCLOG("SWIPED UP");
			
			if (pilihan == 1)
			{
				HomeMenu::btn_sound();
				benar += 1;
				mulai = 0;
			}
			else
			{
				HomeMenu::btn_wrong();
				salah += 1;
			}

			isTouchDown = false;
		}
	}
	///////////////

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



	bool Game5::onTouchBegan(Touch *touch, Event *event)
	{
		if (touch->getLocation().y < 600)
		{
			initialTouchPos[0] = touch->getLocation().x;
			initialTouchPos[1] = touch->getLocation().y;
			currentTouchPos[0] = touch->getLocation().x;
			currentTouchPos[1] = touch->getLocation().y;

			isTouchDown = true;
		}
		else
		{

		}
		return true;
	}

	void Game5::onTouchMoved(Touch *touch, Event *event)
	{
		currentTouchPos[0] = touch->getLocation().x;
		currentTouchPos[1] = touch->getLocation().y;
	}

	void Game5::onTouchEnded(Touch *touch, Event *event)
	{
		isTouchDown = false;
	}

	void Game5::onTouchCancelled(Touch *touch, Event *event)
	{
		onTouchEnded(touch, event);
	}

