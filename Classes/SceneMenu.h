#ifndef __SCENE_MENU_H__
#define __SCENE_MENU_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class SceneMenu :public Scene
{
private:
	
public:

	void ButtonStartCallBack(Ref* sender);
	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(SceneMenu);

	Label* label_brain;
	Label* label_wars;
	Button* button_start;
	Sprite* icon;
	Sprite* bg;
	float waktu = 5;
	float waktu_loading = 3;
	void penjadwalanWaktu(float dt);

	
	
};


#endif