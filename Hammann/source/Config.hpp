/***************************************************************************************************/
/*                                               Deep Learning Developing Kit                                                   */
/*								        		 	              Hammann    															   */
/*								        		 	             Config File    															   */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// SFML Library
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
// STD
#include <string>
#include <iostream>
#include <cmath>
#include <Dwmapi.h>
#include <shlobj.h>
#include <Windows.h>
#include <io.h>

static const unsigned int windowHight = 550;
static const unsigned int windowWidth = 400;
static const std::string HammannTexturePath1 = "resource\\textures\\hammann_g.png";
static const std::string HammannTexturePath2 = "resource\\hammann_d.png";
static const std::string HammannAudioPath1 = "resource\\hammann_login.ogg";
static const std::string ResourcePathRoot = "resource";

static const bool LogResourceFileDetail = true;

static const double scaleMax = 0.5;
static const double scaleMin = 0.2;

static const std::string LogfilePath = "log\\log.txt";

#pragma comment (lib, "Dwmapi.lib")