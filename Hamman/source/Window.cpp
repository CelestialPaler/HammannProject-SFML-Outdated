#include "Window.h"

void Window::Run(void)
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHight), title, sf::Style::None);
	WindowConfig(window);

	// DefineWindowShape(window);

	while (window.isOpen())
	{
		EventHandle(window);
		Update(window);
		Clear(window);
		Draw(window);
		Display(window);
	}
}

void Window::Update(sf::RenderWindow & _window)
{
	hamman.Update();
}

void Window::Draw(sf::RenderWindow & _window)
{
	_window.draw(hamman.sprite);
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
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, WS_EX_TOOLWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

	MARGINS margins;
	margins.cxLeftWidth = -1;
	SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
	DwmExtendFrameIntoClientArea(hwnd, &margins);
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			if (evt.type == sf::Event::MouseButtonPressed)
			{
				if (evt.mouseButton.button == sf::Mouse::Right)
				{
					hamman.ChangeCharactor();
				}
			}
		}
	}
}

void Window::DefineWindowShape(sf::RenderWindow & _window)
{
	for (size_t i = 0; i < 2; i++)
	{
		Clear(_window);
		Draw(_window);
		Display(_window);
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
					tempRgn = CreateRectRgn(xLeft, y, xRight, y + 1);
					CombineRgn(wndRgn, wndRgn, tempRgn, RGN_OR);
					DeleteObject(tempRgn);
				}
			}
		}
		SetWindowRgn(hwnd, wndRgn, TRUE);
		if (wndRgn != NULL) 
			DeleteObject(wndRgn);
	}
}

