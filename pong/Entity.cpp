#include "Common.h"
#include "Entity.h"

TextEntity::TextEntity(sf::Text& text) : m_text(text)
{
}

void TextEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text);
}
