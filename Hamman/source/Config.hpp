/***************************************************************************************************/
/*                                               Deep Learning Developing Kit                                                   */
/*								        		 	              Hamman    															   */
/*								        		 	             Config File    															   */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// SFML Library
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
// STD
#include <string>
#include <iostream>
#include <cmath>
#include <Dwmapi.h>
#include <shlobj.h>
#include <Windows.h>

static const unsigned int windowHight = 550;
static const unsigned int windowWidth = 400;
static const std::string hammanTexturePath1 = "resource\\hamman_g.png";
static const std::string hammanTexturePath2 = "resource\\hamman_d.png";

static const float scaleMax = 0.5;
static const float scaleMin = 0.2;

#pragma comment (lib, "Dwmapi.lib")