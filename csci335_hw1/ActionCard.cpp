/******************************************************************************
File            : ActionCard.cpp
Title           : Project 1: Card Game
Author          : Aleena Tim
Created on      : 11/05/2023
Description     : ActionCard Class inherits from Card Class
******************************************************************************/
#include "ActionCard.hpp"

ActionCard::ActionCard()
{
	
	this->setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
	if (this->getDrawn() == 1)
	{
		std::regex draw("^DRAW [0-9] CARD\\(S\\)");
		std::regex play("^PLAY [0-9] CARD\\(S\\)");
		if (this->getInstruction() == "REVERSE HAND" || this->getInstruction() == "SWAP HAND WITH OPPONENT" || std::regex_match(this->getInstruction(), draw) || std::regex_match(this->getInstruction(), play))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void ActionCard::Print() const
{
	std::cout << "Type: " << this->getType() << "\nInstruction: " << this->getInstruction() << "\nCard:\n";
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