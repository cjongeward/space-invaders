#include "TextObject.h"

void TextObject::setFont(const sf::Font & newFont)
{
  this->font = newFont;
  this->text.setFont(this->font);
}

void TextObject::setText(const std::string & str)
{
  this->text.setString(str);
}

void TextObject::setCharacterSize(const unsigned int size)
{
  this->text.setCharacterSize(size);
}
