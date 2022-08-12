#include "texture.h"
#include "renderer.h"
#include "Core/logger.h"
#include <SDL.h>
#include <SDL_image.h>

namespace vl
{
    Texture::~Texture()
    {
        if (m_texture) SDL_DestroyTexture(m_texture);
    }

    bool Texture::Create(const std::string& name, void* data)
    {
        // check that data is not null;
        Renderer* renderer = static_cast<Renderer*>(data);

        return Create(*renderer, name);
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if (!surface)
        {
            LOG(SDL_GetError());
            return false;
        }

        // create texture
        m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        if (!m_texture)
        {
            LOG(SDL_GetError());
            SDL_FreeSurface(surface);

            return false;
        }

        SDL_FreeSurface(surface);

        return true;
    }

    Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

        return Vector2(point.x, point.y);
    }
}

