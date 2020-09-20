#include <algorithm> // std::shuffle
#include <array>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

enum class CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,

    MAX_SUITS
};

enum class CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,

    MAX_RANKS
};

struct Card
{
    CardRank rank{};
    CardSuit suit{};
};

struct Player
{
    int score{};
};

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

// Maximum score before losing.
constexpr int maximumScore{21};

// Minimum score that the dealer has to have.
constexpr int minimumDealerScore{17};

void printCard(const Card &card)
{
    switch (card.rank)
    {
    case CardRank::RANK_2:
        std::cout << '2';
        break;
    case CardRank::RANK_3:
        std::cout << '3';
        break;
    case CardRank::RANK_4:
        std::cout << '4';
        break;
    case CardRank::RANK_5:
        std::cout << '5';
        break;
    case CardRank::RANK_6:
        std::cout << '6';
        break;
    case CardRank::RANK_7:
        std::cout << '7';
        break;
    case CardRank::RANK_8:
        std::cout << '8';
        break;
    case CardRank::RANK_9:
        std::cout << '9';
        break;
    case CardRank::RANK_10:
        std::cout << 'T';
        break;
    case CardRank::RANK_JACK:
        std::cout << 'J';
        break;
    case CardRank::RANK_QUEEN:
        std::cout << 'Q';
        break;
    case CardRank::RANK_KING:
        std::cout << 'K';
        break;
    case CardRank::RANK_ACE:
        std::cout << 'A';
        break;
    default:
        std::cout << '?';
        break;
    }

    switch (card.suit)
    {
    case CardSuit::SUIT_CLUB:
        std::cout << 'C';
        break;
    case CardSuit::SUIT_DIAMOND:
        std::cout << 'D';
        break;
    case CardSuit::SUIT_HEART:
        std::cout << 'H';
        break;
    case CardSuit::SUIT_SPADE:
        std::cout << 'S';
        break;
    default:
        std::cout << '?';
        break;
    }
}

int getCardValue(const Card &card)
{
    // Handle rank 2 - 10. We could do this in the switch, but it would be long.
    if (card.rank <= CardRank::RANK_10)
    {
        return (static_cast<int>(card.rank) + 2);
    }

    switch (card.rank)
    {
    case CardRank::RANK_JACK:
    case CardRank::RANK_QUEEN:
    case CardRank::RANK_KING:
        return 10;
    case CardRank::RANK_ACE:
        return 11;
    default:
        // Should never happen. If it does, we have a bug in our code.
        return 0;
    }
}

void printDeck(const deck_type &deck)
{
    for (const auto &card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }

    std::cout << '\n';
}

deck_type createDeck()
{
    deck_type deck{};

    index_type card{0};

    auto suits{static_cast<int>(CardSuit::MAX_SUITS)};
    auto ranks{static_cast<int>(CardRank::MAX_RANKS)};

    for (int suit{0}; suit < suits; ++suit)
    {
        for (int rank{0}; rank < ranks; ++rank)
        {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }

    return deck;
}

void shuffleDeck(deck_type &deck)
{
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

    std::shuffle(deck.begin(), deck.end(), mt);
}

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(const deck_type &deck, index_type &nextCardIndex, Player &player)
{
    while (true)
    {
        std::cout << "You have: " << player.score << '\n';

        if (player.score > maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                player.score += getCardValue(deck[nextCardIndex++]);
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const deck_type &deck, index_type &nextCardIndex, Player &dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score < minimumDealerScore)
    {
        dealer.score += getCardValue(deck[nextCardIndex++]);
    }

    // If the dealer's score is too high, they went bust.
    return (dealer.score > maximumScore);
}

bool playBlackjack(const deck_type &deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    index_type nextCardIndex{0};

    // Create the dealer and give them 1 card.
    Player dealer{getCardValue(deck[nextCardIndex++])};

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // Create the player and give them 2 cards.
    Player player{getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1])};
    nextCardIndex += 2;

    if (playerTurn(deck, nextCardIndex, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score > dealer.score);
}

int main()
{
    auto deck{createDeck()};

    shuffleDeck(deck);

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}