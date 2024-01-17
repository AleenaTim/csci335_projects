/******************************************************************************
File            : Deck.cpp
Title           : Project 1: Card Game
Author          : Aleena Tim
Created on      : 11/05/2023
Description     : Deck Class 
******************************************************************************/
#include "Deck.hpp"

/**
 * @post: Construct a new Deck object
 */
template <typename CardType>
Deck<CardType>::Deck() {}

/**
 * @post: Destroy the Deck object
 */
template <typename CardType>
Deck<CardType>::~Deck() {}

/**
 * @post: Add a Card to the Deck
 * @param: const reference to CardType card
 */
template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card)
{
	cards_.push_back(card);
}

/**
 * @post: Draw a card from the deck
 * @pre: the deck is not empty
 * @return the right hand value of type CardType
 */
template <typename CardType>
CardType &&Deck<CardType>::Draw()
{
	if (cards_.empty())
	{
		throw std::runtime_error("Empty deck");
	}

	CardType &&drawnCard = std::move(cards_.back());
	cards_.pop_back();
	return std::move(drawnCard);
}

/**
 * @return if the deck is empty
 */
template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
	return cards_.empty();
}

/**
 * @post: Shuffle the deck
 * Create a random number generator using std::mt19937 with seed 2028358904,
 * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.
 * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
 * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
 */
template <typename CardType>
void Deck<CardType>::Shuffle()
{
	// Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Perform Fisher-Yates shuffle
    for (size_t i = cards_.size() - 1; i > 0; --i) {
        size_t j = std::rand() % (i + 1);
        std::swap(cards_[i], cards_[j]);
    }
}

/**
 * @return the size of the deck
 */
template <typename CardType>
int Deck<CardType>::getSize() const
{
	return cards_.size();
}

/**
 * @return the vector of cards in the deck
 */
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
	return cards_;
}
