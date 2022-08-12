#pragma once
#include "Resource/resource.h"
#include <string>

struct _TTF_Font;
namespace vl
{

	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& name, void* data = nullptr) override ;
		void Load(const std::string& filename, int fontSize);

		friend class Text;
	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}