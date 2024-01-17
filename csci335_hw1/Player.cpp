/******************************************************************************
File            : Player.cpp
Title           : Project 1: Card Game
Author          : Aleena Tim
Created on      : 11/05/2023
Description     : Player Class 
******************************************************************************/
#include "Player.hpp"
#include <cctype>

int getNumber(std::string str)
{
    int i = 0, num = 0;
    while (!isdigit(str[i]))
        i++;
    while (isdigit(str[i]))
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

/**
 * @post: Construct a new Player object
 */
Player::Player()
{
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

/**
 * @post: Destroy the Player object
 */
Player::~Player() {}

/**
 * @return the player's hand
 */
const Hand &Player::getHand() const
{
    return hand_;
}
/**
 * @post: Set the player's hand
 * @param const reference to a hand object
 */
void Player::setHand(const Hand &hand)
{
    hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const
{
    return score_;
}
/**
 * @post: Set the player's score
 * @param: score
 */
void Player::setScore(const int &score)
{
    score_ = score;
}

/**
 * @post: Play a given action card
 * @param: an Actioncard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard &&card)
{
    std::string ins = card.getInstruction();
    std::cout << "PLAYING ACTION CARD: " + ins << '\n';
    std::regex draw("DRAW \\d+ CARD\\(S\\)");
    std::regex play("PLAY \\d+ CARD\\(S\\)");
    std::regex reverse("REVERSE HAND");
    std::regex swap("SWAP HAND WITH OPPONENT");

    if (std::regex_search(ins, draw))
    {
        int k = getNumber(ins);
        while (k-- > 0)
        {
            drawPointCard();
        }
    }
    else if (std::regex_search(ins, play))
    {
        int k = getNumber(ins);
        while (k-- > 0)
        {
            playPointCard();
        }
    }
    else if (std::regex_search(ins, reverse))
    {
        hand_.Reverse();
    }
    else if (std::regex_search(ins, swap))
    {
        std::swap(hand_, opponent_->hand_);
    }
}

/**
 * @post: Draw a point card and place it in the player's hand
 */
void Player::drawPointCard()
{ 
    if (pointdeck_ != nullptr)
    {
        PointCard c1 = pointdeck_->Draw();
        hand_.addCard(std::move(c1));
    }
}
/**
 * @post: Play a point card from the player's hand and update the player's score
 */
void Player::playPointCard()
{
    score_ += hand_.PlayCard();
}

/**
 * @post: Set the opponent of the player
 * @param a pointer to a Player opponent
 */
void Player::setOpponent(Player *opponent)
{
    opponent_ = opponent;
    if (opponent != nullptr)
    {
        opponent->setActionDeck(actiondeck_);
        opponent->setPointDeck(pointdeck_);
    }
}
/**
 * @return: a pointer to the player's opponent
 */
Player *Player::getOpponent()
{
    return opponent_;
}

/**
 * @post: set the action deck of the player
 * @param: A pointer to a deck holding Action cards
 */
void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
    actiondeck_ = actiondeck;
}
/**
 * @return a pointer to the player's action deck
 */
Deck<ActionCard> *Player::getActionDeck()
{
    return actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param: A pointer to a deck holding Point cards
 */
void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
    pointdeck_ = pointdeck;
}
/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard> *Player::getPointDeck()
{
    return pointdeck_;
}