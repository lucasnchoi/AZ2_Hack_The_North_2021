#include "TextureManager.h"

using namespace GameEngine;

TextureManager* TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}


TextureManager::~TextureManager()
{
	UnLoadTextures();
}


void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture* texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);

		m_textures[a] = texture;
	}
}


void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture) {
		case GameEngine::eTexture::Explosion_0:
			return sf::Vector2f(48.f, 48.f);
		case GameEngine::eTexture::Bomb_Blink:
			return sf::Vector2f(18.f, 18.f);
		case GameEngine::eTexture::Explosion_1:
			return sf::Vector2f(32.f, 32.f);
		case GameEngine::eTexture::Rocket_Blink:
			return sf::Vector2f(25.f, 45.f);
		}

		return sf::Vector2f(-1.f, -1.f);
	}
}
