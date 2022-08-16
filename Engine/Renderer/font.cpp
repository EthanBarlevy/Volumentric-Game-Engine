#include "font.h"
#include <SDL_ttf.h>

namespace vl
{
	Font::Font(const std::string& filename, int fontSize)
	{
		Load(filename, fontSize);
	}

	Font::~Font()
	{
		if (m_ttfFont) TTF_CloseFont(m_ttfFont);
	}

	bool Font::Create(std::string name, ...)
	{
		va_list args;
		va_start(args, name);
		int size = va_arg(args, int);
		va_end(args);

		Load(name, size);

		return false;
	}

	void Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	}
}
