/******************************************************************************
File            : PointCard.cpp
Title           : Project 1: Card Game
Author          : Aleena Tim
Created on      : 11/05/2023
Description     : PointCard Class inherits from Card Class
******************************************************************************/
#include "PointCard.hpp"
/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard()
{

	this->setType(POINT_CARD);
}
/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
 */
bool PointCard::isPlayable()
{
	if (this->getDrawn() == 1 && std::stoi(this->getInstruction()) >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card:
 * [ImageData]
 *
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void PointCard::Print() const
{
	std::cout << "Type: " << this->getType() << "\nPoints: " << this->getInstruction() << "\nCard:\n";
	if (this->getImageData() == nullptr)
	{
		std::cout << "No image data\n";
	}
	else
	{
		for (int i = 0; i < 80; i++)
		{
			std::cout << this->getImageData()[i] << " ";
		}
		std::cout << "\n";
	}
}