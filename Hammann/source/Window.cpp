#include "Window.h"

void Window::Run(void)
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHight), title, sf::Style::None);
	WindowConfig(window);
	ResourceConfig();

	//while (window.isOpen())
	//{
	//	DefineWindowShape(window);
	//	EventHandle(window);
	//	Update(window);
	//	Clear(window);
	//	Draw(window);
	//	Display(window);
	//}
}

void Window::Update(sf::RenderWindow & _window)
{
	Hammann.Update();
}

void Window::Draw(sf::RenderWindow & _window)
{
	_window.draw(Hammann.sprite);
}

void Window::Clear(sf::RenderWindow & _window)
{
	_window.clear(sf::Color::Transparent);
}

void Window::Display(sf::RenderWindow & _window)
{
	_window.display();
}

void Window::WindowConfig(sf::RenderWindow & _window)
{
	_window.setFramerateLimit(60);

	HWND hwnd = _window.getSystemHandle();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

	MARGINS margins;
	margins.cxLeftWidth = -1;
	SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE | WS_EX_TOOLWINDOW);
	DwmExtendFrameIntoClientArea(hwnd, &margins);
}

void Window::ResourceConfig(void)
{
	ResourceManager.Init();
	Hammann.SetCharactor(ResourceManager.GetTexturePath("hammann_d.png"));
}

void Window::EventHandle(sf::RenderWindow & _window)
{
	static sf::Vector2i grabOffset;
	static bool grabFlag = false;

	sf::Event evt;
	while (_window.pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed)
			_window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			if (evt.type == sf::Event::MouseButtonPressed)
			{
				if (evt.mouseButton.button == sf::Mouse::Left)
				{
					grabOffset = _window.getPosition() - sf::Mouse::getPosition();
					grabFlag = true;
				}
			}
			else if (evt.type == sf::Event::MouseButtonReleased)
			{
				if (evt.mouseButton.button == sf::Mouse::Left)
					grabFlag = false;
			}
			else if (evt.type == sf::Event::MouseMoved)
			{
				if (grabFlag)
					_window.setPosition(sf::Mouse::getPosition() + grabOffset);
			}
		}
	}
}

void Window::DefineWindowShape(sf::RenderWindow & _window)
{
	const unsigned int windowShapeOffsetY = 5;
	const unsigned int windowShapeOffsetX = 2;

	HRGN wndRgn = CreateRectRgn(0, 0, 0, 0);
	HWND hwnd = _window.getSystemHandle();
	sf::Image img = _window.capture();
	for (unsigned int y = 0; y < img.getSize().y; y++)
	{
		unsigned int xIndex = 0;
		while (xIndex < img.getSize().x)
		{
			HRGN tempRgn;
			int  xLeft = 0, xRight = 0;
			while ((xIndex < img.getSize().x) && (img.getPixel(xIndex, y) == sf::Color::Transparent))
				xIndex++;
			xLeft = xIndex;

			while ((xIndex < img.getSize().x) && (img.getPixel(xIndex, y) != sf::Color::Transparent))
				xIndex++;
			xRight = xIndex;

			if (xLeft != xRight)
			{
				tempRgn = CreateRectRgn(xLeft - windowShapeOffsetX,
															y - windowShapeOffsetY, 
															xRight + windowShapeOffsetX, 
															y + windowShapeOffsetY + 1);
				CombineRgn(wndRgn, wndRgn, tempRgn, RGN_OR);
				DeleteObject(tempRgn);
			}
		}
	}
	SetWindowRgn(hwnd, wndRgn, TRUE);
	if (wndRgn != NULL)
		DeleteObject(wndRgn);
}

void Window::RefreshShape(sf::RenderWindow & _window)
{
	static unsigned int shapeRefreshCounter = 0;
	static unsigned int shapeRefreshFlag = 0;
	
	// Preload some frames to avoid buggy stuff
	if(false)
	{
		for (size_t i = 0; i < 2; i++)
		{
			Update(_window);
			Clear(_window);
			Draw(_window);
			Display(_window);
		}
	}

	if (shapeRefreshFlag==1)
	{
		system("cls");
		std::cout << "INFO: Window::DefineWindowShape Counter : " << shapeRefreshCounter++ << std::endl;
		DefineWindowShape(_window);
	}
	else if (shapeRefreshFlag==15)
		shapeRefreshFlag = 0;
	shapeRefreshFlag++;
}

