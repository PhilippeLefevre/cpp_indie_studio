/*
** MainMenu.hh for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Tue May 09 18:37:17 2017 Tanguy Lelievre
** Last update	Sun Jun 18 16:15:13 2017 Tanguy Lelievre
*/

#ifndef MAINMENU_HH_
# define MAINMENU_HH_

# include <driverChoice.h>
# include <dirent.h>
# include <sys/types.h>
# include "irrlicht.h"
# include "Options.hh"
# include <ctime>

class	MainMenu : public irr::IEventReceiver
{
public:
  enum id
  {
    // Main Menu
    GUI_MAIN_MENU_ELEMENT = 0,
    SCENE_MAIN_MENU_NODE,
    GUI_QUIT_BUTTON,
    GUI_NEW_GAME_BUTTON,
    GUI_LOAD_GAME_BUTTON,
    GUI_SCORE_BUTTON,
    GUI_OPTION_BUTTON,

    // Options Menu
    GUI_OPTION_MENU_ELEMENT,
    SCENE_OPTION_MENU_NODE,
    GUI_FULLSCREEN_CHECKBOX,
    GUI_AA_CHECKBOX,
    GUI_VSYNC_CHECKBOX,
    GUI_RES_COMBOBOX,
    GUI_SOUND_LEVEL_SCROLLBAR,
    GUI_SOUND_MUTE_CHECKBOX,
    GUI_MUSIC_LEVEL_SCROLLBAR,
    GUI_MUSIC_MUTE_CHECKBOX,
    GUI_EFFECTS_LEVEL_SCROLLBAR,
    GUI_EFFECTS_MUTE_CHECKBOX,
    GUI_BACK_OPTIONS_BUTTON,
    GUI_APPLY_BUTTON,

    // New Game Menu
    GUI_NEW_GAME_MENU_ELEMENT,
    SCENE_NEW_GAME_MENU_NODE,
    GUI_START_NEW_GAME_BUTTON,
    GUI_BACK_NEW_GAME_BUTTON,
    GUI_NBPLAYER_COMBOBOX,
    GUI_NBIA_COMBOBOX,
    GUI_MAP_LISTBOX,

    // Load Game Menu
    GUI_LOAD_GAME_MENU_ELEMENT,
    SCENE_LOAD_GAME_MENU_NODE,

    // Scores Menu
    GUI_SCORE_MENU_ELEMENT,
    SCENE_SCORE_MENU_NODE,
    GUI_SCORE_POINTS_LISTBOX,
    GUI_SCORE_PSEUDO_LISTBOX,
    GUI_BACK_SCORE_BUTTON,
  };

public:
  MainMenu();
  ~MainMenu();

  irr::s32	run();

  void	createWindow();
  bool	OnEvent(const irr::SEvent &event);
  void	LoadGame();
  void	Menu();
  void	OptionMenu();
  irr::core::stringc	getMap() const;
  irr::s32	getNbIA() const;
  irr::s32	getNbPlayer() const;

private:
  void	prepareGUI();
  void	prepareScene();
  void	optsChange();
  Options	_opts;

  irr::s32	_quit;
  irr::gui::IGUIElement* _rootGUI;
  irr::scene::ISceneNode* _rootScene;

  // Main Menu
  void	MainMenuGUI();
  void	MainMenuScene();
  irr::gui::IGUIElement* _MainMenuGUI;
  irr::scene::IAnimatedMeshSceneNode *_MainMenuScene;

  // New Game Menu
  void	NewGameGUI();
  void	NewGameScene();
  irr::gui::IGUIElement* _NewGameGUI;
  irr::scene::IAnimatedMeshSceneNode *_NewGameScene;

  // Load Game Menu
  void	LoadGameGUI();
  void	LoadGameScene();
  irr::gui::IGUIElement* _LoadGameGUI;
  irr::scene::IAnimatedMeshSceneNode *_LoadGameScene;

  // Score Menu
  void	ScoreGUI();
  void	ScoreScene();
  irr::gui::IGUIElement* _ScoreGUI;
  irr::scene::IAnimatedMeshSceneNode *_ScoreScene;

  // Options Menu
  void	GOptionsGUI();
  void	GOptionsScene();
  irr::gui::IGUIElement* _GOptionGUI;
  irr::scene::IAnimatedMeshSceneNode *_GOptionScene;

  irr::SIrrlichtCreationParameters _params;
  irr::IrrlichtDevice *_Mdevice;
  irr::core::dimension2d<irr::u32> _dim;

  irr::video::E_DRIVER_TYPE _driverType;
  irr::gui::IGUISkin* _skin;
  irr::gui::IGUIFont* _font;

  irr::video::IVideoDriver* _driver;
  irr::gui::IGUIEnvironment* _guienv;
  irr::scene::ISceneManager* _smgr;
  irr::scene::IAnimatedMesh* _mesh;
  irr::scene::IAnimatedMeshSceneNode* _modelNode;
  irr::scene::ISceneNodeAnimator* _ani;

  irr::gui::IGUIButton* _button;
  irr::gui::IGUIComboBox* _combobox;
  irr::gui::IGUIScrollBar* _scrollbar;
  irr::video::IImage*	_image;
  irr::gui::IGUIListBox* _listbox;
};

#endif /* !MAINMENU_HH_ */
