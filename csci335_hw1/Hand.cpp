/******************************************************************************
File            : Hand.cpp
Title           : Project 1: Card Game
Author          : Aleena Tim
Created on      : 11/05/2023
Description     : Hand Class
******************************************************************************/
#include "Hand.hpp"
#include <algorithm>

// Big Five and constructor
/**
 * @post: Construct a new Hand object
 */
Hand::Hand() {}
/**
 * @post: Destroy the Hand object
 */
Hand::~Hand() {}
/**
 * Copy Constructor
 * @param: other Hand object
 */
Hand::Hand(const Hand &other)
{
    cards_ = other.cards_;
}
/**
 * Copy Assignment Operator
 * @param: other Hand object
 * @return this Hand
 */
Hand &Hand::operator=(const Hand &other)
{
    if (this != &other)
    {
        cards_ = other.cards_;
    }
    return *this;
}
/**
 * Move Constructor
 * @param: other Hand object
 */
Hand::Hand(Hand &&other)
{
    cards_ = std::move(other.cards_);
}
/**
 * Move assignment operator
 * @param: other Hand object
 * @return this Hand
 */
Hand &Hand::operator=(Hand &&other)
{
    if (this != &other)
    {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

/**
 * @return Hand
 */
const std::deque<PointCard> &Hand::getCards() const
{
    return cards_;
}

/**
 * @post: Add a card to the hand
 * @param PointCard object
 */
void Hand::addCard(PointCard &&card)
{
    PointCard &c1 = card;
    c1.setDrawn(true);
    cards_.push_back(std::move(c1));
}

/**
 * @return true if hand is empty, false otherwise
 */
bool Hand::isEmpty() const
{
    return cards_.empty();
}

/**
 * @post: Reverse the hand
 */
void Hand::Reverse()
{
    std::reverse(cards_.begin(), cards_.end());
}

/**
 * @post: Play the card at the front of the hand, removing it from the hand
 * Throws an exception if the hand is empty or the card is not playable
 * If the card is not playable, the card is removed from the hand
 * @return the points earned from playing the card
 */
#include <sstream>

int Hand::PlayCard()
{
    if (cards_.empty())
    {
        throw std::runtime_error("Empty Hand");
    }
    PointCard &my_card = cards_.front();
    int my_score = 0;
    if (my_card.isPlayable())
    {
        my_score = std::stoi(my_card.getInstruction());
        cards_.pop_front();
    }
    else
    {
        cards_.pop_front();
    }
    return my_score;
}
