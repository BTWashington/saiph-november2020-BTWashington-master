#include "precompiled_header"

#ifdef BUGS

#include "ExitState.h"
#include "Model/BaseObject.h"
#include "View/ViewManager.h"
#include <fstream>

//TODO Bug #48: Find and fix the bug in this function.
void ExitState::Init()
{
	background = new BaseObject();
	ViewManager::GetInstance().AddObject(background, 0);
	// SetDimensions takes a float parameter -> Loss of Precision on the conversion with an INT argument
	// Function could still function properly until eroneous data
	// Bug had INT going into SetDimensions -> added '.0f' to each argument
	background->SetDimensions(1024.0f, 1024.0f);
	background->SetColor(0.5f, 0.5f, 0.5f, 0.5f);
	background->SetTexture("Resources/images/intro.png");
	background->SetPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f);

	cursor = new BaseObject();
	ViewManager::GetInstance().AddObject(cursor, 5);
	cursor->SetTexture("Resources/images/reticle.png");
	// SetDimensions takes a float parameter -> Loss of Precision on the conversion with an INT argument 
    // Function could still function properly until eroneous data
	cursor->SetDimensions(32.0f,32.0f);
	// SetColor takes floats -> change the arguments from '1' to '1.0f' 
	// effectivly converted the argument to a float per the function
	// definition
	cursor->SetColor(0.74f,1.0f,1.0f,1.0f);

	// save app data
	std::ofstream ofs;							// Changed trunc to app -> trunc could lead to the overwriting of data 												
	ofs.open("Resources/config.xml", std::ios_base::app);
	ofs << "<Config>\n";
	ofs << "  <Window fullscreen=\"" << ((SaiphApp::GetFullscreen()) ? "true" : "false") << "\" renderer=\""
		<< ((SaiphApp::GetRenderer()) ? "directx" : "opengl") << "\"/>\n";
	ofs << "  <StartData level=\"" << SaiphApp::GetLevel() << "\" score=\"" << SaiphApp::GetLevel()
		<< "\" ship=\"" << SaiphApp::GetShipID() << "\" weapon=\"" << SaiphApp::GetWeaponID()
		<< "\" weaponLevel=\"" << SaiphApp::GetWeaponLevel() << "\" generator=\"" << SaiphApp::GetGeneratorID()
		<< "\" shield=\"" << SaiphApp::GetShieldID() << "\" propulsion=\"" << SaiphApp::GetPropulsionID()
		<< "\"/>\n";
	ofs << "  <Control style=\"" << ((SaiphApp::GetControl()) ? "cartesian" : "polar") << "\"/>\n";
	ofs << "</Config>";
	ofs.close();
}

void ExitState::Shutdown()
{
	ViewManager::GetInstance().RemoveObject(background);
	delete background;
	background = NULL;

	ViewManager::GetInstance().RemoveObject(cursor);
	delete cursor;
	cursor = NULL;
}

//TODO Bug #9: Find and fix the bug in this function.
unsigned int ExitState::Heartbeat(float _delta)
{
	// '_delta' is never used
	unsigned int transition = ENDGAME;

	// update reticle (mouse cursor)
	POINT mouse;
	GetCursorPos(&mouse);	
	ScreenToClient(FindWindow(WINDOW_TITLE, WINDOW_TITLE), &mouse);
	cursor->SetXPosition(float(mouse.x));
	cursor->SetYPosition(float(mouse.y));
	// Memory address of VK_RETURN was 0x1 -> changed to 0x0 to match definition
	if((GetAsyncKeyState(VK_RETURN) & 0x0) || (GetAsyncKeyState(VK_LBUTTON) & 0x1))
		transition = -1;
	return transition;
}

void ExitState::RenderFrame() const
{
	ViewManager::GetInstance().BeginScene();
	ViewManager::GetInstance().RenderObjects();
	ViewManager::GetInstance().RenderText(100.0f, 25.0f, "Credits:");
	ViewManager::GetInstance().RenderText(100.0f, 75.0f, "Programmers:");
	ViewManager::GetInstance().RenderText(100.0f, 100.0f, "Derek Bliss");
	ViewManager::GetInstance().RenderText(100.0f, 125.0f, "Nick Penney");
	ViewManager::GetInstance().RenderText(100.0f, 150.0f, "John Wileczek");
	ViewManager::GetInstance().RenderText(100.0f, 200.0f, "Testers:");
	ViewManager::GetInstance().RenderText(100.0f, 225.0f, "Barry McCall");
	ViewManager::GetInstance().RenderText(100.0f, 250.0f, "Cromwell Engage");
	ViewManager::GetInstance().RenderText(100.0f, 275.0f, "John Magno");
	ViewManager::GetInstance().RenderText(100.0f, 325.0f, "Artwork by:");
	ViewManager::GetInstance().RenderText(100.0f, 350.0f, "Danc - Tyrian 2k <http://www.lostgarden.com/index.html>");
	ViewManager::GetInstance().RenderText(100.0f, 375.0f, "Derek Bliss");
	ViewManager::GetInstance().RenderText(100.0f, 400.0f, "Casey Reed - NASA <http://www.nasa.gov>");
	ViewManager::GetInstance().RenderText(100.0f, 500.0f, "Please press Enter or Left Mouse Button to continue...");
	ViewManager::GetInstance().EndScene();
}
#endif BUGS